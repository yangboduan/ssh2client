CPP      = g++
CC       = gcc
CFLAGS   = -std=c++11 -g
OBJ      = m_regex.o ssh2_exec.o 
LINKOBJ  = m_regex.o ssh2_exec.o 
BIN      = ssh_exec
RM       = rm -rf
LIB	 = -lssh2  /usr/local/lib/libboost_regex.so
$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIB)  
clean: 
	${RM} $(OBJ) $(BIN)

cleanobj:
	${RM} *.o

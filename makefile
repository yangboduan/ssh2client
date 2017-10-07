CPP      = g++
CC       = gcc
CFLAGS   = -std=gnu++0x -g
OBJ      = ssh2_exec.o 
LINKOBJ  = ssh2_exec.o 
BIN      = ssh_exec
RM       = rm -rf
LIB	 = -lssh2
$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIB)  
clean: 
	${RM} $(OBJ) $(BIN)

cleanobj:
	${RM} *.o

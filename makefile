CPP      = g++
CC       = gcc
CFLAGS   = -std=gnu++0x
OBJ      = main.o 
LINKOBJ  = main.o 
BIN      = ssh_exec
RM       = rm -rf
LIB	 = -lssh2
$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIB)  
clean: 
	${RM} $(OBJ) $(BIN)

cleanobj:
	${RM} *.o

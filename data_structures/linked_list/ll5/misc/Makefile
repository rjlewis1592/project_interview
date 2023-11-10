CC=gcc
CFLAGS=-g -Wall -Wconversion #-DLIST_DEBUG
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
SRC=$(PWD)

all: ns

ns: $(OBJ)/numeric_strings.o
	$(CC) $(CFLAGS) $(OBJ)/numeric_strings.o -o ns
	mv ns $(BIN)

$(OBJ)/numeric_strings.o: $(SRC)/numeric_strings.c
	$(CC) $(CFLAGS) -c $(SRC)/numeric_strings.c
	mv numeric_strings.o $(OBJ)

clean:
	rm -rf $(OBJ)/* $(BIN)/* 

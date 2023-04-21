CC=gcc
CFLAGS=-g -Wall
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INCLUDE=-I $(PWD)/include/

all: str

str: $(OBJ)/str_main.o $(OBJ)/str_utils.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/str_main.o $(OBJ)/str_utils.o -o str
	mv str $(BIN)

$(OBJ)/str_main.o: $(SRC)/str_main.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/str_main.c
			mv str_main.o $(OBJ)

$(OBJ)/str_utils.o: $(SRC)/str_utils.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/str_utils.c
			mv str_utils.o $(OBJ)
clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install: str
		install -m 0755 str $(BIN)/
    
.PHONY: install

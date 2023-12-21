CC=gcc
CFLAGS=-g -Wall -DBIT_OPS_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include

all: sort

sort: $(OBJ)/sort_main.o $(OBJ)/sort_ops.o $(OBJ)/sort_utils.o # $(INCLUDE)/sort_cmn.h $(INCLUDE)/sort_utils.h $(INCLUDE)/sort_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/sort_main.o $(OBJ)/sort_ops.o $(OBJ)/sort_utils.o -o sort
	mv sort $(BIN)

$(OBJ)/sort_main.o: $(SRC)/sort_main.c $(INCLUDE)/sort_cmn.h $(INCLUDE)/sort_utils.h $(INCLUDE)/sort_ops.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/sort_main.c
	mv sort_main.o $(OBJ)

$(OBJ)/sort_ops.o: $(SRC)/sort_ops.c $(INCLUDE)/sort_cmn.h $(INCLUDE)/sort_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/sort_ops.c
	mv sort_ops.o $(OBJ)

$(OBJ)/sort_utils.o: $(SRC)/sort_utils.c $(INCLUDE)/sort_cmn.h 
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/sort_utils.c
	mv sort_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/sort $(INSTALL_DIR)/

.PHONY: install
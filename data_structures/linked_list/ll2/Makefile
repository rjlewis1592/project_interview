CC=gcc
CFLAGS=-g -Wall -DLIST_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: lst

lst: $(OBJ)/list_main.o $(OBJ)/list_ops.o $(INCLUDE)/list_cmn.h $(INCLUDE)/list_defs.h $(INCLUDE)/list_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/list_main.o $(OBJ)/list_ops.o -o lst
	mv lst $(BIN)

$(OBJ)/list_main.o: $(SRC)/list_main.c
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/list_main.c
	mv list_main.o $(OBJ)

$(OBJ)/list_ops.o: $(SRC)/list_ops.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/list_ops.c
	mv list_ops.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/lst $(INSTALL_DIR)/

.PHONY: install

CC=gcc
CFLAGS=-g -Wall -DTREE_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: tr

tr: $(OBJ)/tree_main.o $(OBJ)/tree_ops.o $(OBJ)/tree_utils.o
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/tree_main.o $(OBJ)/tree_ops.o $(OBJ)/tree_utils.o -o tr
	mv tr $(BIN)

$(OBJ)/tree_main.o: $(SRC)/tree_main.c $(INCLUDE)/tree_defs.h $(INCLUDE)/tree_cmn.h $(INCLUDE)/tree_utils.h $(INCLUDE)/tree_ops.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/tree_main.c
	mv tree_main.o $(OBJ)

$(OBJ)/tree_ops.o: $(SRC)/tree_ops.c $(INCLUDE)/tree_cmn.h $(INCLUDE)/tree_defs.h $(INCLUDE)/tree_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/tree_ops.c
	mv tree_ops.o $(OBJ)

$(OBJ)/tree_utils.o: $(SRC)/tree_utils.c $(INCLUDE)/tree_cmn.h $(INCLUDE)/tree_defs.h $(INCLUDE)/tree_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/tree_utils.c
	mv tree_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/tr $(INSTALL_DIR)/

.PHONY: install

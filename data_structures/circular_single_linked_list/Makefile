CC=gcc
CFLAGS=-g -Wall -DLIST_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: clst

clst: $(OBJ)/list_main.o $(OBJ)/list_ops.o $(OBJ)/list_utils.o $(INCLUDE)/list_cmn.h $(INCLUDE)/list_defs.h $(INCLUDE)/list_ops.h $(INCLUDE)/list_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/list_main.o $(OBJ)/list_ops.o $(OBJ)/list_utils.o -o clst
	mv clst $(BIN)

$(OBJ)/list_main.o: $(SRC)/list_main.c $(INCLUDE)/list_cmn.h $(INCLUDE)/list_utils.h $(INCLUDE)/list_ops.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/list_main.c
	mv list_main.o $(OBJ)

$(OBJ)/list_ops.o: $(SRC)/list_ops.c $(INCLUDE)/list_cmn.h $(INCLUDE)/list_defs.h $(INCLUDE)/list_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/list_ops.c
	mv list_ops.o $(OBJ)

$(OBJ)/list_utils.o: $(SRC)/list_utils.c $(INCLUDE)/list_cmn.h $(INCLUDE)/list_defs.h $(INCLUDE)/list_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/list_utils.c
	mv list_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/clst $(INSTALL_DIR)/

.PHONY: install

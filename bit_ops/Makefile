CC=gcc
CFLAGS=-g -Wall -DBIT_OPS_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: bitops

bitops: $(OBJ)/bit_ops_main.o $(OBJ)/bit_ops.o $(OBJ)/bit_ops_utils.o $(INCLUDE)/bit_ops_cmn.h $(INCLUDE)/bit_ops_defs.h $(INCLUDE)/bit_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/bit_ops_main.o $(OBJ)/bit_ops.o $(OBJ)/bit_ops_utils.o -o bitops
	mv bitops $(BIN)

$(OBJ)/bit_ops_main.o: $(SRC)/bit_ops_main.c $(INCLUDE)/bit_ops_cmn.h $(INCLUDE)/bit_ops_defs.h $(INCLUDE)/bit_ops.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/bit_ops_main.c
	mv bit_ops_main.o $(OBJ)

$(OBJ)/bit_ops.o: $(SRC)/bit_ops.c $(INCLUDE)/bit_ops_cmn.h $(INCLUDE)/bit_ops_defs.h $(INCLUDE)/bit_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/bit_ops.c
	mv bit_ops.o $(OBJ)

$(OBJ)/bit_ops_utils.o: $(SRC)/bit_ops_utils.c $(INCLUDE)/bit_ops_cmn.h $(INCLUDE)/bit_ops_defs.h $(INCLUDE)/bit_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/bit_ops_utils.c
	mv bit_ops_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/bitops $(INSTALL_DIR)/

.PHONY: install
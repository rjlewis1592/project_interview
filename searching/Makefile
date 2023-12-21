CC=gcc
CFLAGS=-g -Wall -DSEARCH_OPS_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include

all: srch

srch: $(OBJ)/search_main.o $(OBJ)/search_ops.o $(OBJ)/search_utils.o
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/search_main.o $(OBJ)/search_ops.o $(OBJ)/search_utils.o -o srch
	mv srch $(BIN)

$(OBJ)/search_main.o: $(SRC)/search_main.c $(INCLUDE)/search_cmn.h $(INCLUDE)/search_utils.h $(INCLUDE)/search_ops.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/search_main.c
	mv search_main.o $(OBJ)

$(OBJ)/search_ops.o: $(SRC)/search_ops.c $(INCLUDE)/search_cmn.h $(INCLUDE)/search_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/search_ops.c
	mv search_ops.o $(OBJ)

$(OBJ)/search_utils.o: $(SRC)/search_utils.c $(INCLUDE)/search_cmn.h 
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/search_utils.c
	mv search_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/* $(INSTALL_DIR)/*

install:
		install -m 0755 $(BIN)/srch $(INSTALL_DIR)/

.PHONY: install
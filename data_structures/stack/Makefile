CC=gcc
CFLAGS=-g -Wall -DSTACK_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: stk

stk: $(OBJ)/stack_main.o $(OBJ)/stack_ops.o $(OBJ)/stack_utils.o # $(INCLUDE)/stack_cmn.h $(INCLUDE)/stack_defs.h $(INCLUDE)/stack_ops.h $(INCLUDE)/stack_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/stack_main.o $(OBJ)/stack_ops.o $(OBJ)/stack_utils.o -o stk
	mv stk $(BIN)

$(OBJ)/stack_main.o: $(SRC)/stack_main.c $(INCLUDE)/stack_cmn.h $(INCLUDE)/stack_defs.h $(INCLUDE)/stack_ops.h $(INCLUDE)/stack_utils.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/stack_main.c
	mv stack_main.o $(OBJ)

$(OBJ)/stack_ops.o: $(SRC)/stack_ops.c $(INCLUDE)/stack_cmn.h $(INCLUDE)/stack_defs.h $(INCLUDE)/stack_ops.h $(INCLUDE)/stack_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/stack_ops.c
	mv stack_ops.o $(OBJ)

$(OBJ)/stack_utils.o: $(SRC)/stack_utils.c $(INCLUDE)/stack_cmn.h $(INCLUDE)/stack_defs.h $(INCLUDE)/stack_ops.h $(INCLUDE)/stack_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/stack_utils.c
	mv stack_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/stk $(INSTALL_DIR)/

.PHONY: install

CC=gcc
CFLAGS=-g -Wall -DQUEUE_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: lq

lq: $(OBJ)/queue_main.o $(OBJ)/queue_ops.o $(OBJ)/queue_utils.o #$(INCLUDE)/queue_cmn.h $(INCLUDE)/queue_defs.h $(INCLUDE)/queue_ops.h $(INCLUDE)/queue_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/queue_main.o $(OBJ)/queue_ops.o $(OBJ)/queue_utils.o -o lq
	mv lq $(BIN)

$(OBJ)/queue_main.o: $(SRC)/queue_main.c $(INCLUDE)/queue_cmn.h $(INCLUDE)/queue_utils.h $(INCLUDE)/queue_ops.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/queue_main.c
	mv queue_main.o $(OBJ)

$(OBJ)/queue_ops.o: $(SRC)/queue_ops.c $(INCLUDE)/queue_cmn.h $(INCLUDE)/queue_defs.h $(INCLUDE)/queue_ops.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/queue_ops.c
	mv queue_ops.o $(OBJ)

$(OBJ)/queue_utils.o: $(SRC)/queue_utils.c $(INCLUDE)/queue_cmn.h $(INCLUDE)/queue_defs.h $(INCLUDE)/queue_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/queue_utils.c
	mv queue_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/lq $(INSTALL_DIR)/

.PHONY: install

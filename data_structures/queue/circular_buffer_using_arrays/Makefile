CC=gcc
CFLAGS=-g -Wall -DCBUF_DEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=$(PWD)/include/

all: cbuf

cbuf: $(OBJ)/cbuf_main.o $(OBJ)/cbuf_ops.o $(OBJ)/cbuf_utils.o
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/cbuf_main.o $(OBJ)/cbuf_ops.o $(OBJ)/cbuf_utils.o -o cbuf
	mv cbuf $(BIN)

$(OBJ)/cbuf_main.o: $(SRC)/cbuf_main.c $(INCLUDE)/cbuf_main.h $(INCLUDE)/cbuf_cmn.h $(INCLUDE)/cbuf_ops.h $(INCLUDE)/cbuf_utils.h
	$(CC) $(CFLAGS) -I  $(INCLUDE) -c $(SRC)/cbuf_main.c
	mv cbuf_main.o $(OBJ)

$(OBJ)/cbuf_ops.o: $(SRC)/cbuf_ops.c $(INCLUDE)/cbuf_ops.h $(INCLUDE)/cbuf_cmn.h $(INCLUDE)/cbuf_defs.h $(INCLUDE)/cbuf_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/cbuf_ops.c
	mv cbuf_ops.o $(OBJ)

$(OBJ)/cbuf_utils.o: $(SRC)/cbuf_utils.c $(INCLUDE)/cbuf_cmn.h $(INCLUDE)/cbuf_defs.h $(INCLUDE)/cbuf_utils.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/cbuf_utils.c
	mv cbuf_utils.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/cbuf $(INSTALL_DIR)/

.PHONY: install

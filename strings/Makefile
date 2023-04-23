CC=gcc
CFLAGS=-g -Wall
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INCLUDE=$(PWD)/include/

all: my_strcpy my_strcat

my_strcat: $(OBJ)/my_strcat.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strcat.o  -o my_strcat
	mv my_strcat $(BIN)

$(OBJ)/my_strcat.o: $(SRC)/my_strcat.c
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strcat.c
			mv my_strcat.o $(OBJ)

my_strcpy: $(OBJ)/my_strcpy.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strcpy.o  -o my_strcpy
	mv my_strcpy $(BIN)

$(OBJ)/my_strcpy.o: $(SRC)/my_strcpy.c
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strcpy.c
			mv my_strcpy.o $(OBJ)
clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install: str
		install -m 0755 str $(BIN)/
    
.PHONY: install
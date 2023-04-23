CC=gcc
CFLAGS=-g -Wall
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INCLUDE=$(PWD)/include/

all: my_strcpy my_strcat my_strlen my_strrev_one my_strncpy 

my_strrev_one: $(OBJ)/my_strrev_one.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strrev_one.o  -o my_strrev_one
	mv my_strrev_one $(BIN)

$(OBJ)/my_strrev_one.o: $(SRC)/my_strrev_one.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strrev_one.c
	mv my_strrev_one.o $(OBJ)

my_strlen: $(OBJ)/my_strlen.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strlen.o  -o my_strlen
	mv my_strlen $(BIN)

$(OBJ)/my_strlen.o: $(SRC)/my_strlen.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strlen.c
	mv my_strlen.o $(OBJ)

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

my_strncpy: $(OBJ)/my_strncpy.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strncpy.o  -o my_strncpy
	mv my_strncpy $(BIN)

$(OBJ)/my_strncpy.o: $(SRC)/my_strncpy.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strncpy.c
	mv my_strncpy.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install: str
		install -m 0755 str $(BIN)/
    
.PHONY: install
CC=gcc
CFLAGS=-g -Wall
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INCLUDE=$(PWD)/include/

all: my_strcpy my_strcpy_ptr my_strcat my_strcat_ptr my_strncat my_strlen my_strlen_ptr my_strrev_one my_strncpy my_strncpy_ptr my_strstr rev_individual_words

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

my_strlen_ptr: $(OBJ)/my_strlen_ptr.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strlen_ptr.o  -o my_strlen_ptr
	mv my_strlen_ptr $(BIN)

$(OBJ)/my_strlen_ptr.o: $(SRC)/my_strlen_ptr.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strlen_ptr.c
	mv my_strlen_ptr.o $(OBJ)

my_strcat: $(OBJ)/my_strcat.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strcat.o  -o my_strcat
	mv my_strcat $(BIN)

$(OBJ)/my_strcat.o: $(SRC)/my_strcat.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strcat.c
	mv my_strcat.o $(OBJ)

my_strcat_ptr: $(OBJ)/my_strcat_ptr.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strcat_ptr.o  -o my_strcat_ptr
	mv my_strcat_ptr $(BIN)

$(OBJ)/my_strcat_ptr.o: $(SRC)/my_strcat_ptr.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strcat_ptr.c
	mv my_strcat_ptr.o $(OBJ)

my_strncat: $(OBJ)/my_strncat.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strncat.o  -o my_strncat
	mv my_strncat $(BIN)

$(OBJ)/my_strncat.o: $(SRC)/my_strncat.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strncat.c
	mv my_strncat.o $(OBJ)

my_strncat_ptr: $(OBJ)/my_strncat_ptr.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strncat_ptr.o  -o my_strncat_ptr
	mv my_strncat_ptr $(BIN)

$(OBJ)/my_strncat_ptr.o: $(SRC)/my_strncat_ptr.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strncat_ptr.c
	mv my_strncat_ptr.o $(OBJ)

my_strcpy: $(OBJ)/my_strcpy.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strcpy.o  -o my_strcpy
	mv my_strcpy $(BIN)

$(OBJ)/my_strcpy.o: $(SRC)/my_strcpy.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strcpy.c
	mv my_strcpy.o $(OBJ)

my_strcpy_ptr: $(OBJ)/my_strcpy_ptr.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strcpy_ptr.o  -o my_strcpy_ptr
	mv my_strcpy_ptr $(BIN)

$(OBJ)/my_strcpy_ptr.o: $(SRC)/my_strcpy_ptr.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strcpy_ptr.c
	mv my_strcpy_ptr.o $(OBJ)

my_strncpy: $(OBJ)/my_strncpy.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strncpy.o  -o my_strncpy
	mv my_strncpy $(BIN)

$(OBJ)/my_strncpy.o: $(SRC)/my_strncpy.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strncpy.c
	mv my_strncpy.o $(OBJ)

my_strncpy_ptr: $(OBJ)/my_strncpy_ptr.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strncpy_ptr.o  -o my_strncpy_ptr
	mv my_strncpy_ptr $(BIN)

$(OBJ)/my_strncpy_ptr.o: $(SRC)/my_strncpy_ptr.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strncpy_ptr.c
	mv my_strncpy_ptr.o $(OBJ)

my_strstr: $(OBJ)/my_strstr.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/my_strstr.o  -o my_strstr
	mv my_strstr $(BIN)

$(OBJ)/my_strstr.o: $(SRC)/my_strstr.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/my_strstr.c
	mv my_strstr.o $(OBJ)

rev_individual_words: $(OBJ)/rev_individual_words.o $(INCLUDE)/cmn_hdr.h $(INCLUDE)/cmn_defs.h
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJ)/rev_individual_words.o  -o rev_individual_words
	mv rev_individual_words $(BIN)

$(OBJ)/rev_individual_words.o: $(SRC)/rev_individual_words.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/rev_individual_words.c
	mv rev_individual_words.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

#install: str
#		install -m 0755 str $(BIN)/
    
.PHONY: install
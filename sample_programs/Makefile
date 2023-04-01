CC=gcc
CFLAGS=-g -Wall
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INCLUDE=-I $(PWD)/include/

all: hello_world hello_one hello_two hello_three

hello_world: $(OBJ)/hello_world.o
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/hello_world.o -o hello_world
			mv hello_world $(BIN)

$(OBJ)/hello_world.o: $(SRC)/hello_world.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_world.c
			mv hello_world.o $(OBJ)

hello_one: $(OBJ)/hello_one_main.o $(OBJ)/hello_one_print.o
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/hello_one_main.o $(OBJ)/hello_one_print.o -o hello_one
			mv hello_one $(BIN)

$(OBJ)/hello_one_main.o: $(SRC)/hello_one_main.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_one_main.c
			mv hello_one_main.o $(OBJ)

$(OBJ)/hello_one_print.o: $(SRC)/hello_one_print.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_one_print.c
			mv hello_one_print.o $(OBJ)

hello_two: $(OBJ)/hello_two_main.o $(OBJ)/hello_two_print.o
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/hello_two_main.o $(OBJ)/hello_two_print.o -o hello_two
			mv hello_two $(BIN)

$(OBJ)/hello_two_main.o: $(SRC)/hello_two_main.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_two_main.c
			mv hello_two_main.o $(OBJ)

$(OBJ)/hello_two_print.o: $(SRC)/hello_two_print.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_two_print.c
			mv hello_two_print.o $(OBJ)

hello_three:$(OBJ)/hello_three_main.o $(OBJ)/hello_three_print.o
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/hello_three_main.o $(OBJ)/hello_three_print.o -o hello_three
			mv hello_three $(BIN)

$(OBJ)/hello_three_main.o: $(SRC)/hello_three_main.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_three_main.c
			mv hello_three_main.o $(OBJ)

$(OBJ)/hello_three_print.o: $(SRC)/hello_three_print.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/hello_three_print.c
			mv hello_three_print.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install: hello_world hello_one hello_two hello_three
		install -m 0755 hello_world $(BIN)/
		install -m 0755 hello_one $(BIN)/
		install -m 0755 hello_two $(BIN)/
		install -m 0755 hello_three $(BIN)/
    
.PHONY: install

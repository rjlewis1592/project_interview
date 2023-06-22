CC=gcc
CFLAGS=-g -Wall -lpthread
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=-I $(PWD)/include/

all: t01_alarm t01_alarm_fork t01_alarm_thread t00_lifecycle t01_lifecycle

t01_alarm: $(OBJ)/alarm.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/alarm.o -o t01_alarm
	mv t01_alarm $(BIN)

$(OBJ)/alarm.o: $(SRC)/alarm.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/alarm.c
	mv alarm.o $(OBJ)

t01_alarm_fork: $(OBJ)/alarm_fork.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/alarm_fork.o -o t01_alarm_fork
	mv t01_alarm_fork $(BIN)

$(OBJ)/alarm_fork.o: $(SRC)/alarm_fork.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/alarm_fork.c
	mv alarm_fork.o $(OBJ)

t01_alarm_thread: $(OBJ)/alarm_thread.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/alarm_thread.o -o t01_alarm_thread
	mv t01_alarm_thread $(BIN)

$(OBJ)/alarm_thread.o: $(SRC)/alarm_thread.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/alarm_thread.c
	mv alarm_thread.o $(OBJ)

t00_lifecycle: $(OBJ)/lifecycle.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/lifecycle.o -o t00_lifecycle
	mv t00_lifecycle $(BIN)

$(OBJ)/lifecycle.o: $(SRC)/lifecycle.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/lifecycle.c
	mv lifecycle.o $(OBJ)

t01_lifecycle: $(OBJ)/t01_lifecycle.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/t01_lifecycle.o -o t01_lifecycle
	mv t01_lifecycle $(BIN)

$(OBJ)/t01_lifecycle.o: $(SRC)/t01_lifecycle.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/t01_lifecycle.c
	mv t01_lifecycle.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/t01_alarm $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_alarm_fork $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_alarm_thread $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t00_lifecycle $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_lifecycle $(INSTALL_DIR)/
    
.PHONY: install

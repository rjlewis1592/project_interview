CC=gcc
CFLAGS=-g -Wall -lpthread
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=-I $(PWD)/include/

all: t01_alarm t01_alarm_fork

t01_alarm: $(OBJ)/alarm.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/alarm.o -o t01_alarm
	mv t01_alarm $(BIN)

$(OBJ)/alarm.o: $(SRC)/alarm.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/alarm.c
	mv alarm.o $(OBJ)

t01_alarm_fork: $(OBJ)/alarm.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/alarm.o -o t01_alarm_fork
	mv t01_alarm_fork $(BIN)

$(OBJ)/alarm_fork.o: $(SRC)/alarm_fork.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/alarm_fork.c
	mv alarm_fork.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/t01_alarm $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_alarm_fork $(INSTALL_DIR)/
    
.PHONY: install

CC=gcc
CFLAGS=-g -Wall -lpthread -DDEBUG
SRC=$(PWD)/src
OBJ=$(PWD)/obj
BIN=$(PWD)/bin
INSTALL_DIR=$(PWD)/install
INCLUDE=-I $(PWD)/include/

all: t01_alarm t01_alarm_fork t01_alarm_thread t00_lifecycle t01_lifecycle t00_alarm_mutex t01_alarm_mutex t00_trylock t01_trylock t00_cond_static t00_cond_dynamic

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

t00_alarm_mutex: $(OBJ)/alarm_mutex.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/alarm_mutex.o -o t00_alarm_mutex
	mv t00_alarm_mutex $(BIN)

$(OBJ)/alarm_mutex.o: $(SRC)/alarm_mutex.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/alarm_mutex.c
	mv alarm_mutex.o $(OBJ)

t01_alarm_mutex: $(OBJ)/t01_alarm_mutex.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/t01_alarm_mutex.o -o t01_alarm_mutex
	mv t01_alarm_mutex $(BIN)

$(OBJ)/t01_alarm_mutex.o: $(SRC)/t01_alarm_mutex.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/t01_alarm_mutex.c
	mv t01_alarm_mutex.o $(OBJ)

t00_trylock: $(OBJ)/trylock.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/trylock.o -o  t00_trylock
	mv t00_trylock $(BIN)

$(OBJ)/trylock.o: $(SRC)/trylock.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/trylock.c
	mv trylock.o $(OBJ)

t01_trylock: $(OBJ)/t01_trylock.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/t01_trylock.o -o t01_trylock
	mv t01_trylock $(BIN)

$(OBJ)/t01_trylock.o: $(SRC)/t01_trylock.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/t01_trylock.c
	mv t01_trylock.o $(OBJ)

t00_cond_static: $(OBJ)/cond_static.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/cond_static.o -o t00_cond_static
	mv t00_cond_static $(BIN)

$(OBJ)/cond_static.o: $(SRC)/cond_static.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/cond_static.c
	mv cond_static.o $(OBJ)

t00_cond_dynamic: $(OBJ)/cond_dynamic.o
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ)/cond_dynamic.o -o t00_cond_dynamic
	mv t00_cond_dynamic $(BIN)

$(OBJ)/cond_dynamic.o: $(SRC)/cond_dynamic.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)/cond_dynamic.c
	mv cond_dynamic.o $(OBJ)

clean:
	rm -rf $(OBJ)/*  $(BIN)/*

install:
		install -m 0755 $(BIN)/t01_alarm $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_alarm_fork $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_alarm_thread $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t00_lifecycle $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_lifecycle $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t00_alarm_mutex $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_alarm_mutex $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t00_trylock $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t01_trylock $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t00_cond_static $(INSTALL_DIR)/
		install -m 0755 $(BIN)/t00_cond_dynamic $(INSTALL_DIR)/
    
.PHONY: install

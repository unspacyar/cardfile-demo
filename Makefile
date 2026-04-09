# Makefile for Haiku Cardfile application

# Variables
CC = gcc
CFLAGS = -Wall -g

# Targets
.PHONY: all clean

all: cardfile

cardfile: cardfile.o
	$(CC) $(CFLAGS) -o cardfile cardfile.o

cardfile.o: cardfile.c
	$(CC) $(CFLAGS) -c cardfile.c

clean:
	rm -f cardfile cardfile.o
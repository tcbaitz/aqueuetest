#define compiler
CC=g++

#define flag variables
CFLAGS=-c -Wall

all: AQTest

AQTest: Aqueuemain.o
	$(CC) Aqueuemain.o -o AQTest

Aqueuemain.o: Aqueuemain.cpp
	$(CC) $(CFLAGS) Aqueuemain.cpp

clean:
	rm -rf *o AQTest
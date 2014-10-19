#===================================================
# makefile for the leetcode projects:
# Just change the source file name to make it work
#===================================================

CC=g++
CFLAGS=-c -Wall -Werror -std=c++11 -g
LDFLAGS=
SOURCES=maxProfit_2.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~


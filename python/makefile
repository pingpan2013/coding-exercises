CC=g++
CFLAGS=-c -Wall -Werror -std=c++11 -g
LDFLAGS=-std=c++11
SOURCES=preOderderTraversal.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.o

DIRS=Tree and Graph

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~


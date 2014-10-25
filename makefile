CC=g++
CFLAGS=-c -Wall -Werror -std=c++11 -g
LDFLAGS=-std=c++11
SOURCES=linkedList.cpp test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.o

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~


CC=g++
CFLAGS=-c -Wall -std=c++11 
LDFLAGS=
INLCUDES=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=./Src/Graphics_designer.cpp ./Src/Main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=/usr/bin

all: compile doit run
        
compile:$(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

doit:
	$(CC) Main.o Graphics_designer.o -o $(EXECUTABLE) $(LIBFLAGS)

run:
	./main

clean:
	rm *.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)


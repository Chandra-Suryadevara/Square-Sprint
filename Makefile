CC=g++
CFLAGS=-c -Wall -std=c++11 
LDFLAGS=
INLCUDES=-I Resources/include
LIBFLAGS=-LResources/lib -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=./Src/Graphics_designer.cpp ./Src/Main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $(INLCUDES) $< -o $@ $(LIBFLAGS)

clean:
	rm *.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)
CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
INLCUDES=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SOURCES=./Src/Graphics_designer.cpp ./Src/Main.cpp ./Src/Square_Main.cpp ./Src/Spikes.cpp ./Src/Audio_game.cpp ./Src/SpikesManager.cpp ./Src/Menu.cpp ./Src/Text_handler.cpp ./Src/HighScoreManager.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Square_Sprint
BINDIR=/usr/bin

all: dependencies compile doit run

dependencies:
	@echo "Installing dependencies..."
	@sudo apt-get install g++
	@sudo apt install -y libsfml-dev
	@sudo apt-get install build-essential

compile:$(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

doit:
	$(CC) Main.o Graphics_designer.o HighScoreManager.o Square_Main.o Spikes.o Audio_game.o Menu.o Text_handler.o SpikesManager.o -o $(EXECUTABLE) $(LIBFLAGS)

run:
	./Square_Sprint

clean:
	rm *.o

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)

uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)

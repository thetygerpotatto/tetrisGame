CC = g++
CFLAGS = -Wall -g -mwindows  
LIBS = -lraylib

all: tetris clean

tetris: src/piece.o src/playfield.o  
	$(CC) $(CFLAGS) src/piece.o src/playfield.o src/square.o src/rotations.o src/main.cpp -o bin/tetris $(LIBS)

src/playfield.o: src/square.o src/piece.o src/playfield.cpp 
	$(CC) $(CFLAGS) -c src/playfield.cpp -o src/playfield.o 

src/piece.o: src/square.o src/rotations.o src/piece.cpp 
	$(CC) $(CFLAGS) -c src/piece.cpp -o src/piece.o

src/rotations.o: src/rotations.cpp
	$(CC) $(CFLAGS) -c src/rotations.cpp -o src/rotations.o

src/square.o: src/square.cpp
	$(CC) $(CFLAGS) -c src/square.cpp -o src/square.o

clean:
	del .\src\square.o
	del .\src\piece.o
	del .\src\playfield.o
	del .\src\rotations.o
	bin/tetris

test:
	$(CC) src/test.cpp -o test
	test

COMPILER = g++ --std=c++11

all: main

main: main.o game.o
	$(COMPILER) main.o game.o -o tictactoe.out

main.o:
	$(COMPILER) -c main.cpp

game.o:
	$(COMPILER) -c game.cpp

clear:
	rm -rf *.o *.out

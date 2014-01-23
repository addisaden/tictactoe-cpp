COMPILER = g++ --std=c++11

all: main

main: main.o game.o
	$(COMPILER) main.o game.o -o tictactoe.out

main.o:
	$(COMPILER) -c main.cpp

game.o:
	$(COMPILER) -c game.cpp

test: game_test

game_test: game.o
	$(COMPILER) game.o game_test.cpp -o game_test.out
	./game_test.out

clear:
	rm -rf *.o *.out

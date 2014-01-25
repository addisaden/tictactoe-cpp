COMPILER = g++ --std=c++11

all: main

main: main.o game.o player_human.o
	$(COMPILER) main.o game.o player_human.o -o tictactoe.out

main.o:
	$(COMPILER) -c main.cpp

game.o:
	$(COMPILER) -c game.cpp

player_human.o:
	$(COMPILER) -c player_human.cpp

test: game_test

game_test: game.o
	$(COMPILER) game.o game_test.cpp -o game_test.out
	./game_test.out

clear:
	rm -rf *.o *.out

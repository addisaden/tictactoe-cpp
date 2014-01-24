#include <iostream>
#include <cassert>
#include "game.hpp"

// __Winner-Test__

void test_winner_nobody() {
  TicTacToe::Game game;
  assert(game.winner() == 0);
  std::cout << "An empty field has no winner." << std::endl;
}

void test_winner_x() {
  TicTacToe::Game game;
  game.go(0);
  game.go(3);
  game.go(1);
  game.go(4);
  game.go(2);
  assert(game.winner() == 1);
  std::cout << "X can win." << std::endl;
}

void test_winner_o() {
  TicTacToe::Game game;
  game.go(8);
  game.go(0);
  game.go(3);
  game.go(1);
  game.go(4);
  game.go(2);
  assert(game.winner() == 2);
  std::cout << "O can win." << std::endl;
}

void test_winner_no_possible_move() {
  TicTacToe::Game game;
  /*
   * 0|1|2 x|o|x
   * 3|4|5 o|o|x
   * 6|7|8 x|x|o
   *
   */
  game.go(0); // x
  game.go(1); // o
  game.go(2); // x
  game.go(3); // o
  game.go(5); // x
  game.go(4); // o
  game.go(6); // x
  game.go(8); // o
  game.go(7); // x
  assert(game.winner() == -1);
  std::cout << "Nobody can win." << std::endl;
}

// __Possible-Move-Test__

void test_possible_move() {
  TicTacToe::Game game;
  assert(game.go(0));
  std::cout << "Move on an empty field." << std::endl;
}

void test_impossible_move() {
  TicTacToe::Game game;
  game.go(0);
  assert(game.go(0) == false);
  std::cout << "Can't move on an filled field." << std::endl;
}

void test_out_of_range_move() {
  TicTacToe::Game game;
  assert(game.go(100) == false);
  std::cout << "Can't move out of place." << std::endl;
}

int main() {
  std::cout << "__Winner-Test__" << std::endl;
  test_winner_nobody();
  test_winner_x();
  test_winner_o();
  test_winner_no_possible_move();

  std::cout << std::endl << "__Possible-Move-Test__" << std::endl;
  test_possible_move();
  test_impossible_move();
  test_out_of_range_move();

  return 0;
}

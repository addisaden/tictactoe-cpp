#include <iostream>
#include <cassert>
#include "game.hpp"

void test_winner_nobody() {
  TicTacToe::Game game;
  assert(game.winner() == 0);
  std::cout << "An empty field has no winner." << std::endl;
}

void test_winner_x() {
  std::cout << "X can win (not implemented yet)" << std::endl;
}

void test_winner_o() {
  std::cout << "O can win (not implemented yet)" << std::endl;
}

void test_winner_no_possible_move() {
  std::cout << "Nobody wins when all field are filled and there is no winner. (not implemented yet)" << std::endl;
}

int main() {
  std::cout << "__Winner-Test__" << std::endl;
  test_winner_nobody();
  test_winner_x();
  test_winner_o();
  test_winner_no_possible_move();
  return 0;
}

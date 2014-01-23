#include <iostream>
#include <cassert>
#include "game.hpp"

void zero_winner() {
  TicTacToe::Game game;
  assert(game.winner() == 0);
  std::cout << "An empty field has no winner." << std::endl;
}

int main() {
  zero_winner();
  return 0;
}

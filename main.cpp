#include <iostream>
#include "game.hpp"

using namespace std;

int main() {
  TicTacToe::Game game;

  game.go(0);
  game.go(1);
  game.go(4);

  cout << game.to_string() << endl;

  return 0;
}

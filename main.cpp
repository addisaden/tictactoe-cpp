#include <iostream>
#include "game.hpp"

using namespace std;

int main() {
  TicTacToe::Game game;

  game.go(0);
  game.go(3);
  game.go(4);
  game.go(5);
  game.go(8);

  cout << game.to_string() << endl;
  cout << "Winner: " << game.winner() << endl;

  return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include "game.hpp"
#include "player_human.hpp"

using namespace std;

void make_space () {
  for(int i = 0; i < 50; i++) cout << endl;
}

int main() {
  TicTacToe::Game game;
  TicTacToe::Player_Human p1 {"Adrian", 'X', 1}, p2 {"Georg", 'O', 2};

  int eingabe;
  string seingabe;

  while(game.winner() == 0) {

    int feld[9];
    for(int i = 0; i < 9; i++)
      feld[i] = game.get(i);
    
    switch(game.current()) {
      case 1:
        game.go(p1.go(game.to_string(), feld));
        break;
      case 2:
        game.go(p2.go(game.to_string(), feld));
        break;
      default:
        cout << "ERROR: game.winner() == " << game.winner() << endl;
    }
  }

  make_space();

  cout << game.to_string() << endl << endl;

  switch(game.winner()) {
    case 1:
      cout << "X hat gewonnen.";
      break;
    case 2:
      cout << "O hat gewonnen.";
      break;
    case (-1):
      cout << "Es ist unentschieden.";
      break;
    default:
      cout << "ERROR: game.winner() == " << game.winner();
  }
  cout << endl;

  return 0;
}

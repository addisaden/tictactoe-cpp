#include <iostream>
#include "game.hpp"

using namespace std;

void make_space () {
  for(int i = 0; i < 50; i++) cout << endl;
}

int main() {
  TicTacToe::Game game;

  int eingabe;

  while(game.winner() == 0) {
    make_space();

    cout << "TIC TAC TOE" << endl << endl;

    cout << " 1 | 2 | 3" << endl;
    cout << " 4 | 5 | 6" << endl;
    cout << " 7 | 8 | 9" << endl;
    cout << endl << "-1: exit" << endl << endl << endl;

    cout << game.to_string() << endl;
    
    switch(game.current()) {
      case 1:
        cout << "X: ";
        break;
      case 2:
        cout << "O: ";
        break;
      default:
        cout << "ERROR: game.winner() == " << game.winner() << endl;
    }

    while(true) {
      cin >> eingabe;

      if(eingabe == -1) return 0;

      if(not game.go(eingabe - 1)) {
        cout << "Eingabe falsch. Bitte ein unbelegtes Spielfeld zwischen 1 und 9 wählen." << endl;
        cout << ">> ";
      } else {
        break;
      }
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

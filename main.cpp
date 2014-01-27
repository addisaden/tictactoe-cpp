#include <iostream>
#include <string>
#include <sstream>
#include "game.hpp"
#include "player_human.hpp"
#include "player_computer.hpp"

using namespace std;

void make_space () {
  for(int i = 0; i < 50; i++) cout << endl;
}

int main() {
  string p1_name, p2_name;

  cout << "  T I C   T A C   T O E" << endl << endl << endl;

  cout << "Name: ";
  getline(cin, p1_name);

  p2_name = "Computer";


  TicTacToe::Game game;
  TicTacToe::Player_Human p1 {p1_name, 'X', 1};
  TicTacToe::Player_Computer p2 {p2_name, 'O', 2};

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
      cout << p1_name << " hat mit 'X' gewonnen.";
      break;
    case 2:
      cout << p2_name << " hat mit 'O' gewonnen.";
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

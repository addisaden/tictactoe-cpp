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
  string p1_name, p2_name, seingabe;
  int eingabe;
  char p1_sign, p2_sign, p1_id, p2_id;

  cout << "  T I C   T A C   T O E" << endl << endl << endl;

  cout << "Name: ";
  getline(cin, p1_name);

  p2_name = "Computer";


  TicTacToe::Game game;

  eingabe = 0;

  while(eingabe != 1 && eingabe != 2) {
    cout << endl << "1. X spielen" << endl << "2. O spielen" << endl;
    cout << ">> ";
    getline(cin, seingabe);
    stringstream(seingabe) >> eingabe;
  }

  if(eingabe == 1) {
    p1_sign = 'X';
    p1_id = 1;
    p2_sign = 'O';
    p2_id = 2;
  } else {
    p2_sign = 'X';
    p2_id = 1;
    p1_sign = 'O';
    p1_id = 2;
  }
  TicTacToe::Player_Human p1 {p1_name, p1_sign, p1_id};
  TicTacToe::Player_Computer p2 {p2_name, p2_sign, p2_id};

  while(game.winner() == 0) {

    int feld[9];
    for(int i = 0; i < 9; i++)
      feld[i] = game.get(i);

    int current = game.current();
    
    if(current == p1_id)
      game.go(p1.go(game.to_string(), feld));
    else if (current == p2_id)
      game.go(p2.go(game.to_string(), feld));
    else
      cout << "ERROR: game.winner() == " << game.winner() << endl;
  }

  make_space();

  cout << game.to_string() << endl << endl;

  switch(game.winner()) {
    case 1:
      cout << p1_name << " hat mit '" << p1_sign << "' gewonnen.";
      break;
    case 2:
      cout << p2_name << " hat mit '" << p2_sign << "' gewonnen.";
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

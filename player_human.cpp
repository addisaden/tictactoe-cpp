#include <iostream>
#include <sstream>
#include "player_human.hpp"

void clear_above () {
  for(int i = 0; i < 42; i++)
    std::cout << std::endl;
}

int TicTacToe::Player_Human::go(std::string game_representation, int feld[]) {
  int wahl;
  std::string swahl;

  clear_above ();

  std::cout << " 1 | 2 | 3" << std::endl << " 4 | 5 | 6" << std::endl << " 7 | 8 | 9" << std::endl << std::endl;

  std::cout << game_representation << std::endl << std::endl;
  
  while(true) {
    std::cout << name << " (" << sign << "): ";

    std::getline(std::cin, swahl);
    std::stringstream(swahl) >> wahl;
    wahl--;

    if(wahl < 0 || wahl > 8)
      std::cout << std::endl << "Feld existiert nicht. ";
    else if(feld[wahl] != 0)
      std::cout << std::endl << "Feld ist belegt. ";
    else
      break;

    std::cout << "Bitte Eingabe wiederholen." << std::endl;
  }
  return wahl;
}

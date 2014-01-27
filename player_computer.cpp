#include "player_computer.hpp"
#include <iostream>

int TicTacToe::Player_Computer::go(std::string game_repr, int field[9]) {
  std::cout << "0" << std::endl;
  // set chooser to zero
  for(int i = 0; i < 9; i++)
    chooser[i] = 0;

  for(int i = 0; i < 8; i++) {
    int wina = winner_positions[i][0];
    int winb = winner_positions[i][1];
    int winc = winner_positions[i][2];

    /*
     * X = OWN
     * O = OTHER
     * + = EMPTY
     * + + + =    1    1    1
     * x + + = -100    3    3
     * x x + = -100 -100  100
     * x o + = -100 -100   -1
     * o o + = -100 -100   50
     * o + + = -100    2    2
     *
     */
    
    if( (field[wina] != 0 && field[wina] != player_id) ||
        (field[winb] != 0 && field[winb] != player_id) ||
        (field[winc] != 0 && field[winc] != player_id)) {
      chooser[wina] = chooser[wina] - 1;
      chooser[winb] = chooser[winb] - 1;
      chooser[winc] = chooser[winc] - 1;
    } else if (field[wina] == player_id ||
               field[winb] == player_id ||
               field[winc] == player_id) {
      chooser[wina] += 3;
      chooser[winb] += 3;
      chooser[winc] += 3;
    } else {
      chooser[wina] += 2;
      chooser[winb] += 2;
      chooser[winc] += 2;
    }
  }

  int choosed = -1;
  int choosed_value = -100;

  for(int i = 0; i < 9; i++) {
    if(field[i] != 0) {
      continue;
    } else if(choosed == -1) {
      choosed = i;
      choosed_value = chooser[i];
    }

    if(chooser[i] >= choosed_value) {
      choosed_value = chooser[i];
      choosed = i;
    }
  }

  return choosed;
}

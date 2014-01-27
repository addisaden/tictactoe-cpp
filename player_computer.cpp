#include "player_computer.hpp"
#include <iostream>

int TicTacToe::Player_Computer::go(std::string game_repr, int field[9]) {
  // set chooser to zero
  for(int i = 0; i < 9; i++)
    chooser[i] = 0;

  for(int ii = 0; ii < 8; ii++) {
    int wina = winner_positions[ii][0];
    int winb = winner_positions[ii][1];
    int winc = winner_positions[ii][2];

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
    int other = 0,
        self = 0,
        nothing = 0,
        current[3] = { wina, winb, winc };

    for(int i = 0; i < 3; i++) {
      int val = field[current[i]];
      if(val == 0) {
        nothing++;
      } else if(val == player_id) {
        self++;
      } else if(val != player_id && val != 0) {
        other++;
      }
    }

    // + + + =    1    1    1
    if(nothing >= 3) {
      chooser[wina]++;
      chooser[winb]++;
      chooser[winc]++;
    }
    // x + + = -100    3    3
    else if(nothing > 1 && self >= 1) {
      for(int i = 0; i < 3; i++) {
        if(field[current[i]] == 0)
          chooser[current[i]] += 3;
        else
          chooser[current[i]] -= 100;
      }
    }
    // x x + = -100 -100  100
    else if(nothing == 1 && self == 2) {
      for(int i = 0; i < 3; i++) {
        if(field[current[i]] == 0)
          chooser[current[i]] += 100;
        else
          chooser[current[i]] -= 100;
      }
    }
    // x o + = -100 -100   -1
    else if(other >= 1 && self >= 1) {
      for(int i = 0; i < 3; i++) {
        if(field[current[i]] == 0)
          chooser[current[i]] -= 1;
        else
          chooser[current[i]] -= 100;
      }
    }
    // o o + = -100 -100   50
    else if(nothing == 1 && other == 2) {
      for(int i = 0; i < 3; i++) {
        if(field[current[i]] == 0)
          chooser[current[i]] += 50;
        else
          chooser[current[i]] -= 100;
      }
    }
    // o + + = -100    2    2
    else if(nothing >= 2 && other >= 1) {
      for(int i = 0; i < 3; i++) {
        if(field[current[i]] == 0)
          chooser[current[i]] += 2;
        else
          chooser[current[i]] -= 100;
      }
    }
  }

  int choosed = -1;
  int choosed_value = 0;

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

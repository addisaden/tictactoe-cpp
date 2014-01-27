#include <string>

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "player.hpp"
#endif

namespace TicTacToe {
  class Player_Computer: public Player {
    private:
      int winner_positions[8][3];
      int chooser[9];

    public:
      Player_Computer(std::string name, char sign, int id) :
        Player(name, sign, id) {
          int winners[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
          };
          for(int j = 0; j < 8; j++)
            for(int i = 0; i < 3; i++)
              winner_positions[j][i] = winners[j][i];
        }

      int go(std::string, int[]);
  };
}

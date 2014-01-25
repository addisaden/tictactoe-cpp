#include <string>
#include "player.hpp"

namespace TicTacToe {
  class Player_Human: public Player {
    public:
      Player_Human(std::string name, char sign, int id) : Player(name, sign, id) {
        // here there could be more initialization
      }

      int go(std::string, int[]);
  };
}

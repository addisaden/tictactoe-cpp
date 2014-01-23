#include <sstream>
#include <string>

namespace TicTacToe {
  class Game {
    private:
      int field[9];
      int move;

    public:
      Game (void);
      std::string to_string ();
      bool go (int);
  };
}

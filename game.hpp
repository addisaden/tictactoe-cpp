#include <sstream>
#include <string>

namespace TicTacToe {
  class Game {
    private:
      int field[9];
      int move;

    public:
      // Create a new game
      Game ();

      // Give a String of the field
      std::string to_string ();

      // possible field = 0 - 8
      // true = move successed
      // false = cant move on chosen field
      bool go (int);

      //  0 = Nobody wins
      //  1 = X wins
      //  2 = O wins
      // -1 = Nobody can win
      int winner ();

      //  0 = No move
      //  1 = X turn
      //  2 = O turn
      int current ();
  };
}

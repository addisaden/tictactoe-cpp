#include <string>

namespace TicTacToe {
  class Player {
    protected:
      std::string name;
      char sign;
      int player_id;

    public:
      Player(std::string name_parameter, char sign_parameter, int player_id_parameter) {
        name = name_parameter;
        sign = sign_parameter;
        player_id = player_id_parameter;
      }

      virtual int go(std::string game_representation, int[]) =0;
  };
}

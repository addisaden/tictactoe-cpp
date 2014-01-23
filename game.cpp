#include "game.hpp"

TicTacToe::Game::Game () {
  for(int i = 0; i < 9; i++)
    field[i] = 0;
  move = 0;
}

char h_v2char (int value) {
  switch (value) {
    case 0:
      return ' ';
    case 1:
      return 'X';
    case 2:
      return 'O';
  }
}

std::string TicTacToe::Game::to_string () {
  std::stringstream result;

  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < 3; i++) {
      result << " " << h_v2char(field[j * 3 + i]) << " ";
      if (i < 2) {
        result << "|";
      } else {
        result << std::endl;
      }
    }
    if (j < 2)
      result << "---+---+---" << std::endl;
  }

  return result.str();
}

bool TicTacToe::Game::go (int id) {
  if (id < 9 && id >= 0) {
    if (field[id] == 0) {
      field[id] = move % 2 + 1;
      move++;
      return true;
    }
  }

  return false;
}

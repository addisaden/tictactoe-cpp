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
  if(winner() != 0)
    return false;

  if (id < 9 && id >= 0) {
    if (field[id] == 0) {
      field[id] = move % 2 + 1;
      move++;
      return true;
    }
  }

  return false;
}

int TicTacToe::Game::winner () {
  const int WINNERS[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
  };

  // is winner?
  for(int winners_id = 0; winners_id < 8; winners_id++) {
    int a = field[ WINNERS[winners_id][0] ];
    int b = field[ WINNERS[winners_id][1] ];
    int c = field[ WINNERS[winners_id][2] ];

    if ((a != 0) && (a == b) && (a == c)) {
      return a;
    }
  }

  // is no possible field
  for(int i = 0; i < 9; i++) {
    if(field[i] == 0)
      return 0;
    else
      continue;
  }

  return (-1);
}

int TicTacToe::Game::current () {
  if(winner() != 0) {
    return 0;
  }
  return ((move % 2) + 1);
}

int TicTacToe::Game::get(int i) {
  if(i < 0 || i > 8) {
    return -1;
  }
  return field[i];
}


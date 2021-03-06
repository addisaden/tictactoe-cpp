#include <iostream>
#include <cassert>
#include "game.hpp"

// __Winner-Test__

void test_winner_nobody() {
  TicTacToe::Game game;
  assert(game.winner() == 0);
  std::cout << "An empty field has no winner." << std::endl;
}

void test_winner_x() {
  TicTacToe::Game game;
  game.go(0);
  game.go(3);
  game.go(1);
  game.go(4);
  game.go(2);
  assert(game.winner() == 1);
  std::cout << "X can win." << std::endl;
}

void test_winner_o() {
  TicTacToe::Game game;
  game.go(8);
  game.go(0);
  game.go(3);
  game.go(1);
  game.go(4);
  game.go(2);
  assert(game.winner() == 2);
  std::cout << "O can win." << std::endl;
}

void test_winner_no_possible_move() {
  TicTacToe::Game game;
  /*
   * 0|1|2 x|o|x
   * 3|4|5 o|o|x
   * 6|7|8 x|x|o
   *
   */
  game.go(0); // x
  game.go(1); // o
  game.go(2); // x
  game.go(3); // o
  game.go(5); // x
  game.go(4); // o
  game.go(6); // x
  game.go(8); // o
  game.go(7); // x
  assert(game.winner() == -1);
  std::cout << "Nobody can win." << std::endl;
}

// __Possible-Move-Test__

void test_possible_move() {
  TicTacToe::Game game;
  assert(game.go(0));
  std::cout << "Move on an empty field." << std::endl;
}

void test_impossible_move() {
  TicTacToe::Game game;
  game.go(0);
  assert(game.go(0) == false);
  std::cout << "Can't move on an filled field." << std::endl;
}

void test_out_of_range_move() {
  TicTacToe::Game game;
  assert(game.go(100) == false);
  std::cout << "Can't move out of place." << std::endl;
}

// __Current-Move-Test__

void test_current_move() {
  TicTacToe::Game game, game2;
  assert(game.current() == 1);
  game.go(0);
  assert(game.current() == 2);
  game.go(1);
  assert(game.current() == 1);
  std::cout << "Can get current move." << std::endl;;

  // On win, no possible move
  game.go(3);
  game.go(4);
  game.go(6);
  assert(game.go(8) == false);
  assert(game.current() == 0);
  assert(game.winner() == 1);
  std::cout << "No current move with a winner." << std::endl;

  // Can't get current, when there is no possible move
  game2.go(0); // x
  game2.go(1); // o
  game2.go(2); // x
  game2.go(3); // o
  game2.go(5); // x
  game2.go(4); // o
  game2.go(6); // x
  game2.go(8); // o
  game2.go(7); // x
  assert(game2.go(8) == false);
  assert(game2.current() == 0);
  assert(game2.winner() == (-1));
  std::cout << "No current move without a blank field." << std::endl;
}

// __Get-Field-Test__

void test_get_field() {
  TicTacToe::Game game;
  assert(game.get(0) == 0);
  std::cout << "Can get Empty-Field." << std::endl;
  game.go(0);
  assert(game.get(0) == 1);
  std::cout << "Can get X-Field." << std::endl;
  game.go(1);
  assert(game.get(1) == 2);
  std::cout << "Can get O-Field." << std::endl;
  assert(game.get(100) == (-1));
  std::cout << "Can't get non-existing-field." << std::endl;
}

int main() {
  std::cout << "__G_A_M_E__T_E_S_T__" << std::endl << std::endl;
  std::cout << "__Winner-Test__" << std::endl;
  test_winner_nobody();
  test_winner_x();
  test_winner_o();
  test_winner_no_possible_move();

  std::cout << std::endl << "__Possible-Move-Test__" << std::endl;
  test_possible_move();
  test_impossible_move();
  test_out_of_range_move();

  std::cout << std::endl << "__Current-Move-Test__" << std::endl;
  test_current_move();

  std::cout << std::endl << "__Get-Field-Test__" << std::endl;
  test_get_field();

  return 0;
}

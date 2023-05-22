#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Piece.h"
using namespace std;

class Board {
private:
  Piece board[8][8];
  bool makeMove(string move, int halfMoves);
  bool doMove(string move);
  int halfMoves = 0;

public:
  Board() {}
  void resetBoard();
  int letterToNum(char letter);
  void printBoard();
  void play();
  Piece pieceAt(string space);
};

#endif
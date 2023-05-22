#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include "Board.h"
using namespace std;

class Piece {
public:
  static const int WHITE = 0, BLACK = 1;
  Board board;
  int color = -1 ; // 0=White, 1=Black
  string symbols[2];
  
  Piece() {}
  Piece(int theColor, int* theBoard) {
    color = theColor;
    board = theBoard;
  }

  bool isValidMove(string move) {
    cout << "No piece found";
    return false;
  };

  string toString() {return symbols[color];}

  int getDelta(string move) {
    int startX = board.letterToNum(move[0]);
    int startY = board.letterToNum(move[1]);
    int endX = board.letterToNum(move[0]);
    int endY = board.letterToNum(move[1]);

    int arr[] = {endX - startX, endY - startY};
    return arr*;
  }
};

#endif
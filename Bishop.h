#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Board.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Bishop : public Piece {
using Piece::Piece;
public:
  Bishop() {
    symbols[0] = "\u2657";
    symbols[1] = "\u265D";
  }

bool isValidMove(string move) {
    int[2] delta = board.getDelta(move);

    //Check for friendly fire
    if(board.pieceAt(move.substr(2) == color) {
      cout << "End square is occupied by a friendly piece"
      return false;
    }

    //Check if it is an attack  
    //Check if it is a valid move
    
    return true;
  }

  
};

#endif
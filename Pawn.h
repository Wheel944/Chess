#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Board.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Pawn : public Piece {
using Piece::Piece;
public:
  Pawn() {
    symbols[0] = "\u2659";
    symbols[1] = "\u265F";
  }
  bool hasMoved = false;
  bool isValidMove(string move) {
    int delta[2] = board.getDelta(move);

    //Check for friendly fire
    if(board.pieceAt(move.substr(2)).color == color) {
      cout << "End square is occupied by a friendly piece";
      return false;
    }

    //Check if it is an attack
    if(abs(delta[0]) != 1 && //Is moving 1 horizontaly
      !((color == WHITE && delta[1] == 1) || //Is white and moving up
       delta[1] == -1)) {//Is black and moving down
      hasMoved = true;
      return true;
    }

    if(delta[0] == 0) {
      //Check if the pawn is moving by 2 on its first move
      if(!(color == WHITE && delta[1] == 2)
         || delta[1] != -2 && hasMoved) {
        cout << "Invalid destination";
        return false;
      }
      
      //Check if it is a valid forward move
      if((color == WHITE && delta[1] == 1) ||
         delta[1] == -1) {
        cout << "Invalid destination";
        return false;
      }
    }
    
    return true;
  }

  
};

#endif
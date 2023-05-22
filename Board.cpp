#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include <string>
#include <iostream>
using namespace std;

void Board :: resetBoard() {
  board[0][0] = new Rook(0, board);
  board[0][1] = new Knight(0, board);
  board[0][2] = new Bishop(0, board);
  board[0][4] = new King(0, board);
  board[0][3] = new Queen(0, board);
  board[0][5] = new Bishop(0, board);
  board[0][6] = new Knight(0, board);
  board[0][7] = new Rook(0, board);
  for(int i = 0; i < board[0].length; i++) {
    board[1][i] = new Pawn(0, board);
    board[6][i] = new Pawn(1, board);
  }
  board[7][0] = new Rook(1, board);
  board[7][1] = new Knight(1, board);
  board[7][2] = new Bishop(1, board);
  board[7][4] = new King(1, board);
  board[7][3] = new Queen(1, board);
  board[7][5] = new Bishop(1, board);
  board[7][6] = new Knight(1, board);
  board[7][7] = new Rook(1, board);
}

void Board :: play() {
  resetBoard();
  
  while(true) {
    printBoard();
    
    //Will loop until the user inputs a valid move
    do {
      if(halfMoves % 2 == 0)
        cout << "White to move: ";
      else
        cout << "Black to move: ";
      String move;
      cin >> move;
    } while(!makeMove(move, halfMoves))
      
    halfMoves++;
    
    
    break;
  }
}

bool Board :: makeMove(String move, int halfMoves) {
  int row = stoi(move[1]);
  int col = letterToNum(move[0]);
  Piece selected = board[row - 1][col];
  
  if(selected.color != halfMoves % 2) {
    cout << "Invalid color";
    return false;
  }
  
  return selected.isValidMove(move);
}

bool Board :: doMove(string move) {
  return true;
}

void Board :: printBoard() {
  int row = 0, col = 0;
  for(int row = 0; row < 8; row++) {
    for(int col = 0; col < 8; col++) {
      cout << board[row][col].toString();
    }
    cout << "\n";
  }

  
}

int Board :: letterToNum(char letter) {
  switch(letter) {
    case 'a':
      return 0;
    case 'b':
      return 1;
    case 'c':
      return 2;
    case 'd':
      return 3;
    case 'e':
      return 4;
    case 'f':
      return 5;
    case 'g':
      return 6;
    case 'h':
      return 7;
    default:
      return -1;
  }
}
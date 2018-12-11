//
//  position.cpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//
#include <iostream>
#include "position.hpp"

position::position ()  {
        reset();
}

void position::reset(){
    //set board to starting position
    setboard();
    EXS_Board = 0;
    OHS_Board = 0;
    ply = 0;
    sideToPlay = EX;
    score = zeroo;
    gameWon = false;
    nodes = 0;
    printBoard();
}

void position::setboard(){
    //in future, take in argument, like fen
    for (int i = 0; i<numOfSq; i++){
        if(i != 3 && i!= 7) board[i] = empty;
        else board[i] = notBoard;
    }
}

piece position::get_sideToPlay(){
    return sideToPlay;
}
bool position::get_gameWon(){
    return gameWon;
}

bitboard position::get_EXS_Board(){
    return EXS_Board;
}

bitboard position::get_OHS_Board(){
    return OHS_Board;
}

int position::get_ply(){
    return ply;
}

int position::get_nodes(){
    return nodes;
}

void position:: inc_nodes(){
    nodes++;
}

void position::clear_nodes(){
    nodes=0;
}
void position::do_move(move m)
{
    if (!sqIsOccupied(EXS_Board, OHS_Board, m)){
        ply++;
        //either move m will be the actual bit index (0..A) or the 3x3 matrix the user puts in
        //right now its the index
        place_piece(m);
       // printBoard();
        sideToPlay == EX ? gameWon = isGameWon(EXS_Board) : gameWon = isGameWon(OHS_Board);
        
        sideToPlay == EX ? sideToPlay = OH : sideToPlay = EX;
    
    }
    else {
        std::cout << "NOT A LEGAL MOVE, SQUARE IS OCCUPIED, TRY AGAIN... \n\n";
    }
}

void position::do_move_user(move m)
{
    if(m != none){
    if (!sqIsOccupied(EXS_Board, OHS_Board, m)){
        ply++;
        //either move m will be the actual bit index (0..A) or the 3x3 matrix the user puts in
        //right now its the index
        place_piece(m);
        printBoard();
        sideToPlay == EX ? gameWon = isGameWon(EXS_Board) : gameWon = isGameWon(OHS_Board);
        
        sideToPlay == EX ? sideToPlay = OH : sideToPlay = EX;
        
        }
    else {
        std::cout << "NOT A LEGAL MOVE, SQUARE IS OCCUPIED, TRY AGAIN... \n\n";
    }
    }
    else {
        std::cout << "NOT A LEGAL MOVE, SQUARE IS OCCUPIED, TRY AGAIN... \n\n";
    }
}

void position::undo_move(move m)
{
    //
    //there is not a check to see if removing the piece is legal yet
    //
    
    ply--;
    remove_piece(m);
    sideToPlay == EX ? sideToPlay = OH : sideToPlay = EX;
  
    //debug:
   // gameWon = false;
    /////////
    
    
    //printBoard();
}

void position::place_piece(move m){
    piece player = sideToPlay;
    player == EX ? EXS_Board |= squareBitMask[m] : OHS_Board |= squareBitMask[m];
    //debug
   // player == EX ? printBitboard(EXS_Board) : printBitboard(OHS_Board);
    player == EX ? board[m] = EX : board[m] = OH ;
}

void position::remove_piece(move m){
    //
    //there is not a check to see if removing the piece is legal yet
    //
    piece player = sideToPlay;
    player == OH ? EXS_Board ^= squareBitMask[m] : OHS_Board ^= squareBitMask[m];
    board[m] = empty;
}
bool position::legal_move(move m) {

    return sqIsOccupied(EXS_Board, OHS_Board, m);
    
}
void position::printBoard(){
  /*  for (int i = numOfSq-1; i>=0; i--){
        if(i != 3 && i!= 7) {
            if(board[i] == EX)  std::cout << "X ";
            else if(board[i] == OH) std::cout << "O ";
            else std::cout << "_ ";
        }
        else std::cout << "\n";
    }
    
    std::cout << "\n\n";*/
    uint16_t sq = 0;
    uint16_t rk = 0;
    std::cout << "////////////////////// \n";
    for( int16_t i= 2; i >= 0; i--)
    {
        rk = i << 2;
        
        for( int16_t j= 0; j <3; j++)
        {
            sq = rk + j;
            if(board[sq] == EX)  std::cout << "X ";
            else if(board[sq] == OH) std::cout << "O ";
            else std::cout << "_ ";
        }
        std::cout <<"\n";
    }
    std::cout << "////////////////////// \n\n";
}

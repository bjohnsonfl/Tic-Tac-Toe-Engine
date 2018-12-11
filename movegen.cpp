//
//  movegen.cpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/5/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#include <iostream>

#include "movegen.hpp"


move moveList[8];
move* generateAllMoves (position& pos, move * moveList){
    
    //position.legal_move in conjunction with isSqOccupied in bitboard.cpp are good...
    //for validating user input. Despite the fact the code will be very similar for this function...
    //there does not need to be two function calls per for loop as well as calculating the same ...
    //variable twice, so just write it out. plus this func will be totally different for chess later
    
    
    //important, as more plys are played, the number of possible moves goes down, but the array size stays the same so larger indexed moves will not be over written, so its important to keep track of depth and how many plys are left.
    
   // move*list = moveList;
    bitboard occupied  = pos.get_EXS_Board() | pos.get_OHS_Board();
    occupied = ~occupied;  //all the not occupied, possible legal moves
    occupied = occupied &  board; // to account for the bits not representing the board but appear in the for loop
    for (square sq = a1; sq < numOfSq; sq++)
    {
        if(((squareBitMask[sq] & occupied) == squareBitMask[sq] )&& squareBitMask[sq])
        {
            *moveList++ = move(sq);
        }
    }
    
    
    return moveList;
}

move coordToMove (char coord [], bool extended)
{
    move m;
    
    //int16_t file = 0;
    //int16_t rank = 0;
    int i, j;
    if(extended)
    {
        i = 2;
        j = 3;
    }
    else{
        i = 0;
        j = 1;
    }
    if(coord[i] > 'c' || coord[i] < 'a') {
        std:: cout <<"1 Invalid entry, type H for help and commands or try again \n";
     return none;
    }
    if(coord[j] > '3' || coord[j] < '1') {
        std::cout <<"2 Invalid entry, type H for help and commands or try again \n";
        return none;
    }
    file f = file(coord[i] - 'a' );
    rank rk = rank(coord[j] - '1');
    
    square sq = square((rk << 2) + f);   //stockfish make_square(rank, file)
    m = move(sq);                       //stockfish ish make_move(sq_from, sq_to)
   // std::cout <<  " file: " << f << " rank: " << rk << std::endl;
   // std::cout << "move: " << m << "\n";
    
    
    return m;
}

//only need to check the player's pieces who just moved
bool isGameWon (bitboard pieces)
{
    //printBitboard(pieces);
    for(int i=0; i<8 ; i++)
    {
        if((winMask[i] & pieces) == winMask[i]) return true;
    }
    return false;
}

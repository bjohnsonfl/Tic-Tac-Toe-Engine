//
//  bitboard.cpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//
#include <iostream>
#include "bitboard.hpp"

bitboard squareBitMask[numOfSq];
bitboard fileBitMask [numOfFile];
bitboard rankBitMask [numOfRank];
bitboard winMask[8];




void bitboards::init(){
    u_int16_t one = 1;
   
    for (int i = 0; i<numOfSq; i++){
        if(i != 3 && i!= 7) squareBitMask[i] = (one << i);
    }
    
    for( int i = 0; i < numOfFile; i++)
    {
        fileBitMask[i] = fileA << i;
    }
    
    for( int i = 0; i < numOfRank; i++)
    {
        rankBitMask[i] = rank1 << (4*i);
    }
    
    //inititiate win mask
    int i = 0;
    for (rank a = rank_1; a < numOfRank ; a++)
    {
        winMask[i] = rankBitMask[a];
        i++;
    }
    for (file a = file_a; a < numOfFile ; a++)
    {
        winMask[i] = fileBitMask[a];
        i++;
    }
    winMask[6] = 0x421; //diagonal wins
    winMask[7] = 0x124;
    
}
bool sqIsOccupied (bitboard ex, bitboard oh, move m){
    
    bitboard occupied = ex | oh;
    occupied &= squareBitMask[m];
    return occupied;
}

void printBitboard(bitboard board){
    uint16_t sq = 0;
    uint16_t rk = 0;
    
    std::cout << "////////////////////// \n";
    for( int16_t i= 2; i >= 0; i--)
    {
        rk = i << 2;
        
        for( int16_t j= 0; j <3; j++)
        {
            sq = rk + j;
            if(board & squareBitMask[sq]) std::cout << "# ";
            else std::cout << "- ";
        }
        std::cout <<"\n";
    }
    std::cout << "////////////////////// \n\n";
    
}


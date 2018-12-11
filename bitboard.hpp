//
//  bitboard.hpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#ifndef bitboard_hpp
#define bitboard_hpp

#include <stdio.h>
#include "position.hpp"
#include "types.hpp"



constexpr bitboard board = 0x0777;
constexpr bitboard fileA = 0x0111;
constexpr bitboard fileB = fileA << 1;
constexpr bitboard fileC = fileA << 2;

constexpr bitboard rank1 = 0x0007;
constexpr bitboard rank2 = rank1 << (4 * 1);
constexpr bitboard rank3 = rank1 << (4 * 2);

extern bitboard squareBitMask[numOfSq];
extern bitboard fileBitMask [numOfFile];
extern bitboard rankBitMask [numOfRank];
extern bitboard winMask[8];
namespace bitboards {
    void init();
}
bool sqIsOccupied(bitboard ex, bitboard oh, move m);
void printBitboard(bitboard board);

#endif /* bitboard_hpp */

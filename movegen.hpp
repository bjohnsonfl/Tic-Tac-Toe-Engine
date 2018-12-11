//
//  movegen.hpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/5/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#ifndef movegen_hpp
#define movegen_hpp

#include <stdio.h>

#include "bitboard.hpp"
#include "position.hpp"
#include "types.hpp"

class position;
// this is tic tac toe, so theres only 9 total moves to think about
//for chess think about using a vector or a pointer to a structure like stockfish
extern move moveList[8];

move* generateAllMoves (position& pos, move * moveList);

move coordToMove (char coord [], bool extended);
bool isGameWon(bitboard pieces);


#endif /* movegen_hpp */

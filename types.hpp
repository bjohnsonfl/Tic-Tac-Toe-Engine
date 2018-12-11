//
//  types.hpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#ifndef types_hpp
#define types_hpp

#include <iostream>
#include <stdio.h>
#include <vector>

typedef u_int16_t bitboard;
/*
 method of determining square index in bitboard:
    bit 0 - 1       :      file
    bit 2 - 3       :      rank
 bitboard bits:
    bit 0 - 2       :       rank 1
    bit 4 - 6       :       rank 2
    bit 8 - A       :       rank 3
    bits 3, 7, B - F:       unused
 */
enum square {
    a1 = 0, b1, c1, //r1
    a2 = 4, b2, c2, //r2
    a3 = 8, b3, c3,  //r3
//  f1  f2  f3
    numOfSq = 11
};
enum file {
    file_a= 0, file_b = 1, file_c = 2, numOfFile = 3
};

enum rank {
    rank_1 = 0, rank_2 = 1, rank_3 = 2, numOfRank = 3
};

enum move {
    none=11
};

enum piece{
    EX, OH, numOfPiece = 2,  empty = -1, notBoard = -2
};

enum value {
    zero = 0,
    draw = 0,
    win = 10,
    lose = -10,
    min = -20,
    max = 20
};

enum score {
    zeroo = 0
};

inline square operator++(square& d, int) { return d = square(int(d) + 1); }
inline rank operator++(rank& d, int) { return d = rank(int(d) + 1); }
inline file operator++(file& d, int) { return d = file(int(d) + 1); }
//namespace pv{
//extern std::vector<move> pvTable;
extern move pvTable[9];
/*inline void clear_pvTable(){pvTable.clear();}
inline void print_pvTable(){
    for (int i=0; i< pvTable.size();i++)
    {
        std::cout<<pvTable[i] << " \n";
    }
}*/
//}

#endif /* types_hpp */

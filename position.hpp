//
//  position.hpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#ifndef position_hpp
#define position_hpp

#include <stdio.h>

#include "bitboard.hpp"
#include "movegen.hpp"
#include "types.hpp"
class position {
    
private:
    piece board [numOfSq];
    bitboard EXS_Board;
    bitboard OHS_Board;
    
    int ply;
    piece sideToPlay;
    score score;
    bool gameWon;
    int nodes;
    
    void place_piece(move m);
    void remove_piece (move m);
   
public:
    position ();
    void printBoard ();
    void reset();
    void setboard();
    void do_move (move m );
    void do_move_user (move m );
    void undo_move (move m);
    bool legal_move (move m);

    piece get_sideToPlay();
    bool get_gameWon();
    bitboard get_EXS_Board();
    bitboard get_OHS_Board();
    int get_ply();
    int get_nodes();
    
    void inc_nodes();
    void clear_nodes();
   
};




#endif /* position_hpp */

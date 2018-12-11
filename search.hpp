//
//  search.hpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#ifndef search_hpp
#define search_hpp

#include <stdio.h>

#include "types.hpp"
#include "bitboard.hpp"
#include "position.hpp"
#include "movegen.hpp"

namespace search {
    void search (position& pos, int depth);

}


value miniMax(position& pos, int depth, bool isMax);
value alphaBeta_miniMax(position& pos, int depth, int alpha, int beta, bool isMax);
#endif /* search_hpp */

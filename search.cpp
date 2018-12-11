//
//  search.cpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//
#include <iostream>
#include "search.hpp"

//std::vector<move> pvTable;
move pvTable[9];

void search::search(position& pos, int depth)
{
   
 
    pos.clear_nodes();
   // miniMax(pos, depth, true);
    alphaBeta_miniMax(pos, depth, -20, 20, true);
}

value miniMax(position& pos, int depth, bool isMax)
{
    pos.inc_nodes();
    if(pos.get_gameWon() && !isMax)
    {
        return value(win + value(depth+1));
    }
    if(pos.get_gameWon() && isMax)
    {
        return value(lose - value(depth+1));
    }
    if(depth == 0)
    {
        return draw;
    }
    
    
    move allMoves [8];
    move *list  = allMoves;
    move * end;
    end = generateAllMoves(pos, allMoves);
    
    value max_score = min;
    value min_score = max;
    value current_score = zero ;
    move best_move = none;
    
    while(list != end)
    {
        
        if (isMax == true){
          
            pos.do_move(*list);
            current_score = miniMax( pos,  depth -1 ,  false);
            pos.undo_move(*list);
           
            if(current_score > max_score) {
                best_move = *list;
                max_score = current_score;
            }
            
            list++;
        }
        
        else {
           
            pos.do_move(*list);
            current_score = miniMax( pos,depth-1, true);
            pos.undo_move(*list);
            if(current_score < min_score) {
                best_move = *list;
                min_score = current_score;
            }
            
            list++;
        }
    }
    
    pvTable[depth] = best_move;
    return isMax == true ? max_score : min_score;
}



value alphaBeta_miniMax(position& pos, int depth, int alpha, int beta,bool isMax){
    pos.inc_nodes();
    if(pos.get_gameWon() && !isMax)
    {
        return value(win + value(depth+1));
    }
    if(pos.get_gameWon() && isMax)
    {
        return value(lose - value(depth+1));
    }
    if(depth == 0)
    {
        return draw;
    }
    
    
    move allMoves [8];
    move *list  = allMoves;
    move * end;
    end = generateAllMoves(pos, allMoves);
    
    value max_score = min;
    value min_score = max;
    value current_score = zero ;
    move best_move = none;
    
    while(list != end)
    {
        
        if (isMax == true){
            
            pos.do_move(*list);
            current_score = alphaBeta_miniMax(pos, depth -1, alpha,  beta, false);
            pos.undo_move(*list);
            
            if(current_score > max_score) {
                best_move = *list;
                max_score = current_score;
            }
            //std::cout << "max score: " <<max_score << " alpha: " <<alpha << "\n";
            if(alpha < max_score) alpha = max_score;
            
            if(alpha >= beta)
            {
                break;
            }
            
            list++;
        }
        
        else {
            
            pos.do_move(*list);
            current_score =  alphaBeta_miniMax(pos, depth -1, alpha,  beta, true);
            pos.undo_move(*list);
            if(current_score < min_score) {
                best_move = *list;
                min_score = current_score;
            }
            
            if(beta > min_score) beta = min_score;
            
            if(alpha >= beta) break;
            
            list++;
        }
    }
    
    pvTable[depth] = best_move;
    return isMax == true ? max_score : min_score;
    
    
    
}


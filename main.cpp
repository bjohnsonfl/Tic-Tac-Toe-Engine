//
//  main.cpp
//  TicTacToeAI
//
//  Created by Blake Johnson on 12/3/18.
//  Copyright © 2018 Blake Johnson. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "bitboard.hpp"
#include "movegen.hpp"
#include "position.hpp"
#include "search.hpp"
#include "types.hpp"
using namespace std;



int main(int argc, const char * argv[]) {
    cout << "Tic-Tac-Toe Engine\n";
    cout << "type in a command and attribute\n";
    cout << "type 'h' for the help menu and a list of commands\n\n\n";
    cout << "the board is in the format: \n\n";
    cout << " a3 | b3 | c3 \n";
    cout << " ------------\n";
    cout << " a2 | b2 | c2 \n";
    cout << " ------------\n";
    cout << " a1 | b1 | c1 \n\n Type in a square to place a move \n\n";
    bool run = false;
    char line [5];
    clock_t t;
   
    position * pos = new position();
    bitboards::init();
    
    while (!run)
    {
        
        cin.getline(line, 5);
        //cout << " line = '" << line <<"'"<< endl;
        switch (line[0]) {
            case 'q':
                run = true;
                cout << "Quiting...";
                break;
            case 'h':
                cout << "* * * help menu * * *\n";
                cout << "All inputs need to be lowercase letters. \n";
                cout << "ONLY 4 CHARACTERS (SPACES COUNT AS 1 CHARACTER) \n";
                cout << "Do not put more than one space between a command and attributes \n";
                cout << "Commands are single letters representing actions like move and undo move.\n";
                cout << "Attributes are the data to be inputed like a move coordinate ie. a1 \n";
               
                cout << "command formats:\n";
                cout << "Move:        rank+file\n";
                cout << "Undo Move: u rank+file\n";
                cout << "Help:      h \n";
                cout << "Quit:      q \n";
                
                cout << "the board is in the format: \n\n";
                cout << " a3 | b3 | c3 \n";
                cout << " ------------\n";
                cout << " a2 | b2 | c2 \n";
                cout << " ------------\n";
                cout << " a1 | b1 | c1 \n\n";
                break;
                
            case 'u' :
                pos->undo_move(coordToMove(line, true));
                break;
            case 'n' :
                pos->reset();
                break;
            default:
             
                pos->do_move_user(coordToMove(line, false));
                if(pos->get_gameWon())
                {
                    cout << "GAME IS OVER! \n" ;
                    (!(pos -> get_sideToPlay())) == 0 ?  cout << "X " :  cout << "O ";
                    cout << " Won the game.\n To play another game press n or q to quit. \n";
                    break;
                }
                t = clock();
                search::search(*pos, 9 - pos->get_ply());
                t= clock()-t;
                cout << "Number of nodes: "<<pos->get_nodes() <<" Number of Seconds:  "<< float(t)/CLOCKS_PER_SEC << endl;
                
                pos->do_move_user(pvTable[9 - pos->get_ply()]);
                if(pos->get_gameWon())
                {
                    cout << "GAME IS OVER! \n" ;
                    (!(pos -> get_sideToPlay())) == 0 ?  cout << "X " :  cout << "O ";
                    cout << " Won the game.\n To play another game press n or q to quit. \n";
                    
                }
                
                
                
                break;
                
          
        }
        cin.clear();
       // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        
    };
    
    
    return 0;
}




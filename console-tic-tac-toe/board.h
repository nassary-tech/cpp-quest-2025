//
// Created by Amr Khaled on 9/17/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "player.h"
#include "ai.h"
using namespace std;

namespace board_class {
    class board {
    private:
        char board_plane[3][3];
        char current_player;
    public:
        board(): current_player('X') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board_plane[i][j] = ' ';
                }
            }
        };

        void display();
        void reset();
        char get_cell(char row, int col);
        bool check_empty(char row, int col);
        bool check_move(player_class::player& P);
        void make_move(player_class::player& P);
        string check_winner(player_class::player& P1, player_class::player& P2);
    };
}

#endif //BOARD_H
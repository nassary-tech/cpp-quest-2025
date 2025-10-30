//
// Created by Amr Khaled on 9/17/2025.
//

#ifndef AI_H
#define AI_H

#include "board.h"
#include "player.h"
#include <iostream>

#include "board.h"

namespace board_class {
    class board;
}

using namespace std;

namespace ai_class {
    class ai : public player_class::player {
    public:
        string level;
        int ai_wins;

        ai(){};
        ai(string n, char s, string l):player(n, s) {
            name = n;
            symbol = s;
            level = l;
        };

        void set_level(string l);
        void set_wins(int w);

        string get_level();
        int get_wins();
        void get_move(char row, int col);
        void calc_move(board_class::board& grid, player& P);
    };
}

#endif //AI_H
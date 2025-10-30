//
// Created by Amr Khaled on 9/17/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

namespace player_class {
    class player {
    public:
        string name;
        char symbol;
        bool is_ai;
        char row;
        int col;
        static int player_wins;

        player(){};
        player(string n, char s) {
            name = n;
            symbol = s;
        };

        void set_name(string n);
        void set_symbol(char s);
        void set_move(char r, int c);
        void set_row(char r);
        void set_col(int c);

        string get_name();
        char get_symbol();
        char get_row();
        int get_col();
    };
}

#endif //PLAYER_H
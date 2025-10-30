//
// Created by Amr Khaled on 9/17/2025.
//

#include "board.h"
#include "ai.h"
#include <iostream>
using namespace std;
using namespace board_class;
using namespace ai_class;

void ai::set_level(string l) {level = l;}

void ai::set_wins(int w) {ai_wins = w;}

string ai::get_level() {return level;}

void ai::calc_move(board& grid, player& P) {
    char row;
    int col;

    if (get_level() == "easy") {
        while (true) {
            row = 'A' + rand() % 3;
            col = rand() % 3 + 1;

            if (grid.check_empty(row, col)) {
                set_move(row, col);
                return;
            }
        }
    }

    if (get_level() == "medium") {
        bool winning = false, blocking = false;

        for (int i = 0; i < 3; i++) {
            int ai_moves = 0, P_moves = 0;
            char empty_row = 'A';
            int empty_col = 0;

            for (int j = 0; j < 3; j++) {
                row = 'A' + i;
                col = j + 1;
                char cell = grid.get_cell(row, col);

                if (cell == get_symbol()) {
                    ai_moves++;
                }
                else if (cell == P.get_symbol()) {
                    P_moves++;
                }
                else if (grid.check_empty(row, col) && empty_col == 0) {
                    empty_row = row;
                    empty_col = col;
                }
            }

            if (empty_col != 0 && ai_moves == 2) {
                set_move(empty_row, empty_col);
                winning = true;
                return;
            }
            if (empty_col != 0 && P_moves == 2) {
                set_move(empty_row, empty_col);
                blocking = true;
                return;
            }

        }

        for (int j = 0; j < 3; j++) {
            int ai_moves = 0, P_moves = 0;
            char empty_row = 'A';
            int empty_col = 0;

            for (int i = 0; i < 3; i++) {
                row = 'A' + i;
                col = j + 1;
                char cell = grid.get_cell(row, col);

                if (cell == get_symbol()) {
                    ai_moves++;
                }
                else if (cell == P.get_symbol()) {
                    P_moves++;
                }
                else if (grid.check_empty(row, col) && empty_col == 0) {
                    empty_row = row;
                    empty_col = col;
                }
            }

            if (empty_col != 0 && ai_moves == 2) {
                set_move(empty_row, empty_col);
                winning = true;
                return;
            }
            if (empty_col != 0 && P_moves == 2) {
                set_move(empty_row, empty_col);
                blocking = true;
                return;
            }

        }

        {
            int ai_moves = 0, P_moves = 0;
            char empty_row = 'A';
            int empty_col = 0;

            for (int i = 0; i < 3; i++) {
                row = 'A' + i;
                col = i + 1;
                char cell = grid.get_cell(row, col);

                if (cell == get_symbol()) {
                    ai_moves++;
                }
                else if (cell == P.get_symbol()) {
                    P_moves++;
                }
                else if (grid.check_empty(row, col) && empty_col == 0) {
                    empty_row = row;
                    empty_col = col;
                }
            }

            if (empty_col != 0 && ai_moves == 2) {
                set_move(empty_row, empty_col);
                winning = true;
                return;
            }
            if (empty_col != 0 && P_moves == 2) {
                set_move(empty_row, empty_col);
                blocking = true;
                return;
            }

        }

        {
            int ai_moves = 0, P_moves = 0;
            char empty_row = 'A';
            int empty_col = 0;

            for (int i = 0; i < 3; i++) {
                row = 'A' + i;
                col = 3 - i;
                char cell = grid.get_cell(row, col);

                if (cell == get_symbol()) {
                    ai_moves++;
                }
                else if (cell == P.get_symbol()) {
                    P_moves++;
                }
                else if (grid.check_empty(row, col) && empty_col == 0) {
                    empty_row = row;
                    empty_col = col;
                }
            }

            if (empty_col != 0 && ai_moves == 2) {
                set_move(empty_row, empty_col);
                winning = true;
                return;
            }
            if (empty_col != 0 && P_moves == 2) {
                set_move(empty_row, empty_col);
                blocking = true;
                return;
            }
        }

        if (!winning && !blocking) {
            if (grid.check_empty('B', 2)) {
                set_move('B', 2);
                return;
            }

            while (true) {
                row = 'A' + rand() % 3;
                col = rand() % 3 + 1;

                if (grid.check_empty(row, col)) {
                    set_move(row, col);
                    return;
                }
            }
        }
    }
}
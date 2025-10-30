//
// Created by Amr Khaled on 9/17/2025.
//

#include "board.h"
#include "player.h"
#include "ai.h"
#include <iostream>
using namespace std;
using namespace board_class;
using namespace player_class;
using namespace ai_class;

void board::display() {
    cout << "=================================" << "\n";
    cout << " " << " " << "." << " " << "1" << " " << "." << " " << "2" << " " << "." << " " << "3" << " " << "." << "\n";
    cout << "A" << " " << "|" << " " << board_plane[0][0] << " | " << board_plane[0][1] << " | " << board_plane[0][2] << " " << "|" << "\n";
    cout << "-" << " " << "+" << "---+---+---" << "+" << "\n";
    cout << "B" << " " << "|" << " " << board_plane[1][0] << " | " << board_plane[1][1] << " | " << board_plane[1][2] << " " << "|" << "\n";
    cout << "-" << " " << "+" << "---+---+---" << "+" << "\n";
    cout << "C" << " " << "|" << " " << board_plane[2][0] << " | " << board_plane[2][1] << " | " << board_plane[2][2] << " " << "|" <<  "\n";
    cout << "-" << " " << "+" << "---+---+---" << "+" << "\n";
    cout << "=================================" << "\n";
}

void board::reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board_plane[i][j] = ' ';
        }
    }
}

char board::get_cell(char row, int col) {
    int new_row;

    if (row == 'A' || row == 'a') {
        new_row = 0;
    }
    if (row == 'B' || row == 'b') {
        new_row = 1;
    }
    if (row == 'C' || row == 'c') {
        new_row = 2;
    }

    char cell = board_plane[new_row][col - 1];
    return cell;
}

bool board::check_empty(char row, int col) {
    int new_row;

    if (row == 'A' || row == 'a') {
        new_row = 0;
    }
    else if (row == 'B' || row == 'b') {
        new_row = 1;
    }
    else if (row == 'C' || row == 'c') {
        new_row = 2;
    }

    return board_plane[new_row][col - 1] == ' ';
}

bool board::check_move(player& P) {
    bool is_valid = false;
    bool valid_input = false;
    char row = P.get_row();
    int new_row, col = P.get_col();

    if ((row == 'A' || row == 'a') && (col >= 1 && col <= 3)) {
        valid_input = true;
    }
    if ((row == 'B' || row == 'b') && (col >= 1 && col <= 3)) {
        valid_input = true;
    }
    if ((row == 'C' || row == 'c') && (col >= 1 && col <= 3)) {
        valid_input = true;
    }

    if (row == 'A' || row == 'a') {
        new_row = 0;
    }
    if (row == 'B' || row == 'b') {
        new_row = 1;
    }
    if (row == 'C' || row == 'c') {
        new_row = 2;
    }

    if (valid_input && board_plane[new_row][col - 1] == ' ') {
        is_valid = true;
    }

    return is_valid;
}

void board::make_move(player& P) {
    char row = P.get_row();
    int new_row, col = P.get_col() - 1;

    if (row == 'A' || row == 'a') {
        new_row = 0;
    }
    if (row == 'B' || row == 'b') {
        new_row = 1;
    }
    if (row == 'C' || row == 'c') {
        new_row = 2;
    }

    board_plane[new_row][col] = P.get_symbol();
}

string board::check_winner(player& P1, player& P2) {
    char symbol1 = P1.get_symbol();
    char symbol2 = P2.get_symbol();
    bool P1_win = false, P2_win = false;
    int empty_count = 0;

    for (int i = 0; i < 3; i++) {
        int P1_score = 0, P2_score = 0;

        for (int j = 0; j < 3; j++) {
            if (board_plane[i][j] == symbol1) {
                P1_score++;
            }
            if (board_plane[i][j] == symbol2) {
                P2_score++;
            }
        }

        if (P1_score == 3) {
            P1_win = true;
        }
        if (P2_score == 3) {
            P2_win = true;
        }
    }

    for (int i = 0; i < 3; i++) {
        int P1_score = 0, P2_score = 0;

        for (int j = 0; j < 3; j++) {
            if (board_plane[j][i] == symbol1) {
                P1_score++;
            }
            if (board_plane[j][i] == symbol2) {
                P2_score++;
            }
        }

        if (P1_score == 3) {
            P1_win = true;
        }
        if (P2_score == 3) {
            P2_win = true;
        }
    }

    {
        int P1_score = 0, P2_score = 0;

        for (int i = 0; i < 3; i++) {
            if (board_plane[i][i] == symbol1) {
                P1_score++;
            }
            if (board_plane[i][i] == symbol2) {
                P2_score++;
            }
        }

        if (P1_score == 3) {
            P1_win = true;
        }
        if (P2_score == 3) {
            P2_win = true;
        }
    }

    {
        int P1_score = 0, P2_score = 0;

        for (int i = 0; i < 3; i++) {
            if (board_plane[i][2 - i] == symbol1) {
                P1_score++;
            }
            if (board_plane[i][2 - i] == symbol2) {
                P2_score++;
            }
        }

        if (P1_score == 3) {
            P1_win = true;
        }
        if (P2_score == 3) {
            P2_win = true;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board_plane[i][j] == ' ') {
                empty_count++;
            }
        }
    }

    if (P1_win) {
        return "P1";
    }
    if (P2_win) {
        return "P2";
    }
    if (!P1_win && !P2_win && empty_count == 0) {
        return "draw";
    }

    return "ongoing";
}
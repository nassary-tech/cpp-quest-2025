//
// Created by Amr Khaled on 9/17/2025.
//

#include "player.h"
#include <iostream>
using namespace std;
using namespace player_class;

void player::set_name(string n) {name = n;}

void player::set_symbol(char s) {symbol = s;}

void player::set_move(char r, int c) {row = r; col = c;}

string player::get_name() {return name;}

char player::get_symbol() {return symbol;}

char player::get_row() {return row;}

int player::get_col() {return col;}
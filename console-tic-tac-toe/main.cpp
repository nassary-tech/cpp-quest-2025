#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include "board.h"
#include "player.h"
#include "ai.h"
using namespace std;
using namespace board_class;
using namespace player_class;
using namespace ai_class;

void refresh_grid(board& game);
void choose_level(ai& AI);

void player_turn(board& game, player& P);
void ai_turn(board& game, player& P, ai& AI);
bool check_end(board& game, player& P1, player& P2);

void ct_delay(float seconds);   //Delay function (ctime)
void end_program(int delay);   //End the program function (delay in seconds)

void show_menu()
{
    cout << "=================================" << "\n";
    cout << "Who do you want to play against?" << "\n";
    cout << "---------------------------------" << "\n";
    cout << "1. vsAI" << "\n";
    cout << "2. vsPlayer" << "\n";
    cout << "3. Exit" << "\n";
    cout << "=================================" << "\n";
    cout << "Enter your choice: ";
}

void credits(float delay) {
    string credit = "By: Nassary ";

    for (char c: credit) {
        cout << c;
        ct_delay(delay);
    }

    ct_delay(delay * 2);
    cout << "=====================" << "\n";

    // ct_delay(delay);
    // cout << "----";
    //
    // string title = "WELCOME TO MY TIC-TAC-TOE";
    //
    // for (char c: title) {
    //     cout << c;
    //     ct_delay(delay);
    // }
    //
    // cout << "----" << "\n";
    // ct_delay(delay * 2);
}

int main() {
    board game;
    string P1_name = "P1", P2_name = "P2";
    int mode = 1;

    player P1;
    P1.set_name(P1_name);
    P1.set_symbol('X');

    player P2;
    P2.set_name(P2_name);
    P2.set_symbol('O');

    ai P2_ai;
    P2_ai.is_ai = true;
    P2_ai.set_name("AI");
    P2_ai.set_level("easy");
    P2_ai.set_symbol('O');

    credits(0.25);

    cout << "----WELCOME TO MY TIC-TAC-TOE----" << "\n";

    while (true) {
        show_menu();
        cin >> mode;

        switch (mode) {
            case 1:
                srand(time(NULL));

                choose_level(P2_ai);
                game.reset();
                cout << "=================================" << "\n";
                cout << "------------vsAI GAME------------" << "\n";
                refresh_grid(game);

                while (true) {
                    player_turn(game, P1);
                    if (check_end(game, P1, P2_ai)) {break;}

                    //refresh_grid(game);

                    ai_turn(game, P1, P2_ai);
                    if (check_end(game, P1, P2_ai)) {break;}

                    //refresh_grid(game);
                }
                break;
            case 2:
                game.reset();
                cout << "=================================" << "\n";
                cout << "----------vsPlayer GAME----------" << "\n";
                refresh_grid(game);

                while (true) {
                    player_turn(game, P1);
                    if (check_end(game, P1, P2)) {break;}

                    //refresh_grid(game);

                    player_turn(game, P2);
                    if (check_end(game, P1, P2)) {break;}

                    //refresh_grid(game);
                }
                break;
            case 3:
                end_program(3);
                break;
            default:
                cout << "=================================" << "\n";
                cout << "Invalid Input!" << "\n";
        }
    }
}

void refresh_grid(board& game) {
    cout << "\033[2J\033[1;1H";
    game.display();
}

void choose_level(ai& AI) {
    int ai_level;

    while (true) {
        cout << "=================================" << "\n";
        cout << "Choose the difficulty of the AI:" << "\n";
        cout << "---------------------------------" << "\n";
        cout << "1. Easy" << "\n";
        cout << "2. Medium" << "\n";
        cout << "=================================" << "\n";
        cout << "Enter your choice: ";
        cin >> ai_level;

        if (ai_level == 1) {
            AI.set_level("easy");
            break;
        }
        if (ai_level == 2) {
            AI.set_level("medium");
            break;
        }
        cout << "=================================" << "\n";
        cout << "Invalid Input!" << "\n";
    }
}

void player_turn(board& game, player& P) {
    char row;
    int col;

    while (true) {
        cout << "It's" << " " + P.get_name() + "'s turn:";
        cin.ignore();
        cin >> row >> col;
        P.set_move(row, col);

        if (game.check_move(P)) {
            game.make_move(P);
            refresh_grid(game);
            break;
        }

        cout << "=================================" << "\n";
        cout << "Invalid input!" << "\n";
        refresh_grid(game);
    }
}

void ai_turn(board& game, player& P, ai& AI) {
    AI.calc_move(game, P);
    game.make_move(AI);
    refresh_grid(game);
}

bool check_end(board& game, player& P1, player& P2) {
    string winner = game.check_winner(P1, P2);

    if (winner == "P1") {
        cout << P1.get_name() + " " << "is the Winner!" << "\n";
        return true;
    }
    if (winner == "P2") {
        cout << P2.get_name() + " " << "is the Winner!" << "\n";
        return true;
    }
    if (winner == "draw") {
        cout << "It's a draw!" << "\n";
        return true;
    }
    if (winner == "ongoing") {
        return false;
    }
}

//Delay function (ctime)
void ct_delay(float seconds)
{
    clock_t start_time = clock();   //Variables
    double clocks_needed = seconds * CLOCKS_PER_SEC;

    while (clock() - start_time < clocks_needed) {}   //Busy loop, does nothing till the time is up
}

//End the program function
void end_program(int delay)
{
    char choice;

    cout << "=================================" << "\n";
    cout << "Are you sure you want to exit the program? (y/n)" << "\n";
    cout << ">>";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cin.ignore();   //Ignore the newline left in the input
        cout << "---------------------------------" << "\n";

        for (int i = delay; i >= 0; i--)   //Loop that counts down the delay time
        {
            cout << "\r" << "Exiting in " << i << "..." << flush;
            ct_delay(0.75);
        }

        exit(0);   //Exit the program
    }
    if (choice == 'n' || choice == 'N')
    {
        return;
    }

    cout << "=================================" << "\n";
    cout << "Invalid Input!" << "\n";

}
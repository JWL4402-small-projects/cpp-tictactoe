#include "TicTacToe.h"

#include <iostream>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace TicTacToe;

/// @brief Starts a game of TicTacToe.
void TicTacToe::start() {
    bool active = true;
    char turn = 'X';

    GameState state = UNDECIDED;
    char winner = ' ';

    char board[9];
    std::fill_n(board, 9, ' ');

    while (active) {
        print_board(board);
        printf("Player %c, it is your turn to play. Please select a position [1-9] : ", turn);
        int pos;
        do {
            while (!(std::cin >> pos)) {
                printf("\nIncorrect input. Please enter a valid numeric position [1-9] : ");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (pos < 1 || pos > 9) {
                printf("\nIncorrect input. Please enter a valid position [1-9] : ");
                continue;
            }
            if (board[pos - 1] != ' ') {
                printf("\nIncorrect input. Please enter an available position [1-9] : ");
                continue;
            }
            std::cout << std::endl;
        } while ((pos < 1 || pos > 9) || board[pos - 1] != ' ');
        
        pos--; // decrement so that it reflects the desired array index
        
        board[pos] = turn;
        state = check_win(board);

        if (state != UNDECIDED) {
            active = false;
            winner = turn;
        }
        else {
            turn = turn != 'X' ? 'X' : 'O';
        }
    }

    print_board(board);
    switch (state)
    {
    case DRAW:
        printf("The game was a draw!");
        break;
    case WIN:
        printf("Player %c won the game. Congratulations.", winner);
        break;
    default:
        throw;
    }
}

/// @brief Welcomes the player to the game and explains the rules.
void TicTacToe::welcome() {
    printf("Welcome to TicTacToe!\n\n");

    printf("To play the game, select a position on the board by inputting the corresponding number.\n\n");
    
    char board[9];
    for (int i = 0; i < 9; i++) {
        board[i] = 49 + i; // converts to ASCII code so it's easiest to just embrace it
    }
    print_board(board);
    printf("\nEnjoy the game!\n");
    printf("\n-------------------------\n\n");
}

/// @brief Prints the TicTacToe board to the console.
/// @param board A char array representing the board.
void TicTacToe::print_board(char* board) {
	printf(" %c | %c | %c", *board, *(board + 1), *(board + 2));
	printf("\n---+---+---\n");
	printf(" %c | %c | %c", *(board + 3), *(board + 4), *(board + 5));
	printf("\n---+---+---\n");
	printf(" %c | %c | %c\n", *(board + 6), *(board + 7), *(board + 8));
}

/// @brief Checks if there is a winner or draw.
/// @param board A char array representing the board.
/// @return A GameState value, either UNDECIDED, DRAW, or WIN, depending on the state of the board.
GameState TicTacToe::check_win(char* board) {
    int pos[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    int i;
    for (i = 0; i < 8; i++) {
        char p1 = board[pos[i][0]];
        char p2 = board[pos[i][1]];
        char p3 = board[pos[i][2]];
        if (p1 != ' ' && p1 == p2 && p2 == p3) {

            return WIN;
        }
    }

    int empty = 0;
    for (i = 0; i < 9; i++) {
        if (*(board + i) == ' ') { empty++; }
    } // checks if any empty spaces remain in the board
    if (empty == 0) { return DRAW; }

    return UNDECIDED;
}
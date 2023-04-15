#include "TicTacToe.h"

#include <cstdio>
#include <algorithm>

using namespace TicTacToe;

void TicTacToe::start() {
	bool active = true;

	char turn = 'X';

	char board[9];
	std::fill_n(board, 9, 'X'); // for testing

    board[0] = board[2] = board[3] = board[5] = board[7] = 'O'; // for testing

	print_board(board);
    printf("%c", check_win(board));
}

void TicTacToe::print_board(char* board) {
	printf(" %c | %c | %c", *board, *(board + 1), *(board + 2));
	printf("\n---+---+---\n");
	printf(" %c | %c | %c", *(board + 3), *(board + 4), *(board + 5));
	printf("\n---+---+---\n");
	printf(" %c | %c | %c\n", *(board + 6), *(board + 7), *(board + 8));
}

char TicTacToe::check_win(char* board) {
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
            return p1;
        }
    }

    int empty = 0;
    for (i = 0; i < 9; i++) {
        if (*(board + i) == ' ') { empty++; }
    }
    if (empty == 0) { return 'D'; }

    return ' ';
}
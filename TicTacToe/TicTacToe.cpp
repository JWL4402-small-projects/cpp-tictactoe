#include "TicTacToe.h"

#include <cstdio>
#include <algorithm>

using namespace TicTacToe;

void TicTacToe::start() {
	bool active = true;

	char turn = 'X';

	char board[9];
	std::fill_n(board, 9, ' ');

	print_board(board);
}

void TicTacToe::print_board(char* board) {
	printf(" %c | %c | %c", *board, *(board + 1), *(board + 2));
	printf("\n---+---+---\n");
	printf(" %c | %c | %c", *(board + 3), *(board + 4), *(board + 5));
	printf("\n---+---+---\n");
	printf(" %c | %c | %c", *(board + 6), *(board + 7), *(board + 8));
}
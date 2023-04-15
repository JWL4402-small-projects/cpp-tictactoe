#pragma once

namespace TicTacToe
{
	enum GameState { UNDECIDED, DRAW, WIN };

	void start();
	void print_board(char*);
	GameState check_win(char*);
}
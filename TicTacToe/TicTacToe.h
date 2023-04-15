#pragma once

namespace TicTacToe
{
	/// @brief Represents the state of the game, either UNDECIDED, DRAW, or WIN.
	enum GameState { UNDECIDED, DRAW, WIN };

	void start();
	void welcome();
	void print_board(char*);
	GameState check_win(char*);
}
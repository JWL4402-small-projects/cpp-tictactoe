#pragma once

namespace TicTacToe
{
	/// @brief Represents the state of the game, either UNDECIDED, DRAW, or WIN.
	enum GameState { UNDECIDED, DRAW, WIN };

	/// @brief Starts a game of TicTacToe.
	void start();
	void print_board(char*);
	GameState check_win(char*);
}
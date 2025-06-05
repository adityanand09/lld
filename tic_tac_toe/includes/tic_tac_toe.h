#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

#include "player.h"
#include "board.h"
#include <deque>
#include <string>

class TicTacToe {

private:
	std::deque<Player*> m_players;
	Board *m_board;

public:
	void initializeGame();

	void start();

private:
	bool isThereWinner(Piece* piece);

	std::string startGame();
};

#endif
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "piece.h"
#include <string>
#include <iostream>

class Player {
private:
	std::string m_player_name;
	Piece* m_piece;
public:
	Player();

	Piece* getPiece();

	std::string getPlayerName();
};

#endif
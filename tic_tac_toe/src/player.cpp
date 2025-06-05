#include "player.h"

Player::Player() {
	std::cout << "Enter player name : ";
	std::cin >> m_player_name;
	m_piece = new Piece();
}

Piece* Player::getPiece() {
	return m_piece;
}

std::string Player::getPlayerName() {
	return m_player_name;
}
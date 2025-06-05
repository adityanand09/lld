#include "player.h"

Player::Player(std::string player_name, Piece* piece) {
	m_player_name = player_name;
	m_piece = piece;
}

Piece* Player::getPiece() {
	return m_piece;
}

std::string Player::getPlayerName() {
	return m_player_name;
}
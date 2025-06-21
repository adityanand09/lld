#include "piece.h"

Piece::Piece(char piece_symbol) {
	m_piece_symbol = piece_symbol;
}

char Piece::getPieceSymbol() {
	return m_piece_symbol;
}
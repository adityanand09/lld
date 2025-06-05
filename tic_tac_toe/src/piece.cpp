#include "piece.h"

Piece::Piece() {
	char piece_symbol;
	while (true) {
		std::cout << "Enter piece symbol for current player : ";
		std::cin >> piece_symbol;
		if (!m_used_symbols.count(piece_symbol)) {
			m_used_symbols.insert(piece_symbol);
			break;
		} else {
			std::cout << "Entered piece symbol is already choosen\n";
		}
	}
	m_piece_symbol = piece_symbol;
}

char Piece::getPieceSymbol() {
	return m_piece_symbol;
}
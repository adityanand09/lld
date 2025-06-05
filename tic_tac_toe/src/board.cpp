#include "board.h"

Board::Board() {
	std::cout << "Enter board size : ";
	std::cin >> m_size;
	m_cells.resize(m_size);
	for (auto &row : m_cells) {
		row.resize(m_size);
		for (auto &piece : row) {
			piece = nullptr;
		}
	}
	m_free_cells_count = m_size * m_size;
}

bool Board::addPiece(int row, int col, Piece* piece) {
	if (m_cells[row][col] == nullptr) {
		m_cells[row][col] = piece;
		m_free_cells_count--;
		return true;
	}
	return false;
}

int Board::getFreeCellsCount() {
	return m_free_cells_count;
}

int Board::getBoardSize() {
	return m_size;
}

Piece* Board::getPiece(int row, int col) {
	return m_cells[row][col];
}

void Board::printBoard() {
	for (auto &row : m_cells) {
		for (auto &piece : row) {
			if (piece != nullptr) {
				std::cout << ' ' << piece->getPieceSymbol() << ' ';
			} else {
				std::cout << " _ ";
			}
		}
		std::cout << '\n';
	}
}
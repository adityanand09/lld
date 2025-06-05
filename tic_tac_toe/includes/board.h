#ifndef __BOARD_H__
#define __BOARD_H__

#include "piece.h"
#include <iostream>
#include <vector>

class Board {

private:
	int m_size;
	int m_free_cells_count;
	std::vector<std::vector<Piece*>> m_cells;

public:
	Board(int size);

	bool addPiece(int row, int col, Piece* piece);

	int getFreeCellsCount();

	int getBoardSize();

	Piece* getPiece(int row, int col);

	void printBoard();

};

#endif
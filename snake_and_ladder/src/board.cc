#include "board.h"
#include <random>

Board::Board(int rows, int cols) 
    : m_rows(rows), m_cols(cols), m_cells(rows, std::vector<Cell*>(cols)), m_dsu(rows * cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m_cells[i][j] = new Cell();
        }
    }
}

void Board::addSnakes(int snake_count) {
    while (snake_count) {
        int start = rand() % (m_rows * m_cols);
        int end = rand() % (m_rows * m_cols);
        
        // Ensure the snake does not lead to itself and is a valid jump
        if (start != end && end < start && isPositionValid(start) && isPositionValid(end) && !isWinningPosition(start)) {
            if (m_dsu.connected(start, end)) {
                continue; // Skip if already connected in DSU
            }
            Jump* snake = new Jump(start, end);
            Cell* cell = getCell(start);
            cell->setJump(snake);
            m_dsu.unite(start, end);
            snake_count--;
        }
    }
}

void Board::addLadders(int ladder_count) {
    while (ladder_count) {
        int start = rand() % (m_rows * m_cols);
        int end = rand() % (m_rows * m_cols);
        
        // Ensure the ladder does not lead to itself and is a valid jump
        if (start != end && end > start && isPositionValid(start) && isPositionValid(end)) {
            if (m_dsu.connected(start, end)) {
                continue;
            }
            Jump* ladder = new Jump(start, end);
            Cell* cell = getCell(start);
            cell->setJump(ladder);
            m_dsu.unite(start, end);
            ladder_count--;
        }
    }
}

bool Board::isWinningPosition(int position) {
    int row = position / m_cols;
    int col = position % m_cols;
    return (row == m_rows - 1 && col == m_cols - 1);
}

Cell* Board::getCell(int position) {
    int row = position / m_cols;
    int col = position % m_cols;
    return m_cells[row][col];
}

bool Board::isPositionValid(int position) {
    int row = position / m_cols;
    int col = position % m_cols;
    return (row >= 0 && row < m_rows && col >= 0 && col < m_cols);
}
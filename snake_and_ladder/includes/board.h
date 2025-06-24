#include <vector>
#include "dsu.h"
#include "cell.h"

class Board {
    private:
        int m_rows;
        int m_cols;
        std::vector<std::vector<Cell*>> m_cells;
        DSU m_dsu;
    public:
        Board(int rows, int cols);
        void addSnakes(int snake_count);
        void addLadders(int ladder_count);
        bool isWinningPosition(int position);
        Cell* getCell(int position);
        bool isPositionValid(int position);
};
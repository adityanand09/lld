#include "jump.h"

class Cell {
    private:
        Jump* m_jump;
    public:
        Cell();
        void setJump(Jump* jump);
        Jump* getJump();
};
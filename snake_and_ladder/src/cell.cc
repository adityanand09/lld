#include "cell.h"

Cell::Cell() : m_jump(nullptr) {}

void Cell::setJump(Jump* jump) {
    m_jump = jump;
}

Jump* Cell::getJump() {
    return m_jump;
}
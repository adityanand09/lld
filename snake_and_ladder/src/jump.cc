#include "jump.h"

Jump::Jump(int start, int end) : m_start(start), m_end(end) {}

int Jump::getStart() {
    return m_start;
}

int Jump::getEnd() {
    return m_end;
}
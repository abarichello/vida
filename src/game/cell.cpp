#include "game/cell.h"

Cells::Cell::Cell() : state(Cells::State::Dead), body(cellDimensions.x, cellDimensions.y, cellDimensions.z) {
}

void Cells::Cell::flip() {
    if (state == State::Dead) {
        state = State::Alive;
    } else {
        state = State::Dead;
    }
}

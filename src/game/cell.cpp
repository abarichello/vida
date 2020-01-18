#include "game/cell.h"

Cells::Cell::Cell(m3d::Vector3f dimensions) : body(dimensions.x, dimensions.y, dimensions.z) {
}

void Cells::flip(Cell& cell) {
    if (cell.state == State::Dead) {
        cell.state = State::Alive;
    } else {
        cell.state = State::Dead;
    }
}

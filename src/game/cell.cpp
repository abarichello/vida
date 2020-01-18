#include "game/cell.h"

void Cells::flip(Cell& cell) {
    if (cell.state == State::Dead) {
        cell.state = State::Alive;
    } else {
        cell.state = State::Dead;
    }
}

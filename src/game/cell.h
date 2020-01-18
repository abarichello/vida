#pragma once

namespace Cells {
    enum class State { Dead, Alive };

    struct Cell {
        Cells::State state = Cells::State::Dead;
    };

    void flip(Cell& cell);
}  // namespace Cells

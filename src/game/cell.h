#pragma once

#include <m3dia.hpp>

namespace Cells {
    enum class State { Dead, Alive };

    struct Cell {
        Cell(m3d::Vector3f dimensions);
        Cells::State state = Cells::State::Dead;
        m3d::Cuboid body;
    };

    void flip(Cell& cell);
}  // namespace Cells

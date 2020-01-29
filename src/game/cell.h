#pragma once

#include <m3dia.hpp>

namespace Cells {
    enum class State { Dead, Alive };
    const m3d::Vector3f cellDimensions{0, 3, 3};

    struct Cell {
        Cell();

        void flip();

        Cells::State state;
        m3d::Cuboid body;
    };

}  // namespace Cells

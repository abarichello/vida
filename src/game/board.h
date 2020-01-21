#pragma once

#include <m3dia.hpp>
#include <memory>
#include <iostream>

#include "game/cell.h"

class Board {
public:
    Board();

    void update(m3d::Camera& camera, float delta);
    void draw(m3d::Screen& screen);

    m3d::Vector2f size = m3d::Vector2f{32, 32};
    m3d::Vector3f cellDimensions = m3d::Vector3f{3, 3, 3};
    Cells::Cell testCell;

    float moveRate = 10.f;

private:
    std::vector<Cells::Cell> cells;
    m3d::Vector3f startPos = m3d::Vector3f{0, 0, 0};
};

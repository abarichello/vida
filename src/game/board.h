#pragma once

#include <m3dia.hpp>
#include <memory>
#include <iostream>

#include "game/cell.h"

class Board {
public:
    Board(m3d::Vector2f boardSize);

    void setup();
    void update(m3d::Camera& camera, float delta);
    void draw(m3d::Screen& screen);

    Cells::Cell testCell;

    float moveRate = 10.f;

private:
    m3d::Vector2f boardSize;
    m3d::Vector3f startPos;
    std::vector<Cells::Cell> cells;
};

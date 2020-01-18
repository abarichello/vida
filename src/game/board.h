#pragma once

#include <m3dia.hpp>
#include <memory>

class Board {
public:
    Board(m3d::Vector2f size = m3d::Vector2f{500, 500});

    void update(m3d::Camera& camera, float delta);
    void draw(m3d::Screen& screen);

    m3d::Vector2f size;
    m3d::Rectangle testRect;
    m3d::Cuboid cube;

    float moveRate = 10.f;

private:
    m3d::Vector3f startPos = m3d::Vector3f{0, 0, 0};
};

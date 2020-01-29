#include "game/board.h"
#include "game/cell.h"

Board::Board(m3d::Vector2f boardSize)
    : testCell(), boardSize(boardSize), startPos(m3d::Vector3f{0, 0, 0}), cells(boardSize.u * boardSize.v) {
    setup();
    testCell.body.setPosition(startPos);
}

void Board::setup() {
    for (int i = 0; i < boardSize.u; ++i) {
        for (int j = 0; j < boardSize.v; ++j) {
            float x = i * Cells::cellDimensions.y;
            float y = j * Cells::cellDimensions.z;
            cells.at(i * boardSize.v + j).body.setPosition(m3d::Vector3f{x, y, 0});
        }
    }
}

void Board::update(m3d::Camera& camera, float delta) {
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Up)) {
        camera.moveY(moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Down)) {
        camera.moveY(-moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Left)) {
        camera.moveX(moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Right)) {
        camera.moveX(-moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::L)) {
        camera.moveZ(-moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::R)) {
        camera.moveZ(moveRate * delta);
    }
}

void Board::draw(m3d::Screen& screen) {
    for (unsigned int i = 0; i < cells.size(); ++i) {
        screen.drawTop(cells[i].body, m3d::RenderContext::Mode::Spatial);
    }
}

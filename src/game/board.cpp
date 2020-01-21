#include "game/board.h"

Board::Board() : testCell(cellDimensions) {
    testCell.body.setPosition(startPos);
}

void Board::update(m3d::Camera& camera, float delta) {
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Up)) {
        camera.moveY(moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Down)) {
        camera.moveY(-moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Left)) {
        camera.moveX(-moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Right)) {
        camera.moveX(moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::L)) {
        camera.moveZ(-moveRate * delta);
    }
    if (m3d::buttons::buttonDown(m3d::buttons::Button::R)) {
        camera.moveZ(moveRate * delta);
    }
    printf("Camera X:%d | Y:%d | Z:%d \n", (int)camera.getPositionX(), (int)camera.getPositionY(),
           (int)camera.getPositionZ());
}

void Board::draw(m3d::Screen& screen) {
    screen.drawTop(testCell.body, m3d::RenderContext::Mode::Spatial);
}

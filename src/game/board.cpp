#include "game/board.h"

Board::Board(m3d::Vector2f size)
    : cube(3, 3, 3), size(size), testRect(0, 0, 1000, 1000, m3d::Color(255, 255, 255)) {
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
    std::printf("Camera X %f | Y %f | Z %f\n", camera.getPositionX(), camera.getPositionY(), camera.getPositionZ());
}

void Board::draw(m3d::Screen& screen) {
    screen.drawTop(testRect, m3d::RenderContext::Mode::Spatial);
    screen.drawTop(cube, m3d::RenderContext::Mode::Spatial);
}

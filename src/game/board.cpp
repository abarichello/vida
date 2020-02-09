#include "game/board.h"
#include "game/cell.h"

Board::Board(m3d::Vector2f boardSize)
    : testCell(), boardSize(boardSize), startPos(m3d::Vector3f{0, 0, 0}), cells(boardSize.u * boardSize.v) {
    setup();
}

void Board::setup() {
    if (!cubeTexture.loadFromFile("romfs:/resources/texures/texture.png")) {
        std::cout << "Error loading cube texture file\n";
    }
    testCell.body.bindTexture(cubeTexture);
    for (int i = 0; i < boardSize.u; ++i) {
        for (int j = 0; j < boardSize.v; ++j) {
            float x = i * Cells::cellDimensions.y;
            float y = j * Cells::cellDimensions.z;

            int vectorIndex = i * boardSize.v + j;
            auto& cell = cells.at(vectorIndex);
            cell.body.setPosition(m3d::Vector3f{x, y, 0});
            if ((i * j + 1) % 2 == 0) {
                cell.state = Cells::State::Alive;
            }
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
        if (cells[i].state == Cells::State::Dead) {
            cells[i].body.bindTexture(cubeTexture);
        } else {
            cells[i].body.unbindTexture();
        }
        screen.drawTop(cells[i].body, m3d::RenderContext::Mode::Spatial);
    }
    screen.drawTop(testCell.body, m3d::RenderContext::Mode::Spatial);
}

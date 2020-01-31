#include <iostream>

#include "gui/fps.h"

FPS::FPS() : text("FPS: 0.0") {
}

void FPS::update(float delta) {
    if (m3d::buttons::buttonDown(m3d::buttons::Button::Select) && m3d::buttons::buttonPressed(m3d::buttons::Button::B)) {
        printFPS = !printFPS;
    }
    if (!printFPS) {
        return;
    }

    frameCount++;
    this->delta += delta;
    if (this->delta >= 1.0 / updateRate) {
        fps = frameCount / this->delta;
        std::cout << "FPS: " << fps << "\n";
        frameCount = 0;
        this->delta -= 1.0 / updateRate;
    }
}

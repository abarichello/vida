#pragma once

#include <m3dia.hpp>

struct FPS {
    FPS();
    void update(float delta);

    std::string text;
    bool printFPS = true;

private:
    const int updateRate = 3;
    int frameCount = 0;
    float delta = 0.0f;
    float fps = 0.0f;
};

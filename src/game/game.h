#pragma once

#include <m3dia.hpp>
#include <iostream>

#include "game/board.h"
#include "util/console.h"
#include "util/util.h"

class Game {
public:
    Game();

    void startup();
    void run();
    void update(float delta);
    void draw();

    m3d::Applet app;
    m3d::Screen screen;

    Board board;

private:
#ifdef DEBUG
    Console console;
    FPS fps;
#endif
};

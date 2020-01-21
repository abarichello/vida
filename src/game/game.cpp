#include "game/game.h"

Game::Game() : board() {
    startup();
}

void Game::startup() {
    auto topRes = Util::getScreenResolution(m3d::RenderContext::ScreenTarget::Top);
    text.setPosition(topRes.u / 2, topRes.v / 4);

    std::cout << "Start game\n";
    std::cout << "2DS: " << app.is2ds() << "\nBattery level: " << app.getBatteryLevel() << "\n";
    std::cout << topRes.u << " " << topRes.v << "\n";

#ifdef DEBUG
    console.setDebugConsole();
#endif
}

void Game::run() {
    m3d::Clock clock;
    clock.start();

    while (app.isRunning()) {
        float delta = clock.getTime().getAsSeconds();
        clock.reset();
        clock.start();
        update(delta);
        draw();
    }
}

void Game::update(float delta) {
    if (m3d::buttons::buttonPressed(m3d::buttons::Start)) {
        app.exit();
    }

    auto& camera = screen.getCamera(m3d::RenderContext::ScreenTarget::Top);
    board.update(camera, delta);
#ifdef DEBUG
    if (m3d::buttons::buttonDown(m3d::buttons::Select) && m3d::buttons::buttonPressed(m3d::buttons::A)) {
        console.toggleConsole();
    }
#endif
}

void Game::draw() {
    board.draw(screen);

    screen.drawTop(text);
    screen.render();
}

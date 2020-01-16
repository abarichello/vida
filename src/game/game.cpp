#include "game/game.h"

Game::Game() {
    startup();
}

void Game::startup() {
    auto topRes = Util::getScreenResolution(m3d::RenderContext::ScreenTarget::Top);
    text.setPosition(topRes.u / 2, topRes.v / 4);

    std::cout << "Start game\n";
    std::printf("2DS: %d\nBattery Level: %d", app.is2ds(), app.getBatteryLevel());
    std::cout << topRes.u << " " << topRes.v << "\n";
}

void Game::run() {
    while (app.isRunning()) {
        update();
        draw();
    }
}

void Game::update() {
    if (m3d::buttons::buttonPressed(m3d::buttons::Start)) {
        app.exit();
    }

    // --- Debug ---
    if (m3d::buttons::buttonPressed(m3d::buttons::A)) {
        printf("%d\n", app.getCurrentFrame());
    }
#ifdef DEBUG
    console.setDebugConsole();
    if (m3d::buttons::buttonDown(m3d::buttons::Select) && m3d::buttons::buttonPressed(m3d::buttons::A)) {
        console.toggleConsole();
    }
#endif
}

void Game::draw() {
    screen.drawTop(text);
    screen.render();
}

#include <m3dia.hpp>

#include "util/util.h"
#include "util/console.h"

int main() {
    m3d::Applet app;
    m3d::Screen screen;
#ifdef DEBUG
    Console console;
    console.setDebugConsole();
#endif

    auto text = m3d::Text("VIDA");
    auto topRes = Util::getScreenResolution(m3d::RenderContext::ScreenTarget::Top);
    text.setPosition(topRes.u / 2, topRes.v / 4);
    printf("%f %f\n", topRes.u, topRes.v);

    while (app.isRunning()) {
        if (m3d::buttons::buttonPressed(m3d::buttons::Start)) {
            app.exit();
        }
        if (m3d::buttons::buttonPressed(m3d::buttons::A)) {
            screen.clear();
            printf("%d\n", app.getCurrentFrame());
        }
#ifdef DEBUG
        if (m3d::buttons::buttonDown(m3d::buttons::Select) && m3d::buttons::buttonPressed(m3d::buttons::A)) {
            console.toggleConsole();
        }
#endif

        screen.drawTop(text);
        screen.render();
    }
    return 0;
}

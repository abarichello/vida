#include <m3dia.hpp>
#include "util/util.h"

int main() {
    m3d::Applet app;
    m3d::Screen screen;

    auto text = m3d::Text("VIDA");
    auto topRes = Util::getScreenResolution(m3d::RenderContext::ScreenTarget::Top);
    text.setPosition(topRes.u / 2, topRes.v / 2);

    while (app.isRunning()) {
        if (m3d::buttons::buttonPressed(m3d::buttons::Start)) {
            app.exit();
        }

        screen.drawTop(text);
        screen.drawBottom(text);
        screen.render();
    }
    return 0;
}

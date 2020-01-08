#include <m3dia.hpp>

int main() {
    m3d::Applet app;

    while (app.isRunning()) {
        if (m3d::buttons::buttonPressed(m3d::button::Start)) {
            app.exit();
        }
    }
}

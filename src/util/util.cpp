#include "util.h"

m3d::Vector2f Util::getScreenResolution(m3d::RenderContext::ScreenTarget screen) {
    switch (screen) {
        case m3d::RenderContext::ScreenTarget::Top:
            return m3d::Vector2f{(float)m3d::Screen::getScreenWidth(m3d::RenderContext::ScreenTarget::Top),
                                 (float)m3d::Screen::getScreenHeight()};
        case m3d::RenderContext::ScreenTarget::Bottom:
            return m3d::Vector2f{(float)m3d::Screen::getScreenWidth(m3d::RenderContext::ScreenTarget::Bottom),
                                 (float)m3d::Screen::getScreenHeight()};
        default:
            return m3d::Vector2f{0, 0};
    }
}

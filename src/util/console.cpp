#include "util/console.h"
#include "util/util.h"

Console::Console() : console(consoleGetDefault()) {
    this->startConsole();
}

void Console::startConsole() {
    consoleInit(GFX_BOTTOM, consoleGetDefault());
}

void Console::setDebugConsole() {
    console->fg = 9;
    console->bg = 0;
}

void Console::toggleConsole() {
    if (hidden) {
        consoleSelect(consoleGetDefault());
    } else {
        consoleClear();
        consoleSelect(NULL);
    }
    hidden = !hidden;
}

bool Console::active() const {
    return !hidden;
}

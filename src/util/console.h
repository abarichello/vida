#pragma once

#include <m3dia.hpp>
#include <memory>

class Console {
public:
    Console();

    void startConsole();
    void setDebugConsole();
    void toggleConsole();

    bool active() const;

    std::unique_ptr<PrintConsole> console;
    bool hidden = false;
};

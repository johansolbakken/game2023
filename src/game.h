#pragma once

#include "window.h"

#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void processEvents();
    void update();
    void render();

private:
    bool m_running = true;
    std::unique_ptr<Window> m_window;
};

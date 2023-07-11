#pragma once

#include "window.h"
#include "mesh.h"
#include "camera2d.h"

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
    std::unique_ptr<Mesh> m_mesh;
	std::unique_ptr<Camera2D> m_camera;

};

#include "game.h"

#include "renderer.h"

#include <glm/gtc/matrix_transform.hpp>

Game::Game()
{
    m_window = std::make_unique<Window>();

    m_mesh = std::make_unique<Mesh>("models/2CylinderEngine.gltf");

    Renderer::init();
    Renderer::updateViewport(800, 600);
}

Game::~Game()
{
}

void Game::run()
{
    while (m_running)
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    m_running = !m_window->shouldClose();
}

void Game::update()
{
}

void Game::render()
{
    Renderer::clear({0.2f, 0.3f, 0.3f, 1.0f});

    Renderer::drawQuad({0.0f, 0.0f}, {0.5f, 0.5f}, {1.0f, 0.0f, 0.0f, 1.0f});

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.005f));

    Renderer::drawMesh(*m_mesh, modelMatrix);

    m_window->update();
}
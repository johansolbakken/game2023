#include "game.h"

#include "renderer/renderer.h"

Game::Game()
{
	m_window = std::make_unique<Window>();
	m_camera = std::make_unique<Camera2D>();
	m_camera->init(800, 600);

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
	Renderer::clear({ 0.2f, 0.3f, 0.3f, 1.0f });

	Renderer::beginScene(m_camera->getCameraMatrix());
	Renderer::drawQuad({ 0.0f, 0.0f }, { 0.5f, 0.5f }, { 1.0f, 0.0f, 0.0f, 1.0f });
	Renderer::endScene();

	m_window->update();
}
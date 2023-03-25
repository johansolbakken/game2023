#include "game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::run()
{
    while (true)
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
}

void Game::update()
{
}

void Game::render()
{
}
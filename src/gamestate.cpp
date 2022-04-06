#include "gamestate.h"
GameState::GameState(Game* game)
{
    this->game = game;
}

GameState::~GameState()
{
}
void GameState::setWindow(sf::RenderWindow* window)
{
    m_window = window;
}

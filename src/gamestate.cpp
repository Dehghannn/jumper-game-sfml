#include "gamestate.h"
GameState::GameState(Game* game, sf::RenderWindow* window)
{
    this->game = game;
    this->m_window = window;
}

GameState::~GameState()
{
}
void GameState::setWindow(sf::RenderWindow* window)
{
    m_window = window;
}

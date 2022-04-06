#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Game;
/**
 * @brief GameState class is an interface for all game states
 * 
 */
class GameState
{
private:
    /* data */
public:
    GameState(Game* game);
    ~GameState();
    virtual void draw() = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void handleInputPress(sf::Keyboard::Key key) = 0;
    virtual void handleInputRelease(sf::Keyboard::Key key) = 0;    
    virtual void setSpeedScaleFactor(float newSSF) = 0;
    virtual void setWindow(sf::RenderWindow* window);
protected:
    sf::RenderWindow *m_window; /// a pointer to the main window in the game
    Game* game;

};


#pragma once
#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "game.h"
#include <iostream>
class OverState : public GameState
{
private:
    /* data */
public:
    OverState(Game* game, sf::RenderWindow* window);
    ~OverState();

    void draw() override;
    void update(sf::Time delta) override;
    void handleInputPress(sf::Keyboard::Key key) override;
    void handleInputRelease(sf::Keyboard::Key key) override;    
    void setSpeedScaleFactor(float newSSF) override;
    void setWindow(sf::RenderWindow* window) override;

private:
    sf::Font m_font;

    sf::Text m_scoreText;
    sf::Text m_helpText1;
    sf::Text m_helpText2;


    std::vector<sf::Text> texts;

};


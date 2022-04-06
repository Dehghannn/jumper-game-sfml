#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "entity.h"
#include "game.h"
class Game;

class StartState: public GameState
{
private:
    /* data */
public:
    StartState(Game* game);
    ~StartState();
    void draw() override;
    void update(sf::Time delta) override;
    void handleInputPress(sf::Keyboard::Key key) override;
    void handleInputRelease(sf::Keyboard::Key key) override;
    void setSpeedScaleFactor(float newSSF) override;
    ///overriding set window because we have entities in this state that need their window to be set
    void setWindow(sf::RenderWindow* window) override;

private:
    std::vector<std::shared_ptr<Entity> > m_entities; /// all the entities in this state
    sf::Font m_font;
    sf::Text m_text;
    sf::Clock m_clock;
    sf::Time m_TextAnimationTime;
    bool m_isStarted = false;
    bool m_showText = true;
    void startTextAnimation();
};



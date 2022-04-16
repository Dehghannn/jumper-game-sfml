#pragma once
#include <iostream>
#include <memory>
#include "gamestate.h"
#include "entity.h"
#include "jumper.h"
#include "trophy.h"
class Game;
/**
 * @brief PlayState is a state of the game in wich player(s) actually are playing the game
 * 
 */
class PlayState : public GameState
{
private:
    /* data */
public:
    PlayState(Game* game);
    ~PlayState();
    void draw() override;
    void update(sf::Time delta) override;
    void handleInputPress(sf::Keyboard::Key key) override;
    void handleInputRelease(sf::Keyboard::Key key) override;
    void setSpeedScaleFactor(float newSSF) override;
    ///overriding set window because we have entities in this state that need their window to be set
    void setWindow(sf::RenderWindow* window) override;

private:
    std::vector<std::shared_ptr<Entity> > m_entities; /// all the entities in this state
    sf::Text m_scoreText;
    sf::Text m_timeText;
    sf::Font m_font;
    int m_score = 23;
    sf::Clock m_gameClock;
    int m_remainingTime = 60;
};


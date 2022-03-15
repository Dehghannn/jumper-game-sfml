#pragma once
#include <iostream>
#include <memory>
#include "gamestate.h"
#include "entity.h"
#include "jumper.h"
/**
 * @brief PlayState is a state of the game in wich player(s) actually are playing the game
 * 
 */
class PlayState : public GameState
{
private:
    /* data */
public:
    PlayState(/* args */);
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
};


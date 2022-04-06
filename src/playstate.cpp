#include "playstate.h"

PlayState::PlayState(Game* game): GameState(game)
{

    //creating entities
    std::shared_ptr<Entity> jumper = std::make_shared<Jumper>();
    m_entities.push_back(jumper);

    std::shared_ptr<Entity> jumper2 = std::make_shared<Jumper>();
    m_entities.push_back(jumper2);
    
}

PlayState::~PlayState()
{
}
void PlayState::draw()
{
    ///draw all the entities in the state
    if(!m_window)
    {
        return;
    }
    for(auto entity : m_entities)
    {
        entity->draw();
    }
}
void PlayState::update(sf::Time delta)
{
    ///update all the entities in the state
    for(auto entity : m_entities)
    {
        entity->update(delta);
    }
}
void PlayState::handleInputPress(sf::Keyboard::Key key)
{
    //temp 
    m_entities.at(0)->handleInputPress(key);
}
void PlayState::handleInputRelease(sf::Keyboard::Key key)
{
    //temp 
    m_entities.at(0)->handleInputRelease(key);

}
void PlayState::setSpeedScaleFactor(float newSSF)
{
    for(auto entity : m_entities)
    {
        entity->setSpeedScaleFactor(newSSF);
    }
}
void PlayState::setWindow(sf::RenderWindow* window)
{
    m_window = window;
    for(auto entity : m_entities)
    {
        entity->setWindow(window);
    }
}

#include "trophy.h"
Trophy::Trophy(/* args */)
{
    this->m_entityTexture.loadFromFile(assets_path + "/bubble.png");
    this->m_entitySprite.setTexture(m_entityTexture);
    //this->m_entitySprite.scale(sf::Vector2f(0.2, 0.2));
    this->m_entitySprite.setScale(0.03, 0.03);
    this->m_entitySprite.setPosition(200, 300);
}
void Trophy::draw()
{
    m_window->draw(m_entitySprite);
}
void Trophy::update(sf::Time delta)
{
}
void Trophy::move(sf::Time delta){}
void Trophy::handleInputPress(sf::Keyboard::Key key){}
void Trophy::handleInputRelease(sf::Keyboard::Key key){}



#include "entity.h"

Entity::Entity(/* args */)
{
}

Entity::~Entity()
{
}
void Entity::setWindow(sf::RenderWindow *window)
{
    m_window = window;
    m_windowHeight = m_window->getSize().y;
    m_windowWidth = m_window->getSize().x;
    verticalCollisionY = (m_windowHeight - 60 - m_entitySprite.getLocalBounds().height/2);
    std::cout << "new window set to Entity with size of " << m_windowWidth << " x " << m_windowHeight << std::endl;
}
void Entity::draw()
{
    m_window->draw(m_entitySprite);
}
void Entity::move(sf::Time delta)
{
    m_y += (m_verticalSpeed * m_speedScaleFactor) * delta.asMilliseconds();
    if(m_y >= verticalCollisionY)
    {
        m_y = verticalCollisionY;
        m_verticalSpeed *= 0.8f;
        m_verticalSpeed = - (m_verticalSpeed);
    }
    if(m_y < -100.f)
    {
        m_y = -100.f;
    }
    if(!m_downIsPressed && !m_upIsPressed)
    {
        m_verticalSpeed += m_verticalAcceleration;
    }
        

    m_x += (m_horizontalSpeed * m_speedScaleFactor) * delta.asMilliseconds();
    if((m_horizontalSpeed > 0 && !m_rightIsPressed) || (m_horizontalSpeed < 0 && !m_leftIsPressed))
    {
        m_horizontalSpeed *= 0.97f;
    }
    if(m_x - m_entitySprite.getLocalBounds().width/2 <= 0)
    {
        m_x = m_entitySprite.getLocalBounds().width/2;
    }else if(m_x + m_entitySprite.getLocalBounds().width/2 >= m_windowWidth)
    {
        m_x = m_windowWidth - m_entitySprite.getLocalBounds().width/2;
    }
    m_entitySprite.setPosition(m_x, m_y);
    m_verticalAcceleration = 0.01f * delta.asMilliseconds();
}
void Entity::setVerticalAcceleration(float newVerticalAcc)
{

}
void Entity::setSpeedScaleFactor(float newSSF)
{
    m_speedScaleFactor = newSSF;
    m_verticalAcceleration *= m_speedScaleFactor;
}
void Entity::setVerticalSpeed(float newVerticalSpeed)
{
    m_verticalSpeed = newVerticalSpeed;
}
void Entity::update(sf::Time delta)
{
    move(delta);
    m_delta = delta;
    //m_verticalSpeed *= delta.asSeconds();
    //m_horizontalSpeed *= delta.asSeconds();
}
void Entity::jump()
{
    std::cout << "last frame time : " << m_delta.asMicroseconds() << std::endl;
    setVerticalSpeed(-2);
}
void Entity::handleInputPress(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Space :
        jump();
        /* code */
        break;
    case sf::Keyboard::Right :
        moveRight();
        break;
    case sf::Keyboard::Left :
        moveLeft();
        break;
    case sf::Keyboard::Up :
        moveUp();
        break;
    case sf::Keyboard::Down :
        moveDown();
        break;
    default:
        break;
    }
}
void Entity::handleInputRelease(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Right :
        m_rightIsPressed = false;
        break;
    case sf::Keyboard::Left :
        m_leftIsPressed = false;
        break;
    case sf::Keyboard::Up : 
        m_upIsPressed = false;
        break;
    case sf::Keyboard::Down : 
        m_downIsPressed = false;
        break;
    default:
        break;
    }
}
void Entity::moveRight()
{
    m_horizontalSpeed = 1.f;
    m_rightIsPressed = true;
}
void Entity::moveLeft()
{
    m_horizontalSpeed = -1.f;
    m_leftIsPressed = true;
}
void Entity::moveUp()
{
    m_verticalSpeed = -1.f;
    m_upIsPressed = true;
}
void Entity::moveDown()
{
    m_verticalSpeed = 1.f;
    m_downIsPressed = true;
}
void Entity::setPosition(int x, int y)
{
    m_entitySprite.setPosition(x, y);
}

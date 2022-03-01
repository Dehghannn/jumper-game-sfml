#include "jumper.h"
sf::Texture Jumper::m_jumperTexture;
Jumper::Jumper()
{
    m_jumperTexture.loadFromFile("../assets/jumper.png");
    m_jumperTexture.setSmooth(true);
    m_jumperSprite.setTexture(m_jumperTexture);
    m_jumperSprite.setScale(0.08f, 0.08f);

    m_verticalAcceleration = 0.008;
    m_verticalSpeed = -3;

    m_x = 400;
    m_y = 140;
    m_jumperSprite.setPosition(m_x, m_y);
}
void Jumper::draw(sf::RenderWindow *window)
{
    window->draw(m_jumperSprite);
}
void Jumper::move()
{
    m_y += m_verticalSpeed;
    if(m_y >= verticalCollisionY)
    {
        m_y = verticalCollisionY;
        m_verticalSpeed *= 0.7;
        m_verticalSpeed = - (m_verticalSpeed);
    }
    m_jumperSprite.setPosition(m_x, m_y);
}
void Jumper::setVerticalAcceleration(float newVerticalAcc)
{

}
void Jumper::setVerticalSpeed(float newVerticalSpeed)
{
    m_verticalSpeed = newVerticalSpeed;
}
void Jumper::setVerticalDirection(bool newDirection){}
void Jumper::update()
{
    move();
    m_verticalSpeed += m_verticalAcceleration;
}
void Jumper::jump()
{
    std::cout << "jumped" << std::endl;
    setVerticalSpeed(-2);
}
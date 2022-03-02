#include "jumper.h"
sf::Texture Jumper::m_jumperTexture;
Jumper::Jumper()
{
    m_jumperTexture.loadFromFile(assets_path + "/jumper.png");
    m_jumperTexture.setSmooth(true);
    m_jumperSprite.setTexture(m_jumperTexture);
    m_jumperSprite.setScale(0.08f, 0.08f);

    verticalCollisionY = (m_windowHeight - 80 - 130);

    m_verticalAcceleration = 0.005;
    m_verticalSpeed = -3;

    m_horizontalSpeed = 0;

    m_x = m_windowWidth / 2;
    m_y = m_windowHeight / 3;
    m_jumperSprite.setPosition(m_x, m_y);
}
void Jumper::setWindow(sf::RenderWindow *window)
{
    m_window = window;
    m_windowHeight = m_window->getSize().y;
    m_windowWidth = m_window->getSize().x;
    verticalCollisionY = m_windowHeight - 80 - 130;
    std::cout << "new window set to jumper with size of " << m_windowWidth << " x " << m_windowHeight << std::endl;
}
void Jumper::draw()
{
    m_window->draw(m_jumperSprite);
}
void Jumper::move()
{
    m_y += (m_verticalSpeed * m_speedScaleFactor);
    if(m_y >= verticalCollisionY)
    {
        m_y = verticalCollisionY;
        m_verticalSpeed *= 0.7;
        m_verticalSpeed = - (m_verticalSpeed);
    }
    if(m_y < -100)
    {
        m_y = -100;
    }

    m_x += (m_horizontalSpeed * m_speedScaleFactor);
    if((m_horizontalSpeed > 0 && !m_rightIsPressed) || (m_horizontalSpeed < 0 && !m_leftIsPressed))
    {
        m_horizontalSpeed *= 0.97;
    }
    if(m_x <= -50)
    {
        m_x = -50;
    }else if(m_x >= (m_windowWidth - 50))
    {
        m_x = m_windowWidth - 50;
    }
    m_jumperSprite.setPosition(m_x, m_y);
}
void Jumper::setVerticalAcceleration(float newVerticalAcc)
{

}
void Jumper::setSpeedScaleFactor(float newSSF)
{
    m_speedScaleFactor = newSSF;
    m_verticalAcceleration *= m_speedScaleFactor;
}
void Jumper::setVerticalSpeed(float newVerticalSpeed)
{
    m_verticalSpeed = newVerticalSpeed;
}
void Jumper::update()
{
    move();
    m_verticalSpeed += m_verticalAcceleration;
}
void Jumper::jump()
{
    //std::cout << "jumped" << std::endl;
    setVerticalSpeed(-1.5);
}
void Jumper::handleInputPress(sf::Keyboard::Key key)
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
    default:
        break;
    }
}
void Jumper::handleInputRelease(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Right :
        m_rightIsPressed = false;
        break;
    case sf::Keyboard::Left :
        m_leftIsPressed = false;
        break;
    default:
        break;
    }
}
void Jumper::moveRight()
{
    m_horizontalSpeed = 1;
    m_rightIsPressed = true;
}
void Jumper::moveLeft()
{
    m_horizontalSpeed = -1;
    m_leftIsPressed = true;
}

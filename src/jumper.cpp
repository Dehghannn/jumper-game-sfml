#include "jumper.h"
sf::Texture Jumper::m_jumperTexture;
Jumper::Jumper()
{
    m_jumperTexture.loadFromFile(assets_path + "/jumper2.png");
    m_jumperTexture.setSmooth(true);
    m_jumperSprite.setTexture(m_jumperTexture);
    // m_jumperSprite.setScale(0.08f, 0.08f);
    //m_jumperSprite.setScale(1, 1);
    //m_jumperSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    m_jumperSprite.setOrigin(sf::Vector2f(m_jumperSprite.getLocalBounds().width/2, m_jumperSprite.getLocalBounds().height/2));
    std::cout << m_jumperSprite.getLocalBounds().height << std::endl;
    std::cout << m_jumperSprite.getOrigin().x << " " << m_jumperSprite.getOrigin().y << std::endl;
    std::cout << m_windowHeight << std::endl;
    verticalCollisionY = (m_windowHeight - 60 - m_jumperSprite.getLocalBounds().height/2);

    m_verticalAcceleration = 0.1;
    m_verticalSpeed = 0;

    m_horizontalSpeed = 0;

    m_x = m_windowWidth / 2;
    m_y = m_windowHeight / 3;
    m_y = verticalCollisionY;
    m_jumperSprite.setPosition(m_x, m_y);
}
void Jumper::setWindow(sf::RenderWindow *window)
{
    m_window = window;
    m_windowHeight = m_window->getSize().y;
    m_windowWidth = m_window->getSize().x;
    verticalCollisionY = (m_windowHeight - 60 - m_jumperSprite.getLocalBounds().height/2);
    std::cout << "new window set to jumper with size of " << m_windowWidth << " x " << m_windowHeight << std::endl;
}
void Jumper::draw()
{
    m_window->draw(m_jumperSprite);
}
void Jumper::move(sf::Time delta)
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

    m_x += (m_horizontalSpeed * m_speedScaleFactor) * delta.asMilliseconds();
    if((m_horizontalSpeed > 0 && !m_rightIsPressed) || (m_horizontalSpeed < 0 && !m_leftIsPressed))
    {
        m_horizontalSpeed *= 0.97f;
    }
    if(m_x - m_jumperSprite.getLocalBounds().width/2 <= 0)
    {
        m_x = m_jumperSprite.getLocalBounds().width/2;
    }else if(m_x + m_jumperSprite.getLocalBounds().width/2 >= m_windowWidth)
    {
        m_x = m_windowWidth - m_jumperSprite.getLocalBounds().width/2;
    }
    m_jumperSprite.setPosition(m_x, m_y);
    m_verticalAcceleration = 0.01f * delta.asMilliseconds();
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
void Jumper::update(sf::Time delta)
{
    move(delta);
    m_verticalSpeed += m_verticalAcceleration;
    m_delta = delta;
    //m_verticalSpeed *= delta.asSeconds();
    //m_horizontalSpeed *= delta.asSeconds();
}
void Jumper::jump()
{
    std::cout << "last frame time : " << m_delta.asMicroseconds() << std::endl;
    setVerticalSpeed(-2);
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
    m_horizontalSpeed = 1.f;
    m_rightIsPressed = true;
}
void Jumper::moveLeft()
{
    m_horizontalSpeed = -1.f;
    m_leftIsPressed = true;
}

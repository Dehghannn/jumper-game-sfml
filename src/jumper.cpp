#include "jumper.h"

Jumper::Jumper()
{
    m_entityTexture.loadFromFile(assets_path + "/jumper2.png");
    m_entityTexture.setSmooth(true);
    m_entitySprite.setTexture(m_entityTexture);
    // m_entitySprite.setScale(0.08f, 0.08f);
    //m_entitySprite.setScale(1, 1);
    //m_entitySprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    m_entitySprite.setOrigin(sf::Vector2f(m_entitySprite.getLocalBounds().width/2, m_entitySprite.getLocalBounds().height/2));
    std::cout << m_entitySprite.getLocalBounds().height << std::endl;
    std::cout << m_entitySprite.getOrigin().x << " " << m_entitySprite.getOrigin().y << std::endl;
    std::cout << m_windowHeight << std::endl;
    verticalCollisionY = (m_windowHeight - 60 - m_entitySprite.getLocalBounds().height/2);

    m_verticalAcceleration = 0.1;
    m_verticalSpeed = 0;

    m_horizontalSpeed = 0;

    m_x = m_windowWidth / 2;
    m_y = m_windowHeight / 3;
    m_y = verticalCollisionY;
    m_entitySprite.setPosition(m_x, m_y);
}

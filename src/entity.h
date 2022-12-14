#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * This class is an interface for all entities in the game
**/
class Entity
{
public:
    Entity(/* args */);
    ~Entity();
    virtual void draw();
    virtual void move(sf::Time delta);
    virtual void update(sf::Time delta);
    virtual void handleInputPress(sf::Keyboard::Key key);
    virtual void handleInputRelease(sf::Keyboard::Key key);

    void setVerticalAcceleration(float newAcc);
    void setVerticalSpeed(float newVerticalSpeed);
    void setWindow(sf::RenderWindow* window);
    void setSpeedScaleFactor(float newSSF);
    void setPosition(int x, int y);

    protected:
    sf::Texture m_entityTexture;
    sf::Sprite m_entitySprite;

    float m_verticalSpeed;
    float m_horizontalSpeed;
    float m_x;
    float m_y;
    float m_verticalAcceleration;
    float m_speedScaleFactor = 1;
    int verticalCollisionY;

    int m_windowWidth = 800;
    int m_windowHeight = 600;

    bool m_leftIsPressed = false;
    bool m_rightIsPressed = false;
    bool m_upIsPressed = false;
    bool m_downIsPressed = false;

    sf::Time m_delta = sf::Time::Zero;
    sf::RenderWindow *m_window;

    protected:
    virtual void jump();
    virtual void moveRight();
    virtual void moveLeft();
    virtual void moveUp();
    virtual void moveDown();


};


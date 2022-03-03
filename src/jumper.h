#pragma once
#include <iostream>
#include <numeric>
#include <SFML/Graphics.hpp> 
#include "defs.h"
class Jumper{
    public:
    Jumper();
    void draw();
    void move();
    void setVerticalAcceleration(float newAcc);
    void setVerticalSpeed(float newVerticalSpeed);
    void update(sf::Time delta);
    void handleInputPress(sf::Keyboard::Key key);
    void handleInputRelease(sf::Keyboard::Key key);
    void setWindow(sf::RenderWindow* window);
    void setSpeedScaleFactor(float newSSF);

    private:
    static sf::Texture m_jumperTexture;
    sf::Sprite m_jumperSprite;

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

    sf::Time m_delta = sf::Time::Zero;

    void jump();
    void moveRight();
    void moveLeft();

    sf::RenderWindow *m_window;


};

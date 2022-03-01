#pragma once
#include <iostream>
#include <SFML/Graphics.hpp> 
class Jumper{
    public:
    Jumper();
    void draw(sf::RenderWindow * window);
    void move();
    void setVerticalDirection(bool newDirection);
    void setVerticalAcceleration(float newAcc);
    void setVerticalSpeed(float newVerticalSpeed);
    void update();
    void jump();

    private:
    static sf::Texture m_jumperTexture;
    sf::Sprite m_jumperSprite;

    float m_verticalSpeed;
    bool m_verticalDirection;
    float m_horizontalSpeed;
    bool m_horizontalDirection;
    float m_x;
    float m_y;
    float m_verticalAcceleration;
    const int verticalCollisionY = 330;

};
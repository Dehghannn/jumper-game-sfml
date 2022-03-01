#pragma once
#include <SFML/Graphics.hpp>
#include "jumper.h"
class Game{

    public:
    Game();
   // ~Game();

    enum State{
        Notstarted,
        Started,
        count
    };
    sf::Texture& backGround() const;
    void setBackGround(sf::Texture newBackGround);

    void run();

    private:
    sf::RenderWindow m_window;

    bool m_gameStarted;
    sf::Texture m_backGroundTexture;
    sf::Sprite m_backGroundSprite;

    sf::Sprite m_groundSprite;
    sf::Texture m_groundTexture;

    Jumper m_jumper;

};
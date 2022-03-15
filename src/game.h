#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "playstate.h"
#include "defs.h"

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


    std::array<std::shared_ptr<GameState>, 4> m_gameStates; /// four game states in this game
    std::shared_ptr<GameState> m_currentStatePtr; /// pointer to the current state of the game

};

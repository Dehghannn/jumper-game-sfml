#include "game.h"
Game::Game():m_window(sf::VideoMode(800, 600), "Jumper")
{
    m_gameStarted = 0; // game is not started by default!

    //init background
    m_backGroundTexture.loadFromFile("../assets/background.jpg", sf::IntRect(0, 0, 800, 600));
    m_backGroundSprite.setTexture(m_backGroundTexture);

    m_groundTexture.loadFromFile("../assets/ground.png");
    m_groundTexture.setSmooth(true);
    m_groundTexture.setRepeated(true);
    m_groundSprite.setScale(1.11f, 0.823f);
    m_groundSprite.setTexture(m_groundTexture);
    m_groundSprite.setPosition(0, m_window.getSize().y - 140);

}
void Game::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            /* code */
            if(event.type == sf::Event::Closed)
            {
                m_window.close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space){
                    m_jumper.jump();
                }
            }
        }
        
        m_window.clear();
        m_window.draw(m_backGroundSprite);
        m_window.draw(m_groundSprite);
        m_jumper.draw(&m_window);
        m_jumper.update();
        m_window.display();
    }
}
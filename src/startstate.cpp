#include "startstate.h"

StartState::StartState(Game* game): GameState(game)
{
    //load font here
    m_font.loadFromFile("/home/dehghannn/.fonts/SourceCodePro-Black.otf");
    m_text.setFont(m_font);
    m_text.setString("Press any button to start");
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(32);
    startTextAnimation();
}

StartState::~StartState()
{
}
void StartState::draw()
{
    ///draw all the entities in the state
    if(!m_window)
    {
        return;
    }
    for(auto entity : m_entities)
    {
        entity->draw();
        
    }
    if(m_showText)
    {
        m_window->draw(m_text);
    }
}
void StartState::update(sf::Time delta)
{
    ///update all the entities in the state
    for(auto entity : m_entities)
    {
        entity->update(delta);
    }
    m_TextAnimationTime = m_clock.getElapsedTime();
    if(m_TextAnimationTime.asMilliseconds() > 500)
    {
        m_showText = !m_showText;
        m_clock.restart();
        std::cout << m_showText;
    }

}
void StartState::handleInputPress(sf::Keyboard::Key key)
{
    //temp 
    //change game state here
    game->changeGameState(Game::State::Started);
}
void StartState::handleInputRelease(sf::Keyboard::Key key)
{
    //temp 
    

}
void StartState::setSpeedScaleFactor(float newSSF)
{
    for(auto entity : m_entities)
    {
        entity->setSpeedScaleFactor(newSSF);
    }
}
void StartState::setWindow(sf::RenderWindow* window)
{
    m_window = window;

    m_text.setPosition(m_window->getSize().x / 3, m_window->getSize().y * 2 / 3);
    for(auto entity : m_entities)
    {
        entity->setWindow(window);
    }
}
void StartState::startTextAnimation()
{
    if(m_isStarted == false)
    {
        m_clock.restart();
        m_isStarted = true;
    }
}
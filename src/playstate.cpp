#include "playstate.h"

PlayState::PlayState(Game* game, sf::RenderWindow* window): GameState(game, window)
{

    //creating entities
    std::shared_ptr<Entity> jumper = std::make_shared<Jumper>();
    m_entities.push_back(jumper);

    // std::shared_ptr<Entity> jumper2 = std::make_shared<Jumper>();
    // m_entities.push_back(jumper2);

    std::shared_ptr<Entity> trophy = std::make_shared<Trophy>();
    m_entities.push_back(trophy);

    m_font.loadFromFile("/home/dehghannn/.fonts/SourceCodePro-Black.otf");

    m_scoreText.setFont(m_font);
    m_timeText.setFont(m_font);
    m_scoreText.setString(std::to_string(m_score));
    m_timeText.setString(std::to_string(m_remainingTime));
    m_scoreText.setFillColor(sf::Color::White);
    m_timeText.setFillColor(sf::Color::White);
    m_scoreText.setCharacterSize(55);
    m_timeText.setCharacterSize(72);

    m_timeText.setPosition(m_window->getSize().x/2 - m_timeText.getLocalBounds().width / 2, 5);
    m_scoreText.setPosition(20, m_timeText.getPosition().y + m_timeText.getLocalBounds().height - m_scoreText.getLocalBounds().height);
    
}

PlayState::~PlayState()
{
}
void PlayState::draw()
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
    m_window->draw(m_scoreText);
    m_window->draw(m_timeText);
}
void PlayState::update(sf::Time delta)
{
    ///update all the entities in the state
    for(auto entity : m_entities)
    {
        entity->update(delta);
    }
    sf::Time elapsed = m_gameClock.getElapsedTime();
    if(elapsed.asMilliseconds() > 1000)
    {
        m_remainingTime--;
        m_gameClock.restart();
        m_timeText.setString(std::to_string(m_remainingTime));
    }
    m_scoreText.setString(std::to_string(m_score));
    if(m_remainingTime <= 10)
    {
        m_timeText.setFillColor(sf::Color::Red);
        if(m_remainingTime == 0)
        {
            //the game is set over in here
            game->setScore(m_score);
            this->game->changeGameState(Game::State::Over);
        } 
    }
}
void PlayState::handleInputPress(sf::Keyboard::Key key)
{
    //temp 
    m_entities.at(0)->handleInputPress(key);
}
void PlayState::handleInputRelease(sf::Keyboard::Key key)
{
    //temp 
    m_entities.at(0)->handleInputRelease(key);

}
void PlayState::setSpeedScaleFactor(float newSSF)
{
    for(auto entity : m_entities)
    {
        entity->setSpeedScaleFactor(newSSF);
    }
}
void PlayState::setWindow(sf::RenderWindow* window)
{
    m_window = window;
    for(auto entity : m_entities)
    {
        entity->setWindow(window);
    }

}

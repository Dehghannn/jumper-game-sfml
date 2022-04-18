#include "overstate.h"
OverState::OverState(Game* game, sf::RenderWindow* window):GameState(game, window)
{
    if(!m_font.loadFromFile("/home/dehghannn/.fonts/SourceCodePro-Black.otf"))
    {
        std::cout << "failed to open font file!" << std::endl;
        exit(1);
    }

    texts.push_back(m_scoreText);
    texts.push_back(m_helpText1);
    texts.push_back(m_helpText2);

    for(auto text : texts)
    {
        text.setFont(m_font);
        std::cout << "set font for the text" << std::endl;
    }

    m_scoreText.setCharacterSize(40);
    m_helpText1.setCharacterSize(30);
    m_helpText2.setCharacterSize(30);

    m_helpText1.setString("Time is up!");
    m_helpText2.setString("Press any button to restart");
    m_scoreText.setString("You're Score : " + std::to_string(game->getScore()));

    // m_scoreText.setFillColor(sf::Color::Green);
    // m_helpText1.setFillColor(sf::Color::Red);
    // m_helpText2.setFillColor(sf::Color::White);

    //m_scoreText.setPosition((m_window->getSize().x / 2) - (m_scoreText.getLocalBounds().width / 2), 200);
    m_scoreText.setPosition(100, 20);
    m_helpText1.setPosition((m_window->getSize().x / 2) - (m_helpText1.getLocalBounds().width / 2), 20);
    m_helpText2.setPosition((m_window->getSize().x / 2) - (m_helpText2.getLocalBounds().width / 2), 20);

    std::cout << m_window->getSize().x << "  " << m_window->getSize().y << std::endl;
}

OverState::~OverState()
{
}
void OverState::draw()
{
    m_scoreText.setString("Hello There");
    m_window->draw(m_scoreText);
    std::string s = m_scoreText.getString();
    std::cout << s << std::endl;
    for(auto text : texts)
    {
        m_window->draw(text);
        //std::string s = text.getString();
        //std::cout << "drew string : "  << s << std::endl;
    }
}
void OverState::update(sf::Time delta)
{

}
void OverState::handleInputPress(sf::Keyboard::Key key){}
void OverState::handleInputRelease(sf::Keyboard::Key key)
{
    game->setScore(0);
    game->changeGameState(Game::State::Notstarted);
}
void OverState::setSpeedScaleFactor(float newSSF){}
void OverState::setWindow(sf::RenderWindow* window)
{
    m_window = window;
}
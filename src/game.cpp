#include "game.h"
Game::Game():m_window(sf::VideoMode(1280, 720), "Jumper")
{
    m_gameStarted = 0; // game is not started by default!

    //init background
    m_backGroundTexture.loadFromFile(assets_path + "/background.jpg", sf::IntRect(0, 0, 1920, 1080));
    m_backGroundSprite.setTexture(m_backGroundTexture);
    m_backGroundSprite.setTextureRect(sf::IntRect(0, 0, m_window.getSize().x, m_window.getSize().y));

    m_groundTexture.loadFromFile(assets_path + "/ground.png");
    m_groundTexture.setSmooth(true);
    m_groundTexture.setRepeated(true);
    std::cout << "maximum ground texture size = " << m_groundTexture.getSize().x << " " << m_groundTexture.getSize().y << std::endl;
    //m_groundSprite.setScale(1.11f, 0.823f);
    m_groundSprite.setTextureRect(sf::IntRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_groundSprite.setTexture(m_groundTexture);
    m_groundSprite.setPosition(0, m_window.getSize().y - 80);


    //creating game states: 
    std::shared_ptr<GameState>  playState = std::make_shared<PlayState>(this, &m_window);
    playState->setWindow(&m_window);
    playState->setSpeedScaleFactor(m_window.getSize().x / 800);

    std::shared_ptr<GameState> startState = std::make_shared<StartState>(this, &m_window);
    startState->setWindow(&m_window);
    startState->setSpeedScaleFactor(m_window.getSize().x / 800);

    std::shared_ptr<GameState> overState = std::make_shared<OverState>(this, &m_window);
    overState->setSpeedScaleFactor(m_window.getSize().x / 800);

    m_gameStates[0] = playState;
    m_gameStates[1] = startState;
    m_gameStates[2] = overState;
    m_currentStatePtr = startState; ///set current state to play state

    // m_currentStatePtr.setWindow(&m_window);
    // m_currentStatePtr.setSpeedScaleFactor();

}
void Game::run()
{
    sf::Clock clock;
    sf::Time delta;
    while (m_window.isOpen())
    {
        delta = clock.restart();
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            /* code */
            if(event.type == sf::Event::Closed)
            {
                m_window.close();
            }
            if(event.type == sf::Event::EventType::KeyPressed)
            {
                m_currentStatePtr->handleInputPress(event.key.code);
            }
            if(event.type == sf::Event::EventType::KeyReleased)
            {
                m_currentStatePtr->handleInputRelease(event.key.code);
            }
        }
        
        m_window.clear();
        m_window.draw(m_backGroundSprite);
        m_window.draw(m_groundSprite);
        m_currentStatePtr->update(delta);
        m_currentStatePtr->draw();
        m_window.display();
        m_window.setFramerateLimit(60);
    }
}
void Game::changeGameState(State state)
{
    switch (state)
    {
    case Started:
        m_currentStatePtr = m_gameStates[0];
        break;
    case Notstarted:
        m_currentStatePtr = m_gameStates[1];
        break;
    case Over:
        m_currentStatePtr = m_gameStates[2];
        std::cout << "game state changed to Over" << std::endl;
        break;
    default:
        break;
    }
}

const int Game::getScore() const
{
    return m_score;
}
void Game::setScore(const int newScore)
{
    this->m_score = newScore;
}
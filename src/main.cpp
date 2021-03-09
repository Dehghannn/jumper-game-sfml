#include <iostream>
#include <typeinfo>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
int main()
{
  // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Close | sf::Style::Titlebar);

    sf::Font font;
    sf::Text text("Hello SFML", font, 50);

    sf::Image image;
    image.loadFromFile("assets/img.png");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Vector2<int> position(0, 0);


    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0,0);
    sprite.setScale(0.2, 0.2);

    sf::Sprite sprite2(texture);
    sprite2.setPosition(100,100);
    sprite2.setRotation(45);
    sprite2.setScale(0.2, 0.2);
 
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
			// Close window on Esc button pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
 
        // Draw the string
        window.draw(text);

        window.draw(sprite);
        window.draw(sprite2);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

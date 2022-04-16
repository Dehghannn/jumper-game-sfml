#include <iostream>
#include "entity.h"
#include "defs.h"
class Trophy : public Entity
{
private:
    /* data */
public:
    Trophy(/* args */);

    void draw() override;
    void move(sf::Time delta) override;
    void update(sf::Time delta) override;
    void handleInputPress(sf::Keyboard::Key key) override;
    void handleInputRelease(sf::Keyboard::Key key) override;
};


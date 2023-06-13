#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "cell.hpp"

class source
{
private:
    sf::CircleShape point;

public:
    source(/* args */);
    ~source();

    // Functions
    void setPosition(sf::Vector2f pos);
    void render(sf::RenderTarget* target);

    sf::Vector2f getPosition();
};

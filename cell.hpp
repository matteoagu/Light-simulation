#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <cmath>

class cell
{
private:
    sf::RectangleShape square;

public:
    cell();
    ~cell();

    // Functions
    void setPosition(sf::Vector2f pos);
    void setFillColor(float color);

    sf::RectangleShape& getBody();
    float distance(sf::Vector2f pos);
};

#include "cell.hpp"

cell::cell()
{
    square.setSize({1,1});
    square.setFillColor({static_cast<unsigned char>(127.5), static_cast<unsigned char>(127.5), static_cast<unsigned char>(127.5)});
}

cell::~cell()
{
}

// Functions
void cell::setPosition(sf::Vector2f pos)
{
    square.setPosition(pos);
}

void cell::setFillColor(float color)
{
    if (std::abs(color)>255) { throw std::runtime_error{"FATAL_ERROR: something was wrong in computing cells color!"}; }
    square.setFillColor({static_cast<unsigned char>(color), static_cast<unsigned char>(color), static_cast<unsigned char>(color)});
}

sf::RectangleShape& cell::getBody()
{
    return square;
}

float cell::distance(sf::Vector2f pos)
{
    float dx = square.getPosition().x - pos.x;
    float dy = square.getPosition().y - pos.y;

    return std::sqrt(dx*dx + dy*dy);
}

#include "source.hpp"

//Const & dest
source::source()
{
    point.setRadius(6.f);
    point.setFillColor(sf::Color::Red);
    point.setOrigin({6,6});
}

source::~source()
{
}

// Functions
void source::setPosition(sf::Vector2f pos)
{
    point.setPosition(pos);
}

void source::render(sf::RenderTarget *target)
{
    target->draw(point);
}

sf::Vector2f source::getPosition()
{
    return point.getPosition();
}

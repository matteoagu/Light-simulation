#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <iostream>
#include <cmath>

#include "cell.hpp"
#include "source.hpp"

class Grid
{
private:
    std::vector<std::vector<cell>> grid;
    sf::Vector2f WSize;

    // Private functions
    void initGrid();
    void computeCellsColor(std::vector<source> bulbs, float k);

public:
    Grid(sf::Vector2f window_size, std::vector<source>, float k);
    ~Grid();

    // Functions
    void render(sf::RenderTarget* target);
};
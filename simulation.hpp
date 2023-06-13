#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "source.hpp"
#include "cell.hpp"
#include "grid.hpp"

#include <array>

class Simulation {
private:
    sf::RenderWindow* window;
    std::vector<source> sources;
    Grid* grid;

    float k;
    unsigned int NSources;

    // Private Functions
    void initWindow();
    void initSources(unsigned int N);
    void initGrid();

public:
    Simulation();
    virtual ~Simulation();

    void updatePollEvents();

    // Functions
    void update();
    void render();
    void run();
};
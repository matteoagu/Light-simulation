#include "grid.hpp"

// Private functions

void Grid::initGrid()
{   
    // Fullfills the grid and sets the positions of all the cells
    std::vector<cell> line;
    cell point;

    for (unsigned int i{}; i<static_cast<unsigned int>(WSize.y); i++) {
        grid.push_back(line);

        for (unsigned int j{}; j<static_cast<unsigned int>(WSize.x); j++) {
            grid[i].push_back(point);

            grid[i][j].setPosition({static_cast<float>(j), static_cast<float>(i)});
        }
    }

    for (unsigned long int i{1}; i<grid.size(); i++) {
        if (grid[i].size() != grid[i-1].size()) { throw std::runtime_error{"FATAL ERROR: something was wrong with Grid::initGrid()"}; }
    }
}

void Grid::computeCellsColor(std::vector<source> bulbs, float k)
{
    for (long unsigned int i{}; i<grid.size(); i++) {
        for (auto& it : grid[i]) {
            std::vector<float> colors;
            float color{};

            for (long unsigned int n{}; n<bulbs.size(); n++) {
                colors.push_back(color);
                float r = it.distance(bulbs[n].getPosition());
                colors[n] = 127.5*(1 + std::cos(k*r)/(1 + std::pow(std::abs(r), 0.15)));
            }

            for (auto& it : colors) {color += it;}

            color /= bulbs.size();            
            it.setFillColor(color);
        }
    }
}

// Constructor & destructor
Grid::Grid(sf::Vector2f window_size, std::vector<source>SourceP, float k)
{
    WSize = window_size;
    initGrid();
    computeCellsColor(SourceP, k);
}

Grid::~Grid()
{
}

// Functions
void Grid::render(sf::RenderTarget *target)
{
    for (int i{}; i<grid.size(); i++) {
        for (auto& it : grid[i]) {
            target->draw(it.getBody());
        }
    }
}
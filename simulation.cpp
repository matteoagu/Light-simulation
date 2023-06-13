#include "simulation.hpp"

// Private functions
void Simulation::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(900,700), "Light simulation", sf::Style::Close | sf::Style::Titlebar);
    window->setPosition({400, 50});
    window->setFramerateLimit(144);
    window->setVerticalSyncEnabled(false);
    window->clear(sf::Color({static_cast<unsigned char>(127.5), static_cast<unsigned char>(127.5), static_cast<unsigned char>(127.5)}));
}

void Simulation::initSources(unsigned int N)
{
    std::cout << "The size of the window is 900x700\n";
    for (unsigned int i{}; i<N; i++) {
        sources.push_back(source());

        float x; float y;
        std::cout << "Choose the position of the " << i+1 << " source: ";
        std::cin >> x >> y;

        sources[i].setPosition({x,y});
    }
}

void Simulation::initGrid()
{
    sf::Vector2f size = {static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)};
    grid = new Grid(size, sources, k);
}

// Const & dest
Simulation::Simulation()
{
    std::cout << "Choose the wave number K: ";
    std:: cin >> k;
    std::cout << "Choose the number of sources: ";
    std::cin >> NSources;

    initSources(NSources);
    initWindow();
    initGrid();
}

Simulation::~Simulation()
{
    delete window;
    delete grid;
}


//Functions
void Simulation::updatePollEvents() {
    sf::Event ev;
    while(window->pollEvent(ev)) {
        if (ev.Event::type == sf::Event::Closed) { window->close(); }
        if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape) { window->close(); }
    }
}

void Simulation::update()
{
    updatePollEvents();
}

void Simulation::render()
{
    window->clear();

    grid->render(window);
    for (auto& it : sources) { it.render(window); }

    window->display();
}

void Simulation::run()
{
    while (window->isOpen()) {
        update();
        render();
    }
}

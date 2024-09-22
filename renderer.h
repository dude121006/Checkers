#pragma once
#include "SFML/Graphics.hpp"
#include "board.h"

class Renderer
{
private:

public:
    int boxSize;
    int numRows;

    std::vector<sf::RectangleShape> grid;

public:
    Renderer(Board& board);

    void render(sf::RenderWindow& window);
};


#include "renderer.h"

Renderer::Renderer(Board &board) : numRows(7), boxSize(200)
{
    grid.resize(numRows);

    for (int x = 0; x < numRows; x++)
    {
        grid[x].setSize(sf::Vector2f(boxSize, boxSize));
        grid[x].setPosition(sf::Vector2f(x * boxSize, 0));
        grid[x].setOutlineThickness(1.0f);
        grid[x].setOutlineColor(sf::Color::Red);

        Color coinColor = board.GetCoinFromIndex(x).GetEnumColor();

        // set grid color based on the cell color
        if (coinColor == White)
        {
            grid[x].setFillColor(sf::Color::White);
        }
        else if (coinColor == Black)
        {
            grid[x].setFillColor(sf::Color::Black);
        }
        else
        {
            grid[x].setFillColor(sf::Color::Green);
        }
    }
}

void Renderer::render(sf::RenderWindow &window)
{
    for (int x = 0; x < numRows; x++)
    {
        window.draw(grid[x]);
    }
}
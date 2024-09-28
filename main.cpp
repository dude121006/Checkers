#include <iostream>
#include "SFML/Graphics.hpp"
#include "board.h"
#include "coin.h"
#include "renderer.h"

//? UPDATE: coin movement bounds
//TODO: add text support
//TODO: game logic
//TODO: better input controls
//TODO: Add setup files

int main()
{
    Board board;
    Renderer renderer(board);

    // position of coins to be swapped with mouse
    std::vector<sf::Vector2i> coinPositions;
    std::vector<int> coinIndices;
    sf::Vector2i windowRelativePos;
    int numSteps = 0;
    int textSpace = 60;

    board.PrintBoard();

    sf::RenderWindow window(sf::VideoMode(renderer.numRows * renderer.boxSize, renderer.boxSize + textSpace), "Checkers");

    // main game loop
    while (window.isOpen())
    {

//*========================================================================================================


        // events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i screenPos = sf::Mouse::getPosition();
                sf::Vector2i windowPos = window.getPosition();

                windowRelativePos = screenPos - windowPos;
            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    coinPositions.push_back(windowRelativePos);

                    if (coinPositions.size() == 1)
                    {
                        coinIndices = board.ConvertPositionsToIndex(coinPositions, renderer.boxSize);
                        renderer.grid[coinIndices[0]].isSelected = true;
                        // renderer.grid[0].isSelected = true;
                        std::cout << coinIndices[0] << std::endl;
                    }
                    else if (coinPositions.size() == 2)
                    {
                        coinIndices = board.ConvertPositionsToIndex(coinPositions, renderer.boxSize);
                        board.MoveCoins(coinIndices); 

                        coinIndices.clear();
                        coinPositions.clear();
                        renderer.UnselectAll();

                        //update count
                        numSteps++;
                        // std::cout << numSteps << std::endl;
                    }

                    //* =-=-=-=-=-

                }
            }
        }

        renderer.UpdateRenderer(board);


//*========================================================================================================

        // clear the window
        window.clear(sf::Color::White);

        // render stuff to window
        renderer.Render(window);

        window.display();
    }

    return 0;
}

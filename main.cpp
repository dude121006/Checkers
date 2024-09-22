#include <iostream>
#include "SFML/Graphics.hpp"
#include "board.h"
#include "coin.h"
#include "renderer.h"


void Print(char x)
{
    std::cout << x << std::endl;
}


int main()
{
    Board board;
    Renderer renderer(board);


    // board.PrintBoard();
    // board.MoveCoins(2, 3);
    // board.PrintBoard();
    // board.MoveCoins(4, 2);
    // board.PrintBoard();

    sf::RenderWindow window(sf::VideoMode(renderer.numRows * renderer.boxSize, renderer.boxSize), "Checkers");
    

    // main game loop
    while (window.isOpen())
    {
        // events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //clear the window
        window.clear();

        //render stuff to window
        renderer.render(window);

        window.display();
    }

    return 0;
}

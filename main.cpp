#include <iostream>
#include "SFML/Graphics.hpp"
#include "board.h"
#include "coin.h"


void Print(char x)
{
    std::cout << x << std::endl;
}


int main()
{
    Board board;

    board.PrintBoard();
    board.MoveCoins(2, 3);
    board.PrintBoard();
    board.MoveCoins(4, 2);
    board.PrintBoard();

    int boxWidth = 200;

    //window stuff
    sf::RenderWindow window(sf::VideoMode(boxWidth * 7, boxWidth), "Checkers");
    

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


        window.display();
    }

    return 0;
}

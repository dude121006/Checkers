#include "renderer.h"

Renderer::Renderer(Board &board) : numRows(7), boxSize(200)
{
    InitSprites();

    for (int x = 0; x < numRows; x++)
    {
        spriteList.resize(numRows);
        grid.resize(numRows);

        Color coinColor = board.GetCoinFromIndex(x).GetEnumColor();
        sf::Color grey(128, 128, 128, 255);

        grid[x].setSize(sf::Vector2f(boxSize, boxSize));

        //static casting to convert the position to an exact integer (to solve rendering issues)
        grid[x].setPosition(sf::Vector2f(static_cast<int>(x * boxSize), 0));
        grid[x].setOutlineThickness(10.0f);
        grid[x].setOutlineColor(grey);

        // set grid color based on the cell color
        if (coinColor == White)
        {
            spriteList[x] = (whiteCoinSprite);
            grid[x].setFillColor(sf::Color::White);
        }
        else if (coinColor == Black)
        {
            spriteList[x] = (blackCoinSprite);
            grid[x].setFillColor(sf::Color::White);
        }
        else
        {
            spriteList[x] = (transparentCoinSprite);
            grid[x].setFillColor(sf::Color::White);
        }


        sf::Vector2u size = blackCoinTexture.getSize();
        spriteList[x].setPosition(sf::Vector2f(x * boxSize, 0));
        spriteList[x].setScale(sf::Vector2f(static_cast<float>( boxSize ) / size.x, (static_cast<float>( boxSize ) / size.y)));
        // spriteList[x].setScale(sf::Vector2f(( boxSize ) / size.x, (( boxSize ) / size.y)));
    }
}

void Renderer::InitSprites()
{
    if (!whiteCoinTexture.loadFromFile("assets/whiteCoin.png"))
    {
        cout << "Couldnt load whiteCoin texture!" << endl;
    }
    if (!blackCoinTexture.loadFromFile("assets/blackCoin.png"))
    {
        cout << "Couldnt load blackCoin texture!" << endl;
    }
    if (!transparentCoinTexture.loadFromFile("assets/transparent.jpg"))
    {
        cout << "Couldnt load transparentCoin texture!" << endl;
    }

    whiteCoinSprite.setTexture(whiteCoinTexture);
    blackCoinSprite.setTexture(blackCoinTexture);
    transparentCoinSprite.setTexture(transparentCoinTexture);

}


void Renderer::Render(sf::RenderWindow &window)
{
    for (int x = 0; x < numRows; x++)
    {
        window.draw(grid[x]);
        window.draw(spriteList[x]);
    }
}


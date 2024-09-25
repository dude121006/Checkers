#include "renderer.h"

Renderer::Renderer(Board &board) : numRows(7), boxSize(200)
{
    InitSprites();
    UpdateRenderer(board);

    if (!font.loadFromFile("assets/JETBRAINSMONONERDFONT-REGULAR.ttf"))
    {
        std::cout << "Couldn't load font!" << "\n";
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

void Renderer::InitText()
{
    text.setFont(font);
    text.setString("HELLO");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);  
}


void Renderer::Render(sf::RenderWindow &window)
{
    for (int x = 0; x < numRows; x++)
    {
        window.draw(grid[x].shape);
        window.draw(spriteList[x]);
        window.draw(grid[x].cellNum);
    }
}

void Renderer::UpdateRenderer(Board& board)
{
    spriteList.resize(numRows);
    grid.clear();

    for (int x = 0; x < numRows; x++)
    {
        grid.push_back(GridCell(x, boxSize, font));

        // set grid color based on the cell color
        Color coinColor = board.GetCoinFromIndex(x).GetEnumColor();

        switch (coinColor)
        {
        case (White):
            spriteList[x] = (whiteCoinSprite);
            break;
        
        case (Black):
            spriteList[x] = (blackCoinSprite);
            break;

        default:
            spriteList[x] = (transparentCoinSprite);
            break;
        }


        sf::Vector2u size = blackCoinTexture.getSize();
        spriteList[x].setPosition(sf::Vector2f(x * boxSize, 0));
        spriteList[x].setScale(sf::Vector2f(static_cast<float>( boxSize ) / size.x, (static_cast<float>( boxSize ) / size.y)));
        // spriteList[x].setScale(sf::Vector2f(( boxSize ) / size.x, (( boxSize ) / size.y)));
    }
}
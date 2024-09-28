#include "renderer.h"

Renderer::Renderer(Board &board) : numRows(7), boxSize(200)
{
    InitSprites();
    InitGrid();
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
    // transparentCoinSprite.setColor(sf::Color::White);

}

// initialize grid once
void Renderer::InitGrid()
{
    grid.resize(numRows);
    for (int x = 0; x < numRows; x++)
    {
        grid[x] = GridCell(x, boxSize, font);
    }
    
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
    // store the isSelected states in a vector
    selectedStates.clear();
    for (const auto &cell : grid)
    {
        selectedStates.push_back(cell.isSelected);
    }

    // reinitialize the coin sprite lists and grid vector
    spriteList.resize(numRows);
    // grid.resize(numRows);

    // set the sprites and grid properties
    for (int x = 0; x < numRows; x++)
    {
        grid[x].UpdateGridCell(x, boxSize, font);

        // if (x < selectedStates.size())
        // { 
        //     grid[x].isSelected = selectedStates[x]; // for safety
        // }

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

        //updating the cellNumColors
        // grid[x].UpdateCellNumColor();
    }
}


void Renderer::UnselectAll()
{
    for (int i = 0; i < grid.size(); i++)
    {
        grid[i].isSelected = false;
    }
}

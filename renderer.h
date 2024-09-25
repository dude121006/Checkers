#pragma once
#include "gridCell.h"
#include "SFML/Graphics.hpp"
#include "board.h"

class Renderer
{
private:

public:
    int boxSize;
    int numRows;

    std::vector<GridCell> grid;
    std::vector<sf::Sprite> spriteList;

    sf::Texture whiteCoinTexture;
    sf::Texture blackCoinTexture;
    sf::Texture transparentCoinTexture;

    sf::Sprite whiteCoinSprite;
    sf::Sprite blackCoinSprite;
    sf::Sprite transparentCoinSprite;

    sf::Font font;
    sf::Text text;

public:
    Renderer(Board& board);

    void Render(sf::RenderWindow& window);
    void UpdateRenderer(Board& board);
    void InitSprites();
    void InitText();
};


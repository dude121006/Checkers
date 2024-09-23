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
    std::vector<sf::Sprite> spriteList;

    sf::Texture whiteCoinTexture;
    sf::Texture blackCoinTexture;
    sf::Texture transparentCoinTexture;

    sf::Sprite whiteCoinSprite;
    sf::Sprite blackCoinSprite;
    sf::Sprite transparentCoinSprite;

public:
    Renderer(Board& board);

    void Render(sf::RenderWindow& window);
    void InitSprites();
};


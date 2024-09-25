#pragma once
#include "SFML/Graphics.hpp"

class GridCell
{

public:
    GridCell(int index, int boxSize, sf::Font& font);
    void SetFillColor(sf::Color color);
    void InitCellNum(int num, int boxSize, sf::Font& font);


public:
    sf::Text cellNum;
    sf::RectangleShape shape;
    sf::Vector2f textOffset;

};
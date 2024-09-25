#include "gridCell.h"
#include <iostream>


GridCell::GridCell(int index, int boxSize, sf::Font& font) : textOffset(sf::Vector2f(0, 17))
{
    sf::Color grey(128, 128, 128, 255);

    //static casting to convert the position to an exact integer (to solve rendering issues)
    shape.setPosition(sf::Vector2f(static_cast<int>(index * boxSize), 0));
    shape.setSize(sf::Vector2f(boxSize, boxSize));
    shape.setOutlineThickness(10.0f);
    shape.setOutlineColor(grey);
    shape.setFillColor(sf::Color::White);

    int num = index + 1;
    InitCellNum(num, boxSize, font);
}

void GridCell::SetFillColor(sf::Color color)
{
    shape.setFillColor(color);
}

void GridCell::InitCellNum(int num, int boxSize, sf::Font& font)
{

    cellNum.setFont(font);
    cellNum.setString(sf::String(std::to_string(num)));
    cellNum.setCharacterSize(30);
    cellNum.setFillColor(sf::Color::Green);
    
    // get the coords of the bottom middle edge of the shape
    sf::Vector2f gridBottomMiddlePos = shape.getPosition() + sf::Vector2f(boxSize/2, boxSize);
    cellNum.setPosition(gridBottomMiddlePos + textOffset);
}
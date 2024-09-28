#include "gridCell.h"
#include <iostream>


GridCell::GridCell(int index, int boxSize, sf::Font& font) 
                            : textOffset(sf::Vector2f(0, 17)), isSelected(false)

{
    UpdateGridCell(index, boxSize, font);
}

void GridCell::SetFillColor(sf::Color color)
{
    shape.setFillColor(color);
}

// sets up the cell number
void GridCell::UpdateCellNum(int num, int boxSize, sf::Font& font)
{
    cellNum.setFont(font);
    cellNum.setString(sf::String(std::to_string(num)));
    cellNum.setCharacterSize(30);
    cellNum.setFillColor(isSelected ? sf::Color::Red : sf::Color::Green);
    
    // get the coords of the bottom middle edge of the shape
    sf::Vector2f gridBottomMiddlePos = shape.getPosition() + sf::Vector2f(boxSize/2, boxSize);
    cellNum.setPosition(gridBottomMiddlePos + textOffset);
}

void GridCell::UpdateCellNumColor()
{
    cellNum.setFillColor(isSelected ? sf::Color::Red : sf::Color::Green);
}

void GridCell::UpdateGridCell(int index, int boxSize, sf::Font& font)
{
    UpdateCellShape(index, boxSize, font);
    int num = index + 1;
    UpdateCellNum(num, boxSize, font);
}

void GridCell::UpdateCellShape(int index, int boxSize, sf::Font& font)
{
    sf::Color grey(128, 128, 128, 255);

    //static casting to convert the position to an exact integer (to solve rendering issues)
    shape.setPosition(sf::Vector2f(static_cast<int>(index * boxSize), 0));
    shape.setSize(sf::Vector2f(boxSize, boxSize));
    shape.setOutlineThickness(10.0f);
    shape.setOutlineColor(grey);
    shape.setFillColor(sf::Color::White);
}
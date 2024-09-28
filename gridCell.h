#pragma once
#include "SFML/Graphics.hpp"

class GridCell
{

public:
    GridCell() = default;
    GridCell(int index, int boxSize, sf::Font& font);
    void SetFillColor(sf::Color color);
    void UpdateCellNumColor();
    void UpdateCellNum(int num, int boxSize, sf::Font& font);
    void UpdateGridCell(int index, int boxSize, sf::Font& font);
    void UpdateCellShape(int index, int boxSize, sf::Font& font);

public:
    sf::Text cellNum;
    sf::RectangleShape shape;
    sf::Vector2f textOffset;
    bool isSelected;

};
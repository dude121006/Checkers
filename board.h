#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "coin.h"
#include "gridCell.h"

using namespace std;

class Board
{
public:
    Board();
    void PrintBoard();

    bool isInBounds(int index);
    bool isValidJump(int initPos, int finalPos);
    bool isFinalDestinationEmpty(int dest);

    std::vector<int> ConvertPositionsToIndex(std::vector<sf::Vector2i> vec, int size);
    int ConvertPositionToIndex(int pos, int size);

    void MoveCoins(int initialPos, int finalPos);
    void MoveCoins(std::vector<int> pos);
    void SwapCoins(int initialPos, int finalPos);
    Coin GetCoinFromIndex(int index);

private:
    vector<Coin> board;
};

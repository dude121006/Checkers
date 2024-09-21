#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum Color
{
    Black,
    White,
    Empty
};

class Coin
{
public:
    Coin(int choice);
    char GetColor();
    Color GetEnumColor();

private:
    Color color;
};


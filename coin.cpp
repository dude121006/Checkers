#include "coin.h"


Coin::Coin(int choice)
{
    if (choice == 0)
        color = Color::Black;
    else if (choice == 1)
        color = Color::White;
    else
        color = Color::Empty;

}

// returns the color of the Coin as a CHAR
char Coin::GetColor()
{
    if (color == Black)
        return 'B'; 
    else if (color == White)
        return 'W'; 
    return 'E';
}

// returns the color of the Coin as an ENUM
Color Coin::GetEnumColor()
{
    return color;
}
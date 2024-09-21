#include "board.h"
#include "coin.h"

void Print(char x)
{
    cout << x << endl;
}

int main()
{
    Board board;

    board.PrintBoard();
    // board.MoveCoins(2, 3);
    // board.PrintBoard();

    return 0;
} 

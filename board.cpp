#include "board.h"

// initialize the board with coins
Board::Board()
{
    board.push_back(Coin(0));
    board.push_back(Coin(0));
    board.push_back(Coin(0));
    board.push_back(Coin(2));
    board.push_back(Coin(1));
    board.push_back(Coin(1));
    board.push_back(Coin(1));
}

// print the coins in the board
void Board::PrintBoard()
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i].GetColor() << " ";
    }
    cout << endl;
}

// swap two coins with their index
void Board::SwapCoins(int initialPos, int finalPos)
{
    Coin tempCoin = board[finalPos];
    board[finalPos] = board[initialPos];
    board[initialPos] = tempCoin;
}

// Move a coin with its init. and final index
void Board::MoveCoins(int initialPos, int finalPos)
{
    if (!isInBounds(initialPos) || !isInBounds(finalPos))
    {
        cout << "Positions out of bounds" << endl;
        return;
    }
    if (GetCoinFromIndex(initialPos).GetColor() == Empty)
    {
        cout << "Choose a non empty Coin" << endl;
        return;
    }

    int dist = abs(finalPos - initialPos);

    if (dist == 1)
    {
        if (isFinalDestinationEmpty(finalPos))
        {
            SwapCoins(initialPos, finalPos);
        }
        else
        {
            cout << "Choose a valid final position (TYPE 1)" << endl;
        }
    }
    else if (dist == 2)
    {
        if (isValidJump(initialPos, finalPos))
        {
            SwapCoins(initialPos, finalPos);
        }
        else
        {
            cout << "Choose a valid final position (TYPE 2)" << endl;
        }
    }
    else
    {
        cout << "Final coin too far" << endl;
    }
}

Coin Board::GetCoinFromIndex(int index)
{
    return board[index];
}

// checks if a coin can jump over a coin of opposite color
bool Board::isValidJump(int initPos, int finalPos)
{
    Coin firstCoin = GetCoinFromIndex(initPos);
    Coin middleCoin = GetCoinFromIndex((initPos + finalPos) / 2);
    Coin lastCoin = GetCoinFromIndex(finalPos);

    return firstCoin.GetEnumColor() != middleCoin.GetEnumColor() && middleCoin.GetEnumColor() != Empty && lastCoin.GetEnumColor() == Empty;
}

bool Board::isFinalDestinationEmpty(int dest)
{
    return GetCoinFromIndex(dest).GetEnumColor() == Empty;
}

bool Board::isInBounds(int index)
{
    if (index >= 0 && index < board.size())
        return true;
    else
        return false;
}

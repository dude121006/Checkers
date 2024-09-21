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
    if (isInBounds(initialPos) && isInBounds(finalPos))    
    {

        //Checks if first coin is empty
        if (GetCoinFromIndex(initialPos).GetColor() == Empty)
        { 
            cout << "Choose a non empty Coin" << endl;
    }

        else
        {
            Coin firstCoin = GetCoinFromIndex(initialPos);        
            Coin middleCoin = GetCoinFromIndex(( initialPos + finalPos )/2);
            Coin lastCoin = GetCoinFromIndex(finalPos);        

            //checks if close cell swap
            if (abs(finalPos - initialPos) == 1)
            {
                if (lastCoin.GetEnumColor() == Empty)
                {
                    SwapCoins(initialPos, finalPos);
                }
                else 
                {
                    cout << "Choose a valid final position (TYPE 1)" << endl;
                }
            }

            else if (abs(finalPos - initialPos) == 2)
            {
                if (firstCoin.GetEnumColor() != middleCoin.GetEnumColor()
                            && middleCoin.GetEnumColor() != Empty && lastCoin.GetEnumColor() == Empty)
                {
                    SwapCoins(initialPos, finalPos);
                }
                else 
                {
                    cout << "Choose a valid final position (TYPE 2)" << endl;
                }
            }

            else {
                cout << "Final coin too far" << endl;
            }
        }
    }
    else 
    {
        cout << "Positions out of bounds" << endl;
    }
}


Coin Board::GetCoinFromIndex(int index)
{
    return board[index];
}

bool Board::isInBounds(int index)
{
    if (index >= 0 && index <= board.size())
        return true;
    else 
        return false;    
}





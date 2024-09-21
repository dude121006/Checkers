#pragma once
#include <iostream>
#include <vector>
#include "coin.h"

using namespace std;

class Board
{
public:
   Board();
   void PrintBoard();

   bool isInBounds(int index);
   bool isValidJump(int initPos, int finalPos);
   bool isFinalDestinationEmpty(int dest);

   void MoveCoins(int initialPos, int finalPos);
   void SwapCoins(int initialPos, int finalPos);
   Coin GetCoinFromIndex(int index);

private:
    vector<Coin> board;
};

// Module3.cpp : Week 3 C++ HW Skerritt
//

#include "stdafx.h"
#include <time.h>
#include <vector>
#include "TicTacToe.h"

int main()
{
    srand(time(NULL));
    TicTacToe game;
    while (game.gameInPlay) //while still playing game
    {
        game.CheckState(1, game.PlayerTurn());
        if (game.gameInPlay) //while still playing game
        {
            game.CheckState(-1, game.ComputerTurn());
        }
    }
    // game ends if all spots filled (9)
    // game ends if player wins
    // game ends if computer wins

    return 0;
}
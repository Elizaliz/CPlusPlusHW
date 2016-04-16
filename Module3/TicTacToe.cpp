// TicTacToe.cpp : Week 3 C++ HW Skerritt
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "TicTacToe.h"

/**
* Game of Tic Tac Toe-- player against the computer.
*/

	TicTacToe::TicTacToe() ///Constructor
	{
      this->gameInPlay = true;
      this->totalTurns = 0;
      this->InitializeBoard();
      this->DisplayBoard();
	}

	TicTacToe::~TicTacToe() {}

	void TicTacToe::CheckState(int player, int rowCol)
	{
		/**check if Player won, Computer Won, or Tie, set the m_game in Play boolean
		*if three in the last played row, column, or diagonals
		*/

      this->DisplayBoard();

		int row = rowCol / 3;
		int col = rowCol % 3;

		///tie if none of the others are true and all positions filled
		if (-1 == rowCol && totalTurns >= 9)
		{
         this->gameInPlay = false;
         this->PrintResult(0);
		}

		/// checking row
		else if (this->getBoardAt(row, 0) == this->getBoardAt(row, 1) && this->getBoardAt(row, 1) == this->getBoardAt(row, 2) && this->getBoardAt(row, 2) == player)
		{
         this->PrintResult(player);
         this->gameInPlay = false;
		}

		///checking column
		else if (this->getBoardAt(0, col) == this->getBoardAt(1, col) && this->getBoardAt(1, col) == this->getBoardAt(2, col) && this->getBoardAt(2, col) == player)
		{
         this->PrintResult(player);
         this->gameInPlay = false;
		}

		///checking diagonals
		else if (this->getBoardAt(0, 0) == this->getBoardAt(1, 1) && this->getBoardAt(1, 1) == this->getBoardAt(2, 2) && this->getBoardAt(2, 2) == player ||
         this->getBoardAt(0, 2) == this->getBoardAt(1, 1) && this->getBoardAt(1, 1) == this->getBoardAt(2, 0) && this->getBoardAt(2, 0) == player)
		{
         this->PrintResult(player);
         this->gameInPlay = false;
		}

		else {
			std::cout << "Let's keep playing. ";
		}
	}

	///returns 1~9 depending on player input
	int TicTacToe::PlayerTurn()
	{
		bool validTurn = false;
		int row = -1;
		int col = -1;

		do
		{
			std::cout << "Your turn. Please enter row, column: ";
			std::cin >> row >> col;
			int rowCol = (row - 1) * 3 + (col - 1);
			if (row > 0 && row < 4 && col >= 0 && col < 4 && this->ValidPosition(rowCol)) ///< checks that input for row and column is valid
			{
				validTurn = true;
				this->totalTurns++;
				this->board[rowCol] = 1;
				return (row - 1) * 3 + (col - 1);
			}
			else
			{
				std::cout << "Not a valid turn, try again" << std::endl;
			}
		} while (!validTurn);

	}

	int TicTacToe::ComputerTurn() /// returns 1~9 depending on next free space
	{
		bool lookingForFreeSpot = true;
		std::cout << "Computer's turn. " << std::endl;

		while (lookingForFreeSpot && totalTurns < 9)
		{
			int randomNumber = rand() % 9; ///<randomly chooses number between 0 ~ 8
			if (this->ValidPosition(randomNumber))
			{
				lookingForFreeSpot = false;
				this->totalTurns++;
				this->board[randomNumber] = -1;
				return randomNumber;
			}
		}
		return -1;
	}

	/// checks if position is currently empty
	bool TicTacToe::ValidPosition(int rowCol)
	{
		if (0 == this->getBoardAt(rowCol))
		{
			return true;
		}
		return false;
	}

	/// Prints if computer won, player won, or tie
	void TicTacToe::PrintResult(int player)
	{
		if (-1 == player)
		{
			std::cout << "The Computer has won!" << std::endl;
		}

		if (1 == player)
		{
			std::cout << "Congratulations, you have won!!!" << std::endl;
		}
		if (0 == player)
		{
			std::cout << "The game has ended in a tie." << std::endl;
		}
	}

	/// Draws the current board
	void TicTacToe::DisplayBoard() 
	{

		for (int i = 0; i < 9; i += 3)
		{
			std::cout << this->getBoardChar(i) << " | " << this->getBoardChar(i + 1) << " | " << this->getBoardChar(i + 2) << std::endl;
			if (i < 6)
			{
				std::cout << "---------" << std::endl;
			}
		}
	}

	/// converts row column descriptor as a single integer and 
	/// returns X, O, or nothing
	char TicTacToe::getBoardChar(int row, int col)
	{
		if (-1 == this->getBoardAt(row, col))
		{
			return 'O';
		}
		if (1 == this->getBoardAt(row, col))
		{
			return 'X';
		}
		else return ' ';
	}

	/// returns X, O, or nothing
	char TicTacToe::getBoardChar(int rowCol)
	{
		if (-1 == this->getBoardAt(rowCol))
		{
			return 'O';
		}
		if (1 == this->getBoardAt(rowCol))
		{
			return 'X';
		}
		else return ' ';
	}

	/// converts row column descriptor as a single integer and 
	/// returns -1 for computer, 1 for player, and 0 for nothing
	int TicTacToe::getBoardAt(int row, int col)
	{
		int rowCol = 3 * row + col;
		return this->board[rowCol];
	}

	/// returns -1 for computer, 1 for player, and 0 for nothing 
	int TicTacToe::getBoardAt(int rowCol)
	{
		return this->board[rowCol];
	}

	/// sets all board values as empty
	void TicTacToe::InitializeBoard()
	{
		for (int i = 0; i < 9; i++)
		{
         this->board.push_back(0);
		}
	}


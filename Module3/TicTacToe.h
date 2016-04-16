#pragma once
// TicTacToe.h : Week 3 C++ HW Skerritt
//

class TicTacToe
{
public:

   bool gameInPlay;///< whether or not to keep the game in play. False if game has been won or ended in a tie.

   TicTacToe();
   ~TicTacToe();
   void CheckState(int player, int rowCol);
   int PlayerTurn();
   int ComputerTurn();

private:

   std::vector<int> board;  ///< 3 x 3 board. 1 is X. -1 is O. 0 is empty.
   int totalTurns; ///< keeps count of total turns

   bool ValidPosition(int rowCol);
   void PrintResult(int player);
   void DisplayBoard();
   char getBoardChar(int row, int col);
   char getBoardChar(int rowCol);
   int getBoardAt(int row, int col);
   int getBoardAt(int rowCol);
   void InitializeBoard();

};

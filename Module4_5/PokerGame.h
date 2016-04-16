#pragma once
#include "Hand.h"
class PokerGame
{
public:
   //figure out constructor and destructor
   PokerGame();
   PokerGame(std::vector<Hand> hs);
   ~PokerGame() {}

   void setHands(std::vector<Hand> hs);
   void addHand(Hand hand);
   std::vector<Hand> myHands;

   int compareMyHands();
   void printResult();

private:

   void printLosingHands(int winner);
};

#include "stdafx.h"
#include "PokerGame.h"
#include <iostream>
#include <string>


//flush
//5 same suit

//straight
//5 chronological

//straight flush
//*flush
//*straight
//5 same suit
//5 chronological

//four of a kind
//*2 2 of a kinds
//4 same value

//one pair
//2 of same value

//three of a kind
//3 same value

//full house
//*2 of a kind
//*3 of a kind

//two pair
//*one pair
//2 same value
//2 same value

//high Card
//only if nothing else checked

PokerGame::PokerGame()
{
}

PokerGame::PokerGame(std::vector<Hand> hs)
{
   setHands(hs);
}

void PokerGame::setHands(std::vector<Hand> hs)
{
   this->myHands = hs;
}

void PokerGame::addHand(Hand hand)
{
   //check types the same
   this->myHands.push_back(hand);
}

int PokerGame::compareMyHands()
{
   int winner = -1;
   int i = 0;
   std::vector<int> handTypes;
   std::vector<Hand> myNewHands;
   for (Hand hand : myHands)
   {
      hand.assignType();
      handTypes.push_back(hand.getHandType());
      myNewHands.push_back(hand);
      i++;
   }

   if (handTypes.size() == 2)
   {
      if (handTypes[0] < handTypes[1])
      {
         winner = 0;
      }
      else if (handTypes[1] < handTypes[0])
      {
         winner = 1;
      }
      else
      {
         if (myNewHands[0].getHighCard() > myNewHands[1].getHighCard())
         {
            winner = 0;
         }
         else if (myNewHands[1].getHighCard() > myNewHands[0].getHighCard())
         {
            winner = 1;
         }
         else winner = -1;
      }
   }
   if (handTypes.size() == 3)
   {
      if (handTypes[0] < handTypes[1] && handTypes[0] < handTypes[2])
      {
         winner = 0;
      }
      else if (handTypes[1] < handTypes[0] && handTypes[1] < handTypes[2])
      {
         winner = 1;
      }
      else if (handTypes[2] < handTypes[0] && handTypes[2] < handTypes[1])
      {
         winner = 2;
      }
      else
      {
         if (myNewHands[0].getHighCard() > myNewHands[1].getHighCard() && myNewHands[0].getHighCard() > myNewHands[2].getHighCard())
         {
            winner = 0;
         }
         else if (myNewHands[1].getHighCard() > myNewHands[0].getHighCard() && myNewHands[1].getHighCard() > myNewHands[2].getHighCard())
         {
            winner = 1;
         }
         else if (myNewHands[2].getHighCard() > myNewHands[0].getHighCard() && myNewHands[2].getHighCard() > myNewHands[1].getHighCard())
         {
            winner = 2;
         }
      }
   }
   return winner;
}

void PokerGame::printResult()
{
   int winner = compareMyHands();

   if (winner != -1)
   {
      myHands[winner].printHand();
      std::cout << "Defeats" << std::endl;
      printLosingHands(winner);
   }
   else
   {
      printLosingHands(-1);
      std::cout << "Tie" << std::endl;
   }
}

void PokerGame::printLosingHands(int winner)
{
   for (int i = 0; i < myHands.size(); i++)
   {
      if (i != winner)
      {
         myHands[i].printHand();
      }
   }
}
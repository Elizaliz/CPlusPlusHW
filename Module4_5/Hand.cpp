#include "stdafx.h"
#include "Hand.h"
#include "Card.h"
#include <algorithm>

class HandType;

Hand::Hand(std::vector<Card> h)
{
   setHand(h);
}


Hand::~Hand()
{
}

void Hand::setHand(std::vector<Card> hand)
{
   if (hand.size() <= 5)
   {
      this->myHand = hand;
   }
}

std::vector<Card> Hand::getHand()
{
   return this->myHand;
}


void Hand::addCard(Card card)
{
   if (myHand.size() <= 4 && uniqueCard(card))
   {
      this->myHand.push_back(card);
   }
}

bool Hand::uniqueCard(Card newCard)
{
   for (Card card : myHand)
   {
      if ((card.getSuit().compare(newCard.getSuit()) == 0) && (card.getValue() == newCard.getValue()))// && card.getValue().compare(newCard.getValue()) == 0)
      {
         return false;
         std::cout << "Duplicate cards not allowed" << std::endl;
      }
   }
   return true;
}

void Hand::sortHand()
{
   // sort using a custom function object
   struct {
      bool operator()(Card a, Card b)
      {
         return a.getValue() < b.getValue();
      }
   } customSort;

   std::sort(std::begin(myHand), std::end(myHand), customSort);
   highCard = myHand[4].getValue();
}

int Hand::getHandType()
{
   return this->typeOfHand;

}

int Hand::getHighCard()
{
   return this->highCard;
}

bool Hand::fiveSequentialValues()
{
   //special cases 2 3 4 5 14
   //2 3 4 5 6 ~ 10 11 12 13 14
   int sequentialCardNum = 1;
   int highestValue = 0;//check what to track
   for (int i = 0; i < 4; i++)
   {
      if (myHand[i + 1].getValue() == 1 + myHand[i].getValue())
      {
         sequentialCardNum++;
      }
      else if (myHand[i + 1].getValue() == myHand[i].getValue())
      {
         return false;
      }
      //might be able to shorten time in loop if detect false early
   }
   if (sequentialCardNum == 5)
   {
      return true;
   }
   else if (myHand[4].getValue() == 14 && myHand[3].getValue() == 5 && sequentialCardNum == 4)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::fiveSameSuits()
{
   int sequentialCardSuit = 1;
   for (int i = 0; i < 4; i++)
   {
      if (myHand[1 + i].getSuit().compare(myHand[i].getSuit()) == 0)
      {
         sequentialCardSuit++;
      }
   }
   if (sequentialCardSuit == 5)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void Hand::checkMultiples(std::vector<int> &pairCards, int &tripleCards, int &quadCards)
{
   std::map<int, int> myMap;
   for (Card card : this->myHand)
   {
      myMap[card.getValue()]++;
   }
   for (auto cards : myMap)
   {
      if (cards.second == 2)
      {
         pairCards.push_back(cards.first);
      }
      if (cards.second == 3)
      {
         tripleCards = cards.first;
      }
      if (cards.second == 4)
      {
         quadCards = cards.first;
      }
   }
}

void Hand::assignType()
{
   bool sameSuit = fiveSameSuits();
   bool sequentialValues = fiveSequentialValues();

   //default hand if nothing else below
   highCard = myHand[4].getValue();
   typeOfHand = HIGH_CARD;

   if (sequentialValues && sameSuit)
   {
      this->typeOfHand = STRAIGHT_FLUSH;
      return;
   }
   if (sameSuit)
   {
      this->typeOfHand = FLUSH;
      return;
   }
   if (sequentialValues)
   {
      this->typeOfHand = STRAIGHT;
      return;
   }

   std::vector<int> pairCardsValues;
   int tripleCardsValue= 0;
   int quadCardsValue = 0;
   checkMultiples(pairCardsValues, tripleCardsValue, tripleCardsValue);

   if (quadCardsValue > 0)
   {
      this->typeOfHand = FOUR_KIND;
      this->highCard = quadCardsValue;
      return;
   }
   if (pairCardsValues.size() == 1 && tripleCardsValue > 0)
   {
      this->typeOfHand = FULL_HOUSE;
      this->highCard = tripleCardsValue;
      return;
   }
   if (pairCardsValues.size() == 2)
   {
      this->typeOfHand = TWO_PAIR;
      if (pairCardsValues[0] > pairCardsValues[1])
      {
         this->highCard = pairCardsValues[0];
      }
      else
      {
         this->highCard = pairCardsValues[1];
      }
      return;
   }
   if (pairCardsValues.size() == 1)
   {
      this->typeOfHand = ONE_PAIR;
      this->highCard = pairCardsValues[0];
      return;
   }
   if (tripleCardsValue > 0)
   {
      this->typeOfHand = THREE_KIND;
      this->highCard = tripleCardsValue;
      return;
   }
   return;
}

void Hand::printHand()
{
   std::cout << "Hand: ";
   for (Card card : myHand)
   {
      card.printCard();
   }
   std::cout << std::endl;
}
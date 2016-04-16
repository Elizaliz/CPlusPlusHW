#pragma once
#include <vector>
#include <map>
#include "Card.h"

class Hand
{
public:
	Hand(std::vector<Card> hand);
	~Hand();

   int highCard = 0;
   std::vector<Card> myHand;
   int typeOfHand;

   void setHand(std::vector<Card> hand);
   void addCard(Card card);

   std::vector<Card> getHand();
   int getHighCard();
   int getHandType();

   void sortHand(); //put values in increasing order
   void assignType();
   void printHand();

private:

   bool uniqueCard(Card card);
   bool fiveSequentialValues();
   bool fiveSameSuits();
   void checkMultiples(std::vector<int> &pairCards, int &tripleCards, int &quadCards);

};

static enum HANDTYPE {STRAIGHT_FLUSH, FOUR_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_KIND, TWO_PAIR, ONE_PAIR, HIGH_CARD};
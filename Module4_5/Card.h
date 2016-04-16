#pragma once
#include <iostream>
#include <vector>

class Card
{
public:

   Card();
   Card(std::string value, std::string suit);

   ~Card();

   void setValueSuit(std::string value, std::string suit);
	void setValue(std::string value);//maybe don't need this
	void setSuit(std::string suit);
	int getValue();
   std::string getStringValue();
	std::string getSuit();
   void printCard();

private:

   int cardValue;
   std::string cardStringValue;
   std::string cardSuit;

   bool verifyValue(std::string valueToVerify);
   bool verifySuit(std::string suitToVerify);
   int Card::convertToNumericalValue(std::string value);

};

static const std::vector<std::string> values = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; //maybe a map of string to value
static const  std::vector<std::string> suits = { "H", "D", "C", "S" }; //should go in priority order

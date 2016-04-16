#include "stdafx.h"
#include "Card.h"
#include <stdexcept>
#include <string>

Card::Card()
{

}

Card::Card(std::string value, std::string suit)
{
   setValue(value);
   setSuit(suit);
}

Card::~Card()
{
}

void Card::setValueSuit(std::string value, std::string suit)
{
   setValue(value);
   setSuit(suit);
}

void Card::setSuit(std::string suit)
{
   if (verifySuit(suit))
   {
      this->cardSuit = suit;
   }
   else
   {
      std::cout << suit << " is not a valid suit" << std::endl;
   }
}

void Card::setValue(std::string value)
{
   if (verifyValue(value))
   {
      int numValue = convertToNumericalValue(value);
      this->cardValue = numValue;
      this->cardStringValue = value;
   }
   else
   {
      std::cout << value << " is not a valid value" << std::endl;
   }

}

int Card::convertToNumericalValue(std::string value)
{
   int intValue = -1;
   try
   {
      intValue = std::stoi(value);
   }
   catch (const std::exception& e)
   {
      //std::cout << e.what();
   }
   if (value.compare("J") == 0)
   {
      intValue = 11;
   }
   else if (value.compare("Q") == 0)
   {
      intValue = 12;
   }
   else if (value.compare("K") == 0)
   {
      intValue = 13;
   }
   else if (value.compare("A") == 0)
   {
      intValue = 14;
   }

   return intValue;


}

std::string Card::getSuit()
{
   return this->cardSuit;
}

int Card::getValue()
{
   return this->cardValue;
}

std::string Card::getStringValue()
{
   return this->cardStringValue;
}

bool Card::verifyValue(std::string valueToVerify)
{
   bool verified = false;
   for (std::string value : values)
   {
      if (value.compare(valueToVerify) == 0)
      {
         verified = true;
      }
   }
   return verified;
}

bool Card::verifySuit(std::string suitToVerify)
{
   bool verified = false;
   for (std::string suit : suits)
   {
      if (suit.compare(suitToVerify) == 0)
      {
         verified = true;
      }
   }
   return verified;
}

void Card::printCard()
{
   std::cout << this->getStringValue() << this->getSuit() << " ";
}
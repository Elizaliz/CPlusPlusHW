// Module4_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hand.h"
#include "Card.h"
#include "PokerGame.h"
#include <iostream>


int main()
{
   Card card1;
   Card card2;
   Card card3;
   Card card4;
   Card card5;

   {
      //Straight Flush
      std::cout << "Straight Flush: " << std::endl;

      card1.setValueSuit("5", "S");
      card2.setValueSuit("4", "S");
      card3.setValueSuit("7", "S");
      card4.setValueSuit("6", "S");
      card5.setValueSuit("8", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("K", "C");
      card2.setValueSuit("J", "C");
      card3.setValueSuit("A", "C");
      card4.setValueSuit("10", "C");
      card5.setValueSuit("Q", "C");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   {
      //Four of a kind

      std::cout << "\nFour of a kind: " << std::endl;

      card1.setValueSuit("3", "D");
      card2.setValueSuit("3", "H");
      card3.setValueSuit("3", "S");
      card4.setValueSuit("6", "S");
      card5.setValueSuit("3", "C");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("5", "S");
      card2.setValueSuit("K", "H");
      card3.setValueSuit("5", "D");
      card4.setValueSuit("5", "C");
      card5.setValueSuit("5", "H");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   {
      //Full house

      std::cout << "\nFull house: " << std::endl;

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "D");
      card3.setValueSuit("6", "D");
      card4.setValueSuit("6", "C");
      card5.setValueSuit("6", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("7", "D");
      card2.setValueSuit("2", "S");
      card3.setValueSuit("2", "C");
      card4.setValueSuit("7", "C");
      card5.setValueSuit("7", "S");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   {
      //Flush

      std::cout << "\nFlush: " << std::endl;

      card1.setValueSuit("9", "S");
      card2.setValueSuit("3", "S");
      card3.setValueSuit("7", "S");
      card4.setValueSuit("6", "S");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("4", "C");
      card2.setValueSuit("3", "C");
      card3.setValueSuit("A", "C");
      card4.setValueSuit("K", "C");
      card5.setValueSuit("5", "C");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   {
      //Three of a kind
      std::cout << "\nThree of a kind: " << std::endl;

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "H");
      card3.setValueSuit("7", "S");
      card4.setValueSuit("3", "C");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("A", "S");
      card2.setValueSuit("3", "S");
      card3.setValueSuit("A", "H");
      card4.setValueSuit("A", "C");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   {
      //Two Pair
      std::cout << "\nTwo Pair: " << std::endl;

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "D");
      card3.setValueSuit("7", "S");
      card4.setValueSuit("5", "C");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "D");
      card3.setValueSuit("A", "S");
      card4.setValueSuit("2", "C");
      card5.setValueSuit("2", "H");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "H");
      card3.setValueSuit("6", "S");
      card4.setValueSuit("8", "C");
      card5.setValueSuit("8", "D");

      std::vector<Card> hand3;
      hand3.push_back(card1);
      hand3.push_back(card2);
      hand3.push_back(card3);
      hand3.push_back(card4);
      hand3.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();
      Hand myHand3(hand3);
      myHand3.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.addHand(myHand3);
      game.printResult();
   }

   {
      //One Pair
      std::cout << "\nOne Pair: " << std::endl;

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "D");
      card3.setValueSuit("7", "S");
      card4.setValueSuit("6", "C");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("3", "S");
      card2.setValueSuit("3", "D");
      card3.setValueSuit("7", "S");
      card4.setValueSuit("6", "C");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   {
      //High Card
      std::cout << "\nHigh card: " << std::endl;

      card1.setValueSuit("3", "S");
      card2.setValueSuit("4", "S");
      card3.setValueSuit("10", "D");
      card4.setValueSuit("6", "C");
      card5.setValueSuit("5", "S");

      std::vector<Card> hand1;
      hand1.push_back(card1);
      hand1.push_back(card2);
      hand1.push_back(card3);
      hand1.push_back(card4);
      hand1.push_back(card5);

      card1.setValueSuit("3", "S");
      card2.setValueSuit("5", "S");
      card3.setValueSuit("A", "S");
      card4.setValueSuit("9", "C");
      card5.setValueSuit("5", "D");

      std::vector<Card> hand2;
      hand2.push_back(card1);
      hand2.push_back(card2);
      hand2.push_back(card3);
      hand2.push_back(card4);
      hand2.push_back(card5);

      Hand myHand1(hand1);
      myHand1.sortHand();
      Hand myHand2(hand2);
      myHand2.sortHand();

      PokerGame game;
      game.addHand(myHand1);
      game.addHand(myHand2);
      game.printResult();
   }

   return 0;
}
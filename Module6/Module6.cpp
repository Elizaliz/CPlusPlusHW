// Module6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Probability.h"
#include <iostream>


int main()
{

   //Testing
   Probability A( .2 );
   Probability B( .3 );
   Probability C( B ); //should be prob of B
   Probability D( -.2 ); //should be prob of 0

   Probability Result1;
   Probability Result2;
   Probability Result3;
   Probability Result4;
   Probability Result5;
   Probability Result6;
   Probability Result7;
   Probability Result8;
   Probability Result9;
   Probability Result10;
   Probability Result11;
   Probability Result12;

   std::cout << "A: " << A << std::endl;
   std::cout << "B: " << B << std::endl;
   std::cout << "C: " << C << std::endl;
   std::cout << "D: " << D << std::endl;

   //Make sure swapping probabilities has same value
   Result1 = A & B;
   Result2 = B & A;
   std::cout << "A & B: " << Result1 << std::endl;
   std::cout << "B & A: " << Result2 << std::endl;

   Result3 = A  |B;
   Result4 = B | A;
   std::cout << "A | B: " << Result3 << std::endl;
   std::cout << "B | A: " << Result4 << std::endl;

   Result5 = A ^ B;
   Result6 = B ^ A;
   std::cout << "A ^ B: A | B - A & B: " << Result5 << std::endl;
   std::cout << "B ^ A : B | A - B & A: " << Result6 << std::endl;

   //Make sure math is done right
   Result7 = ~A;
   Result8.setProbability(1 - A.getProbability());
   std::cout << "~A: " << ~A << std::endl;
   std::cout << "1 - A: " << 1 - A.getProbability() << std::endl;

   Result9 = ~B;
   Result10.setProbability(1 - B.getProbability());
   std::cout << "~B: " << ~B << std::endl;
   std::cout << "1 - B: " << 1 - B.getProbability() << std::endl;

   //Ensure values multiplying properly
   Result11 = A - B;
   Result12.setProbability(A.getProbability() * Result9.getProbability());
   std::cout << "A - B: " << Result11 << std::endl;
   std::cout << "A * ~B: " << Result12 << std::endl;

   return 0;
}


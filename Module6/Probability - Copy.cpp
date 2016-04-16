#include "stdafx.h"
#include "Probability.h"

std::ostream &operator<<(std::ostream & output, Probability A)
{
   output << A.prob;
   return output;
}

Probability& operator&(Probability& A, Probability& B)
{
   Probability probability;
   probability.prob = A.prob * B.prob;
   return probability;
}

Probability& operator|(Probability& A, Probability& B)
{
   Probability probability;
   probability.prob = A.prob + B.prob;
   return probability;
}

Probability& operator^(Probability& A, Probability& B)
{
   Probability probability;

   double prob1 = (A & B).prob;
   double prob2 = (A | B).prob;
   probability.prob = prob2 - prob1;
   //probability.prob = (A&B).prob - (A | B).prob;// I wonder why this returns 0 every time
   return probability;
}

Probability& operator-(Probability& A, Probability& B)
{
  Probability probability;

  probability.prob = (A & ~B).prob;

  return probability;
}

Probability::Probability()
{
   this->prob = 0;
}

Probability::Probability(double prob)
{
   if (prob >= 0 && prob <= 1)
   {
      this->prob = prob;
   }
   else this->prob = 0;
}

Probability::Probability(const Probability &probToCopy)
{
   this->prob = probToCopy.prob;
}

Probability Probability::operator~()
{
   Probability probability;
   probability.prob = 1 - this->prob;
   return probability;
}



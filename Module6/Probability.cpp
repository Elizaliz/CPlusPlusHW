#include "stdafx.h"
#include "Probability.h"

std::ostream &operator<<(std::ostream & output, Probability A)
{
   output << A.getProbability();
   return output;
}

Probability& operator&(Probability& A, Probability& B)
{
   Probability probability;
   probability.setProbability(A.getProbability() * B.getProbability());
   return probability;
}

Probability& operator|(Probability& A, Probability& B)
{
   Probability probability;
   probability.setProbability(A.getProbability() + B.getProbability());
   return probability;
}

Probability& operator^(Probability& A, Probability& B)
{
   Probability probability;
   Probability probability2;

   probability = A & B;
   double prob1 = probability.getProbability();
   
   probability2 = A | B;
   double prob2 = probability2.getProbability();
   probability.setProbability(prob2 - prob1);

   return probability;
}

Probability& operator-(Probability& A, Probability& B)
{
  Probability probability;

  probability = A & ~B;

  return probability;
}

Probability::Probability()
{
   this->setProbability(0);
}

Probability::Probability(double prob)
{
   if (prob >= 0 && prob <= 1)
   {
      this->setProbability(prob);
   }
   else this->setProbability(0);
}

Probability::Probability(const Probability &probToCopy)
{
   this->setProbability(probToCopy.getProbability());
}

Probability Probability::operator~()
{
   Probability probability;
   probability.setProbability(1 - this->getProbability());
   return probability;
}



#pragma once
#include <iostream>

class Probability;

std::ostream& operator<<(std::ostream &, Probability A);
Probability& operator&(Probability& A, Probability& B);
Probability& operator|(Probability& A, Probability& B);
Probability& operator^(Probability& A, Probability& B);
Probability& operator-(Probability& A, Probability& B);

class Probability
{
public:

   Probability();
   Probability(const Probability& probToCopy); // copy constructor
   Probability(double prob);

   double getProbability() const
   {
      return this->prob;
   }
   void setProbability(double prob)
   {
      this->prob = prob;
   }

   Probability operator~();

private:
   double prob;
};


#pragma once
#include "Node.h"
class Sub : public Node
{
public:
   Sub(Node* left, Node* right);
   ~Sub();

   Sub *clone() override
   {
      return new Sub(left->clone(), right->clone());
   }

   double evaluate() const; //pure virtual
   virtual Node* derivative(std::string character) override; //pure virtual
   virtual void print() const; //virtual
};


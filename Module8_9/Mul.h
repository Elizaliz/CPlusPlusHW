#pragma once
#include "Node.h"
class Mul : public Node
{
public:
   Mul(Node* left, Node* right);
   ~Mul();

   Mul *clone() override
   {
      return new Mul(left->clone(), right->clone());
   }

   double evaluate() const; //pure virtual
   virtual Node* derivative(std::string character) override; //pure virtual
   virtual void print() const; //virtual
};


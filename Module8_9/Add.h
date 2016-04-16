#pragma once

#include "Node.h"

class Add : public Node
{
public:
   Add(Node* left, Node* right);
   ~Add();

   Add *clone() override
   {
      return new Add(left->clone(), right->clone());
   }

   double evaluate() const; //pure virtual
   virtual Node* derivative(std::string character) override; //pure virtual
   virtual void print() const; //virtual
};


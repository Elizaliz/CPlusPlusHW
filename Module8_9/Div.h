#pragma once
#include "Node.h"
class Div : public Node
{
public:
   Div(Node* left, Node* right);
   ~Div();

   Div *clone() override
   {
      return new Div(left->clone(), right->clone());
   }
   double evaluate() const; //pure virtual
   virtual Node* derivative(std::string character) override; //pure virtual
   virtual void print() const; //virtual
};


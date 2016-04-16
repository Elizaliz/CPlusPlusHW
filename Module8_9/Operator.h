#pragma once
#include "Node.h"

class Operator : public Node
{
public:
   Operator(Node* left, Node* right); //could be numbers or other operators
   virtual ~Operator();

   //virtual void derivative() const = 0; //pure virtual

   virtual void print() const override; //virtual

private:
};


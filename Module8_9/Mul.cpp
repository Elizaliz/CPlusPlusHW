#include "stdafx.h"
#include "Mul.h"
#include "Add.h"


Mul::Mul(Node* left, Node* right)
{
   setLeftNode(left);
   setRightNode(right);
}

Mul::~Mul()
{
   delete left;
   delete right;
}

double Mul::evaluate() const
{
   return this->getLeftNode()->evaluate() * this->getRightNode()->evaluate();
}

void Mul::print() const
{
   std::cout << "(";
   this->getLeftNode()->print();
   std::cout << " * ";
   this->getRightNode()->print();
   std::cout << ")";
}

Node* Mul::derivative(std::string character)
{
   Node* newNode = new Add(new Mul(this->getLeftNode(), this->getRightNode()->derivative(character)),
      new Mul(this->getLeftNode()->derivative(character), this->getRightNode()));

   return newNode;
}

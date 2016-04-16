#include "stdafx.h"
#include "Add.h"

Add::Add(Node* left, Node* right)
{
   setLeftNode(left);
   setRightNode(right);
}

Add::~Add()
{
   delete left;
   delete right;
}

double Add::evaluate() const
{
   return this->getLeftNode()->evaluate() + this->getRightNode()->evaluate();
}

void Add::print() const
{
   std::cout << "(";
   this->getLeftNode()->print();
   std::cout << " + ";
   this->getRightNode()->print();
   std::cout << ")";
}

Node* Add::derivative(std::string character)
{
   this->setLeftNode(this->getLeftNode()->derivative(character));
   this->setRightNode(this->getRightNode()->derivative(character));

   return this;
}


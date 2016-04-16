#include "stdafx.h"
#include "Sub.h"


Sub::Sub(Node* left, Node* right)
{
   setLeftNode(left);
   setRightNode(right);
}


Sub::~Sub()
{
   delete left;
   delete right;
}


double Sub::evaluate() const
{
   return this->getLeftNode()->evaluate() - this->getRightNode()->evaluate();
}

void Sub::print() const
{
   std::cout << "(";
   this->getLeftNode()->print();
   std::cout << " - ";
   this->getRightNode()->print();
   std::cout << ")";
}

Node* Sub::derivative(std::string character)
{
   this->setLeftNode(this->getLeftNode()->derivative(character));
   this->setRightNode(this->getRightNode()->derivative(character));

   return this;
}
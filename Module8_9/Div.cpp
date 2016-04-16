#include "stdafx.h"
#include "Div.h"
#include "Mul.h"
#include "Sub.h"


Div::Div(Node* left, Node* right)
{
   setLeftNode(left);
   setRightNode(right);
}

Div::~Div()
{
   delete left;
   delete right;
}

double Div::evaluate() const
{
   return this->getLeftNode()->evaluate() / this->getRightNode()->evaluate();
}

void Div::print() const
{
   std::cout << "(";
   this->getLeftNode()->print();
   std::cout << " / ";
   this->getRightNode()->print();
   std::cout << ")";
}

Node* Div::derivative(std::string character)
{
   this->setLeftNode(new Sub(new Mul(this->getRightNode(), this->getLeftNode()->derivative(character)),
      new Mul(this->getLeftNode(), this->getRightNode()->derivative(character))));
   this->setRightNode(new Mul(this->getRightNode(), this->getRightNode()));

   return this;
}

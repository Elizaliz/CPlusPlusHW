#include "stdafx.h"
#include "Operator.h"


Operator::Operator(Node* left, Node* right)
{
   setLeftNode(left);
   setRightNode(right);
}


Operator::~Operator()
{
}

void Operator::print() const
{
   std::cout << "operator" << std::endl;
}
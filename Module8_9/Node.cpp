#include "stdafx.h"
#include "Node.h"

Node::Node()
{
}

Node::Node(Node* left, Node* right)
{
   setLeftNode(left);
   setRightNode(right);
}

Node::~Node()
{
   //std::cout << "node has been destructed";
}

double Node::evaluate() const
{
   return -3;
}
#pragma once

#include "Node.h"

class Node;

class Tree
{
public:
   Tree(Node* left, Node* right);
   ~Tree();

private:
   Node* rootNode;

};


#pragma once

#include <iostream>
#include <string>

class Node
{
public:
   Node();
   Node(Node* left, Node* right);
   virtual ~Node(); //virtual destructor

   virtual Node *clone() = 0; //pure virtual

   void setValue(double value)
   {
      this->value = value;
   }
   virtual double getValue() const
   {
      return this->value;
   }

   void setLeftNode(Node* left)
   {
      this->left = left;
   }
   Node* getLeftNode() const
   {
      return this->left;
   }

   void setRightNode(Node* right)
   {
      this->right = right;
   }
   Node* getRightNode() const
   {
      return this->right;
   }

   virtual Node* derivative(std::string character) = 0; //pure virtual
   virtual double evaluate() const = 0; //pure virtual
   virtual void print() const = 0; //pure virtual

protected:
   Node* left;
   Node* right;
   std::string data;
   double value;
};


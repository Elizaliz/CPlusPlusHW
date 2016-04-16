#pragma once
#include "Node.h"

class Constant : public Node
{
public:
   Constant(double number);
   ~Constant();

   Constant *clone() override
   {
      return new Constant(this->value);
   }

   virtual double getValue() const override;
   virtual void print() const override;
   virtual Node* derivative(std::string character) override; //pure virtual
   virtual double evaluate() const override;

private:
};


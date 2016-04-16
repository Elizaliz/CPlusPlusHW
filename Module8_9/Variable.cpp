#include "stdafx.h"
#include "Variable.h"

Variable::Variable(std::string data)
{
   setData(data);
}


Variable::~Variable()
{
}


double Variable::getValue() const
{
   return myVariables[this->data];
}

double Variable::evaluate() const
{
   return this->getValue();
}

void Variable::print() const
{
   std::cout << this->getData();
}

Node* Variable::derivative(std::string character)
{
   std::string value = this->getData();
   if (value.compare(character) == 0)
   {
      return new Constant(1);
   }
   else return new Constant(0);
}
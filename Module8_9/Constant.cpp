#include "stdafx.h"
#include "Constant.h"


Constant::Constant(double number)
{
   this->setValue(number);
}


Constant::~Constant()
{
}

double Constant::getValue() const
{
   return this->value;
}

double Constant::evaluate() const
{
   return this->value;
}

void Constant::print() const
{
   std::cout << this->getValue();
}

Node* Constant::derivative(std::string character)
{
   return new Constant(0);
   delete this;
}
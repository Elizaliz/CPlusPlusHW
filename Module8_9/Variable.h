#pragma once
#include "Node.h"
#include "Constant.h"
#include <string>
#include <map>

class Variable : public Node
{
public:
   Variable(std::string variable);
   ~Variable();

   Variable *clone() override
   {
      return new Variable(this->data);
   }

   static std::map<std::string, double> myVariables;

   void setData(std::string data)
   {
      this->data = data;
   }
   std::string getData() const
   {
      return this->data;
   }

   virtual double getValue() const override;
   virtual void print() const override;
   virtual Node* derivative(std::string character) override; //pure virtual
   virtual double evaluate() const override;

private:
   std::string data;
};


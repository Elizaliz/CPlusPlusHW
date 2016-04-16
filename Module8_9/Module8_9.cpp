// Module8_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Operator.h"
#include "Node.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "Constant.h"
#include "Variable.h"
#include "Tree.h"

std::map<std::string, double> Variable::myVariables;

int main()
{

   Node* tree2 = new Add(new Constant(2.3), new Constant(7));
   tree2->print();
   std::cout << "\nEvaluate: " << tree2->evaluate() << std::endl;
   tree2->derivative("X");
   tree2->print();
   std::cout << "\nDerivative: " << tree2->evaluate() << "\n" << std::endl;

   Node* tree3 = new Sub(new Variable("X"), new Variable("X"));
   tree3->print();
   std::cout << "\nEvaluate: " << tree3->evaluate() << std::endl;
   tree3->derivative("X");
   tree3->print();
   std::cout << "\nDerivative: " << tree3->evaluate() << "\n" << std::endl;

   Node* tree4 = new Mul(new Variable("Z"), new Constant(3.7));
   tree4->print();
   std::cout << "\nEvaluate: " << tree4->evaluate() << std::endl;
   tree4 = tree4->derivative("Z");
   tree4->print();
   std::cout << "\nDerivative: " << tree4->evaluate() << "\n" << std::endl;


   Node* tree5 = new Div(new Variable("X"), new Constant(3.7));
   tree5->print();
   std::cout << "\nEvaluate: " << tree5->evaluate() << std::endl;
   tree5 = tree5->derivative("X");
   tree5->print();
   std::cout << "\nDerivative: " << tree5->evaluate() << "\n" << std::endl;

   std::cout << "\n\nTesting with example given on HW sheet\n" << std::endl;

   Node* tree = new Add(new Mul(new Constant(2.3), new Variable("X")),
      new Mul(new Variable("Y"), new Sub(new Variable("Z"), new Variable("X"))));

   Variable::myVariables["X"] = 2.0;
   Variable::myVariables["Y"] = 3.0;
   Variable::myVariables["Z"] = 5.0;

   std::cout << "\nX: " << Variable::myVariables["X"] << "\nY: " << Variable::myVariables["Y"] << "\nZ: " << Variable::myVariables["Z"] << std::endl;
   tree->print();
   std::cout << "\nEvaluate: " << tree->evaluate() << std::endl;

   Node* treecopy = tree;
   treecopy->derivative("X");
   treecopy->print();
   std::cout << "\nDerivative X: " << treecopy->evaluate() << std::endl;

   Node* treecopy2 = tree;
   treecopy2->derivative("Y");
   treecopy2->print();
   std::cout << "\nDerivative Y: " << treecopy2->evaluate() << std::endl;

   Node* treecopy3 = tree;
   treecopy3->derivative("Z");
   treecopy3->print();
   std::cout << "\nDerivative Z: " << treecopy3->evaluate() << std::endl;

   return 0;
}
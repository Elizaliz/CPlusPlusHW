// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

//Input three integers and see what type of triangle we have.
void TestIfTriangle(int firstSide, int secondSide, int thirdSide)
{
	std::cout << "Let's see what type of triangle " << firstSide << ", " 
		<< secondSide << ", and " << thirdSide << " can make..." << std::endl;
	std::vector<int> TriangleSides;
	try {

		TriangleSides.push_back(firstSide);
		TriangleSides.push_back(secondSide);
		TriangleSides.push_back(thirdSide);
		std::sort(TriangleSides.begin(), TriangleSides.end());

	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}

	int smallSide = TriangleSides[0];
	int middleSide = TriangleSides[1];
	int bigSide = TriangleSides[2];

	if (smallSide <= 0)
	{
		std::cout << "Make sure all sides are positive integers, or else we don't have a triangle!" << std::endl;
	}
	else if (smallSide == middleSide && middleSide == bigSide)
	{
		std::cout << "You've got yourself an equalateral triangle!" << std::endl;
	}
	else if ((smallSide + middleSide == bigSide))
	{
		std::cout << "You can't make a triangle with these lengths. You just have a line!" << std::endl;
	}
	else if ((smallSide == middleSide) || (middleSide == bigSide) || (smallSide == bigSide))
	{
		std::cout << "You've got yourself an isosceles triangle!" << std::endl;
	}
	else if ((smallSide + middleSide > bigSide))
	{
		std::cout << "You've got yourself a scalene triangle with no sides that are equal!" << std::endl;
	}
	else
	{
		std::cout << "Your inputs are not what are expected! I need three positive integers." << std::endl;
	}

}


//Test Driver
int main()
{
	std::cout << "Entering Triangle Tests:" << std::endl;
	TestIfTriangle(2, -6, 7);
	TestIfTriangle(7, 1, 0);
	TestIfTriangle(14, 14, 14);
	TestIfTriangle(5, 5, 11);
	TestIfTriangle(5, 5, 10);
	TestIfTriangle(4, 7, 11);
	TestIfTriangle(2, -6, 'n'); //the n gets converted to ASCII
	TestIfTriangle(7, 1.53, 0); //the float gets truncated
	std::cout << "Goodbye!" << std::endl;

    return 0;
}

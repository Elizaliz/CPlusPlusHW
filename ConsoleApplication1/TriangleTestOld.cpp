// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	bool toContinue;
	char userResult;
	int firstSide;
	int secondSide;
	int thirdSide;

	do {
		firstSide = 0;
		secondSide = 0;
		thirdSide = 0;
		userResult = NULL;
		toContinue = false;

		std::cout << "Please enter the length of the three sides of your triangle: ";
		std::cin >> firstSide >> secondSide >> thirdSide;
		if (!std::cin)
		{
			std::cout << "An error has occured ";

		}
		else {
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
				return 0;
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

			std::cout << "Do you want to test another triangle? (y/n)" << std::endl;
			std::cin >> userResult;
			if (userResult == 'y')
			{
				toContinue = true;
			}

		}

	} while (toContinue);

	std::cout << "Goodbye!" << std::endl;

    return 0;
}


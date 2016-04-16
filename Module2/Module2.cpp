// Module2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>

class Statistic
{
public:
    Statistic() {}

    ~Statistic() {}

    //adds the number to the sequence you will analyze
    void Add(float n)
    {
        myNumbers.push_back(n);
    }

    void getNumbers()
    {
        std::cout << "These are my numbers: ";
        PrintNumbers();
        std::cout << std::endl;
    }

    void getAverage()
    {
        float avg = Average();
        std::cout << "This is the average: " << avg << std::endl;
    }

    void getSTD()
    {
        float std = STD();
        std::cout << "This is the standard deviation: " << std << std::endl;
    }
private:
    //returns the average of all the numbers in the sequence
    float Average()
    {
        return Sum(1) / TotalNumbers();
    }

    //returns the standard deviation of all the numbers in the sequence
    float STD()
    {
        return SquareRoot((Sum(2) - (Sum(1) * Sum(1) / TotalNumbers())) / (TotalNumbers() - 1));

    }

    int TotalNumbers()
    {
        return myNumbers.size();
    }

    void PrintNumbers()
    {
        for (float number : myNumbers)
        {
            std::cout << number << " ";
        }

    }

    float Square(float n)
    {
        return n*n;
    }

    float SquareRoot(double n)
    {
        return (float)sqrt(n);
    }

    float Sum(int power)
    {
        float totalSum = 0;
        if (power == 1)
        {
            for (float number : this->myNumbers)
            {
                totalSum += number;
            }
        }
        if (power == 2)
        {
            for (float number : this->myNumbers)
            {
                totalSum += Square(number);
            }
        }
        return totalSum;
    }
    std::vector<float> myNumbers;
};

int main()
{
    Statistic stats;
    stats.Add(5);
    stats.Add(10);
    stats.Add(12);
    stats.Add(6);
    stats.Add(15);
    stats.Add(4);

    stats.getNumbers();
    stats.getAverage();
    stats.getSTD();
    

    Statistic stats1;
    stats1.Add(5.4);
    stats1.Add(10);
    stats1.Add(12.3);
    stats1.Add(6.4);
    stats1.Add(15);
    stats1.Add(4.332);

    stats1.getNumbers();
    stats1.getAverage();
    stats1.getSTD();

    //using https://www.easycalculation.com/statistics/standard-deviation.php
    //I verified that my equations were correct
    return 0;
}


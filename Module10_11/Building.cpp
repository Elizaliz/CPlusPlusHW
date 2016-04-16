#include "stdafx.h"
#include "Building.h"
#include "Elevator.h"
#include <iostream>

Building::Building(int floors, int elevators) 
   : floors(floors), elevators(elevators)
{
}


Building::~Building()
{
}

void Building::updatePassengerQueue(int timer)
{
   while (timer >= allPassengers.top()->getStartTime())
   {
      if (allPassengers.top()->getStartFloor() - allPassengers.top()->getEndFloor() > 0)
      {
         downPassengerQueue.push(allPassengers.top());
         allPassengers.pop();
         std::cout << "passenger added to down queue" << std::endl;
      }

      else
      {
         upPassengerQueue.push(allPassengers.top());
         allPassengers.pop();
         std::cout << "passenger added to up queue" << std::endl;
      }
   }
}
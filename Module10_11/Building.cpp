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
         //adding the passenger from the queue into the corresponding floor's priority queue
         downPassengerByFloorQueue[allPassengers.top()->getStartFloor()].push(allPassengers.top());
         allPassengers.pop();
         std::cout << "passenger added to down queue" << std::endl;
      }

      else
      {
         upPassengerByFloorQueue[allPassengers.top()->getStartFloor()].push(allPassengers.top());
         allPassengers.pop();
         std::cout << "passenger added to up queue" << std::endl;
      }
   }
}
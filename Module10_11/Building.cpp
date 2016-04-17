#include "stdafx.h"
#include "Building.h"
#include "Elevator.h"
#include "Timer.h"
#include <iostream>

Building::Building(int numFloors, int elevators, int totalTimeToMoveFloor, int totalTimeToStop)
   : floors(floors)
{
   timer = Timer::getInstance();
   initiateElevators(elevators, totalTimeToMoveFloor, totalTimeToStop);
   initiateFloors(numFloors);
}


Building::~Building()
{
}

void Building::initiateElevators(int numElevators, int totalTimeToMoveFloor, int totalTimeToStop)
{
   for (int i = 0; i < numElevators; i++)
   {
      Elevator* newElevator = new Elevator(10, 2);
      newElevator->setState(Elevator::STOPPED);
      this->elevators.push_back(newElevator);
   }
}

void Building::initiateFloors(int numFloors)
{
   for (int i = 0; i < numFloors; i++)
   {
      Floor* newFloor = new Floor();
      this->floors.push_back(newFloor);
   }
}

void Building::updatePassengerQueue()
{
   while (timer->getTime() >= allPassengers.top()->getStartTime())
   {
      // checking if passenger should be added to up or down queue
      if (allPassengers.top()->getStartFloor() - allPassengers.top()->getEndFloor() > 0)
      {
         //adding the passenger from the queue into the corresponding floor's priority queue
         floors[allPassengers.top()->getStartFloor()]->downPassengerFloorQueue.push(allPassengers.top());
         allPassengers.pop();
         std::cout << "passenger added to down queue" << std::endl;
      }

      else
      {
         //adding the passenger from the queue into the corresponding floor's priority queue
         floors[allPassengers.top()->getStartFloor()]->upPassengerFloorQueue.push(allPassengers.top());
         allPassengers.pop();
         std::cout << "passenger added to up queue" << std::endl;
      }
   }
}

Passenger* Building::getNextPassenger()
{
   Passenger* nextPassenger = this->allPassengers.top();
   this->allPassengers.pop();
   return nextPassenger;
}
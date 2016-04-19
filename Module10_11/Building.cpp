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
	  newFloor->setFloor(i + 1); //there is no 0th floor
      this->floors.push_back(newFloor);
   }
}

bool Building::updatePassengerQueue()
{
	bool personAdded = false;
   while (timer->getTime() >= allPassengers.top()->getStartTime())
   {
      // checking if passenger should be added to up or down queue
      if (allPassengers.top()->getStartFloor() - allPassengers.top()->getEndFloor() > 0)
      {
         //adding the passenger from the queue into the corresponding floor's priority queue
         this->floors[allPassengers.top()->getStartFloor()]->downPassengerFloorQueue.push(allPassengers.top());
		 //this->downPassengerQueue.push(allPassengers.top());
		 this->allPassengers.pop();
         std::cout << "passenger added to down queue" << std::endl;
		 personAdded = true;
      }

      else
      {
         //adding the passenger from the queue into the corresponding floor's priority queue
         this->floors[allPassengers.top()->getStartFloor()]->upPassengerFloorQueue.push(allPassengers.top());
		 //this->upPassengerQueue.push(allPassengers.top());
		 this->allPassengers.pop();
         std::cout << "passenger added to up queue" << std::endl;
		 personAdded = true;
	  }
   }
   return personAdded;
}

Passenger* Building::getNextPassenger()
{
	Passenger* nextPassenger;
	// if the down person has been waiting longer, take him
	
	//if (downPassengerQueue.top()->getStartTime() < upPassengerQueue.top()->getStartTime())
	//{
	//	nextPassenger = downPassengerQueue.top();
	//	downPassengerQueue.pop();
	//}
	//else //otherwise, take the up person has been waiting longer
	//{
	//	nextPassenger = upPassengerQueue.top();
	//	upPassengerQueue.pop();
	//}
	//Passenger* nextPassenger = this->allPassengers.top();
   //this->allPassengers.pop();
	//nextPassenger = personfirstInLine.top().front();
	std::priority_queue<Passenger, std::vector< Passenger* >, customSort> personNextInLine;
	for (auto currentFloor : floors)
	{
		if (!this->anotherElevatorGoingToThatFloor(currentFloor->getFloor()))
		{
			if (!currentFloor->downPassengerFloorQueue.empty())
			{
				personNextInLine.push(currentFloor->downPassengerFloorQueue.front());
			}
			else if (!currentFloor->upPassengerFloorQueue.empty())
			{
				personNextInLine.push(currentFloor->upPassengerFloorQueue.front());
			}
		}
	}
	nextPassenger = personNextInLine.top();
	//personfirstInLine.pop();
   return nextPassenger;
}

bool Building::anotherElevatorGoingToThatFloor(int floor)
{
	bool isAnotherElevatorGoingToThatFloor = false;
	for (Elevator* elevator : elevators)
	{
		if (elevator->getDestinationFloor())
		{
			isAnotherElevatorGoingToThatFloor = true;
		}
	}
	return isAnotherElevatorGoingToThatFloor;
}
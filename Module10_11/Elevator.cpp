#include "stdafx.h"
#include "Elevator.h"


Elevator::Elevator(int totalTimeToMoveFloor, int totalTimeToStop)
   : totalTimeToMoveFloors(totalTimeToMoveFloor), totalTimeToStop(totalTimeToStop)
{
   timer = Timer::getInstance();
}

Elevator::~Elevator()
{
}

void Elevator::setState(State state)
{
   this->state = state;
}

Elevator::State Elevator::getState()
{
   return this->state;
}

int Elevator::getNumPassengers()
{
   return this->numPassengers;
}

bool Elevator::checkIfPassengerOnElevatorWantToGetOff()
{
   for (Passenger* passenger : elevatorPassengers)
   {
      if (this->currentFloor == passenger->getEndFloor())
      {
         return true;
      }
   }
   return false;
}

bool Elevator::checkIfPassengerOnNextFloorWantToGetOn(Floor* currentFloor)
{
   if (this->getState() == MOVING_DOWN) //only look at those going down
   {
      if (!currentFloor->downPassengerFloorQueue.empty())
      {
         return true;
      }
   }
   else //elevator moving up, so only collect those people
   {
      if (!currentFloor->upPassengerFloorQueue.empty())
      {
         return true;
      }
   }
   return false;
}
int Elevator::getCurrentFloor()
{
   return this->currentFloor;
}

int Elevator::getTimeMovingToNextFloor()
{
   return this->timeMovingToNextFloor;
}

int Elevator::getTotalTimeToMoveFloors()
{
   return this->timeMovingToNextFloor;
}

void Elevator::resetTimeStopping() 
{
   this->timeStopping = 0;

}

void Elevator::resetTimeMovingToNextFloor()
{
   this->timeMovingToNextFloor = 0;
}

void Elevator::incrementTimeStoppingFloors()
{
   if (timeStopping < totalTimeToStop)
   {
      timeStopping++;
   }
   else
   {
      this->setState(STOPPED);
   }
}

void Elevator::incrementTimeMovingFloors()
{
   if (timeMovingToNextFloor < totalTimeToMoveFloors)
   {
      timeMovingToNextFloor++;
   }
}

void Elevator::updateFloor()
{
   if (getState() == MOVING_DOWN)
   {
      if (this->currentFloor >= 1) //first floor
      {
         this->currentFloor--;
      }
      else // currentFloor == 0
      {
         this->setState(STOPPING);
         this->resetTimeMovingToNextFloor();
      }
   }
   else //(getState() == MOVING_DOWN)
      if (this->currentFloor != 100)
      {
         this->currentFloor++;
      }
      else // currentFloor == 100
      {
         this->setState(STOPPING);
         this->resetTimeMovingToNextFloor();
      }
}

void Elevator::letPassengersOff()
{
   int passengerIndex = 0;
   for (Passenger* passenger : elevatorPassengers)
   {
      if (this->currentFloor == passenger->getEndFloor())
      {
         passenger->setState(Passenger::ARRIVED);
         passenger->setGotOffElevatorTime(timer->getTime());
         elevatorPassengers.erase(elevatorPassengers.begin() + passengerIndex);
      }
      else
      {
         passengerIndex++;
      }
   }
}

void Elevator::letPassengersOn(Floor* currentFloor)
{
   if (this->getState() == MOVING_DOWN) //only look at those going down
   {
      while (!currentFloor->downPassengerFloorQueue.empty() && this->numPassengers <= MAX_CAPACITY)
      {//I want access to the floor queues
         elevatorPassengers.push_back(currentFloor->downPassengerFloorQueue.top());
         currentFloor->downPassengerFloorQueue.pop();
      }
   }
   else //elevator moving up, so only collect those people
   {
      if (!currentFloor->upPassengerFloorQueue.empty() && this->numPassengers <= MAX_CAPACITY)
      {
         elevatorPassengers.push_back(currentFloor->upPassengerFloorQueue.top());
         currentFloor->upPassengerFloorQueue.pop();
      }
   }
}

void Elevator::assignNextPassenger(Passenger* passenger)
{
   if (passenger->getStartFloor() > this->currentFloor)
   {
      this->setState(MOVING_UP);
   }
   else
   {
      this->setState(MOVING_DOWN);
   }
   this->setDestinationFloor(passenger->getStartFloor());
}

void Elevator::setDestinationFloor(int floor)
{
   this->destinationFloor = floor;
}
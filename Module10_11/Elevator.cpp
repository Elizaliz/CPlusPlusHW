#include "stdafx.h"
#include "Elevator.h"


Elevator::Elevator()
{
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

void Elevator::checkIfPassengerOnElevatorWantToGetOff()
{

   for (Passenger* passenger : elevatorPassengerQueue)
   {
      if (this->currentFloor == passenger->getEndFloor())
      {
         passenger->setState(Passenger::ARRIVED); //do I want to move this to the passenger side of things?
         //passenger->setEndTime(timer)
      }
   }
}

void Elevator::checkIfPassengerOnNextFloorWantToGetOn()
{
   if (this->getState() == MOVING_DOWN)
   {
   }
   else
   {

   }

}
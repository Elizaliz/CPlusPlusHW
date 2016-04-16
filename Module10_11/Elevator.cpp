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
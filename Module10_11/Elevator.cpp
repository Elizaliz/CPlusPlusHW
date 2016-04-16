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
   return state;
}
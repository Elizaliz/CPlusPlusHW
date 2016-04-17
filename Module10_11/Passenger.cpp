#include "stdafx.h"
#include "Passenger.h"


Passenger::Passenger(int startTime, int startFloor, int endFloor)
   : startTime(startTime), startFloor(startFloor), endFloor(endFloor)
{
}


Passenger::~Passenger()
{
}


void Passenger::setState(State state)
{
   this->state = state;
}

Passenger::State Passenger::getState()
{
   return state;
}

int Passenger::getStartTime()
{
   return this->startTime;
}

int Passenger::getStartFloor()
{
   return this->startFloor;
}

int Passenger::getEndFloor()
{
   return this->endFloor;
}

void Passenger::setGotOnElevatorTime(int time)
{
   this->gotOnElevatorTime = time;
}

void Passenger::setGotOffElevatorTime(int time)
{
   this->gotOffElevatorTime = time;
}
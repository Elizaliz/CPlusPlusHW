#pragma once
//#define MAX_CAPACITY = 8;
#include "Floor.h"
//#include <iostream>
#include <memory>

class Elevator
{
public:
   enum State { UP, DOWN, MOVING_UP, MOVING_DOWN, STOPPING, STOPPED };
   Elevator();
   ~Elevator();

   void setState(State state);

   State getState();

private:
   int beginningFloor;
   int destinationFloor;

   std::unique_ptr<Floor> firstFloor;
   std::unique_ptr<Floor> secondFloor;
   //int currentTimeDuration;
   //int current allotedTime

   int numPassengers;
   State state;
   //if in moving state, tick through
};


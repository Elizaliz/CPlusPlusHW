#pragma once
#define MAX_CAPACITY    8
#include "Floor.h"
//#include <iostream>
#include <memory>

class Elevator
{
public:
   enum State { MOVING_UP, MOVING_DOWN, STOPPING, STOPPED };
   Elevator();
   ~Elevator();

   void setState(State state);

   State getState();
   int getNumPassengers();

   // sort using a custom function object
   struct customSort {
      bool operator()(Passenger* a, Passenger* b)
      {
         return a->getStartTime() < b->getStartTime();
      }
   };

   std::priority_queue<Passenger, std::vector< Passenger* >, customSort> elevatorPassengerQueue;


private:
   //int beginningFloor;
   int destinationFloor;//might be a pointer to a floor
   //int intermediateFloor;
   int currentFloor; //might be a pointer to a floor
   //std::unique_ptr<Floor> firstFloor;
   //std::unique_ptr<Floor> secondFloor;
   //int currentTimeDuration;
   //int current allotedTime

   int numPassengers;
   State state;
   //if in moving state, tick through
};


#pragma once
#include <algorithm>
#include <vector>
#include <queue>
#include "Passenger.h"

class Building
{
public:
   Building(int floors, int elevators);
   ~Building();

   //auto sortPassengersByDelta(std::vector< Passenger* >);

   // sort using a custom function object
   struct customSort {
      bool operator()(Passenger* a, Passenger* b)
      {
         return a->getStartFloor() < b->getStartFloor();
      }
   };

   //std::sort(std::begin(myPassengers), std::end(myPassengers), customSort);
   std::priority_queue<Passenger, std::vector< Passenger* >, customSort> passengerQueue;

private:
   int floors;
   int elevators;

   int avgWaitTime;
   int avgTravelTime;

   //compare method-- is it the same for all elevators?
   //close up, close down, far up, far down
};


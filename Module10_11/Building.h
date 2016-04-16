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
         return a->getStartTime() < b->getStartTime();
      }
   };

   //std::sort(std::begin(myPassengers), std::end(myPassengers), customSort);
   std::priority_queue<Passenger, std::vector< Passenger* >, customSort> allPassengers;
   //std::priority_queue<Passenger, std::vector< Passenger* >, customSort> downPassengerQueue;
   //std::priority_queue<Passenger, std::vector< Passenger* >, customSort> upPassengerQueue;

   std::vector< std::priority_queue<Passenger, std::vector< Passenger* >, customSort> > downPassengerByFloorQueue;
   std::vector< std::priority_queue<Passenger, std::vector< Passenger* >, customSort> > upPassengerByFloorQueue;


   std::vector<Elevator> elevators;

   //checks to see if any passengers on the top of 
   void updatePassengerQueue(int timer);
private:
   int floors;
   int elevators;

   int avgWaitTime;
   int avgTravelTime;

   //compare method-- is it the same for all elevators?
   //close up, close down, far up, far down
};


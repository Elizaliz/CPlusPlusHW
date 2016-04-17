#pragma once
#include "Passenger.h"
#include <queue>

class Floor
{
public:
   Floor();
   ~Floor();

   // sort using a custom function object
   struct customSort {
      bool operator()(Passenger* a, Passenger* b)
      {
         return a->getStartTime() < b->getStartTime();
      }
   };
   //should have its own queue of folks waiting
   std::priority_queue<Passenger, std::vector< Passenger* >, customSort> floorPassengerQueue;

private:


};


#pragma once
#include <algorithm>
#include <vector>
#include <queue>
#include "Passenger.h"
#include "Elevator.h"

class Building
{
public:
   Building(int floors, int elevators, int totalTimeToMoveFloor, int totalTimeToStop);
   ~Building();

   //auto sortPassengersByDelta(std::vector< Passenger* >);

   // sort using a custom function object
   struct customSort {
      bool operator()(Passenger* a, Passenger* b)
      {
         return a->getStartTime() > b->getStartTime();
      }
   };

   // organize by first person waiting on each of the floors
   struct customSort2 { 
	   bool operator()(std::queue<Passenger*> a, std::queue<Passenger*> b)
	   {
		   //return a[0]->getStartTime() < b[0]->getStartTime();
		   return a.front()->getStartTime() < b.front()->getStartTime();
	   }
   };


   //std::sort(std::begin(myPassengers), std::end(myPassengers), customSort);
   std::priority_queue<Passenger, std::vector< Passenger* >, customSort> allPassengers;
   //std::priority_queue<Passenger, std::vector< Passenger* >, customSort> downPassengerQueue;
   //std::priority_queue<Passenger, std::vector< Passenger* >, customSort> upPassengerQueue;

   //std::vector< std::priority_queue<Passenger, std::vector< Passenger* >, customSort> > downPassengerByFloorQueue;
   //std::vector< std::priority_queue<Passenger, std::vector< Passenger* >, customSort> > upPassengerByFloorQueue;

   std::priority_queue< std::queue<Passenger*>, std::vector<std::queue<Passenger*>>, customSort2> personfirstInLine;
   //std::priority_queue<Passenger, std::vector< Passenger* >, customSort> personNextInLine;


   std::vector<Elevator*> elevators;
   std::vector<Floor*> floors;

   //checks to see if any passengers on the top of 
   bool updatePassengerQueue();
   Passenger* getNextPassenger();
   bool anotherElevatorGoingToThatFloor(int floor);

private:
   int avgWaitTime;
   int avgTravelTime;
   Timer *timer;
   int numFloors;

   void initiateElevators(int elevators, int totalTimeToMoveFloor, int totalTimeToStop);
   void initiateFloors(int numFloors);

   //compare method-- is it the same for all elevators?
   //close up, close down, far up, far down
};


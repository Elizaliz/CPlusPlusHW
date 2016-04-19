#pragma once
#define MAX_CAPACITY    8
#include "Floor.h"
#include <memory>
#include "Passenger.h"
#include <queue>
#include "Timer.h"

class Elevator
{
public:
   enum State { MOVING_UP, MOVING_DOWN, STOPPING, STOPPED };
   Elevator(int totalTimeToMoveFloor, int totalTimeToStop);
   ~Elevator();

   void setState(State state);

   State getState();
   int getNumPassengers();
   void letPassengersOff();
   void letPassengersOn(Floor* nextFloor);

   // sort using a custom function object
   //struct customSort {
   //   bool operator()(Passenger* a, Passenger* b)
   //   {
   //      return a->getStartTime() < b->getStartTime();
   //   }
   //};

   //std::priority_queue<Passenger, std::vector< Passenger* >, customSort> elevatorPassengerQueue;
   std::vector< Passenger*> elevatorPassengers;

   bool checkIfPassengerOnElevatorWantToGetOff();
   bool checkIfPassengerOnNextFloorWantToGetOn(Floor* nextFloor);

   void incrementTimeMovingFloors();
   void incrementTimeStoppingFloors();

   void updateFloor();

   int getTimeMovingToNextFloor();
   int getTotalTimeToMoveFloors();

   void resetTimeStopping();
   void resetTimeMovingToNextFloor();

   void setcurrentFloor(int);
   int getCurrentFloor();

   void setDestinationFloor(int floor);
   int getDestinationFloor();

   void assignNextPassenger(Passenger* passenger);

private:
   Timer *timer;

   int destinationFloor;
   int currentFloor;

   int timeMovingToNextFloor; // up until 10 or 5
   int totalTimeToMoveFloors;
   int timeStopping; // up until 2
   int totalTimeToStop;

   int numPassengers;
   State state;
   //if in moving state, tick through
};


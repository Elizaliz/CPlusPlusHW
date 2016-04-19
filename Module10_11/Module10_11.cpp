// Module10_11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "Building.h"
#include "Passenger.h"
#include "Elevator.h"
#include "Floor.h"
#include "Timer.h"
#include <iostream> // input output stream
#include <fstream> // file stream
#include <string>

int main()
{
   Building *mainBuilding = new Building(100, 4, 10, 2);
   Timer *timer = Timer::getInstance();

   //read in numbers from file
   //populate 502 passengers

   //file dealio
   // ifstream constructor opens the file in parent folder
   std::ifstream inPassengerFile("C:\\Users\\lizsk\\Source\\Repos\\CPlusPlusHW\\Module10_11\\Mod10_assignment_Elevators.csv", std::ios::in);
   if (inPassengerFile)
   {
      int StartTime = 0;
      int StartFloor = 0;
      int EndFloor = 0;
      char comma = 0;
      std::string dummy;

      inPassengerFile >> dummy >> dummy >> dummy >> dummy;//ignores first row

      while (inPassengerFile >> StartTime >> comma >> StartFloor >> comma >> EndFloor)
      {
         Passenger* newPassenger = new Passenger(StartTime, StartFloor, EndFloor);
         newPassenger->setState(Passenger::WAITING);
         mainBuilding->allPassengers.push(newPassenger);
      }

   }

   while (true)//!mainBuilding->allPassengers.empty() && !mainBuilding->downPassengerByFloorQueue.empty()
	  //&& !mainBuilding->upPassengerByFloorQueue.empty()) //go until people are all satisfied
   {
	   //if (mainBuilding->updatePassengerQueue()) //this will check starttime of passenger and add to priority queue (which organizes by startTime
	   //{
		   //go through elevators and make decisions
	   for (Elevator* elevator : mainBuilding->elevators) //elevatorList is a vector
	   {
		   //if (mainBuilding->updatePassengerQueue())
		   //{
			   switch (elevator->getState())
			   {

			   case (Elevator::MOVING_UP):
				   if (elevator->getTimeMovingToNextFloor() == elevator->getTotalTimeToMoveFloors())
				   {
					   //check the floor and see if anyone on the elevator wants to get off at the next floor
					   elevator->checkIfPassengerOnElevatorWantToGetOff(); //needs floor, passengers on elevator
					   if (elevator->getNumPassengers() < MAX_CAPACITY)
					   {
						   //check the floor and see if anyone on the floor is waiting
						   if (elevator->checkIfPassengerOnNextFloorWantToGetOn(mainBuilding->floors[elevator->getCurrentFloor() + 1]))
						   {
							   elevator->setState(Elevator::STOPPING);//stop at the next floor
							   elevator->resetTimeStopping(); //resetting the value
						   }
					   }
					   else
					   {
						   elevator->updateFloor();
					   }
				   }
				   else
				   {
					   elevator->incrementTimeMovingFloors();
				   }
				   break;

			   case (Elevator::MOVING_DOWN):
				   //check at the very end of the MOVINGUP || MOVINGDOWN
				   if (elevator->getTimeMovingToNextFloor() == elevator->getTotalTimeToMoveFloors())
				   {
					   //check the floor and see if anyone on the elevator wants to get off at the next floor
					   elevator->checkIfPassengerOnElevatorWantToGetOff(); //needs floor, passengers on elevator
					   if (elevator->getNumPassengers() < MAX_CAPACITY)
					   {
						   //check the floor and see if anyone on the floor is waiting
						   if (elevator->checkIfPassengerOnNextFloorWantToGetOn(mainBuilding->floors[elevator->getCurrentFloor() - 1]))
						   {
							   elevator->setState(Elevator::STOPPING);//stop at the next floor
							   elevator->resetTimeStopping(); //resetting the value
						   }
					   }
					   else
					   {
						   elevator->updateFloor();
					   }
				   }
				   else
				   {
					   elevator->incrementTimeMovingFloors();
				   }
				   break;

			   case (Elevator::STOPPING):
				   // count to length of time it takes to stop
				   elevator->incrementTimeStoppingFloors();
				   break;

			   case (Elevator::STOPPED):
				   //if people want to get off, let them get off
				   elevator->letPassengersOff();
				   //if people want to get on, let them get on (as long as <=8)
				   elevator->letPassengersOn(mainBuilding->floors[elevator->getCurrentFloor()]);
				   //figure out which floor to go to as the end goal
				   if (elevator->elevatorPassengers.empty())
				   {
					   //get next person off priority queue and set the end location
					   elevator->assignNextPassenger(mainBuilding->getNextPassenger());
				   }
				   break;

			   }
	   }
	   timer->tick();
	   
   }

   //add up and take the average of the total wait time
   //add up and take the average of the total travel time
   return 0;
}


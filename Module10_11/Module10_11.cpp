// Module10_11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "Building.h"
#include "Passenger.h"
#include "Elevator.h"
#include "Floor.h"
#include <iostream> // input output stream
#include <fstream> // file stream
#include <string>



int main()
{
   Building *mainBuilding = new Building(100, 4);

   //read in numbers from file
   //populate 502 passengers

   //file dealio
   // ifstream constructor opens the file in parent folder
   std::ifstream inPassengerFile("C:\\Users\\lizsk\\Documents\\APL EP\\C++\\Module 11\\Mod10_assignment_Elevators.csv", std::ios::in);
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
         mainBuilding->passengerQueue.emplace(newPassenger);
      }

   }


   int timer = 0;

   while (!mainBuilding->passengerQueue.empty())//go until people are all satisfied
   {
      building->updatePassengerQueue(timer); //this will check starttime of passenger and add to priority queue (which organizes by startTime
      //I've got my priority queue
      //if person at front of queue startTime has been reached, get on elevator
      //else continue until next tick

      //each elevator has a priority queue that has up to 8 people
      //if empty, move to next floor up(?)

      //each floor has a priority queue

      //go through elevators and make decisions
      for (Elevator elevator : elevatorList) //elevatorList is a vector
      {
         switch (elevator.getState())
         {
         case (Elevator::State::MOVING_UP) :
            //check the floor and see if anyone on the elevator wants to get off at the next floor
            //check only in the beginning or at the very end of the MOVINGUP
            checkIfPassengerOnElevatorWantToGetOff(); //needs floor, passengers on elevator
            if (elevator.getNumPassengers() < MAX_CAPACITY)
            {
               //check the floor and see if anyone on the floor is waiting
               checkIfPassengerOnNextFloorWantsToGetOn();
               //count to length of time it takes to get to the floor
            }
            break;

         case (Elevator::State::MOVING_DOWN) :
            //check the floor and see if anyone on the floor is waiting
            //check the floor and see if anyone on the elevator wants to get off at the next floor
            //count to length of time it takes to get to the floor
            break;

         case (Elevator::State::STOPPING) :
            // count to length of time it takes to stop
            break;

         case (Elevator::State::STOPPED) :
            //if people want to get off, let them get off
            //if people want to get on, let them get on (as long as <=8)
            //figure out which floor to go to as the end goal
            break;

         default:
         }

      }




      timer++;
   }

   //add up and take the average of the total wait time
   //add up and take the average of the total travel time



   return 0;
}


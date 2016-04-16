// Module10_11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "Building.h"
#include "Passenger.h"
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

      int timer = 0;
      
      while (!mainBuilding->passengerQueue.empty())//go until people are all satisfied
      {
         //I've got my priority queue
         //if person at front of queue startTime has been reached, get on elevator
         //else continue until next tick

         //each elevator has a priority queue that has up to 8 people
         //if empty, move to next floor up(?)

         //each floor has a priority queue





         timer++;
      }

   }

   return 0;
}


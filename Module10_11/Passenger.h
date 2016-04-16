#pragma once
class Passenger
{
public:
   enum State {WAITING, IN_TRANSIT, ARRIVED};
   Passenger(int startTime, int startFloor, int endFloor);
   ~Passenger();

   void setState(State state);
   State getState();

   int getStartFloor();
   int getEndFloor();

private:
   int startFloor;
   int endFloor;
   int startTime;

   int waitTime;
   int travelTime;

   State state;
};


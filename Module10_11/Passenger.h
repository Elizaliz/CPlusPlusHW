#pragma once
class Passenger
{
public:
   enum State {WAITING, ON_ELEVATOR, ARRIVED};
   enum DIRECTION {UP, DOWN};
   Passenger(int startTime, int startFloor, int endFloor);
   ~Passenger();

   void setState(State state);
   State getState();
   int getStartTime();
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


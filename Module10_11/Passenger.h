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

   void setGotOnElevatorTime(int time);
   void setGotOffElevatorTime(int time);

private:
   int startFloor;
   int endFloor;
   int startTime; //started waiting time

   int gotOnElevatorTime;
   int gotOffElevatorTime;

   int waitTime;
   int travelTime;

   State state;
};


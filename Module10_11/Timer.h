#pragma once
//singleton design

class Timer
{
public:
   static Timer* getInstance();

   int getTime();
   void tick();

protected:
   Timer();
   Timer(const Timer&);
   Timer& operator= (const Timer&);

   int time;
};


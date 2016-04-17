#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
{

}
Timer* Timer::getInstance()
{
   static Timer timer;
   return &timer;
   //time = 0;
}

void Timer::tick()
{
   this->time++;
}

int Timer::getTime()
{
   return this->time;
}
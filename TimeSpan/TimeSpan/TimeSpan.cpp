#include "TimeSpan.h"
#include <iostream>
#include <math.h>

using namespace std;


TimeSpan::TimeSpan()
{
  hours=0;
  minutes=0;
  seconds=0;
}

TimeSpan::TimeSpan(double sec)
{
  seconds=sec;
  convert(hours, minutes, seconds);
  normalize(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double min, double sec)
{
  minutes=min;
  seconds=sec;
  convert(hours, minutes, seconds);
  normalize(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double hour, double min, double sec)
{
  hours=hour;
  minutes=min;
  seconds=sec;
  convert(hours, minutes, seconds);
  normalize(hours, minutes, seconds);
}

int TimeSpan:: getHours()const
{
  cout<<hours;
  return hours;
}

int TimeSpan:: getMinutes()const
{
  cout<<minutes;
  return minutes;
}

int TimeSpan::getSeconds()const
{
  return seconds;
}

void TimeSpan::setHours(int hour)
{
  hours=hour;
  normalize(hours, minutes, seconds);
}

void TimeSpan::setMinutes(int min)
{
  minutes=min;
  normalize(hours, minutes, seconds);
}

void TimeSpan::setSeconds(int sec)
{
  seconds=sec;
  normalize(hours, minutes, seconds);
}

void TimeSpan::normalize(double &hours, double &minutes, double &seconds)const
{
  hours=int (hours);
  minutes=int (minutes);
  seconds= int (seconds);
    
  while(seconds<0)
  {
    if(minutes>0)
    {
      minutes--;
      seconds+=60;
    }
    else if(minutes==0 && hours>0)
    {
      minutes--;
      seconds+=60;
    }
    else if(minutes<0)
    {
      minutes--;
      seconds+=60;
    }
  }
  while(seconds >59)
  {
    minutes++;
    seconds-=60;
    
    if(seconds>0 && minutes<0)
    {
      minutes++;
      seconds-=60;
    }
  }
  while(minutes<0)
  {
    if(hours>0)
    {
      hours--;
      minutes+=60;
    }
    else if(minutes<-59)
    {
      hours--;
      minutes+=60;
    }
  }
  while(minutes>59)
  {
    hours++;
    minutes-=60;
  }

}

TimeSpan TimeSpan::operator+(const TimeSpan &dur2)const
{
  TimeSpan dur1;
  dur1.hours=hours+dur2.hours;
  dur1.minutes=minutes+dur2.minutes;
  dur1.seconds=seconds+dur2.seconds;
  normalize(dur1.hours, dur1.minutes, dur1.seconds);
  return (dur1);
}

TimeSpan TimeSpan::operator-(const TimeSpan &dur2)const
{
  TimeSpan dur1;
  dur1.hours=hours-dur2.hours;
  dur1.minutes=minutes-dur2.minutes;
  dur1.seconds=seconds-dur2.seconds;
  normalize(dur1.hours, dur1.minutes, dur1.seconds);
  return (dur1);
}

TimeSpan TimeSpan::operator+=(const TimeSpan &dur2)
{
  hours=hours+dur2.hours;
  minutes=minutes+dur2.minutes;
  seconds=seconds+dur2.seconds;
  normalize(hours, minutes, seconds);
  return (*this);
}

TimeSpan TimeSpan::operator-=(const TimeSpan &dur2)
{
  hours=hours-dur2.hours;
  minutes=minutes-dur2.minutes;
  seconds=seconds-dur2.seconds;
  normalize(hours, minutes, seconds);
  return (*this);
}

bool  TimeSpan:: operator==(const TimeSpan &dur)const
{
  return((hours==dur.hours) && (minutes==dur.minutes) && (seconds==dur.seconds));
}

bool TimeSpan:: operator!=(const TimeSpan &dur)const
{
  return ((hours!=dur.hours) || (minutes!=dur.minutes) || (seconds!=dur.seconds));
}

ostream & operator<<(ostream & out, const TimeSpan &dur)
{
  out<<"Hours: "<<dur.hours<<" Minutes: "<<dur.minutes <<" Seconds: "<<dur.seconds<<endl;
  return out;
}

istream & operator>>(istream & in, TimeSpan &dur)
{
  in >> dur.hours >> dur.minutes >> dur.seconds;
  dur.convert(dur.hours, dur.minutes, dur.seconds);
  dur.normalize(dur.hours, dur.minutes, dur.seconds);
  return in;
}
////////////////////////////////////////////////////////////////
//this function is used to convert/cast any given number to ints
////////////////////////////////////////////////////////////////
void TimeSpan::convert(double &hours, double &minutes, double &seconds)
{
  double tempHours=hours;
  double tempMinutes=minutes;
  double tempSeconds=seconds;
    
  hours= int (tempHours);
  minutes= fmod(60*tempHours, 60) + int (tempMinutes);
  seconds= fmod(60*tempMinutes, 60) + int (tempSeconds);
}
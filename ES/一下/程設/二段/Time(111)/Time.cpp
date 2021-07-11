#include<iostream>
#include<iomanip>
#include"Time.h"
using namespace std;

//(a)
Time::Time(int h, int m , int s)
:totalSecond(h*3600+m*60+s)
{
	
}
//(b)
//Time::Time(int h, int m , int s)
//{
//	setTime(h ,m ,s);
//}

//(c)
void Time::setTime(int h, int m , int s)
{
    setHour(h);
	setMinute(m );
    setSecond(s);
}

//(d)
void Time::setHour(int h)
{
	int m ,s;
	m =getMinute();
	s=getSecond();
	totalSecond=h*3600+m*60+s;
}

void Time::setMinute(int m)
{
	int h ,s;
	h=getHour();
	s=getSecond();
	totalSecond=h*3600+m*60+s;
}

void Time::setSecond(int s)
{
	int h,m ;
	h=getHour();
	m =getMinute();
	totalSecond=h*3600+m*60+s;
}

int Time::getHour() const
{
	return totalSecond/3600;
}

int Time::getMinute() const
{
	int m ;
	m =totalSecond%3600;
	m =m/60;
	return m ; 
}

int Time::getSecond() const
{
	return totalSecond%60;
}

void Time::printUniversal() const
{
	cout<<getHour()<<":"<<getMinute()<<":"<<getSecond()<<endl;
}

void Time::printStandard() const
{
	if(getHour()>=12)
	{
		 if(getHour()==12)
		cout<<12 <<":"<<getMinute()<<":"<<getSecond()<<endl;
		else
	    cout<<getHour()%12 <<":"<<getMinute()<<":"<<getSecond()<<endl;
	}
   
	else
	printUniversal();
}
//(e) ¦bprint¸òget¥[¤Wconst 

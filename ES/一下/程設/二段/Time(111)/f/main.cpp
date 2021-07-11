#include<iostream>
#include<iomanip>
#include"Time.h"
using namespace std;

int main()
{
	Time x(13,3,6);
	Time y;
	x.printUniversal();
	y.printUniversal();
	x.setHour(18).setMinute(0).setSecond(0);
	y.setTime(18,0,0).printStandard();
	x.printUniversal();
	y.printUniversal();
		
	return 0;
}

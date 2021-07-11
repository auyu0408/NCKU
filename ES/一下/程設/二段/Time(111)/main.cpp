#include<iostream>
#include<iomanip>
#include"Time.h"
using namespace std;

int main()
{
	Time x(13,3,6);
	Time y(4,5,59);
	const Time noon(12,0,0);
	x.printUniversal();
	x.printStandard();
	y.printUniversal();
	y.printStandard();
	noon.printUniversal();
	noon.printStandard();	
	return 0;
}

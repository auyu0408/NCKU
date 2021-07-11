#include<iostream>
using namespace std;
#include"Triangle.h"

Triangle::Triangle(string name,int l,int h)
:Shape(name)
{
	length=l;
	high=h;
}

double Triangle::CalculateArea() const
{
	return 0.5*length*high;
}

#include<iostream>
using namespace std;
#include"circle.h"
Circle::Circle(string name,int r)
:Shape(name)
{
	radius=r;
}
double Circle::CalculateArea() const
{
	return radius*radius*3.14159;
}

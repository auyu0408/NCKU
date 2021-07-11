#include<iostream>
using namespace std;
#include"square.h"

Square::Square(string name,int l)
:Shape(name)
{
	side=l;
}

double Square::CalculateArea() const
{
	return side*side;
}

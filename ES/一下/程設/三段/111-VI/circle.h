#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
#include<string>
using namespace std;
#include "shape.h"

class Circle:public Shape
{
	public:
		Circle(string,int);
		virtual double CalculateArea() const;
  
	private:
		int radius;
};
#endif

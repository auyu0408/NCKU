#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<string>
using namespace std;

class Shape
{
	public:
		Shape(string);
		string getShapeName();
		virtual double CalculateArea() const =0;
		
	protected:
		string shapeName;
} ;
#endif

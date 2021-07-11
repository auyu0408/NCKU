#ifndef SQUARE_H
#define SQUARE_H
#include<iostream>
#include<string>
using namespace std;
#include "shape.h"

class Square:public Shape
{
	public:
		Square(string,int);
		virtual double CalculateArea() const;
		
	private:
	    int side;	
};
#endif

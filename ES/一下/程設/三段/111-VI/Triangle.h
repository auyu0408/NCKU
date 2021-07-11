#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include<string>
using namespace std;
#include"shape.h"

class Triangle:public Shape
{
	public:
		Triangle(string,int,int);
		virtual double CalculateArea() const;
		
	private:
		int length;
		int high;
};
#endif

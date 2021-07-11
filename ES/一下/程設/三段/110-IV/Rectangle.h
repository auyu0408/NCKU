#include<iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Quardilateral.h"
using namespace std;

class Rectangle:public Quardilateral
{
	public:
		Rectangle(int,int);
		virtual double calculatearea() const;
	private:
		int h;
		int w;
};

Rectangle::Rectangle(int high,int width)
{
	h=high;
	w=width;
}

double Rectangle::calculatearea() const;
{
	return h*w ;
}
#endif

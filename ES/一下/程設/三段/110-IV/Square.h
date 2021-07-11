#include<iostream>
#ifndef SQUARE_H
#define SQUARE_H
#include"Quardilateral.h"
using namespace std;

class Square:public Quardilateral
{
	public:
		Square(int);
		virtual double calculatearea()) const;
	private:
		int l;
};

Square::Square(int length)
{
	l=length;
}

double Square::calculatearea() const;
{
	return l*l;
}
#endif

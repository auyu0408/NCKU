#include<iostream>
#include<iomanip>
#include"Complex.h"
using namespace std;

Complex::Complex(double r, double i)
{
	realPart=r;
	imaginaryPart=i;
	cout<<"Complex number("<<realPart<<"+"<<imaginaryPart<<"i) is constructed."<<endl;
}

Complex Complex::add(Complex Adder)
{
	return Complex(realPart+Adder.realPart,imaginaryPart+Adder.imaginaryPart);
}

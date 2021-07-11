#include<iostream>
#include<iomanip>
#include"Complex.h"
#include<iostream>
#include<string>
using namespace std;

Complex::Complex(double r,double i)
:realPart(r),imaginaryPart(i)
{
	cout<<"Complex number ("<<realPart<<","<<imaginaryPart<<") is constructed." <<endl;
}

Complex::~Complex()
{
	cout<<"Complex number ("<<realPart<<","<<imaginaryPart<<") is destroyed."<<endl; 
}

Complex::Complex(const Complex& copied)
{
	realPart=copied.realPart;
	imaginaryPart=copied.imaginaryPart;
	cout<<"Complex number ("<<realPart<<","<<imaginaryPart<<") is constructed by copied."<<endl; 
}

Complex &Complex::operator+(const Complex& add)
{
	realPart=realPart+add.realPart;
	imaginaryPart=imaginaryPart+add.imaginaryPart;
	return *this;
}

ostream &operator <<(ostream &output, const Complex& o)
{
	output<<o.realPart<<"+"<<o.imaginaryPart<<"i";
}

istream &operator >>(istream &input, const Complex& i)
{
	input>>i.realPart;
	input.ignore();
	input>>i.imaginaryPart;
	input.ignore();
}

bool Complex::operator==(const Complex&a) const
{
	if(realPart==a.realPart&&imaginaryPart==a.imaginaryPart)
	return true;
	else
	return false;
}

bool Complex::operator!=(const Complex&b ) const
{
	return !(*this==b );
}

Complex &Complex::operator++()
{
	realPart+=1;
	imaginaryPart+=1;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex temp = *this;
	realPart+=1;
	imaginaryPart+=1;
	return *this;
}

Complex &Complex::operator--()
{
	realPart-=1;
	imaginaryPart-=1;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex temp = *this;
	realPart-=1;
	imaginaryPart-=1;
	return *this;
}

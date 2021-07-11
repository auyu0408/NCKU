#include<iostream>
#include<iomanip>
#include<string>
#include "Complex.h"
using namespace std;

//(a)
Complex::Complex(double r, double i)
:realPart(r),imaginaryPart(i)
{
	cout<<"Complex like ("<<realPart<<","<<imaginaryPart<<") is constructed."<<endl;
}
//(b)
Complex::~Complex()
{
	cout<<"Complex like ("<<realPart<<","<<imaginaryPart<<") is destroyed."<<endl;
}
//(c)
Complex::Complex(const Complex &c)
:realPart(c.realPart),imaginaryPart(c.imaginaryPart)
{
	cout<<"Complex like ("<<realPart<<","<<imaginaryPart<<") is constructed by copied."<<endl;
}
//(d)
void Complex::Add(Complex a)
{
	realPart=realPart+a.realPart;
	imaginaryPart=imaginaryPart+a.imaginaryPart;
}
//(e)
void Complex::operator+(const Complex& right)
{
	realPart=realPart+right.realPart;
	imaginaryPart=imaginaryPart+right.imaginaryPart;
}
//(f)
void Complex::PrintComplex()
{
	cout<<realPart<<"+"<<imaginaryPart<<"*i"<<endl;
}
//(g)
ostream &operator<<( ostream &output, const Complex &o)
{
	output<<o.realPart;
	output<<"+"<<o.imaginaryPart;
	output<<"i ";
}

istream &operator>>( istream &input, const Complex &i)//Complex a+bi
{
	input>>i.realPart;
	input.ignore(1);//ignore"+"
	input>>i.imaginaryPart;
	input.ignore(1);//ignore"i"
	return input;
}
//(h)
bool Complex::operator==(const Complex&b) const
{
	if(realPart==b.realPart&&imaginaryPart==b.imaginaryPart)
	return true;
	else
	return false;
}

bool Complex::operator!=(const Complex&b) const
{
	return !(*this==b );//自a=b中會有true or fals,把它反轉即為!= 
}
//(i)
const Complex &Complex::operator=(const Complex&a)
{
	realPart=a.realPart;
	imaginaryPart=a.imaginaryPart;
	return *this;
}
//(j)
Complex Complex::operator++()
{
	realPart+=1;
	imaginaryPart+=1;
	return *this;
}

Complex Complex::operator--()
{
	realPart-=1;
	imaginaryPart-=1;
	return *this;
}



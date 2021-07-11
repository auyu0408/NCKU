#include<iostream>
#include<iomanip>
#include"Rational.h"
using namespace std;

Rational::Rational(int n, int d )
{
    setRational(n,d);
}

void Rational::setRational(int num , int den )
{
	setNumerator(num);
	setDenominator(den);
	reduce();
}

void Rational::setNumerator(int numerat)
{
	structRational.numerator=numerat;
}

void Rational::setDenominator(int denominat)
{
	structRational.denominator=denominat==0?1:denominat;
}

Rational &Rational::operator+(const Rational &a)
{
	structRational.numerator=a.structRational.numerator*structRational.denominator+a.structRational.denominator*structRational.numerator;
	structRational.denominator=a.structRational.denominator*structRational.denominator;
	reduce();
}

Rational &Rational::operator-(const Rational &s)
{
	structRational.numerator=-s.structRational.numerator*structRational.denominator+s.structRational.denominator*structRational.numerator;
	structRational.denominator=s.structRational.denominator*structRational.denominator;
	reduce();
}

Rational &Rational::operator*(const Rational &m)
{
	structRational.numerator=m .structRational.numerator*structRational.numerator;
	structRational.denominator=m .structRational.denominator*structRational.denominator;
	reduce();
}

Rational &Rational::operator/(const Rational &d)
{
	structRational.numerator=d.structRational.denominator*structRational.numerator;
	structRational.denominator=d.structRational.numerator*structRational.denominator;
	reduce();
}

bool Rational::operator==(const Rational &c)
{
	if(structRational.numerator==c.structRational.numerator&&structRational.denominator==c.structRational.denominator)
	return true;
	else
	return false;
} 

bool Rational::operator!=(const Rational &x)
{
	return !(*this==x);
}

bool Rational::operator>(const Rational &y)
{
	if(structRational.numerator*y.structRational.denominator>y.structRational.numerator*structRational.denominator)
	return true;
	else 
	return false;
}

bool Rational::operator>=(const Rational &z)
{
	return !(*this<z);
}

bool Rational::operator<(const Rational &w)
{
	if(structRational.numerator*w.structRational.denominator<w.structRational.numerator*structRational.denominator)
	return true;
	else 
	return false;
	
}

bool Rational::operator<=(const Rational &s)
{
	return !(*this>s);
}


void Rational::printRational() 
{
	if(structRational.denominator==0)
	cout<<"Error"<<endl;
	if(structRational.numerator==0)
	cout<<0;
	else
	cout<<getNumerator()<<"/"<<getDenominator();
}

int Rational::getNumerator()
{
	return structRational.numerator;
}

int Rational::getDenominator()
{
	return structRational.denominator;
}

void Rational::printingFloat()
{
	float i;
	float n=structRational.numerator;
	float d=structRational.denominator;
	if(structRational.denominator==0)
	cout<<"Error"<<endl;
	if(structRational.numerator==0)
	cout<<0;
	else
	{
	i=n/d;
	cout<<i;
	}
	
}

void Rational::reduce()
{
	int n=structRational.numerator<0? -structRational.numerator:structRational.numerator;
	int d=structRational.denominator<0?-structRational.denominator:structRational.denominator;
	int largest=n > d? n:d;
	int gcd=0;
	
	for(int i=2;i<=largest;i++)	
	{
	   if (n%i==0&&d%i==0)
	   {
	   gcd=i;
	   }
	}
	   
	if(gcd!=0) 
	{
	structRational.numerator=n/gcd;
	structRational.denominator=d/gcd;
	}
	else
	{
	structRational.numerator=n;
	structRational.denominator=d;
	}

}

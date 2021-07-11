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
	numerator=numerat;
}

void Rational::setDenominator(int denominat)
{
	denominator=denominat;
}

void Rational::adding(Rational a)
{
	numerator=a.numerator*denominator+a.denominator*numerator;
	denominator=a.denominator*denominator;
	reduce();
}

void Rational::subtracting(Rational s)
{
	numerator=-s.numerator*denominator+s.denominator*numerator;
	denominator=s.denominator*denominator;
	reduce();
}

void Rational::multiplying(Rational m )
{
	numerator=m .numerator*numerator;
	denominator=m .denominator*denominator;
	reduce();
}

void Rational::dividing(Rational d )
{
	numerator=d.denominator*numerator;
	denominator=d.numerator*denominator;
	reduce();
}

void Rational::printing() 
{
	if(denominator==0)
	cout<<"Error"<<endl;
	if(numerator==0)
	cout<<0;
	else
	cout<<getNumerator()<<"/"<<getDenominator();
}

int Rational::getNumerator()
{
	return numerator;
}

int Rational::getDenominator()
{
	return denominator;
}

void Rational::printingFloat()
{
	float i;
	float n=numerator;
	float d=denominator;
	if(denominator==0)
	cout<<"Error"<<endl;
	if(numerator==0)
	cout<<0;
	else
	{
	i=n/d;
	cout<<i;
	}
	
}

void Rational::reduce()
{
	int n=numerator<0? -numerator:numerator;
	int d=denominator<0?-denominator:denominator;
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
	numerator=n/gcd;
	denominator=d/gcd;
	}
	else
	{
	numerator=n;
	denominator=d;
	}

}

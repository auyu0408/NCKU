#ifndef Rational_H
#define Rational_H
#include<iostream>

typedef struct
{
	int numerator;
	int denominator;
}RationalStruct;

class Rational
{
	public:
	    Rational (int=0,int=1);
	    void setRational(int,int);
	    void setNumerator(int);
	    void setDenominator(int);
		Rational &operator+(const Rational &);
		Rational &operator-(const Rational &);
		Rational &operator*(const Rational &);
		Rational &operator/(const Rational &);
		bool operator==(const Rational &);
		bool operator!=(const Rational &);
		bool operator>(const Rational &);
		bool operator>=(const Rational &);
		bool operator<(const Rational &);
		bool operator<=(const Rational &);
		void printRational();
		int getNumerator();
		int getDenominator();
		void printingFloat();
		void reduce();
	private:
		RationalStruct structRational;
} ;

#endif

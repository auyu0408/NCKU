#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include<string>
using namespace std;

class Complex
{
	friend ostream &operator<<(ostream&, const Complex&);
	friend istream &operator>>(istream&, const Complex&);
	
	public:
		Complex(double=1,double=0);
		~Complex();
		Complex(const Complex&);
		Complex &operator+(const Complex&);
		bool operator==(const Complex&) const;
		bool operator!=(const Complex&) const;
		Complex &operator++();
		Complex operator++(int);
		Complex &operator--();
		Complex operator--(int);
		
	private:
		double realPart;
		double imaginaryPart;
} ;

#endif

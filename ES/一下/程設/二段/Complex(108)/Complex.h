#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Complex
{
	friend ostream &operator<<( ostream &, const Complex &);
	friend istream &operator>>( istream &, const Complex &);
	
  public:
    Complex(double=1,double=0);
	~Complex();
	Complex(const Complex&);
    void Add(Complex);
    void operator+(const Complex&);
    void PrintComplex();
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;
    const Complex &operator=(const Complex&);
    Complex operator++();
    Complex operator--(); 

  private:
  	double realPart;
	double imaginaryPart;

};


#endif 

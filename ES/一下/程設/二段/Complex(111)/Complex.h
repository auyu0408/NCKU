#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
	public:
		Complex(double=1,double=0);
		Complex add(Complex);
	
	private:
		double realPart;
		double imaginaryPart;
};

#endif

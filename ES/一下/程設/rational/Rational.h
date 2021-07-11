#ifndef Rational_H
#define Rational_H
class Rational
{
	public:
	    Rational (int=0,int=1);
	    void setRational(int,int);
	    void setNumerator(int);
	    void setDenominator(int);
		void adding(Rational);
		void subtracting(Rational);
		void multiplying(Rational);
		void dividing(Rational);
		void printing();
		int getNumerator();
		int getDenominator();
		void printingFloat();
		void reduce();
	private:
		int numerator;
		int denominator;
} ;

#endif

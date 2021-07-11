#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial{
	public:
		Polynomial( int = 0, int = 0, int = 0);		// default constructor with default arguments
		Polynomial( const Polynomial & );	// copy constructor
		~Polynomial();		// destructor
		operator int() const;	//Conversion constructor from Polynomial object to int
		void set( int, int, int );
	private:
		int *coeff;
};

#endif

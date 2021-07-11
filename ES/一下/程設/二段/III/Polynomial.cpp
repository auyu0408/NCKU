#include <iostream>
#include "Polynomial.h"
using namespace std;

// (a)
Polynomial::Polynomial( int a, int b, int c) {
	coeff = new int[ 3 ];
	coeff[ 0 ] = a;
	coeff[ 1 ] = b;
	coeff[ 2 ] = c;
}

// (b)
Polynomial::Polynomial( const Polynomial &polynomialToCopy ) {
	coeff = new int[ 3 ];
	for ( int i = 0; i<3; i++ ) {
		coeff[ i ] = polynomialToCopy.coeff[ i ];
	}
}

// (c)
Polynomial::~Polynomial() {
	delete [] coeff;
}

// (d)
Polynomial::operator int() const {
	int sum = 0;
	for ( int i = 0; i<3; i++ ) {
		sum += coeff[ i ];
	}
	return sum;
}



void Polynomial::set( int a, int b, int c ) {
	coeff[ 0 ] = a;
	coeff[ 1 ] = b;
	coeff[ 2 ] = c;
	
}

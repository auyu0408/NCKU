#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
	cout << "Creating a Polynomial object A as x^2+2x+3 :\n";
	Polynomial A( 1, 2, 3 );

	cout << "Creating a Polynomial object B by copy constructor :\n";
	Polynomial B = A;

	cout << "Setting B as 4x^2+5x+6 \n";
	B.set( 4, 5, 6);

	cout << "Converting A to int :\n" << static_cast< int >( A ) << endl;
	cout << "Converting B to int :\n" << static_cast< int >( B ) << endl;

	system("pause");
	return 0;
}

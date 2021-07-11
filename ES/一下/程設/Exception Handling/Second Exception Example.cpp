#include <iostream>
using namespace std;
int main()
{
	double Operand1, Operand2, Result;
	const char Operator = '/';
	// Request two numbers from the user
	cout << "This program allows you to perform a division of two numbers\n";
	cout << "To proceed, enter two numbers\n";
	try {
		cout << "First Number: ";
		cin >> Operand1;
		cout << "Second Number: ";
		cin >> Operand2;
		if( Operand2 == 0 ) // Find out if the denominator is 0
				throw 0;
		Result = Operand1 / Operand2; // Perform a division and display the result
		cout << "\n" << Operand1 << " / " << Operand2 << " = " << Result << "\n\n";
	}
	catch(const int n) // Catch an exception
	{
		// Display a string message accordingly
		cout << "\nBad Operator: Division by " << n << " not allowed\n\n";
	}
 return 0;
}

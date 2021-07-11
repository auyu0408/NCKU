#include <iostream>
using namespace std;
int main()
{
	double Operand1, Operand2, Result;
// Request two numbers from the user
	cout << "This program allows you to perform a divisio of two numbers\n";
	cout << "To proceed, enter two numbers: ";
	try {
		cout << "First Number: ";
		cin >> Operand1;
		cout << "Second Number: ";
		cin >> Operand2;
	// Find out if the denominator is 0
	if( Operand2 == 0 )
		throw "Division by zero not allowed";
	// Perform a division and display the result
	Result = Operand1 / Operand2;
	cout << "\n" << Operand1 << " / " << Operand2 << " = " << Result << "\n\n";
	}
	catch(const char* Str) // Catch an exception
	{
	// Display a string message accordingly
		cout << "\nBad Operator: " << Str;
	}
 return 0;
}

// Program to depict Exception Handling 
// Using stack unwinding 

#include <iostream> 
#include <stdexcept> 
using namespace std; 

// defining the CheckDenominator function 
float CheckDenominator(float den) 
{ 

	// if denominator is zero 
	// throw exception 
	if (den == 0) { 
		throw runtime_error("Math error: Attempted to divide by zero\n"); 
	} 
	else
		return den; 
} // end CheckDenominator 

// defining Division function 
float Division(float num, float den) 
{ 
	// Division function calls CheckDenominator 
	return (num / CheckDenominator(den)); 

} // end Division 

int main() 
{ 
	float numerator, denominator, result; 
	numerator = 12.5; 
	denominator = 0; 

	// try block calls the Division function 
	try { 
		result = Division(numerator, denominator); 

		// This will not print in this example 
		cout << "The quotient is "
			<< result << endl; 
	} 

	// catch block catches exception if any 
	catch (runtime_error& e) { 

		// prints that exception has occurred 
		// calls the what function using object of 
		// runtime_error class 
		cout << "Exception occurred" << endl 
			<< e.what(); 
	} 
} // end main 


// Program to depict user defined exception handling 

#include <iostream> 
#include <stdexcept> 
// For using runtime_error 

using namespace std; 

// User defined class for handling exception 
// Class Exception publicly inherits 
// the runtime_error class 

class Exception : public runtime_error { 
public: 
	// Defining constructor of class Exception 
	// that passes a string message to the runtime_error class 
	Exception() 
		: runtime_error("Math error: Attempted to divide by Zero\n") 
	{ 
	} 
}; 

// defining Division function 
float Division(float num, float den) 
{ 

	// If denominator is Zero 
	// throw user defined exception of type Exception 
	if (den == 0) 
		throw Exception(); 

	// otherwise return the result of division 
	return (num / den); 

} // end Division 

int main() 
{ 
	float numerator, denominator, result; 
	numerator = 12.5; 
	denominator = 0; 

	// try block calls the Division function 
	try { 
		result = Division(numerator, denominator); 

		// this will not print in this example 
		cout << "The quotient is " << result << endl; 
	} 

	// catch block catches exception if any 
	// of type Exception 
	catch (Exception& e) { 

		// prints that exception has occurred 
		// calls the what function using object of 
		// the user defined class called Exception 
		cout << "Exception occurred" << endl 
			<< e.what(); 
	} 

} // end main 


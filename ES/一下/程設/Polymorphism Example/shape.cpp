#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;        


#include "shape.h" // Shape class definition

// constructor initializes shapeName and grades array
Shape::Shape( string name )
{
   setShapeName( name ); // initialize shapeName
} // end Shape constructor

// function to set the course name
void Shape::setShapeName( string name )
{
   shapeName = name; // store the course name
} // end function setCourseName

// function to retrieve the course name
string Shape::getShapeName()const
{
   return shapeName;
} // end function getCourseName

// display a welcome message to the GradeBook user
double Shape::area() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "The area of the shape is\n" << endl;
} // end function displayMessage

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;        


#include "circle.h" // Shape class definition

// constructor initializes shapeName and grades array
Circle::Circle( string name, int r )
:Shape(name)
{
   setRadius( r ); // initialize shapeName
} // end Shape constructor

// function to set the course name
void Circle::setRadius( int r )
{
   radius = r; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Circle::getRadius()
{
   return radius;
} // end function getCourseName

// display a welcome message to the GradeBook user
double Circle::area() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "The area of the " << getShapeName() << " is\n" << 3.14159*radius*radius << endl;
} // end function displayMessage

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;        

#include "triangle.h" // Shape class definition

// constructor initializes shapeName and grades array
Triangle::Triangle( string name, int b, int h )
:Shape(name)
{
   setBaseLength( b ); // initialize shapeName
   setHeight( h );
} // end Shape constructor

// function to set the course name
void Triangle::setBaseLength( int b )
{
   baselength = b; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Triangle::getBaseLength()
{
   return baselength;
} // end function getCourseName

void Triangle::setHeight( int h )
{
   height = h; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Triangle::getHeight()
{
   return height;
} // end function getCourseName

// display a welcome message to the GradeBook user
double Triangle::area() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "The area of the " << shapeName << " is\n" << 0.5*baselength*height << endl;
} // end function displayMessage

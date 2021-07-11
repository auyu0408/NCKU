#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;        
#include <string> // program uses C++ Standard Library string class

#include "trapezium.h" // Rectangle class implementation


// constructor initializes a rectangle
Trapezium::Trapezium( string name, int ul, int ll, int h )
:Shape(name)
{
   setUpperLength( ul ); // initialize shapeName
   setLowerLength( ll );
   setHeight( h );
} // end Shape constructor

// function to set the course name
void Trapezium::setUpperLength( int ul )
{
   upperlength = ul; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Trapezium::getUpperLength()
{
   return upperlength;
} // end function getCourseName

void Trapezium::setLowerLength( int ll )
{
   lowerlength = ll; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Trapezium::getLowerLength()
{
   return lowerlength;
} // end function getCourseName

void Trapezium::setHeight( int h )
{
   height = h; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Trapezium::getHeight()
{
   return height;
} // end function getCourseName

// display a welcome message to the GradeBook user
double Trapezium::area() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "The area of the " << shapeName << " is\n" << 0.5*(upperlength+lowerlength)*height << endl;
} // end function displayMessage

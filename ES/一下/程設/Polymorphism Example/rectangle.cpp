#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;        
#include <string> // program uses C++ Standard Library string class

#include "rectangle.h" // Rectangle class implementation

// constructor initializes a rectangle
Rectangle::Rectangle( string name, int l, int w )
:Shape(name)
{
   setLength( l ); // initialize shapeName
   setWidth( w );
} // end Shape constructor

// function to set the course name
void Rectangle::setLength( int l )
{
   length = l; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Rectangle::getLength()
{
   return length;
} // end function getCourseName

void Rectangle::setWidth( int w )
{
   width = w; // store the course name
} // end function setCourseName

// function to retrieve the course name
int Rectangle::getWidth()
{
   return width;
} // end function getCourseName

// display a welcome message to the GradeBook user
double Rectangle::area() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "The area of the " << shapeName << " is\n" << length*width << endl;
} // end function displayMessage

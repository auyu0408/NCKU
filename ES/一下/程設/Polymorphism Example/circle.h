#include <string> // program uses C++ Standard Library string class
#ifndef CIRCLE
#define CIRCLE

using std::string;

#include "Shape.h"

// Circle class definition
class Circle : public Shape
{
public:
   Circle( string, int );

   void setRadius( int ); // function to set the circle radius
   int getRadius(); // function to retrieve the circle radius
   virtual double area() const; // display the area of the circle

private:
   int radius; // radius of the circle
}; // end class Circle

#endif

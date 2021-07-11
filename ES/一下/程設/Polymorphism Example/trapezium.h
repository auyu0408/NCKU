#include <string> // program uses C++ Standard Library string class
#ifndef TRAPEZIUM
#define TRAPEZIUM

#include "Shape.h"

class Trapezium : public Shape
{
public:
   Trapezium( string, int, int, int );

   void setUpperLength( int ); // function to set the shape name
   int getUpperLength(); // function to retrieve the shape name
   void setLowerLength( int ); // function to set the shape name
   int getLowerLength(); // function to retrieve the shape name
   void setHeight( int ); // function to set the shape name
   int getHeight(); // function to retrieve the shape name
 
   virtual double area() const; // display the area of the shape

private:
   int upperlength;
   int lowerlength;
   int height; // course name for this grade book
}; // end class Circle  
#endif

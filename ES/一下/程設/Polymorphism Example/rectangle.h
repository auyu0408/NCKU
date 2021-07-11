#include <string> // program uses C++ Standard Library string class
#ifndef RECTANGLE
#define RECTANGLE

#include "Shape.h"

class Rectangle : public Shape
{
public:
   Rectangle( string, int, int );

   void setLength( int ); // function to set the shape name
   int getLength(); // function to retrieve the shape name
   void setWidth( int ); // function to set the shape name
   int getWidth(); // function to retrieve the shape name
 
   virtual double area() const; // display the area of the Rectangle

private:
   int length;
   int width; // course name for this grade book
}; // end class Rectangle  

#endif

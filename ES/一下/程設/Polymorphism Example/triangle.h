#ifndef TRIANGLE
#define TRIANGLE

#include "shape.h"

class Triangle : public Shape
{
public:
   Triangle( string, int, int );

   void setBaseLength( int ); // function to set the shape name
   int getBaseLength(); // function to retrieve the shape name
   void setHeight( int ); // function to set the shape name
   int getHeight(); // function to retrieve the shape name
 
   virtual double area()const; // display the area of the shape

private:
   int baselength;
   int height; // course name for this grade book
}; // end class Triangle

#endif

#include <string> // program uses C++ Standard Library string class
#ifndef SHAPE
#define SHAPE

using std::string;

// GradeBook class definition
class Shape
{
public:
   Shape( string );

   void setShapeName( string ); // function to set the shape name
   string getShapeName() const; // function to retrieve the shape name
   virtual double area() const; // display the area of the shape

protected:
   string shapeName; // shape name
}; // end class Shape  

#endif

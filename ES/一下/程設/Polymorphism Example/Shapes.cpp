#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using namespace std;

#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "trapezium.h"

int main()
{
   vector <Shape *> SV;
   Circle cir("circle", 10);
   Triangle tri("triangle", 30, 20);
   Rectangle rec("rectangle", 40, 20);
   Trapezium tra("trapezium", 20, 40, 10);
   
   SV.push_back(&cir);
   SV.push_back(&tri);
   SV.push_back(&rec);
   SV.push_back(&tra);

  for(size_t i=0; i < SV.size(); i++)
   {
      SV[i]->area();
   }

   cout << endl << "Vector Iterator:" << endl;
   vector<Shape *>::iterator cii;
   for(cii=SV.begin(); cii!=SV.end(); cii++)
   {
      (*cii)->area();
   }
 
 //   system("PAUSE");
    return 0;
}

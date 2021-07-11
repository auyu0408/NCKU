#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include "shape.h"
#include "circle.h"
#include "square.h"
#include "Triangle.h"

int main()
{
	vector <Shape *> S;
	Circle cir("circle",10);
	Square squ("square",10);
	Triangle tri("Triangle",10,10);
	
   S.push_back(&cir);
   S.push_back(&squ);
   S.push_back(&tri);
   
   for(size_t i=0; i<S.size(); i++)
   {
   	cout<<S[i]->getShapeName()<<":"<<S[i]->CalculateArea()<<endl;
   }
   
   
   return 0;
}

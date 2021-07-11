#include<iostream>
using namespace std;
#include"shape.h"

Shape::Shape(string Name)
{
	shapeName=Name;
} 

string Shape::getShapeName()
{
	return shapeName;
}


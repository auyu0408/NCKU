#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double Hypotenuse();
double side1 ,side2;

int main()
{
	cout<<"Enter 2 sides of right triangle:";
	cin>>side1>>side2;
	cout<<"Hypotenuse:"<<setprecision(1)<<fixed<<Hypotenuse();
	
} 
double Hypotenuse()
{
	double results,square;
	square=side1*side1+side2*side2;
	results=pow(square,0.5);//sqrt(side1*side1+side2*side2) 
	return results;
}

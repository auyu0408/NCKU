#include<iostream>
#include<iomanip>
#include<string>
#include"Complex.h"
using namespace std;

int main()
{
	Complex x(3,2);
	Complex y(7.5,8);
	Complex z;
	x.PrintComplex();
	cout<<x <<y <<z <<"\n";
	x+y;
	++x;
	--y;
	cout<<x <<y <<z <<endl;
	if(x==y)
	cout<<"x==y"<<endl;
	else
	cout<<"x!=y"<<endl;	
	return 0;
}

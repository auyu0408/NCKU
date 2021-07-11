#include<iostream>
#include<iomanip>
#include"Complex.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	Complex a(2,3);
	Complex b;
	Complex c;
	if(a==b)
	cout<<"a==b"<<endl;
	else
	cout<<"a!=b"<<endl;
	c=a+b;
	a++;
	++b;
	return 0;
}

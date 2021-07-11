#include<iostream>
#include<iomanip>
#include"Complex.h"
using namespace std;

int main()
{
	Complex a(2,3);
	Complex b(4,5);
	Complex c=a.add(b);
	return 0;
}

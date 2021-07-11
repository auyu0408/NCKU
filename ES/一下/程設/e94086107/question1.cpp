#include<iostream>
#include <time.h>
using namespace std;

int main()
{
	unsigned long n;
	cout << (double)clock() / CLOCKS_PER_SEC << " S"<<endl;
	cout<<"enter the fibonacci number you want."<<endl;
	cin>>n;
    for (int i=1;i<10000;i++) 
	{
	unsigned long x=0,y=1,z=0;
	if(n==0)
	cout<<"fabonacci(0)=0";
	else
	for(unsigned long a=1;a<n;a++)
	{
		z=x+y;
		x=y;
		y=z;
	}
	cout<<"fabonacci("<<n<<")="<<z<<endl;
	}

	cout << (double)clock() / CLOCKS_PER_SEC << " S";
	return 0;
} 


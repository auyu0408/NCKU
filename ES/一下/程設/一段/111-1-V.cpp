#include<iostream>
using namespace std;
int gcd(int, int);

int main()
{
	cout<< "please enter two number x,y."<<endl;
    int x,y;
	cin>>x>>y;
    	gcd(x,y);
	return 0;
}

int gcd(int x,int y)
{
    while(y>=x)
	{
	cout<<"y should < x"<<endl;
	cin>>x>>y;
	}

	if (y==0)
	{
	cout<< "gcd is "<<x;
	}
	else
	gcd(y,x%y);
}

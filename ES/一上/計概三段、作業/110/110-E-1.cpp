#include<iostream>
using namespace std;
int main()
{
	int x,v,s,n;
	n=1;
	s=0;
	cout<<"Enter how many number you want to sum."<<endl;
	cin>>x;
	while(n<=x)
	{
		cout<<"Enter the number"<<endl;
		cin>>v;
		s=s+v;
		n++;
	}
	cout<<"the sum is "<<s;
	return 0;
}

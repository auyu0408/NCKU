#include<iostream>
using namespace std;
int main()
{
	int x,v,s;
	s=0;
	cout<<"Enter how many number you want to sum."<<endl;
	cin>>x;
	for(int n=1;n<=x;n++)
	{
		cout<<"Enter the number"<<endl;
		cin>>v;
		s=s+v;
	}
	cout<<"the sum is "<<s;
	return 0;
}

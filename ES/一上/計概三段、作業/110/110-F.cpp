#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cout<<"Enter a number."<<endl;
	cin>>x;
	while(x>=1)
	{
		y=x%10;
		cout<<y;
		x=x/10;
	}
	return 0;
}

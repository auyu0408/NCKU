#include<iostream>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	z=y+(x++);
	cout<<x<<" "<<y<<" "<<z;
	return 0;
}

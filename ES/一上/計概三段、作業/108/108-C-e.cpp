#include<iostream>
using namespace std;
int main()
{
	int x;
	x=1;
	while(x<=20)
	{
		cout<<x <<" ";
		if(x%5==0)
		cout<<endl;
		x++;
	}
	return 0;
}

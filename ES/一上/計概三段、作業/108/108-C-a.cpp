#include<iostream>
using namespace std;
int main()
{
	int sum=0;
	for(int x=1;x <=99;x++)
	{
		if(x%2==1)
		sum=sum+x;
	}
	cout<<sum ;
	return 0;
} 

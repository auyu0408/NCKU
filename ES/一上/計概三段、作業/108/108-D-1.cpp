#include<iostream>
using namespace std;
int main()
{
	int factorial=1 ,i=1;
	cout<<"x\tx!\n";
	while(i<=5)
	{
		factorial*=i;
		cout<<i <<"\t"<<factorial<<"\n";
		i++;
	}
	cout<<endl;
	return 0;
} 

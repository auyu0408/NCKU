#include<iostream>
using namespace std;
int main()
{
	int factorial=1, i=1;
	cout<<"x\tx!\n";
	do
	{
		factorial*=i;
		cout<<i <<"\t"<<factorial<<"\n";
		i++;
	}while(i<=5);
	cout<<endl;
	return 0;
} 

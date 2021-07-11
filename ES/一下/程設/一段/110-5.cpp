#include<iostream>
using namespace std;
int power(int,int);

int main()
{
	cout<<power(3,4);
	return 0;
}

int power(int base,int exponent)
{   
    int answer;
    if(exponent!=1)
	answer=base*power(base,exponent-1);
	if(exponent==1)
	answer=base;
	return answer;
}

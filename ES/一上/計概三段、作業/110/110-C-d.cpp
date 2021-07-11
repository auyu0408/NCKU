#include<iostream>
using namespace std;
int main()
{
	int x;
	x=1;//這樣是初始化嗎 
	while(x<=20)
	{
		cout<<x<<" ";
		if(x%5==0)
		cout<<endl;
		x++;
	}
	return 0;
}

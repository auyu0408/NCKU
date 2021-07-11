#include<iostream>
using namespace std;
int power();//務必先宣告函數且程式必定有main,無法宣告函數後沒有main 
int main()
{
	cout<<"please enter  base x and exponent y"<<endl;
	cout<<"the answer is "<<power()<<endl;
}
int power()
{
	int x,y,r;//r=result 
	cin>>x>>y;
	r=x;
	for(int n=1;n<y;n++)
		r=r*x;
	return r;
}

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int rolldice();

int main()
{
	srand(time(0));//一開始先灑種子 
	int n,sumofdice;
	cin>>n;
	for(int y=1;y<=n;y++)
	{
    sumofdice=rolldice();//裡面這樣代表每次都要叫rolldice回傳一個值,值的rand為當下時間造成 
	cout<<sumofdice<<endl;
    }
	
}
int rolldice()
{
	int die1=1+rand()%6;
	int die2=1+rand()%6;
	int die3=1+rand()%6;
	int sum;
	sum=die1+die2+die3;
	return sum;
}

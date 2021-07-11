#include<iostream>
using namespace std;
void useLocal();
void useSL();
void useG();
int x=1;

int main()
{
	cout<<"global x in main is "<<x<<endl;
	int x=5;
	cout<<"local x in main's outer scope is "<<x<<endl;
	{
		int x=7;
		cout<<"local x in main's inner scope is"<<x<<endl;
	}
	useLocal(); useSL(); useG();
	useLocal(); useSL(); useG();
	cout<<"\nlocal x in main is "<<x<<endl;
}
void useLocal()
{
	int x=25;
	cout<<"\nlocal x is "<<x<<" in useLocal"<<endl;
	x++;
	cout<<"local x is "<<x<<" on exiting useLocal"<<endl;
}
void useSL()
{
	static int x=50;//syatic int 函數會一直存在到程式結束，但因為這個函數是區域內函數，
	cout<<"\n x is "<<x<<" in useSL"<<endl;//所以只有當這個區域再次被呼叫時才能繼續使用，也就是說，第一次離開是51,第二次進去的值就是51 
	x++;
	cout<<"x is "<<x<<" on exiting useSL"<<endl;
}
void useG()
{
	cout<<"\n x is "<<x<<" in useG"<<endl;
	x*=10;
	cout<<"x is "<<x<<" on exiting useG"<<endl;
}

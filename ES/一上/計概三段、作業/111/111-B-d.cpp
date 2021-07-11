#include<iostream>
using namespace std;
int main()
{
	int counter;
	cin>>counter;
	switch(counter%2) //條件放這邊 
	{
		case 0:
			cout<<"An even integer."<<endl;//casec後面只能是字元或數字，不能是條件 
			break;
		case 1:
			cout<<"An odd integer."<<endl;
			break;
	}
	return 0;
}

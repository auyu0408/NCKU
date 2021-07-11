#include<iostream>
using namespace std;

int main()
{
float passes =0, failures =0, studentCounter =0, result;
cout<<"Enter 0 to end."<<endl;

do
{
	cout<<"Enter result(1 = pass, 2 =fail):";
	cin>>result;
	if(result==1||result==2)
	{ 
	if(result==1)
	passes=passes+1;
	else
	failures=failures+1;
	studentCounter ++;
    } 

}while (result!=0);

cout<<"Passed"<< passes<<"\nFailed"<<failures<<endl;
if (passes/studentCounter>=0.8)
cout<<"Bonus to  instructor!"<<endl;
}

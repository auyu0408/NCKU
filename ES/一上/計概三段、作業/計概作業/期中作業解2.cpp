#include<iostream>
using namespace std;

int main()
{
float passes =0, failures =0, studentCounter =0, result;
cout<<"Enter result(1 = pass, 2 =fail),and enter 0 to end.";
cin>> result;

while (result!=0)
{
	if(result==1)
{
	passes=passes+1;
	studentCounter ++;
}
	else if (result==2)
{
	failures=failures+1;
	studentCounter ++;
}
	else
	cout<<"Incorrect number, please enter result.";
	cout<<"Enter result(1 = pass, 2 =fail),and enter 0 to end.";
	cin>>result;
}

cout<<"Passed"<< passes<<"\nFailed"<<failures<<endl;
if (passes/studentCounter>=0.8)
cout<<"Bonus to  instructor!"<<endl;
}

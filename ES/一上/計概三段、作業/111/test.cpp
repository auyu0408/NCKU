#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	//double x;
	int x, y;
    double r;
    cin>>x>>y;
    r=static_cast<double>(x)/y;//把x轉成double,y會跟著以double形式計算,算出來的r為
    cout<<fixed<<showpoint<<x<<endl;//若x,y為int,則以int計算，故r出來也是int(雖然佔身分是double) 
    cout<<r;
    return 0;
}

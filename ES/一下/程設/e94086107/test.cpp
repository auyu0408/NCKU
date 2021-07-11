#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int n=1;
void substr(char[],const char[],int,int);
int main()
{
	char empty[15]={};
	char name[]={"HappyBirthday"};
	substr(empty,name,n,sizeof(name));
	for (int i=0;i<sizeof(name);i++)
	cout<<empty[i];
	return 0;
}
void substr( char dest[],const char src[],int n, int length)
{
	for (int i=0;(dest[i]=src[i+n])!='\0'&&i<length;i++)
	cout<<i<<" "<<n<<dest[i]<<endl;
	dest[length]='\0';
}
	

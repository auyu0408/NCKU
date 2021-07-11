#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
void substr(char *,const char *const ,int*,const int*);
int main()
{
    int n=0;
	const int length=3;
    char name[]="HappyBirthday";
	char empty[length+1]={};
	int *nptr=&n;
	const int *lengthptr=&length;
	substr(empty,name,nptr,lengthptr);
	return 0;
}
void substr( char *dest,const char *const src,int *n,const int *length)
{
	for (int i=0;(*(dest+i)=*(src+(i+*n)))!='\0'&&i<*length;i++)
	cout<<i<<" "<<*n <<*(dest+i)<<endl;
	*(dest+*length)='\0';
}

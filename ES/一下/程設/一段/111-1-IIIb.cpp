#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
void substr(char *,const char *const ,int*);
int main()
{
    int n=0;
    char name[]="HappyBirthday";
	char empty[sizeof(name)]={};
	int *nptr=&n;
	substr(empty,name,nptr);
	return 0;
}
void substr( char *dest,const char *const src,int *n)
{
	for (int i=0;(*(dest+i)=*(src+(i+*n)))!='\0';i++)
	cout<<i<<" "<<*n <<*(dest+i)<<endl;
	*(dest+sizeof(src))='\0';
}

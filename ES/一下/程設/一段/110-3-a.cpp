#include<iostream>
#include<vector>
using namespace std;
char *substr1(char [], char [], size_t, size_t);
char *subster2(char *,char *,size_t *, size_t *);

int main()
{
    size_t n=0;
    char name[]="HappyBirthday";
	char empty[1000]={};
	size_t len=sizeof name;
	size_t *nptr=&n;
	size_t *lenptr=&len;
	substr1(name,empty,n,len);
	cout<<empty<<endl;
	return 0;
}
char *subster1(char s[],char t[],size_t pos, size_t len)
{
	for(int i=0;s[i+pos]!='\0'&&i<len;i++)
	{
	t[i]=s[i+pos];
    }
    t[len]='\0';
    return t;
}
char *substr2(const char *const s,char *t,size_t *pos,size_t *len)
{
	for(int i=0;*(s+i+*pos)!='\0'&&i<*len;i++)
	{
		*(t+i)=*(s+i+*pos);
	}
	*(t+*len)='\0';
	return t;
}

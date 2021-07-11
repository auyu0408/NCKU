#include<iostream>
using namespace std;
void maxdist(const int *);
const char *const name[3]={"Taipei","Rome","New York"};

int main()
{
 	
 	int distance[3]={7804,2685,6204};
    maxdist(distance);
}
void maxdist(const int*D)
{
	int max=0;
	for(int i=0;i<2;i++)
	{
	if(*(D+i)<*(D+i+1));
	max=i+1;
	}
	cout<<*(name+max)<<' '<<D[max];
}

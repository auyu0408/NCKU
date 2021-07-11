#include<iostream>
using namespace std;
 int main()
 {
 	const char *const name[]={"Taipei","Rome","New York"};
 	int distance[]={7804,2685,6204};
 	for(int i=0;i<3;i++)
 	cout<<*(name+i)<<' '<<distance[i]<<endl;
 }

#include<iostream>
using namespace std;
void comission(double *,int[][5],int n);
int Sales[3][5]={{5600,6700,8300,8100,7000},{7600,8900,8100,4200,6600},{6500,6900,9100,8900,8200}};
double rates[5]={0.02,0.03,0.01,0.02,0.04};
const char *const name[]={"Bob ","John","Joe "};
int totalC[3];

int main()
{
	comission(rates,Sales,5);
	cout<<"         "<<"Name"<<"  "<<"P1   P2   P3   P4   P5   "<<' '<<"the total of comission"<<endl;
	for(int i=0;i<3;i++)
	{
	cout<<"salesmen"<<i+1 <<" "<<name[i]<<" ";
	for(int j=0;j<5;j++)
	{
	cout<<Sales[i][j]<<" ";
	}
	cout<<" "<<totalC[i]<<endl;
	}
	
}
void comission(double *array,int array2[][5],int size)
{
	for (int i=0;i<3;i++)
	{
	double total=0;
	for (int j=0;j<size;j++)
	{
		total+=static_cast<double>(array2[i][j])* *(array+j);
	}
	totalC[i]=total;
	}
	
}

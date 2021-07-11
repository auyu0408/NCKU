#include<iostream>
using namespace std;
void comission(double *,int[][5],int n);


int main()
{
	const int k=5;
	int Sales[3][5]={{5600,6700,8300,8100,7000},{7600,8900,8100,4200,6600},{6500,6900,9100,8900,8200}};
	double rates[k]={0.02,0.03,0.01,0.02,0.04};
	double *ratesptr=rates;
	comission(ratesptr,Sales,k);
	return 0;
}
void comission(double *array,int array2[][5] ,int size)
{
	for (int j=0;j<3;j++)
	{
	double total=0;
	for (int i=0;i<size;i++)
	{
		total+=static_cast<double>(array2[j][i])* *(array+i);
	}
	cout<<"comission"<<j+1<<"is:"<<total<<endl;
	}
	

}


#include<iostream>
using namespace std;

int main()
{
	int Sales1[3][5]={{5600,6700,8300,8100,7000},{7600,8900,8100,4200,6600},{6500,6900,9100,8900,8200}};
	int Sales2[3][5]={5600,6700,8300,8100,7000,7600,8900,8100,4200,6600,6500,6900,9100,8900,8200};
 
    double rates1[5]={0.02,0.03,0.01,0.02,0.04};
	double rates2[5];
	rates2[0]=0.02;
	rates2[1]=0.03;
	rates2[2]=0.01;
	rates2[3]=0.02;
	rates2[4]=0.04;
	
	
	return 0;
}
	//cout<<"The sales figure is like:"<<endl;
	
	//for (int i=0;/i<3;i++)
	//{
	//for(int j=0;j<5;j++)
	//cout<<Sales[i][j]<<' ';
	
	//cout<<endl;
	//}
	
	//cout<<"The comission rates is like:"<<endl;
	//for(int j=0;j<5;j++)
	//{
	//cout<<rates[j]<<' ';
	//}
	//cout<<endl;


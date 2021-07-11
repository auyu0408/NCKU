#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void numberprocess();
char C;
int main()
{
	srand(time(0));
	cout<<"I have a number between 1 to 1000.\n";
	cout<<"Can you can guess my number?\n";
	do
	{
	numberprocess();
	}while(C=='y');
	if(C=='n')
	return 0;
} 
void numberprocess()
{
	int A,x;
	A=rand()%1000+1;
	cout<<"Please type your first guess.\n";
	cin>>x;
	while(x!=A)
	{
	if (x>A)
	cout<<"Too high. Try again.\n";
	else
	cout<<"Too low. Try again.\n";
	cin>>x;	
	}	
	cout<<"Excellent! You guessed the number!\nWould you like to play again ( y or n )?\n" ;
	cin>>C;
}

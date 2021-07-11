#include<iostream>
#include"Rational.h"
using namespace std;

 int main()
 {
    Rational r;
    Rational s;
    
    cout<<"test0,printing without setting\nr=";
    r.printing();
    
    int n,d,y,z;
    cout<<"\nYou hve two Rational ,please setting them.\nplease enter numerator1:";
    cin>>n;
    cout<<"please enter denominator1:";
    cin>>d;
    cout<<"please enter numerator2:";
    cin>>y;
    cout<<"please enter denominator2:";
    cin>>z;
    r.setRational(n,d);
 	s.setRational(y,z);
 	
 	cout<<"\ntest1-printing"<<endl;
 	cout<<"the Rational1 is:";
 	r.printing();
 	cout<<endl;
 	cout<<"By floating point format:";
 	r.printingFloat();
 	
 	cout<<"\ntest2-adding"<<endl;
 	r.printing();
 	cout<<"+";
 	s.printing();
 	cout<<"=";
 	r.adding(s);
 	r.printing();
 	
 	cout<<"\ntest3-subtracting"<<endl;
 	r.printing();
 	cout<<"-";
 	s.printing();
 	cout<<"=";
 	r.subtracting(s);
 	r.printing();
 	
 	cout<<"\ntest4-multiplying"<<endl;
 	r.printing();
 	cout<<"*";
 	s.printing();
 	cout<<"=";
 	r.multiplying(s);
 	r.printing();
 	
 	cout<<"\ntest5-dividing"<<endl;
 	r.printing();
 	cout<<"devided";
 	s.printing();
 	cout<<"=";
 	r.dividing(s);
 	r.printing();
 	
 	return 0;
 }

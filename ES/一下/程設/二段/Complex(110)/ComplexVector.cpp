#include"Complex.h"
#include<iostream>
using namespace std;

class ComplexVector
{
	public:
		ComplexVector(int=0);
		ComplexVector();
		~ComplexVector();
		
		const ComplexVector &operator=(const ComplexVector&);
	
	private:
		int size;
		Complex *ptr;
} ;

ComplexVector::ComplexVector(int s)
{
	size=(arraySize>0?arraySize:0);
	ptr= new Complex[];
	for(int i=0;i<size;i++)
	cin>>Complex[i];
}

ComplexVector::~ComplexVector()
{
	delete [] ptr;
}

const ComplexVector &ComplexVector::operator=(const ComplexVector& right) 
{   
    if(&right!=this)
    {
    	if(size!=right.size)
    	{
    		delete[]ptr;
    	    size=right.size;
            ptr=new Complex[];
    	}
    	for (int i=0;i<size;i++)
        ptr[i]=right.ptr[i];
    }
    return *this;
}

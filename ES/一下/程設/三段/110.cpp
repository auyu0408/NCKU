#include<iostream>
using namespace std;
//110-III
class Stack:public List
{
    public:
    	void push(const Node& value)
    	{
    		inserAtFront(value);
    	}
	    void pop(const Node& value);
	    {
	    	removeFromFront(value);
	    }
};
class Queue:public List
{
	public:
		void enqueue(const Node& value)
		{
			insertAtFront(value);
		}
		void dequeue(const Node& value)
		{
			removeFromBack(value);
		}
};

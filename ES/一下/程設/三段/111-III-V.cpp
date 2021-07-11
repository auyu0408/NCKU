#include<iostream>
#include <stdlib.h>
using namespace std;
//III-a
class ListNode
{		
	private:
		int data;
		ListNode *nextptr;
};

//III-b
class List
{
	public:
		List();
		bool insertAtFront(int);
		bool insertAtBack(int);
		bool removeFromFront(int *);
		bool removeFromBack(int *);
		ListNode* getnewNode (int);
		~List();
		
	private:
		ListNode *startPtr;
	
};

//III-c
class ListGen:public List
{
	public:
		ListGen();
		void insertinorder(int);
		int deletfound(int);
};

/*III-d
declared "friend class List" and "friend class ListGen".
*/

//IV
class Queue:public List
{	
    public:
    	void enqueue(int value)
    	{
    		insertAtBack(value);
    	}
    	void dequeue(int *value)
    	{
    		removeFromFront(value);
    	}
};

class Stack:public List
{
	public:
		void push(int value)
		{
			insertAtFront(value);
		}
		void pop(int *value)
		{
			removeFromFront(value);
		}
};
//V-E
struct treeNode
{
	int data;
	treeNode *leftptr;
	treeNode *rightptr;
};
typedef struct treeNode treeNode;
typedef treeNode *treeNodePtr;

void insertNode(treeNode *,int);
treeNodePtr getNewNode(int value );

void insertNode(treeNode **treePtr,int value)
{
	if(treePtr == NULL)
		*treePtr=getNewNode(value);
	else if( value < (*treePtr)->data )
	    insertNode(&(*treePtr)->leftptr,value);
    else if (value>(*treePtr)->data)
	    insertNode(&(*treePtr)->rightptr,value);
	else
	cout << "\nDuplicated Value " << value <<" not inserted\n";
	
}

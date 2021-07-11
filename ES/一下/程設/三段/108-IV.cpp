#include<iostream>
#include <stdlib.h>
using namespace std;

class TreeNode
{
	friend class Tree;
	public:
		TreeNode(int value)
		:data(value)
		{
		}
	private:
		int data;
		TreeNode *leftptr;
		TreeNode *rightptr;
};
class Tree
{
	public:
		Tree();
		void insertnode(TreeNode **,int);
		void inorder(TreeNode *);
		void preorder(TreeNode *);
		void postorder(TreeNode *);
		bool binSearchTree(TreeNode *,int);
	private:
		TreeNode *rootptr;
};

Tree::Tree()
{
	rootptr=0;
}

void Tree::insertnode(TreeNode **ptr,int value)
{
	if (*ptr==NULL)
	*ptr=new TreeNode(value);
	else
	{
		if((*ptr)->data>value)
		insertnode(&(*ptr)->leftptr,value);
		else if((*ptr)->data<value)
		insertnode(&(*ptr)->rightptr,value);
		else
		cout<<"duplicate number.";
	}
}

void Tree::inorder(TreeNode *ptr)
{
	if (ptr!=NULL)
	{
	inorder(ptr->leftptr);
    cout<<" "<<ptr->data;
	inorder(ptr->rightptr);
	}
	
}

void Tree::preorder(TreeNode *ptr)
{
	if (ptr!=NULL)
	{
	cout<<" "<<ptr->data;
	preorder(ptr->leftptr);	
	preorder(ptr->rightptr);
	}
	
}

void Tree::postorder(TreeNode *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->leftptr);
		postorder(ptr->rightptr);
		cout<<" "<<ptr->data;
	}
}

bool Tree::binSearchTree(TreeNode *ptr,int value)
{
	if(ptr==0)
	{
	return false;	
	}
	if((ptr->data)==value)
	{
		return true;
	}
	else if((ptr->data)>value)
	{
		return binSearchTree(ptr->leftptr,value);
	}
	else
	{
		return binSearchTree(ptr->rightptr,value);
	}
}

/*用linearSearch平均搜尋n/2次，用searchtree只要log2n次*/  

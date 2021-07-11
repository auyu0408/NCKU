#include<iostream>
#include "Quadrilatrral.h"
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
using namespace std;

class TreeNode 
{
	friend class Tree;
	public:
		TreeNode(Quadrilateral* value)
		{
		data=value;
		leftptr=0;
		rightptr=0;
		}
	private:
		Quadrilateral *data;
		TreeNode *leftptr;
		TreeNode *rightptr;
};

class Tree
{
	public:
		Tree()
		{
			rootptr=0;
		}
		void Treeinsert(TreeNode **ptr,Quadrilateral *d)
		{
			if(rootptr==0)
			rootptr=getNewNode(d);
			else
			{
				if(((*ptr)->data->calculatearea())>d->calculatearea()) 
				Treeinsert(&((*ptr)->leftptr),d);
				else
				{
					Treeinsert(&((*ptr)->rightptr),d);
				}
			}
				
		}
	
	    
	private:
		Quadrilateral *rootptr;
	
};
#endif

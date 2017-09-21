/*
 * Discription:Program to implement Binary Search Tree
 * Author:Nooras Fatima-16co01
 * Created on:Sep 14,2017
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *q)
{
	if(q!=NULL)
	{
		traverse_inorder(q->left);
		printf("%d\t",q->data);
		traverse_inorder(q->right);
	}
}
void insert(node **r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else
	{
		if(num > temp->data)
				insert(&temp->right,num);
		else
				insert(&temp->left,num);
	}
}
int search(node *q,int num)
{
	if(q==NULL)
	{
		return -1;
	}
	else
	{
		if( q->data==num)
			return 1;
		else
		{
			if(num>q->data)
				return search(q->right,num);
			else
				return search(q->left,num);
		}
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{	
		if(temp->data==num)
		{
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
}
void delete(node **q,int num)
{
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;
	x=NULL;
	xsucc=NULL;
	temp=*q;
	search_node(&x,temp,&parent,num,&f);
	if(f==0)
	{
		printf("\n THE GIVEN NUMBER %d IS NOT FOUND",num);
		return;
	}
	//x has no child
	if((x->left==NULL) && (x->right==NULL))
	{
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	//x has left child
	else if((x->left!=NULL) && (x->right==NULL))
	{
		if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
		//x has right child
	else if((x->right!=NULL) && (x->left==NULL))
	{
		if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}	
			//x has both left and right  child
	else if(x->left!=NULL && x->right!=NULL)
	{
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
			x->data=xsucc->data;
			x=xsucc;
	}
	free(x);
}
int main()
{
	node *root;
	root=NULL;
	insert(&root,20);
	insert(&root,15);
	insert(&root,13);
	insert(&root,17);
	insert(&root,16);
	insert(&root,19);
	insert(&root,18);
	insert(&root,25);
	traverse_inorder(root);
	if(search(root,15)==1)
		printf("\n THE NUMBER %d IS PRESENT IN THE TREE\n",15);
	else
		printf("\n THE NUMBER %d IS IS NOT FOUND\n",15);
	delete(&root,18);
	traverse_inorder(root);
	delete(&root,17);
	traverse_inorder(root);
	return 0;
}

/*

OUTPUT:
---------------------------------------------------
---------------------------------------------------
*/

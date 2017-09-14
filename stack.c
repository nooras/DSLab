/*
 * DISCRIPTION : Array implementation of stack
 * AUTHOR : Nooras Fatima-16co01
 * CREATED ON : July 14,2017
 */

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

int stack[MAXSIZE],top=-1;

int isFull()
{
	//Return 1 if stack is full else return -1
	return top==(MAXSIZE-1);
}

int isEmpty()
{
	//Return 1 if stack is empty else return -1
	return top==-1;
}

int peek()
{
	//Return element at the top of stack
	return stack[top];
}	

void push(int e)
{
	//Insert an element into stack
	if(!isFull())
    {
		top++;
		stack[top]=e;
		printf("\nELEMENT SUCCESSFULLY INSERTED:%d\n",e);
	}
	else 
		printf("\nELEMENT CANNOT BE INSERTED ,STACK OVERFLOW\n");
}

void pop()
{
	//Delete an element from stack
	int d;
	if(!isEmpty())
	{
		d=stack[top];
		top--;
		printf("\nELEMENT SUCCESSFULLY DELETED:%d\n",d);
	}
	else
	{
		printf("\nELEMENT CANNOT BE DELETED ,STACK UNDERFLOW\n");
	}
}

int main()
{
	int choice,e;
	do
	{
		printf("\nENTER \n 1.Push\n 2.Pop\n 3.Peek\n 4.Exit\n");
		printf("\nenter YOUR CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nENTER ELEMNET TO BE INSERTED\n");
				scanf("%d",&e);
				push(e); //call push function
				break;
			case 2:
				pop(); //call pop fuction
				break;
			case 3:
				printf("\nELEMENT AT THE TOP OF STACK :%d",peek());//call peek function 
				break;
			case 4:
				exit(0);//call exit function
			default:
				printf("\nINVALID CHOICE");//for invalid choice
				break;
		}
	}while(1);
	return 0;
}
/*

OUTPUT:
---------------------------------------------------
ENTER
 1.Push
 2.Pop
 3.Peek
 4.Exit

enter YOUR CHOICE
1

ENTER ELEMNET TO BE INSERTED
45

ELEMENT SUCCESSFULLY INSERTED:45

ENTER
 1.Push
 2.Pop
 3.Peek
 4.Exit

enter YOUR CHOICE
1

ENTER ELEMNET TO BE INSERTED
23

ELEMENT SUCCESSFULLY INSERTED:23

ENTER
 1.Push
 2.Pop
 3.Peek
 4.Exit

enter YOUR CHOICE
2

ELEMENT SUCCESSFULLY DELETED:23

ENTER
 1.Push
 2.Pop
 3.Peek
 4.Exit

enter YOUR CHOICE
3

ELEMENT AT THE TOP OF STACK :45
ENTER
 1.Push
 2.Pop
 3.Peek
 4.Exit

enter YOUR CHOICE
4
----------------------------------------------------------
 */

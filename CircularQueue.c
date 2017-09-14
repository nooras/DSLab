/*
 * DISCRIPTION : Array implementation of circular queue
 * AUTHOR : Nooras Fatima-16co01
 * CREATED ON : Aug 10,2017
 */
 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAXSIZE 3

int Queue[MAXSIZE],front=-1,rear=-1;

int isFull()
{
	//return 1 if  is full else return 0
	if((rear==MAXSIZE-1 && front==0)||(rear+1==front))
		return 1;
	else
		return 0;
}

int isEmpty(){
	//return 1 if Queue is empty else return -0
	if(front == -1 && rear == -1)
		return 1;
	else 
		return 0;
}

void display()
{
	//return element at the front of Queue 
	int i=front;
	if(!isEmpty())
	{
		while(i!=rear)
		{
			printf("%d\t",Queue[i]);
			i=(i+1)%MAXSIZE;
		}
		printf("%d\t",Queue[i]);
	}
	else 
		printf("\nQueue is Empty.");
}	

void insertQueue(int d)
{
	//insert an element 
	if(!isFull())
	{
		if(front==-1)
		{
			front++;
		}
		rear=(rear+1) % MAXSIZE;
		Queue[rear]=d;
		printf("ELEMENT INSERT SUCCESSFULLY %d\n",d);
	}
	else
		printf("QUEUE IS FULL ");
}

void deleteQueue()
{
	//delete an element
	if(!isEmpty())
	{
		int d=Queue[front];
		if(front==rear)
			front=rear=-1;
		else 
			front=(front+1) % MAXSIZE;
		printf("THE ELEMENT DELETED IS %d",d);
	}	
	else
		printf("QUEUE IS EMPty");
}

int main()
{
	int choice,e;
	while(1)
	{
	    printf("1.Display 2.INSERT 3.DELETE 4.EXIT\n");
		printf("ENTER CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				display();//call display function
				break;
			case 2:
				printf("ENTER ELEMENT TO INSERT");
				scanf("%d",&e);
				insertQueue(e);//call insertqueue function
				break;
			case 3:
				deleteQueue();//call deletequeue function
				break;
			case 4:
				exit(0);//call exit function
				break;
			default:
				printf("ENTER INVALID CHOICE");//for invalid choice
		}
	}
}
/*

OUTPUT:
-----------------------------------------------------
 1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
2
ENTER ELEMENT TO INSERT10
ELEMENT INSERT SUCCESSFULLY 10
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
2
ENTER ELEMENT TO INSERT65
ELEMENT INSERT SUCCESSFULLY 65
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
2
ENTER ELEMENT TO INSERT40
ELEMENT INSERT SUCCESSFULLY 40
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
2
ENTER ELEMENT TO INSERT12
QUEUE IS FULL 
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
3
THE ELEMENT DELETED IS 10
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
1
65      40      
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE
4
-------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int Queue[MAXSIZE],front=-1,rear=-1;
int isFull()
{
	//return 1 if  is full else return 0
	if(rear == MAXSIZE-1)
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
int peek()
{
	//return element at the front of Queue 
	return Queue[front];
}	
void insertQueue(int d)
{
	if(!isFull())
	{
		if(isEmpty())
		{
			front++;
		}
		Queue[++rear]=d;
		printf("ELEMENT INSERT SUCCESSFULLY %d",d);
	}
	else
		printf("QUEUE IS FULL ");
}
void deleteQueue()
{
	if(!isEmpty())
	{
		int d=Queue[front];
		if(front==rear)
			front=rear=-1;
		else 
			front++;
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
		printf("ENTER CHOICE");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(isEmpty())
					printf("QUEUE IS EMPTY");
				else
					printf("ELEMENT IS FRONT OF QUEUE IS %d",peek());
				break;
			case 2:
				printf("ENTER ELEMENT TO INSERT");
				scanf("%d",&e);
				insertQueue(e);
				break;
			case 3:
				deleteQueue();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("ENTER INVALID CHOICE");
		}
	}
}

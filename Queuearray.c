/*
 * DISCRIPTION : Array implementation of queue
 * AUTHOR : Nooras Fatima-16co01
 * CREATED ON : Aug 10,2017
 */
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
	//insert an element
	if(!isFull())
	{
		if(isEmpty())
		{
			front++;
		}
		Queue[++rear]=d;
		printf("ELEMENT INSERT SUCCESSFULLY %d\n",d);
	}
	else
		printf("QUEUE IS FULL\n ");
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
			front++;
		printf("THE ELEMENT DELETED IS %d\n",d);
	}	
	else
		printf("QUEUE IS EMPtY\n");
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
				if(isEmpty()) //call isEmpty function
					printf("\nQUEUE IS EMPTY");
				else
					printf("\nELEMENT IS FRONT OF QUEUE IS %d\n",peek());
				break;
			case 2:
				printf("\nENTER ELEMENT TO INSERT\n");
				scanf("%d",&e);
				insertQueue(e);//call insertQueue function
				break;
			case 3:
				deleteQueue();//call deleteQueue function
				break;
			case 4:
				exit(0);//call exit function
				break;
			default:
				printf("\nENTER INVALID CHOICE\n");//for default fuction
		}
	}
}
/*
 OUTPUTS:
 ------------------------------------------------
 1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE2
ENTER ELEMENT TO INSERT
12
ELEMENT INSERT SUCCESSFULLY 12
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE2
ENTER ELEMENT TO INSERT
56
ELEMENT INSERT SUCCESSFULLY 56
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE3
THE ELEMENT DELETED IS 12
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE1
ELEMENT IS FRONT OF QUEUE IS 56
1.Display 2.INSERT 3.DELETE 4.EXIT
ENTER CHOICE4
------------------------------------------------
*/

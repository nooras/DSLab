/*
 * DISCRIPTION : Evaluation of postfix expression
 * AUTHOR : Nooras Fatima-16co01
 * CREATED ON : July 27,2017
 */

#include<stdio.h>
#include<ctype.h>
typedef struct conversion
{
	int a[30];
	int  top;
}stack;
void push(stack *s,int);
int pop(stack *s);
int operation(int num1,int num2,char opr);
int evaluate(char pos[]);
int main()
{
	char postfix[30];
	printf("\nENTER POSTFIX EXPRESSION\n");
	scanf("%s",postfix);
	printf("\nEVALUATED POSTFIX EXPRESSION=%d",evaluate(postfix));
	return 0;
}

void push(stack *s,int opr)
{
		if(s->top<29)
		{	s->top++;
			s->a[s->top]=opr;
		}
}
int pop(stack *s)
{
	if (s->top==-1)
	{
		printf("stack is empty\n");
		return 0;
    }
    else
    {
		int data=s->a[s->top--];
		return data;
    }
}
int operation(int num1,int num2,char opr)
{
	switch(opr)
	{
		case'+':
		return num1+num2;
		break;
		case'-':
		return num1-num2;
		break;
		case'*':
		return num1*num2;
		break;
		case'/':
		return num1/num2; 
	}
}
	
int evaluate(char pos[30])
{
	int i,n1,n2,result,opr;
	stack s;
	for(i=0;pos[i]!='\0';i++)
	{
		opr=pos[i];
		if(isdigit(opr))
		push(&s,opr-'0');
		else
		{
			n1=pop(&s);
			n2=pop(&s);
			result=operation(n1,n2,opr);
			push(&s,result);
		}
	}
	return pop(&s);
}

/*
 
 OUTPUT:
 
------------------------------------
ENTER POSTFIX EXPRESSION
453*+

EVALUATED POSTFIX EXPRESSION=19

------------------
(program exited with code: 0)
-------------------------------------
ENTER POSTFIX EXPRESSION
453*+23*+

EVALUATED POSTFIX EXPRESSION=25

------------------
(program exited with code: 0)
-------------------------------------

*/

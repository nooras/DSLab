/*
 * DISCRIPTION : Check continuity of different types of parenthesis using stack
 * AUTHOR : Nooras Fatima-16co01
 * CREATED ON : Aug 04,2017
 */
 
#include<stdio.h>
#include<ctype.h>

typedef struct conversion
{
	char a[30];
	int  top;
}stack;

void push(stack *s,char);

char pop(stack *s);

void checkcontinuity(char exp[]);

int isMatchpair(char left,char right);

int main()
{
	char exp[30];
	printf("\nENTER AN EXPRESSION CONTAINING ONLY BRACKETS:\n");
	scanf("%s",exp);
	checkcontinuty(exp);
	return 0;
}

void push(stack *s,char opr)
{
		if(s->top<29)
		{	
			s->top++;
			s->a[s->top]=opr;
		}
		else
			printf("STACK IS FULL\n");
}

char pop(stack *s)
{
	if (s->top==-1)
	{
		printf("STACK IS EMPTY\n");
		return 0;
    }
    else
    {
		char data=s->a[s->top--];
		return data;
    }
}

void checkcontinuty(char exp[])
{
	int i;
	char c;
	stack s;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		push(&s,exp[i]);
		else
		{
			if(s.top==-1)
			{
				printf("EXPRESSION IS INVALID\n");
				return;
			}
			else
			{
				c=pop(&s);
				if(isMatchpair(c,exp[i]))
					 continue;
				else
				{
					printf("EXPRESSION IS INVALID\n");
					break;
				}
			}

		}
	}
	if(s.top!=-1)
		printf("EXPRESSION IS INVALID\n");
	else
		printf("EXPRESSION IS VALID\n");
	
}

int isMatchpair(char left,char right)
{
		switch(left)
		{
			case '(':
				if(right==')')
					return 1;
				else 
					return 0;
				break;
			case '{': 
				if(right=='}')
					return 1;
				else 
					return 0;
				break;
			case '[':
				if(right==']')
					return 1;
				else
					return 0;
				break;
			default:
				return 0;
		}
}
/*
OUTPUTS:
------------------------------------------------------------------
ENTER AN EXPRESSION CONTAINING ONLY BRACKETS:
{{()[]}{([]())}}
EXPRESSION IS VALID
-----------------------------------------------------------------
ENTER AN EXPRESSION CONTAINING ONLY BRACKETS:
{[()]}}
EXPRESSION IS INVALID
------------------------------------------------------------------

*/

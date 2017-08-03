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
	printf("\nENTER AN EXPRESSION CONTAINING ONLY BRACKETS");
	scanf("%s",exp);
	checkcontinuty(exp);
	return 0;
}

void push(stack *s,char opr)
{
		if(s->top<29)
		{	s->top++;
			s->a[s->top]=opr;
		}
}
char pop(stack *s)
{
	if (s->top==-1)
	{
		printf("stack is empty\n");
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
				printf("expression is invalid\n");
				return;
			}
			else
			{
				c=pop(&s);
				if(isMatchpair(c,exp[i]))
					 continue;
				else
				{
					printf("expression is invalid\n");
					break;
				}
			}

		}
	}
	if(s.top!=-1)
		printf("expresssion not valid\n");
	else
		printf("expresssion valid\n");
	
}
int isMatchpair(char left,char right)
{
		switch(left)
		{
			case '(':if(right==')')
			return 1;
			else 
			return 0;
			break;
			case '{':if(right=='}')
			return 1;
			else 
			return 0;
			break;
			case '[':if(right==']')
			return 1;
			else
			return 0;
			break;
			default:
			return 0;
		}
}


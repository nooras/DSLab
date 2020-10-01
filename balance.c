/*Description: Check the continuity or balance of parenthesis in an expression.
 * Learner: Shiakh Mariyam Anis.
 */


#include<stdio.h>

typedef struct balanced
{
  char a[30];
  int top;
}stack;

 void push(stack *s,char opr)
	{
		if(s->top>29)
		{
			printf("stack is full");
			return ;
		}
			else
		{
		s->top++;
		s->a[s->top]=opr;
	}
	}
  char pop(stack *s)
	{
		if(s->top==-1)
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

int isMatchingpair (char left,char right)
{
	switch(left)
	{
		case '(' : if(right==')')
				return 1;
				else
				return 0;
		
		case '{' : if(right=='}')
				return 1;
				else
				return 0;
		
		case '[' : if(right==']')
				return 1;
				else
				return 0;
		
		default :
				return 0;
	}
}	
	 
void checkcontinuity ( char exp[])
{
	int i;
	stack s;
	s.top=-1;
	char c;
	for(i=0;exp[i]!='\0';i++)
	{
		if (exp[i]=='('|| exp[i]== '{' || exp[i]=='[')
		  push(&s ,exp[i]);
		else
		 {
			 if  (s.top !=-1)
			   c=pop(&s);
			 else
			   printf("exprsesion is invalid");
			 if(isMatchingpair(c,exp[i]))
			   continue;
			  else
			  { 
				printf("expression is invalid");
				return;
			  }
		  }
	}
	 if (s.top==-1)
		printf("expression is valid");	
	 else
		printf("expression is invalid");
}		
		
		   
 
int main()

{
    char expression[30];
    printf("\n ENTER AN EXPRESSION CONTAINING ONLY BRACKET \n");
    scanf("%s",expression);
    checkcontinuity(expression);
    return 0;
}
/*Output
 
 ENTER AN EXPRESSION CONTAINING ONLY BRACKET 
{{()[]()}}
expression is valid
------------------
(program exited with code: 0)
Press return to continue
*/

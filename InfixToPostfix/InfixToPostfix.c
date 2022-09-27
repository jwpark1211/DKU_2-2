#include <stdio.h>
#include <stdlib.h>
#include "st_common.h"

void printStack(Stack* s)
{
	int i;
	for (i = 0; i < s->top + 1; i++)
	{
		printf("%c", s->stack[i]);
	}
	printf("\n");
}
int priority(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '/' || op == '*')
		return 2;
	else if (op == '(' || op == ')')
		return 0;
}
void InfixToPostfix(Stack* s, char* s1)
{
	int i;
	for (i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == '(')   	
			push(s, s1[i]);
		else if (s1[i] == ')')
		{
			while ( (s->stack[s->top])!= '(')
			{
				printf("%c", pop(s));
			}
			pop(s);
		}
		else if (((int)s1[i] >= 65 && (int)s1[i] <= 90) || ((int)s1[i] >= 97 && (int)s1[i] <= 122))
		{
			printf("%c", s1[i]);
		}
		else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '/' || s1[i] == '*')
		{
			if (priority(s->stack[s->top]) >= priority(s1[i]))
			{
			printf("%c", pop(s));
			push(s, s1[i]);
			}
			else
				push(s, s1[i]);
		}
	}
	printStack(s);
	}

int main(void)
{
	Stack stack;
	initStack(&stack);

	char s1[] = "(a-B)*(c+D)/(e-F)";
	InfixToPostfix(&stack, s1);
}

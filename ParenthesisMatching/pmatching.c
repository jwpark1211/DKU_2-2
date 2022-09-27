#include <stdio.h>
#include <stdlib.h>
#include "st_common.h"

void printStack(Stack* s)
{
	int i;
	printf("stack  ");
	for (i = 0; i <s->top+1; i++)
	{
		printf("%d  ", s->stack[i]);
	}
	printf("\n");
}

void ptMatching(Stack* s, char* s1)
{
	int i;
	//stack 출력 
	printf("[stack]\n");
		for (i = 0; i < strlen(s1); i++)
		{
			if (s1[i] == '(') {
				push(s, i);
				printStack(s);
			}
			else if (s1[i] == ')') {
				pop(s);
				printStack(s);
			}
			else
				continue;
		}
	// pair 순서쌍 출력
		printf("[pair]\n");
		for (i = 0; i < strlen(s1); i++)
		{
			if (s1[i] == '(') {
				push(s, i);
			}
			else if (s1[i] == ')') {
				printf("(%d,%d)   ",pop(s),i);
			}
			else
				continue;
		}
       printf("\n");       
}

int main(void)
{
	Stack stack;
	initStack(&stack);
	char s1[] = "(a-b*c)+d-(e-(f-g)/h)/(i*j)-k";
	ptMatching(&stack, s1);

	return 0;
}


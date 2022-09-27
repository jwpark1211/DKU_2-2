#include <stdlib.h>
#include "st_common.h"

void initStack(Stack* s) { s->top = -1; }
int isFull(Stack* s)
{
	return (s->top == SIZE - 1);
}
int isEmpty(Stack* s)
{
	return (s->top == -1);
}
void push(Stack* s, char value)
{
	if (isFull(s))
		printf("스택이 포화상태입니다.");
	else {
		s->stack[++(s->top)] =value;
	}
}
char pop(Stack* s)
{
	if (isEmpty(s)) {
		printf("스택이 비어있습니다.");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

#ifndef ST_COMMON_H
#define ST_COMMON_H

#define SIZE 50

typedef struct {
	char stack[SIZE];
	int top;
}Stack;

void initStack(Stack* );
int isFull(Stack* );
int isEmpty(Stack* );
void push(Stack* , char );
char pop(Stack* );

#endif

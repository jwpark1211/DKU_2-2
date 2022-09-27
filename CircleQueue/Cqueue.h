#ifndef CQUEUE_H
#define CQUEUE_H

#define SIZE 21

typedef struct {
	char arr[SIZE];
	int front, rear;
}Queue;

void initQueue(Queue *q);
int IsEmpty(Queue* q);
int IsFull(Queue* q);
void EnQueue(Queue* q, char value);
void DeQueue(Queue* q);
void PrintQueue(Queue* q);
char RandomAlphabet();

#endif

#include <time.h>
#include <stdlib.h>
#include "Cqueue.h"

char RandomAlphabet()
{
	int randVal = rand() % 26;
	randVal += 65;
	return (char)randVal;
}
void initQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
}
int IsEmpty(Queue* q) {
	return (q->front == q->rear);
}
int IsFull(Queue* q) {
	return ((q->rear + 1) % SIZE == q->front);
}
void PrintQueue(Queue* q) {
	int i;
	for (i = 0; i < SIZE; i++) {
		if (i == (q->front + 1) % SIZE)
			printf("<<");
		else
			printf(" ");
		if (q->front < q->rear) {
			if (q->front < i && i <= q->rear)
				printf("%2c", q->arr[i]);
			else
				printf("__");
		}
		else if (q->rear < q->front) {
			if (i <= q->rear || q->front < i)
				printf("%2c", q->arr[i]);
			else printf("__");
		}
		if (i == q->rear)
			printf(" <-");
		else
			printf(" ");
	}
	printf("\n");

}
void EnQueue(Queue* q, char value) {
	if (IsFull(q))
		printf("큐가 포화상태입니다.\n");
	else {
		q->rear = (q->rear + 1) % SIZE;
		q->arr[q->rear] = value;
		PrintQueue(q);
	}
}
void DeQueue(Queue* q) {
	if (IsEmpty(q))
		printf("큐가 비어있습니다.\n");
	else
	{
		q->front = (q->front + 1) % SIZE;
		PrintQueue(q);
	}
}

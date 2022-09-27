#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cqueue.h"


int main()
{
	Queue q;
	initQueue(&q);

	int i; 
	srand((unsigned)time(NULL));

	for (i = 0; i < 11; i++)
	{
		EnQueue(&q, RandomAlphabet());
	}

	DeQueue(&q);
	DeQueue(&q);

	for (i = 0; i < 11; i++)
	{
		EnQueue(&q, RandomAlphabet());
	}
	return 0;
}


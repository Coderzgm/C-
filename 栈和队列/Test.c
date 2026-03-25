#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	//‘≠µÿ¿©»›
//	//“Ïµÿ¿©»›
//	int* p1 = (int*)malloc(8);
//	printf("%p\n", p1);
//	int* p2 = (int*)realloc(p1,800);
//	printf("%p\n", p2);
//	return 0;
//}
#include"Stack.h"

//int main()
//{
//	ST s;
//	STInit(&s);
//	STPush(&s,1);
//	STPush(&s,2);
//	STPush(&s,3);
//	STPush(&s,4);
//	
//	while(!STEmpty(&s))
//	{
//		printf("%d ", STTop(&s));
//		STPop(&s);
//	}
//
//	STDestroy(&s);
//	return 0;
//}
#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	return 0;
}
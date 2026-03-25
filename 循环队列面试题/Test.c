#include<stdio.h>
#include"WQueue.h"

//初始化顺序队列
void initSeqQueue(SeqQueue* Q)
{
    Q->front = 0;
    Q->rear = Q->front;
    return;
}

//判断队列是否为空
int isEmpty(SeqQueue* Q)
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

//判断队列是否为满
int isFull(SeqQueue* Q)
{
    if (Q->front == (Q->rear + 1) % MAXSIZE)
        return 1;
    else
        return 0;
}

//循环队列的入队列操作,入队成功返回1,入队失败返回0;
int enSeqQueue(SeqQueue* Q, DataType element)
{
    if (isFull(Q))
    {
        //printf("队列已满,无法继续进队!\n");
        return 0;
    }
    else
    {
        Q->queue[Q->rear] = element;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}


//循环队列出队列操作,出队成功返回1,出队失败返回0;
int deSeqQueue(SeqQueue* Q, DataType* element)
{
    if (isEmpty(Q))
    {
        //printf("队列已空,无法继续出队!\n");
        return 0;
    }
    else
    {
        *element = Q->queue[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return 1;
    }
}

//获取队列的长度
int getLength(SeqQueue* Q)
{
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//获取队头元素
int getHead(SeqQueue* Q, DataType* element)
{
    if (isEmpty(Q))
    {
        return 0;
    }
    else
    {
        *element = Q->queue[Q->front];
        return 1;
    }
}

//遍历循环队列
void traverseSeqQueue(SeqQueue* Q)
{
    int i;

    if (isEmpty(Q))
        return;
    else if (Q->front < Q->rear)
    {
        for (i = Q->front; i < Q->rear; i++)
        {
            printf("%d ", Q->queue[i]);
        }
    }
    else
    {
        for (i = Q->front; i < MAXSIZE; i++)
        {
            printf("%d ", Q->queue[i]);
        }
        for (i = 0; i < Q->rear; i++)
        {
            printf("%d ", Q->queue[i]);
        }
    }
    return;
}

//主函数
int main(void)
{
    SeqQueue  Q;
    DataType  element;
    int i;

    initSeqQueue(&Q);

    enSeqQueue(&Q, 1);

    deSeqQueue(&Q, &element);
    for (i = 0; i < 100; i++)
    {
        enSeqQueue(&Q, i);
    }
    traverseSeqQueue(&Q);
    printf("\n");
    return 0;
}

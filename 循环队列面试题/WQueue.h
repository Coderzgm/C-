#pragma once
#include<stdio.h>
#define MAXSIZE 100

typedef int DataType;
//顺序队列的结构体类型
typedef struct
{
    DataType queue[MAXSIZE];//存贮队列元素的一维数组
    int front;//队头指针指示的是队头元素的位置
    int rear;//队尾指针指示的是队尾元素位置的下一个位置
}SeqQueue;

//函数前置声明
void initSeqQueue(SeqQueue* Q);
void traverseSeqQueue(SeqQueue* Q);
int isEmpty(SeqQueue* Q);
int isFull(SeqQueue* Q);
int enSeqQueue(SeqQueue* Q, DataType element);
int deSeqQueue(SeqQueue* Q, DataType* element);
int getLength(SeqQueue* Q);
int getHead(SeqQueue* Q);
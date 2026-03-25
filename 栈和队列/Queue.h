#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

//需要改变结构体内的内容和指针，需要二级指针
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

//改变结构体内的指针，传一级指针改变指向节点的指针
typedef struct Queue
{
	QNode* phead;//结构体指针--解引用一次即可访问数据val
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
//队尾插入
void QueuePush(Queue* pq, QDataType x);
//队头删除
void QueuePop(Queue* pq);

//取队头队尾的数据
QDataType QueueFront(Queue* pq);
QDataType QueueBark(Queue* pq);

//有多少数据
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

////队尾
//void QueuePush(QNode** phead, QNode** ptail, QDataType x);
// 设置两个指向结构体内部的指针的指针，用于改变整个节点的指向
// 同时这也用于定位队列的头尾部分
////队头删除
//void QueuePop(QNode** phead, QNode** ptail);


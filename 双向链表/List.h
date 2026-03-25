#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
//定义双向链表节点的结构
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
//打印
void LTPrint(LTNode* phead);
//初始化
void LTInit(LTNode** pphead);
//不改变哨兵位的地址，传一级指针即可
//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//尾删
void LTPopBack(LTNode* phead);
//头删
void LTPopFornt(LTNode* phead);

//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
LTNode* LTFind(LTNode* phead, LTDataType x);
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Contact.h"
//定义顺序表的结构

//#define N 100
//
////静态顺序表
//struct SeqList
//{
//	int arr[N];
//	int size;//有效数据个数
//};

typedef peoInfo SLDataType;
//重命名int，有时要修改类型，直接将int修改为char即可
//动态顺序表
typedef struct SeqList
{
	SLDataType* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}SL;

//顺序表初始化
void SLInit(SL* ps);//设置一个指向SL的指针ps
//顺序表的销毁
void SLDestory(SL* ps);
//顺序表打印
void SLPrint(SL s);

//头部插入删除/尾部插入删除
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);
	
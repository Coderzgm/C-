#include"SList.h"
void SLTprint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur!=NULL)//pcur!=NULL
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//开辟一个新的节点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL; //这里少写了
	return newnode;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//空链表和非空链表的处理 
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else 
	{
		//找尾
		SLTNode* ptail = *pphead;
		while (ptail->next)//ptail->next!=NULL
		{
			ptail = ptail->next;
		}
		//ptail指向的就是尾结点
		ptail->next = newnode;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode=SLTBuyNode(x);
	newnode->next = *pphead ;
	*pphead = newnode;
}
void SLTPopback(SLTNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* prev = *pphead;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;//->优先级高于*
	free(*pphead);
	*pphead = next;
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)//pcur!=NULL
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	SLTNode* prev = *pphead;
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos节点
void SLErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead && pphead);
	assert(pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
void SListDesTroy(SLTNode** pphead)
{
	assert(*pphead && pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}
#include"List.h"
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
//申请节点
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->data = x;
	node->next = node->prev=node;
	return node;
}
void LTInit(LTNode** pphead)
{
	*pphead = LTBuyNode(-1);
}
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead phead->prew newnode 
	newnode->prev = phead->prev;
	newnode->next = phead;

	phead->prev->next = newnode;
	phead->prev = newnode;
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}
void LTPopBack(LTNode* phead)
{
	//链表必须有效且链表不能为空（只有一个哨兵位（
	assert(phead && phead->next != phead);
	LTNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;

	free(del);
	del = NULL;
}
void LTPopFornt(LTNode* phead)
{
	assert(phead);
	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

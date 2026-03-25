#include"SList.h"

//void SListTest01()
//{
//	//链表是由一个个的节点
//	//创建节点
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->data = 1;
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->data = 2;
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 3;
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//	node4->data = 4;
//	//将四个节点连接起来
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	//调用链表的打印
//	SLTNode* plist = node1;
//	SLTPrint(plist);
//}

void SListTest02()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTprint(plist);
	SListDesTroy(&plist);
	SLTprint(plist);
	//SLTNode* find=SLTFind(plist, 1);
	//SLTInsert(&plist, find, 11);
	//SLTInsertAfter(find, 12);
	//SLErase(&plist, find);
	//SLTprint(plist);
	//SLTEraseAfter(find);
	//SLTprint(plist);
	//if (find==NULL)
	//{
	//	printf("没有找到！\n");
	//}
	//else {
	//	printf("找到了\n");
	//}
	//SLTPushFront(&plist, 5);
	//SLTPopback(&plist);
	//SLTprint(plist);
	//SLTPopback(&plist);
	//SLTprint(plist);
	//SLTPopback(&plist);
	//SLTPopFront(&plist);
	//SLTprint(plist);
}

int main()
{
	SListTest02();
	return 0;
}
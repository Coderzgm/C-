#include"List.h"
void ListTest01()
{
	LTNode* plist = NULL;;
	LTInit(&plist);

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushFront(plist, 4);
	LTPopBack(plist);
	LTPopFornt(plist);
	LTNode* find = LTFind(plist, 2);
	LTInsert(find, 66);
	LTErase(find);
	LTPrint(plist);
	//if (find == NULL)
	//{
	//	printf("找不到！\n");
	//}
	//else {
	//	printf("找到了！\n");
	//}
}
int main()
{
	ListTest01();
	return 0;
}
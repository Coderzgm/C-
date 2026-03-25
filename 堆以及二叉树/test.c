#include"Heap.h"

//二叉树有明确的度
//#define N 4
//struct TreeNode
//{
//	int val;
//	struct TreeNode* subs[N];
//};

//没有明确的度
//struct TreeNode
//{
//	int val;
//	//SeqList subs;//顺序表内部存struct TreeNode*
//};

//链式结构二叉树
//struct TreeNode
//{
//	int val;
//	struct TreeNode* leftchild;
//	struct TreeNode* rightBrother;
//};

void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7,23,55,232,66,222,33,7,1,66,3333,999};
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	//大堆由大到小排序打印
	while (!HPEmoty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}

	//找出最大的前k个
	//int k = 0;
	//scanf("%d", &k);
	//while (k--)
	//{
	//	printf("%d ", HPTop(&hp));
	//	HPPop(&hp);
	//}
	//printf("\n");
	HPDestory(&hp);
}

void HeapSort(int* a, int n)
{	//降序，建小堆
	//升序，建大堆
	//向上调整建堆 O(N*logN)
	/*for (int i = 1; i < n; i++)
	{
		Adjustup(a, i);
	}*/

	//向下调整建堆O(N)
	//第一次建立大堆，从后往前调整建堆
	for (int i = (n - 2) / 2; i > 0; i--)
	{
		AdjustDown(&a, n, i);
	}
	//建成有序的堆后，再建成有序的数组
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		//大堆升序最大数已经在最后，不需要调整，传end
		AdjustDown(&a, end, 0);
		--end;
	}
}

void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,23,55,232,66,222,33,7,1,66,3333,999 };
	HeapSort(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestHeap2();

	return 0;
}
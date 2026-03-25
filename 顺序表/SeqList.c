#include"SeqList.h"

//顺序表初始化
void SLInit(SL* ps)//注意传参传的是地址不是值
//用结构体指针变量对结构体内部的数据进行初始化
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//顺序表销毁
void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//判断并申请空间
SLCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		//申请空间
		//malloc calloc realloc  int arr[100]不够用需增容-->realloc
		//三目表达式
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));//要申请多大空间
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);//直接退出程序，不再继续执行
		}
		//空间申请成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//等价于assert(ps!=NULL)
	//ps->arr[ps->size] = x;
	//++ps->size;
	//插入数据之前先看空间够不够
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
	
}
//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);//看空间够不够，先进行申请空间

	//先让顺序表中已有的数据整体往后挪动一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//arr[1]=arr[0]
	}
	ps->arr[0] = x;
	ps->size++;
}
//打印
//void SLPrint(SL s)
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");
//}
//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	//保证顺序表不为空
	//ps->arr[ps->size-1]=-1;
	--ps->size;
}
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	//数据整体往前挪动一位
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//arr[size-2]=arr[size-1]
	}
	ps->size--;
}
//在指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
//int pos指定的位置，SLDataType x插入的数据
{
	assert(ps);
	assert(pos >= 0 && pos <= ps ->size);
	//插入前先进行判断空间够不够
	SLCheckCapacity(ps);
	//让pos及之后的数据往后挪一位
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//arr[pos+1]=arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除指定位置数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos;i<(ps->size-1);i++)
	{
		ps->arr[i] = ps->arr[i + 1];//arr[size-2]=arr[size-1]
	}
	ps->size--;
}
//查找
//int SLFind(SL* ps, SLDataType x)
//{
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == x)
//		{
//			//找到了
//			return i;
//		}
//	}
//	//没有找到
//	return -1;
//}
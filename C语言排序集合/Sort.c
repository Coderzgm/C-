#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				Swap(&a[j+1], &a[j]);
			}
		}
	}
}
//插入排序
void InsertSort(int* a, int n)
{	//[0,n-1]
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		//[0,n-2]是最后一组
		//[0,end]有序 end+1位置的值插入进入[0.end],保持有序
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}

}

////希尔排序=预排序+插入排序
void ShellSort(int* a, int n)
{
	//int gap = 3;
	//for(int j=0;j<gap;j++)
	//{
	//	for (size_t i = j; i < n - gap; i += gap)
	//	{
	//		int end = i;
	//		int tmp = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (tmp < a[end])
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	}
	//}
	int gap = n;
	while (gap > 1)
	{
		//+1保证最后一个gap一定是1
		//gap>1时时预排序
		//gap==1时时插入排序
		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//选择排序：选出最小的再进行排序
void SelectSort(int* a, int n)
{
	int begin = 0; int end = n - 1;
	while (begin < end)
	{
		int mini = begin; int maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[maxi])
			{
				mini = i;
			}
		}
		Swap(&a[begin],&a[mini]);
		Swap(&a[end],&a[maxi]);
		++begin;
		++end;
	}
}

//堆排序
void AdjustDown(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		//判断左右孩子的大小
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
		//与父亲节点比较
		if (a[root] < a[child])
		{
			Swap(&a[root], &a[child]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
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

//快速排序2 前后指针法
int PartSort2(int* a, int left, int right)
{
	//三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur < right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		else
		{
			++cur;
		}
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

//三数取中
GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	//left midi right
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else//a[left]>a[midi]
	{
		if (a[midi] > a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//快速排序1 左右指针法
int PartSort1(int* a, int left, int right)
{
	// 三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		// 右边先走，找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// 左边后走，找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[keyi], &a[begin]);
	return begin;
}
//有序条件下：效率退化
// 1、随机选key
// 2、三数取中
//快速排序
//面试手撕，不用三数取中和小区间优化
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//排完后的结束条件也是递归法的结束条件
		return;

	//小区间优化，不在递归分割排序，减少递归的次数
	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int keyi = PartSort2(a,left, right);
		//[left,keyi-1] keyi [keyi+1,end]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}

//快速排序非递归,用栈手动维护
#include"Stack.h"
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort2(a, begin, end);
		//[begin,keyi-1] keyi [keyi+1,end]
		//先入右再入左
		//区间内个数判断，仅剩一个值不用入栈了
		if (keyi + 1 < end)
		{
			//小区间begin和end处理
			//先入右再入左
			STPush(&st, end);
			STPush(&st, keyi+1);
		}
		if (begin < keyi - 1)
		{
			STPush(&st, keyi-1);
			STPush(&st, begin);
		}
	}
	STDestroy(&st);
}

//时间复杂度：O(N*logN)
//空间复杂度：O(N)
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin == end)
		return;
	int mid = (begin + end) / 2;
	//如果[begin,mid-1][mid,end]有序就可以进行归并了
	//拆散为个体
	_MergeSort(a, tmp, begin, mid - 1);
	_MergeSort(a, tmp, mid, end);

	//归并
	int begin1 = begin, end1 = mid - 1;
	int begin2 = mid, end2 = end;
	int i = begin;
	while (begin1<=end1 && begin2<=end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//其中一个结束的情况进行分类讨论
	while(begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0,n-1);

	free(tmp);
	tmp = NULL;
}

//归并排序非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	//gap->每组归并数据的个数
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[begin1,end1][begin2,end2]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1; 

			//第二组都越界不存在，这一组不需要归并
			if (begin2 >= n)
			{
				break;
			}

			//第二组的begin2没越界，end2越界了
			if (end2 > n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			//其中一个结束的情况进行分类讨论
			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}
	

	free(tmp);
	tmp = NULL;
}
//时间复杂度：O(N+range)
//只适合整数/适合范围集中的
//空间复杂度：O(range)
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i=1;i<n;i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)calloc(range,sizeof(int));
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	//统计次数
	for (int i = 0; i < n; i++)
	{
		//相对映射--对应尾部下标同样的元素
		//统计各个数出现的次数，让对应下标的元素++
		count[a[i] - min]++;
	}
	//排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(count);
}


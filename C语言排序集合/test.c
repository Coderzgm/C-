#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 2,4,3,1,9,7,6,5,8,0 };

	PrintArry(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestInsertSort();
	return 0;
}
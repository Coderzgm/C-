#pragma once
#include<stdio.h>
#include<stdlib.h>
void Swap(int* p1, int* p2);
void PrintArry(int* a, int n);

//插入排序
void InsertSort(int* a, int n);


//希尔排序=预排序+插入排序
void ShellSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//冒泡排序：适合教学，实践中没啥价值
void BubbleSort(int* a, int n);
//选择排序
void SelectSort(int* a, int n);
//快速排序
void QuickSort(int* a, int left, int right);
//快速排序非递归
void QuickSortNonR(int* a, int left, int right);
//归并排序
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
//记叙排序
void CountSort(int* a, int n);

//这些排序稳定性：相同的值相对顺序不变
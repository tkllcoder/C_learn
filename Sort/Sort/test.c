#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"stack.h"
#include<string.h>

//打印函数
void Print(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//1直接插入排序 以升序为例  对有序，接近有序，局部有序适应性更强。
//最好的情况:顺序O(N)
//最坏的情况:逆序O(N^2)
void InsertSort(int* a, int n)
{
	int i = 0;
	//循环控制有序的数的个数
	for (i = 0; i < n - 1; i++)
	{
		//1.假设前i个数已经有序，则保存第i+1个数
		int end = i;
		int tmp = a[end + 1];
		//2.从end开始与tmp比较，
		//如果end位置数比tmp大，则将end挪到end+1,end--
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			//否则找到合适位置，跳出循环
			else
			{
				break;
			}
		}
		//循环结束，或者跳出循环，都将tmp放到a[end+1]位置
		a[end + 1] = tmp;
	}
}

//2希尔排序 时间复杂度O(N*logN)这里log底数为2. 2^10 = 1024 2^20 = 100w.
void ShellSort(int* a, int n)
{
	int gap = n;
	int i = 0;
	//gap从大到小最后到1
	while (gap /= 2)//logN次循环
	{
		//把间隔为gap的多组数据一起预排。循环结束条件很奇妙
		//接近O(N)
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			//直接插入排序的逻辑 以gap为每次的跳动 预排序
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				//否则找到合适位置，跳出循环
				else
				{
					break;
				}
			}
			//循环结束，或者跳出循环，都将tmp放到a[end+1]位置
			a[end + gap] = tmp;
		}
	}
}

//3堆排序 借助堆来选择
void Swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
//满足条件的向下调整算法 建大堆
void AdjustDown(int* a, int n, int root)
{
	//a.从根节点开始，根节点与左右孩子中大的比较
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//防止越界
		if ((child+1)<n && a[child] < a[child + 1])
		{
			child++;
		}//找到大的孩子下标并与父亲比较
		if (child<n && a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//如果子树都比父亲小则跳出
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//3 1.建堆，构建大堆或者小堆  当子树不是小堆时，从后往前依次调整，使得不断满足调整算法
	//建堆的时间复杂度为O(N)从倒数第二层开始调整 层数 较为精确的N-logN
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//如果要排升序，建大堆，不破坏堆的大体结构
	//2.排序   复杂度为O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		//把最大的数放到最后，end--，调整新的堆循环找最大的数
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a, end, 0);//调整层数次O(logN)
	}
	
}

//4直接选择排序 时间复杂度O(N*N) 不管最好最坏都是O(N*N)
void SelectSort(int* a, int n)
{
	//找出最大的和最小的分别交换到右边和左边 注意指针指向的值
	int begin = 0;
	int end = n - 1;
	int maxi = 0;
	int mini = 0;
	
	while (begin < end)
	{
		//找出最大最小
		for (int i = begin; i < end + 1; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		//最大的交换到右边end-- 假如交换的值为最小，则注意更改下标。
		if (end == mini)
		{
			mini = maxi;
		}
		Swap(&a[maxi], &a[end]);
		end--;

		//最小的交换到左边begin++
		Swap(&a[mini], &a[begin]);
		begin++;
	}
	
}

//5冒泡排序  O(N*N) 
void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	int exchange = 0;

	//排序的趟数 一趟排好一个，n个数就要排n-1趟
	for (i = 0; i < n - 1; i++)
	{
		//每一趟 从第一个数到最后相邻的两个数比较 大的向后交换
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
		}
		//如果一趟下来都没交换，则说明已经有序了
		if (exchange == 0)
		{
			break;
		}
	}
}

//三数取中法，解决快排的缺陷
int GetMiddle(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[right] > a[mid])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[right] > a[left])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}
//挖坑法函数
int DigMethod(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	//1.设三数取中获得的数为坑key，交换到第一个位置去，并保存到tmp
	int key = GetMiddle(a, left, right);
	Swap(&a[begin], &a[key]);
	key = begin;
	int tmp = a[key];
	//每趟O(N)
	//一次挖坑，使坑的数放到合适的位置，左边的数都比它小，右边的数都比它大。
	while (begin < end)
	{
		//2.右边找小，放到坑里，更新坑
		while (begin < end && a[end] >= tmp)
		{
			end--;
		}
		a[key] = a[end];
		key = end;

		//3.左边找大，放到坑里，更新坑
		while (begin < end && a[begin] <= tmp)
		{
			begin++;
		}
		a[key] = a[begin];
		key = begin;
	}
	//4.最后坑位置放tmp
	a[begin] = tmp;
	key = begin;

	return key;
}
//左右指针法函数
int LRPointer(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int key = GetMiddle(a, begin, end);
	Swap(&a[begin], &a[key]);
	key = begin;

	//一趟排完，一个数到合适的位置
	while (begin < end)
	{
		//先右边找小
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		//再左边找大
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		//找到之后两个数交换
		Swap(&a[begin], &a[end]);
	}
	//当begin=end时，找到合适的位置了，
	//再将合适的位置与key进行交换
	Swap(&a[begin], &a[key]);
	key = begin;
	return key;
}
//前后指针法函数
int FrontBack(int* a, int left, int right)
{
	int cur = left + 1;
	int prev = left;
	int key = GetMiddle(a, left, right);
	Swap(&a[prev], &a[key]);
	key = prev;

	while (cur < right + 1)
	{
		//前面指针cur找小
		while ((cur < right + 1) && a[cur] >= a[key])
		{
			cur++;
		}
		//找到小之后prev++，交换prev和cur位置的值，cur++
		if (cur < right + 1)//防止因为结束跳出的影响
		{
			prev++;
			Swap(&a[cur], &a[prev]);
			cur++;
		}
	}
	//找到合适位置后，将key和prev位置的值交换
	Swap(&a[prev], &a[key]);
	key = prev;

	return key;
}
//6快速排序  递归层数，每层O(N)，时间复杂度O(N*logN)
void QuickSort(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}
	//三种方法 获取一段序列的关键位置，使其左边都小于它，右边都大于它
	//int key = DigMethod(a, left, right);
	//int key = LRPointer(a, left, right);
	int key = FrontBack(a, left, right);

	//分治排左半边和右半边
	//小区间优化，当要排序的序列低于10个数的时候，采用插入排序进行更加快速，减少了大部分的递归次数。
	if ((key - 1 - left + 1 > 14))
	{
		QuickSort(a, left, key - 1);
	}
	else
	{
		InsertSort(&a[left], key - 1 - left + 1);
	}
	if ((right - (key + 1) + 1) > 14)
	{
		QuickSort(a, key + 1, right);
	}
	else
	{
		InsertSort(&a[key + 1], right - (key + 1) + 1);
	}
}
//快排非递归 以栈先进后出（后进先出） 来存储左右下标并控制循环条件
void RecycleQSort(int* a, int n)
{
	ST st;
	StackInit(&st);

	//先进右，后出右 后进左，先出左，先排左半部分
	StackPush(&st, n - 1);
	StackPush(&st, 0);
	//栈控制循环
	while (!StackEmpty(&st))
	{
		//取出左右下标
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		//完成本趟排序
		int key = DigMethod(a, left, right);

		//又分为左右部分进栈循环
		if (key + 1 < right)
		{
			//先压右 后压左先出左
			StackPush(&st, right);
			StackPush(&st, key + 1);
		}
		if (left < key - 1)
		{
			//先压右 后压左先出左
			StackPush(&st, key - 1);
			StackPush(&st, left);
		}
	}
	StackDestroy(&st);
}

//7 归并排序 每层N次，logN层，时间复杂度O(N*logN)   
// 1.假设分为两个部分，左半边有序，右半边有序，
//2.左半边与右半边一起开始，找到小的数，放到新的数组中，
//3.然后某一个部分结束，将没结束的数组全部挪到新数组
//4.最后将新数组的拷贝回原数组
void _MergeSort(int* a, int left, int right, int* b)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}

	//分解左右部分 直到不可分之后再从内到外归并
	int left1 = left;
	int right1 = (left + right) / 2;
	int left2 = (left + right) / 2 + 1;
	int right2 = right;
	//1左右半部分有序
	_MergeSort(a, left1, right1, b);
	_MergeSort(a, left2, right2, b);

	//归并排序算法
	int begin1 = left1;
	int begin2 = left2;
	int i = left;//注意起点
	//2
	while (begin1 <= right1 && begin2 <= right2)
	{
		if (a[begin1] < a[begin2])
		{
			b[i++] = a[begin1++];
		}
		else
		{
			b[i++] = a[begin2++];
		}
	}
	//3
	while (begin2 <= right2)
	{
		b[i++] = a[begin2++];
	}
	while (begin1 <= right1)
	{
		b[i++] = a[begin1++];
	}
	//4
	for (i = left; i <= right; i++)
	{
		a[i] = b[i];
	}
}
void MergeSort(int* a, int n)
{
	int* b = (int*)malloc(n * sizeof(int));
	_MergeSort(a, 0, n - 1, b);

	free(b);
}
//归并排序的非递归
void RecycleMSort(int* a, int n)
{
	int* b = (int*)malloc(n * sizeof(int));
	int gap = 1;//设置每组数据个数为gap 每两组进行归并
	while (gap < n)//从一个一个归并到2，4多个一起归并最后实现排序
	{
		for (int i = 0; i < n; i += 2 * gap)//[i, i+gap-1][i+gap, i+2*gap-1]下标设计
		{
			//归并排序算法
			int begin1 = i;
			int begin2 = i + gap;
			int end1 = i + gap - 1;
			int end2 = i + 2 * gap-1;
			int j = i;//注意起点
			//如果右半区间没有 则不用归并，保留到后面
			if (begin2 >= n)
			{
				break;
			}
			//如果右半部分超出数组，则修正到数组尾再归并
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			//2
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					b[j++] = a[begin1++];//放入新的数组
				}
				else
				{
					b[j++] = a[begin2++];
				}
			} 
			//3  某一个条件结束 剩余部分直接放入
			while (begin2 <= end2)
			{
				b[j++] = a[begin2++];
			}
			while (begin1 <= end1)
			{
				b[j++] = a[begin1++];
			}
			//4 某一个条件结束 剩余部分直接放入
			for (j = i; j <= end2; j++)
			{
				a[j] = b[j];
			}
		}
		gap *= 2;
	}
	free(b);
}

//8 计数排序
//时间复杂度为O(N+range)空间复杂的为O(range)仅适用于整数，且如果数相对集中效果更好。
void CountSort(int* a, int n)
{
	//1.找到数组中的最大最小值
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	//2.开辟空间的数量 并初始化为0
	int range = max - min + 1;
	int* tmp = (int*)malloc(range * sizeof(int));
	if (tmp == NULL)
	{
		return;
	}
	memset(tmp, 0, range * sizeof(int));

	//3.计数
	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j] == i + min)
			{
				tmp[i]++;
			}
		}
	}
	//4.排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i] > 0)
		{
			a[j++] = i + min;
			tmp[i]--;
		}
	}
	free(tmp);
}

//排序算法性能测试
void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(N * sizeof(int));
	int* a2 = (int*)malloc(N * sizeof(int));
	int* a3 = (int*)malloc(N * sizeof(int));
	int* a4 = (int*)malloc(N * sizeof(int));
	int* a5 = (int*)malloc(N * sizeof(int));
	int* a6 = (int*)malloc(N * sizeof(int));
	int* a7 = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	/*int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	printf("InsertSort:%d\n", end1 - begin1);*/

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("ShellSort:%d\n", end2 - begin2);

	int begin3 = clock();
	HeapSort(a3, N);
	int end3 = clock();
	printf("HeapSort:%d\n", end3 - begin3);

	/*int begin4 = clock();
	SelectSort(a4, N);
	int end4 = clock();
	printf("SelectSort:%d\n", end4 - begin4);*/

	/*int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();
	printf("BubbleSort:%d\n", end5 - begin5);*/

	int begin6 = clock();
	QuickSort(a6, 0, N-1);
	int end6 = clock();
	printf("QuickSort:%d\n", end6 - begin6);
	/*int begin6 = clock();
	RecycleQSort(a6, N);
	int end6 = clock();
	printf("RecycleQSort:%d\n", end6 - begin6);*/
	
	/*int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();
	printf("MergeSort:%d\n", end7 - begin7);*/
	int begin7 = clock();
	RecycleMSort(a7, N);
	int end7 = clock();
	printf("RecycleMSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

int main()
{
	int arr[] = { 20,17,24,24,27,25,28,20,25 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, n);
	//ShellSort(arr, n);
	//HeapSort(arr, n);
	//SelectSort(arr, n);
	//BubbleSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	//RecycleQSort(arr, n);
	//MergeSort(arr, n);
	//RecycleMSort(arr, n);
	CountSort(arr, n);

	Print(arr, n);

	//TestOP();

	return 0;
}
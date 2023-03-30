#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"stack.h"
#include<string.h>

//��ӡ����
void Print(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//1ֱ�Ӳ������� ������Ϊ��  �����򣬽ӽ����򣬾ֲ�������Ӧ�Ը�ǿ��
//��õ����:˳��O(N)
//������:����O(N^2)
void InsertSort(int* a, int n)
{
	int i = 0;
	//ѭ��������������ĸ���
	for (i = 0; i < n - 1; i++)
	{
		//1.����ǰi�����Ѿ������򱣴��i+1����
		int end = i;
		int tmp = a[end + 1];
		//2.��end��ʼ��tmp�Ƚϣ�
		//���endλ������tmp����endŲ��end+1,end--
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			//�����ҵ�����λ�ã�����ѭ��
			else
			{
				break;
			}
		}
		//ѭ����������������ѭ��������tmp�ŵ�a[end+1]λ��
		a[end + 1] = tmp;
	}
}

//2ϣ������ ʱ�临�Ӷ�O(N*logN)����log����Ϊ2. 2^10 = 1024 2^20 = 100w.
void ShellSort(int* a, int n)
{
	int gap = n;
	int i = 0;
	//gap�Ӵ�С���1
	while (gap /= 2)//logN��ѭ��
	{
		//�Ѽ��Ϊgap�Ķ�������һ��Ԥ�š�ѭ����������������
		//�ӽ�O(N)
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			//ֱ�Ӳ���������߼� ��gapΪÿ�ε����� Ԥ����
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				//�����ҵ�����λ�ã�����ѭ��
				else
				{
					break;
				}
			}
			//ѭ����������������ѭ��������tmp�ŵ�a[end+1]λ��
			a[end + gap] = tmp;
		}
	}
}

//3������ ��������ѡ��
void Swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
//�������������µ����㷨 �����
void AdjustDown(int* a, int n, int root)
{
	//a.�Ӹ��ڵ㿪ʼ�����ڵ������Һ����д�ıȽ�
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//��ֹԽ��
		if ((child+1)<n && a[child] < a[child + 1])
		{
			child++;
		}//�ҵ���ĺ����±겢�븸�ױȽ�
		if (child<n && a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//����������ȸ���С������
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//3 1.���ѣ�������ѻ���С��  ����������С��ʱ���Ӻ���ǰ���ε�����ʹ�ò�����������㷨
	//���ѵ�ʱ�临�Ӷ�ΪO(N)�ӵ����ڶ��㿪ʼ���� ���� ��Ϊ��ȷ��N-logN
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//���Ҫ�����򣬽���ѣ����ƻ��ѵĴ���ṹ
	//2.����   ���Ӷ�ΪO(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		//���������ŵ����end--�������µĶ�ѭ����������
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a, end, 0);//����������O(logN)
	}
	
}

//4ֱ��ѡ������ ʱ�临�Ӷ�O(N*N) ������������O(N*N)
void SelectSort(int* a, int n)
{
	//�ҳ����ĺ���С�ķֱ𽻻����ұߺ���� ע��ָ��ָ���ֵ
	int begin = 0;
	int end = n - 1;
	int maxi = 0;
	int mini = 0;
	
	while (begin < end)
	{
		//�ҳ������С
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
		//���Ľ������ұ�end-- ���罻����ֵΪ��С����ע������±ꡣ
		if (end == mini)
		{
			mini = maxi;
		}
		Swap(&a[maxi], &a[end]);
		end--;

		//��С�Ľ��������begin++
		Swap(&a[mini], &a[begin]);
		begin++;
	}
	
}

//5ð������  O(N*N) 
void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	int exchange = 0;

	//��������� һ���ź�һ����n������Ҫ��n-1��
	for (i = 0; i < n - 1; i++)
	{
		//ÿһ�� �ӵ�һ������������ڵ��������Ƚ� �����󽻻�
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
		}
		//���һ��������û��������˵���Ѿ�������
		if (exchange == 0)
		{
			break;
		}
	}
}

//����ȡ�з���������ŵ�ȱ��
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
//�ڿӷ�����
int DigMethod(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	//1.������ȡ�л�õ���Ϊ��key����������һ��λ��ȥ�������浽tmp
	int key = GetMiddle(a, left, right);
	Swap(&a[begin], &a[key]);
	key = begin;
	int tmp = a[key];
	//ÿ��O(N)
	//һ���ڿӣ�ʹ�ӵ����ŵ����ʵ�λ�ã���ߵ���������С���ұߵ�����������
	while (begin < end)
	{
		//2.�ұ���С���ŵ�������¿�
		while (begin < end && a[end] >= tmp)
		{
			end--;
		}
		a[key] = a[end];
		key = end;

		//3.����Ҵ󣬷ŵ�������¿�
		while (begin < end && a[begin] <= tmp)
		{
			begin++;
		}
		a[key] = a[begin];
		key = begin;
	}
	//4.����λ�÷�tmp
	a[begin] = tmp;
	key = begin;

	return key;
}
//����ָ�뷨����
int LRPointer(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	int key = GetMiddle(a, begin, end);
	Swap(&a[begin], &a[key]);
	key = begin;

	//һ�����꣬һ���������ʵ�λ��
	while (begin < end)
	{
		//���ұ���С
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		//������Ҵ�
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		//�ҵ�֮������������
		Swap(&a[begin], &a[end]);
	}
	//��begin=endʱ���ҵ����ʵ�λ���ˣ�
	//�ٽ����ʵ�λ����key���н���
	Swap(&a[begin], &a[key]);
	key = begin;
	return key;
}
//ǰ��ָ�뷨����
int FrontBack(int* a, int left, int right)
{
	int cur = left + 1;
	int prev = left;
	int key = GetMiddle(a, left, right);
	Swap(&a[prev], &a[key]);
	key = prev;

	while (cur < right + 1)
	{
		//ǰ��ָ��cur��С
		while ((cur < right + 1) && a[cur] >= a[key])
		{
			cur++;
		}
		//�ҵ�С֮��prev++������prev��curλ�õ�ֵ��cur++
		if (cur < right + 1)//��ֹ��Ϊ����������Ӱ��
		{
			prev++;
			Swap(&a[cur], &a[prev]);
			cur++;
		}
	}
	//�ҵ�����λ�ú󣬽�key��prevλ�õ�ֵ����
	Swap(&a[prev], &a[key]);
	key = prev;

	return key;
}
//6��������  �ݹ������ÿ��O(N)��ʱ�临�Ӷ�O(N*logN)
void QuickSort(int* a, int left, int right)
{
	//�ݹ��������
	if (left >= right)
	{
		return;
	}
	//���ַ��� ��ȡһ�����еĹؼ�λ�ã�ʹ����߶�С�������ұ߶�������
	//int key = DigMethod(a, left, right);
	//int key = LRPointer(a, left, right);
	int key = FrontBack(a, left, right);

	//���������ߺ��Ұ��
	//С�����Ż�����Ҫ��������е���10������ʱ�򣬲��ò���������и��ӿ��٣������˴󲿷ֵĵݹ������
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
//���ŷǵݹ� ��ջ�Ƚ����������ȳ��� ���洢�����±겢����ѭ������
void RecycleQSort(int* a, int n)
{
	ST st;
	StackInit(&st);

	//�Ƚ��ң������ ������ȳ���������벿��
	StackPush(&st, n - 1);
	StackPush(&st, 0);
	//ջ����ѭ��
	while (!StackEmpty(&st))
	{
		//ȡ�������±�
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		//��ɱ�������
		int key = DigMethod(a, left, right);

		//�ַ�Ϊ���Ҳ��ֽ�ջѭ��
		if (key + 1 < right)
		{
			//��ѹ�� ��ѹ���ȳ���
			StackPush(&st, right);
			StackPush(&st, key + 1);
		}
		if (left < key - 1)
		{
			//��ѹ�� ��ѹ���ȳ���
			StackPush(&st, key - 1);
			StackPush(&st, left);
		}
	}
	StackDestroy(&st);
}

//7 �鲢���� ÿ��N�Σ�logN�㣬ʱ�临�Ӷ�O(N*logN)   
// 1.�����Ϊ�������֣����������Ұ������
//2.�������Ұ��һ��ʼ���ҵ�С�������ŵ��µ������У�
//3.Ȼ��ĳһ�����ֽ�������û����������ȫ��Ų��������
//4.���������Ŀ�����ԭ����
void _MergeSort(int* a, int left, int right, int* b)
{
	//�ݹ��������
	if (left >= right)
	{
		return;
	}

	//�ֽ����Ҳ��� ֱ�����ɷ�֮���ٴ��ڵ���鲢
	int left1 = left;
	int right1 = (left + right) / 2;
	int left2 = (left + right) / 2 + 1;
	int right2 = right;
	//1���Ұ벿������
	_MergeSort(a, left1, right1, b);
	_MergeSort(a, left2, right2, b);

	//�鲢�����㷨
	int begin1 = left1;
	int begin2 = left2;
	int i = left;//ע�����
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
//�鲢����ķǵݹ�
void RecycleMSort(int* a, int n)
{
	int* b = (int*)malloc(n * sizeof(int));
	int gap = 1;//����ÿ�����ݸ���Ϊgap ÿ������й鲢
	while (gap < n)//��һ��һ���鲢��2��4���һ��鲢���ʵ������
	{
		for (int i = 0; i < n; i += 2 * gap)//[i, i+gap-1][i+gap, i+2*gap-1]�±����
		{
			//�鲢�����㷨
			int begin1 = i;
			int begin2 = i + gap;
			int end1 = i + gap - 1;
			int end2 = i + 2 * gap-1;
			int j = i;//ע�����
			//����Ұ�����û�� ���ù鲢������������
			if (begin2 >= n)
			{
				break;
			}
			//����Ұ벿�ֳ������飬������������β�ٹ鲢
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			//2
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					b[j++] = a[begin1++];//�����µ�����
				}
				else
				{
					b[j++] = a[begin2++];
				}
			} 
			//3  ĳһ���������� ʣ�ಿ��ֱ�ӷ���
			while (begin2 <= end2)
			{
				b[j++] = a[begin2++];
			}
			while (begin1 <= end1)
			{
				b[j++] = a[begin1++];
			}
			//4 ĳһ���������� ʣ�ಿ��ֱ�ӷ���
			for (j = i; j <= end2; j++)
			{
				a[j] = b[j];
			}
		}
		gap *= 2;
	}
	free(b);
}

//8 ��������
//ʱ�临�Ӷ�ΪO(N+range)�ռ临�ӵ�ΪO(range)�����������������������Լ���Ч�����á�
void CountSort(int* a, int n)
{
	//1.�ҵ������е������Сֵ
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
	//2.���ٿռ������ ����ʼ��Ϊ0
	int range = max - min + 1;
	int* tmp = (int*)malloc(range * sizeof(int));
	if (tmp == NULL)
	{
		return;
	}
	memset(tmp, 0, range * sizeof(int));

	//3.����
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
	//4.����
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

//�����㷨���ܲ���
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
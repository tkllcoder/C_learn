#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//检查内存是否足够，需要增容
void CheckBody(contactlist* pc)
{
	if (pc->total == pc->base)
	{
		contacter* ptr = realloc(pc->contact_table, (pc->base + 2) * sizeof(contacter));
		if (ptr == NULL)
		{
			perror("AddContact()");
			return;
		}
		printf("空间开辟成功!\n");
		pc->base += 2;
		pc->contact_table = ptr;
	}
}

//加载上次通讯录信息
void LoadContact(contactlist* pc)
{
	FILE* fp = fopen("contact.txt", "r");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}
	contacter tmp = { 0 };
	while (fread(&tmp, sizeof(contacter), 1, fp))
		//利用fread读取每个元素返回值为读取到的个数，当返回值为零时说明没有元素了
	{
		CheckBody(pc);
		pc->contact_table[pc->total] = tmp;
		pc->total++;
	}
	fclose(fp);
	fp = NULL;
}
////初始化通讯录
//void InitContact(contactlist* pc)
//{
//	memset(pc, 0, sizeof(pc->contact_table));
//	pc->total = 0;
//}
void InitContact(contactlist* pc)
{
	pc->contact_table = calloc(MAX, sizeof(contacter));
	pc->total = 0;
	pc->base = MAX;
	
	//加载上一次保存的通讯录
	LoadContact(pc);
}

//增加通讯人
//void AddContact(contactlist* pc)
//{
//	if (pc->total == MAX)
//	{
//		printf("通讯录已满，不能再添加联系人了！\n");
//		return;
//	}
//	printf("请输入姓名：");
//	scanf("%s", pc->contact_table[pc->total].name);
//	printf("请输入年龄：");
//	scanf("%d", &(pc->contact_table[pc->total].age));
//	printf("请输入性别：");
//	scanf("%s", pc->contact_table[pc->total].gender);
//	printf("请输入电话：");
//	scanf("%s", pc->contact_table[pc->total].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->contact_table[pc->total].addr);
//	printf("添加成功!\n");
//	pc->total++;
//}
void AddContact(contactlist* pc)
{
	CheckBody(pc);//检查内存是否足够，需要增容
	printf("请输入姓名：");
	scanf("%s", pc->contact_table[pc->total].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->contact_table[pc->total].age));
	printf("请输入性别：");
	scanf("%s", pc->contact_table[pc->total].gender);
	printf("请输入电话：");
	scanf("%s", pc->contact_table[pc->total].tele);
	printf("请输入地址：");
	scanf("%s", pc->contact_table[pc->total].addr);
	printf("添加成功!\n");
	pc->total++;
}

//显示通讯录 
void PrintContact(contactlist* pc)
{
	int i = 0;
	if (pc->total == 0)
	{
		printf("抱歉，您目前没有联系人！\n");
		return;
	}
	printf("%-20s\t%-10s\t%-5s\t%-20s\t%-20s\n",
		"姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->total; i++)
	{
		printf("%-20s\t%-10d\t%-5s\t%-20s\t%-20s\n",
			pc->contact_table[i].name,
			pc->contact_table[i].age,
			pc->contact_table[i].gender,
			pc->contact_table[i].tele,
			pc->contact_table[i].addr);
	}
}

//查找联系人
int FindByName(contactlist* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->total; i++)
	{
		if (strcmp(pc->contact_table[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//没找到联系人的情况
}

//删除联系人
void DelContact(contactlist* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->total == 0)
	{
		printf("您的通讯录为空，不可删除!\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", name);
	int ret = 0;
	ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("没有找到相关联系人!\n");
		return;
	}
	//1.假设通过姓名查找联系人，并返回编号
	int i = 0;
	//2.找到了，则删除联系人，从编号后面的联系人向前覆盖信息，总数减1
	for (i = ret; i < (pc->total - 1); i++)
	{
		pc->contact_table[i] = pc->contact_table[i + 1];
	}
	printf("删除成功！\n");
	pc->total--;
}

//查找联系人
void SearchContact(contactlist* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int ret = 0;
	ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("没有找到相关联系人!\n");
		return;
	}
	//找到了打印出来
	printf("%-20s\t%-10s\t%-5s\t%-20s\t%-20s\n",
		"姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-10d\t%-5s\t%-20s\t%-20s\n",
		pc->contact_table[ret].name,
		pc->contact_table[ret].age,
		pc->contact_table[ret].gender,
		pc->contact_table[ret].tele,
		pc->contact_table[ret].addr);
}

//修改联系人
void ModifyContact(contactlist* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int ret = 0;
	ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("没有找到相关联系人!\n");
		return;
	}
	//找到了
	printf("%-20s\t%-10s\t%-5s\t%-20s\t%-20s\n",
		"姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-10d\t%-5s\t%-20s\t%-20s\n",
		pc->contact_table[ret].name,
		pc->contact_table[ret].age,
		pc->contact_table[ret].gender,
		pc->contact_table[ret].tele,
		pc->contact_table[ret].addr);
	printf("请输入修改信息!\n");
	printf("请输入姓名：");
	scanf("%s", pc->contact_table[ret].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->contact_table[ret].age));
	printf("请输入性别：");
	scanf("%s", pc->contact_table[ret].gender);
	printf("请输入电话：");
	scanf("%s", pc->contact_table[ret].tele);
	printf("请输入地址：");
	scanf("%s", pc->contact_table[ret].addr);
	printf("修改成功!\n");
}

//交换函数Swap()
void Swap(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)//每一个字节进行交换
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

//以冒泡排序的思想实现qsort()函数的功能
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	//冒泡排序
	for (i = 0; i < sz - 1; i++)//冒泡排序趟数
	{
		for (j = 0; j < sz - 1 - i; j++)//每趟比较的次数
		{
			//什么条件下交换
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
				//传元素的地址，强制类型转换为char*
				//当比较函数返回值大于零时交换，比较函数的参数传递
			{
				//交换函数
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				//由于不知道元素大小，所以交换时以每个字节进行交换，需要传递元素大小
			}
		}
	}
}

//比较函数
int stru_cmp(const void* e1, const void* e2)
{
	return strcmp(((contacter*)e1)->name, ((contacter*)e2)->name);//强制类型转换
}//字符串比较函数是将字符串的每一位的ASCII码比较的，前位越大的则字符串越大

//结构体数组排序函数
void stru_arr_sort(contacter* pcc, int sz)
{
	bubble_sort(pcc, sz, sizeof(pcc[0]), stru_cmp);
}

//排序联系人
void SortContact(contactlist* pc)
{
	stru_arr_sort(pc->contact_table,
		pc->total);
}

//保存通讯录到文件
void SaveContact(contactlist* pc)
{
	FILE* fp = fopen("contact.txt", "w");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}
	fwrite(pc->contact_table, sizeof(contacter), pc->total, fp);
	fclose(fp);
	fp = NULL;
}

//退出函数
void ExitContact(contactlist* pc)
{
	free(pc->contact_table);
	pc->contact_table = NULL;
	pc->base = 0;
	pc->total = 0;
}
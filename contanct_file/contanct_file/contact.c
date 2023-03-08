#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//����ڴ��Ƿ��㹻����Ҫ����
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
		printf("�ռ俪�ٳɹ�!\n");
		pc->base += 2;
		pc->contact_table = ptr;
	}
}

//�����ϴ�ͨѶ¼��Ϣ
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
		//����fread��ȡÿ��Ԫ�ط���ֵΪ��ȡ���ĸ�����������ֵΪ��ʱ˵��û��Ԫ����
	{
		CheckBody(pc);
		pc->contact_table[pc->total] = tmp;
		pc->total++;
	}
	fclose(fp);
	fp = NULL;
}
////��ʼ��ͨѶ¼
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
	
	//������һ�α����ͨѶ¼
	LoadContact(pc);
}

//����ͨѶ��
//void AddContact(contactlist* pc)
//{
//	if (pc->total == MAX)
//	{
//		printf("ͨѶ¼�����������������ϵ���ˣ�\n");
//		return;
//	}
//	printf("������������");
//	scanf("%s", pc->contact_table[pc->total].name);
//	printf("���������䣺");
//	scanf("%d", &(pc->contact_table[pc->total].age));
//	printf("�������Ա�");
//	scanf("%s", pc->contact_table[pc->total].gender);
//	printf("������绰��");
//	scanf("%s", pc->contact_table[pc->total].tele);
//	printf("�������ַ��");
//	scanf("%s", pc->contact_table[pc->total].addr);
//	printf("��ӳɹ�!\n");
//	pc->total++;
//}
void AddContact(contactlist* pc)
{
	CheckBody(pc);//����ڴ��Ƿ��㹻����Ҫ����
	printf("������������");
	scanf("%s", pc->contact_table[pc->total].name);
	printf("���������䣺");
	scanf("%d", &(pc->contact_table[pc->total].age));
	printf("�������Ա�");
	scanf("%s", pc->contact_table[pc->total].gender);
	printf("������绰��");
	scanf("%s", pc->contact_table[pc->total].tele);
	printf("�������ַ��");
	scanf("%s", pc->contact_table[pc->total].addr);
	printf("��ӳɹ�!\n");
	pc->total++;
}

//��ʾͨѶ¼ 
void PrintContact(contactlist* pc)
{
	int i = 0;
	if (pc->total == 0)
	{
		printf("��Ǹ����Ŀǰû����ϵ�ˣ�\n");
		return;
	}
	printf("%-20s\t%-10s\t%-5s\t%-20s\t%-20s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");
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

//������ϵ��
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
	return -1;//û�ҵ���ϵ�˵����
}

//ɾ����ϵ��
void DelContact(contactlist* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->total == 0)
	{
		printf("����ͨѶ¼Ϊ�գ�����ɾ��!\n");
		return;
	}
	printf("������������");
	scanf("%s", name);
	int ret = 0;
	ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("û���ҵ������ϵ��!\n");
		return;
	}
	//1.����ͨ������������ϵ�ˣ������ر��
	int i = 0;
	//2.�ҵ��ˣ���ɾ����ϵ�ˣ��ӱ�ź������ϵ����ǰ������Ϣ��������1
	for (i = ret; i < (pc->total - 1); i++)
	{
		pc->contact_table[i] = pc->contact_table[i + 1];
	}
	printf("ɾ���ɹ���\n");
	pc->total--;
}

//������ϵ��
void SearchContact(contactlist* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������������");
	scanf("%s", name);
	int ret = 0;
	ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("û���ҵ������ϵ��!\n");
		return;
	}
	//�ҵ��˴�ӡ����
	printf("%-20s\t%-10s\t%-5s\t%-20s\t%-20s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-10d\t%-5s\t%-20s\t%-20s\n",
		pc->contact_table[ret].name,
		pc->contact_table[ret].age,
		pc->contact_table[ret].gender,
		pc->contact_table[ret].tele,
		pc->contact_table[ret].addr);
}

//�޸���ϵ��
void ModifyContact(contactlist* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������������");
	scanf("%s", name);
	int ret = 0;
	ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("û���ҵ������ϵ��!\n");
		return;
	}
	//�ҵ���
	printf("%-20s\t%-10s\t%-5s\t%-20s\t%-20s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-10d\t%-5s\t%-20s\t%-20s\n",
		pc->contact_table[ret].name,
		pc->contact_table[ret].age,
		pc->contact_table[ret].gender,
		pc->contact_table[ret].tele,
		pc->contact_table[ret].addr);
	printf("�������޸���Ϣ!\n");
	printf("������������");
	scanf("%s", pc->contact_table[ret].name);
	printf("���������䣺");
	scanf("%d", &(pc->contact_table[ret].age));
	printf("�������Ա�");
	scanf("%s", pc->contact_table[ret].gender);
	printf("������绰��");
	scanf("%s", pc->contact_table[ret].tele);
	printf("�������ַ��");
	scanf("%s", pc->contact_table[ret].addr);
	printf("�޸ĳɹ�!\n");
}

//��������Swap()
void Swap(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)//ÿһ���ֽڽ��н���
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

//��ð�������˼��ʵ��qsort()�����Ĺ���
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	//ð������
	for (i = 0; i < sz - 1; i++)//ð����������
	{
		for (j = 0; j < sz - 1 - i; j++)//ÿ�˱ȽϵĴ���
		{
			//ʲô�����½���
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
				//��Ԫ�صĵ�ַ��ǿ������ת��Ϊchar*
				//���ȽϺ�������ֵ������ʱ�������ȽϺ����Ĳ�������
			{
				//��������
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				//���ڲ�֪��Ԫ�ش�С�����Խ���ʱ��ÿ���ֽڽ��н�������Ҫ����Ԫ�ش�С
			}
		}
	}
}

//�ȽϺ���
int stru_cmp(const void* e1, const void* e2)
{
	return strcmp(((contacter*)e1)->name, ((contacter*)e2)->name);//ǿ������ת��
}//�ַ����ȽϺ����ǽ��ַ�����ÿһλ��ASCII��Ƚϵģ�ǰλԽ������ַ���Խ��

//�ṹ������������
void stru_arr_sort(contacter* pcc, int sz)
{
	bubble_sort(pcc, sz, sizeof(pcc[0]), stru_cmp);
}

//������ϵ��
void SortContact(contactlist* pc)
{
	stru_arr_sort(pc->contact_table,
		pc->total);
}

//����ͨѶ¼���ļ�
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

//�˳�����
void ExitContact(contactlist* pc)
{
	free(pc->contact_table);
	pc->contact_table = NULL;
	pc->base = 0;
	pc->total = 0;
}
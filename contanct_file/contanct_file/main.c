#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��̬�����ڴ�ʵ�����ݵ����洢

//�˵�����
void menu()
{
	printf("******************************\n");
	printf("*****    1.add  2.del    *****\n");
	printf("***** 3.search  4.modify *****\n");
	printf("*****    5.sort 6.print  *****\n");
	printf("*****      0.exit        *****\n");
	printf("******************************\n");
}

//ö������
enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
int main()
{
	int input = 0;
	contactlist con;//����ͨѶ¼

	//��ʼ��ͨѶ¼  ���ϴδ洢���ļ��е�ͨѶ¼��ȡ����
	InitContact(&con);
	do
	{
		menu();
		printf("����������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			//���ܺ���
		case ADD:
			AddContact(&con);//���һ��ͨѶ��
			break;
		case DEL:
			DelContact(&con);//ɾ��һ����ϵ��
			break;
		case SEARCH:
			SearchContact(&con);//������ϵ��
			break;
		case MODIFY:
			ModifyContact(&con);//�޸���ϵ��
			break;
		case SORT:
			SortContact(&con);//����ͨѶ¼
			break;
		case PRINT:
			PrintContact(&con);//��ʾͨѶ¼
			break;
		case EXIT:
			SaveContact(&con);//����ͨѶ¼���ļ�
			ExitContact(&con);//�˳�ͨѶ¼���ڴ��ͷ�
			printf("�˳�����\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);

	return 0;
}
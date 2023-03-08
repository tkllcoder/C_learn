#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//动态开辟内存实现数据的灵活存储

//菜单函数
void menu()
{
	printf("******************************\n");
	printf("*****    1.add  2.del    *****\n");
	printf("***** 3.search  4.modify *****\n");
	printf("*****    5.sort 6.print  *****\n");
	printf("*****      0.exit        *****\n");
	printf("******************************\n");
}

//枚举类型
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
	contactlist con;//创建通讯录

	//初始化通讯录  将上次存储到文件中的通讯录读取出来
	InitContact(&con);
	do
	{
		menu();
		printf("请输入您的选择：");
		scanf("%d", &input);
		switch (input)
		{
			//功能函数
		case ADD:
			AddContact(&con);//添加一个通讯人
			break;
		case DEL:
			DelContact(&con);//删除一个联系人
			break;
		case SEARCH:
			SearchContact(&con);//查找联系人
			break;
		case MODIFY:
			ModifyContact(&con);//修改联系人
			break;
		case SORT:
			SortContact(&con);//排序通讯录
			break;
		case PRINT:
			PrintContact(&con);//显示通讯录
			break;
		case EXIT:
			SaveContact(&con);//保存通讯录到文件
			ExitContact(&con);//退出通讯录，内存释放
			printf("退出程序\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);

	return 0;
}
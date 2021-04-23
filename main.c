#include<stdio.h>
#include<stdlib.h> //动态内存分配malloc的头文件
#include<string.h>
#define LEN sizeof(struct Link) //字节数为struct Link字节数的符号常量



struct Link //定义联系人信息结构体
{
	char name[20]; //姓名
	char unit[20]; //工作单位
	char phone[15]; //电话号码
	char mail[20]; //E-mail地址
}Link_s[100]; //可储存100个联系人信息

//声明程序中要用到的函数

void input(); //新建联系人信息
void enquiry(); //查询联系人信息
void alter(); //修改联系人信息
void del(); //删除联系人信息
void display(); //显示联系人信息
void menu(); //主菜单

void menu()//主菜单函数
{
	system("pause");//调用system(“pause”)函数清空界面
	printf("\n\n\n\n\n");//控制主功能菜单显示位置
	printf("\t\t|***************通讯录管理系统***************|\n");
	printf("\t\t| 1.新建联系人信息 |\n");
	printf("\t\t| 2.查询联系人信息 |\n");
	printf("\t\t| 3.修改联系人信息 |\n");
	printf("\t\t| 4.删除联系人信息 |\n");
	printf("\t\t| 5.显示联系人信息 |\n");
	printf("\t\t| 6.退出系统 |\n");
	printf("\t\t|********************************************|\n");
	printf("请选择功能（1~6）：\n");
}

int main()//主函数
{
	int n;
	menu();//调用主菜单
	scanf_s("%d", &n);//用户选择功能

	while (n)
	{
		switch (n)
		{
		case 1:input(); break;
		case 2:enquiry(); break;
		case 3:alter(); break;
		case 4:del(); break;
		case 5:display(); break;
		case 6:exit(0);
		}
		printf("请选择功能（1~6）：");
		scanf_s("%d", &n);//用户选择功能
	}
	return 0;
}

void input() //新建联系人
{
	int i, record = 0;//定义一个循环变量以及记录通讯录中联系人个数的变量
	char ch[2] = {0, 0};//字符数组用来记录用户的输入
	FILE *fp ;//定义指向文件的指针变量

	if ((fp = fopen_s(&fp, "data.txt", "a+")) == NULL)//调用fopen函数创建一个新的文本来保存联系人信息
	{
		printf("不能打开文件夹!\n");
		return;
	}
	while (feof(fp) == 0)//判断文件是否结束
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)//使用fresd函数将文件中的记录逐条读取到结构体数组
		{
			record++;
		}
	}
	fclose(fp);//关闭文件
	if (record == 0)//判断当前通讯录是否为空
	{
		printf("没有联系人记录!\n");
	}
	else
	{
		system("pause");//清屏
		display();//显示联系人的所有信息
	}

	if ((fp = fopen_s(&fp, "data.txt", "wb")) == NULL)//如果打开文件失败
	{
		printf("无法打开该文件\n");
	}
	//将数据重写入磁盘
	for (i = 0; i < record; i++)
	{
		fwrite(&Link_s[i], LEN, 1, fp);
	}
		printf("是否新建联系人(y/n)");//提示用户输入
	scanf_s("%s", ch, sizeof(ch));
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)//判断用户是否需要新建
	{
		printf("姓名:");
		scanf_s("%s", &Link_s[record].name, sizeof(Link_s[record].name));
		//判断用户输入姓名在通讯录中是否存在
		for (i = 0; i < record; i++)
		{
			if (strcmp(Link_s[i].name, Link_s[record].name) == 0)
			{
				printf("名称已经存在，请按任意键继续。");
				system("pause");
				fclose(fp);
				return;
			}
		}
		printf("工作单位:");
		scanf_s("%s", &Link_s[record].unit, sizeof(Link_s[record].unit));
		printf("电话号码:");
		scanf_s("%s", &Link_s[record].phone, sizeof(Link_s[record].phone));
		printf("E-mail:");
		scanf_s("%s", &Link_s[record].mail, sizeof(Link_s[record].mail));

			if (fwrite(&Link_s[record], LEN, 1, fp) != 1)//将新建联系人信息保存到磁盘文件
			{
				printf("无法保存记录");
				system("pause"); //按任意键继续
			}
			else
			{
				printf("%s 信息保存成功!\n", Link_s[record].name);
				record++;
			}

		printf("是否继续新建联系人?(y/n):");
		scanf_s("%s", ch, sizeof(ch));
	}
	if(fp)
	{ 
	fclose(fp);
	}
	printf("新建完成!\n");
}

void enquiry() //查询联系人
{
	menu();//调用主菜单
	FILE* fp;
	int i, n, record = 0;

	char ch[2], name[20], phone[15];//定义数组接收用户的输入信息

	//打开磁盘文件，并将磁盘文件中的通讯录逐条读取到内存结构体数组
	if ((fp = fopen_s(&fp, "data.txt", "rb")) == NULL)
	{
		printf("无法打开该文件\n");
		return;
	}

	while (feof(fp) == 0)//判断是否到达文件的尾部
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)
		{
			record++;//record终值为通讯录条目
		}
	}
	fclose(fp);

	if (record == 0)
	{
		printf("没有该联系人信息！\n");
		return;
	}
	printf("按姓名查找输入1，按手机号查找输入2：");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("请输入姓名:");
		scanf_s("%s", name, sizeof(name));
	}

	if (n == 2)
	{
		printf("请输入电话号码:");
		scanf_s("%s", phone, sizeof(phone));
	}

	//通过姓名或电话号查找通讯录指定信息，运用字符比较函数
	for (i = 0; i < record; i++)
	{
		if ((strcmp(name, Link_s[i].name) == 0) || (strcmp(phone, Link_s[i].phone) == 0))
		{
			printf("找到联系人，是否显示？(y/n):");
			scanf_s("%s", ch, sizeof(ch));
			if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
			{
				printf("姓名 工作单位 电话号码 E-mail \t\n ");
				printf("%s %s %s %s\n", Link_s[i].name, Link_s[i].unit, Link_s[i].phone, Link_s[i].mail);
			}
			break;
		}
	}
	//判断循环结束是因为没有找到联系人还是因为找到了但是没有显示联系人信息
	if (i == record)
		printf("找不到该联系人\n");
}

void alter() //修改联系人信息
{
	menu();//调用主菜单
	FILE* fp;
	int i, j, record = 0;
	char name[20];
	if ((fp = fopen_s(&fp, "data.txt", "r+")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}

	while (feof(fp) == 0)
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)
		{
			record++;
		}
	}
	if (record == 0)
	{
		printf("没有联系人记录!\n");
		fclose(fp);
		return;
	}
	display();
	//修改联系人信息//
	printf("请输入您要修改的联系人姓名：\n");
	scanf_s("%s", &name, sizeof(name));
	for (i = 0; i < record; i++)
	{
		if (strcmp(name, Link_s[i].name) == 0)
		{
			printf("找到联系人！你可以修改数据！\n");
			printf("姓名:");
			scanf_s("%s", &Link_s[i].name, sizeof(Link_s[i].name));
			printf("工作单位:");
			scanf_s("%s", &Link_s[i].unit, sizeof(Link_s[i].unit));
			printf("电话号码:");
			scanf_s("%s", &Link_s[i].phone, sizeof( Link_s[i].phone));
			printf("E-mail地址:");
			scanf_s("%s", &Link_s[i].mail, sizeof(Link_s[i].mail));
			printf("修改成功！");
			//打开磁盘，将修改后的联系人信息写入磁盘
			if ((fp = fopen_s(&fp, "data.txt", "wb")) == NULL)
			{
				printf("无法打开文件\n");
				return;
			}
			for (j = 0; j < record; j++)
			{
				if (fwrite(&Link_s[j], LEN, 1, fp) != 1)
				{
					printf("无法保存！");
					system("pause"); //按任意键继续
				}
			}
			fclose(fp);
			return;
		}
	}
	printf("没有找到该联系人信息\n");//没有找到该条联系人信息
}

void del() //删除联系人信息
{
	menu();//调用主菜单
	FILE* fp;
	int i, j, record = 0;
	char ch[2];
	char name[15];

	if ((fp = fopen_s(&fp, "data.txt", "r+")) == NULL)
	{
		printf("不能打开该文件!\n");
		return;
	}

	while (feof(fp) == 0)
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)
		{
			record++;
		}
		fclose(fp);
	}
	if (record == 0)
	{
		printf("没有该联系人记录!\n");
		return;
	}

	display();
	//删除联系人信息
	printf("请输入要删除的联系人姓名：");
	scanf_s("%s", &name, sizeof(name));
	for (i = 0; i < record; i++)
	{
		if (strcmp(name, Link_s[i].name) == 0)
		{
			printf("查找到该联系人，是否删除?(y/n)");
			scanf_s("%s", ch, sizeof(ch));
			if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
			{
				for (j = i; j < record; j++)
				{
					Link_s[j] = Link_s[j + 1];
				}
				record--;
			}
			//将删除后的通讯录写入对应的磁盘文文件
			if ((fp = fopen_s(&fp, "data.txt", "wb")) == NULL)
			{
				printf("无法打开文件\n");
				return;
			}
			for (j = 0; j < record; j++)
			{
				if (fwrite(&Link_s[j], LEN, 1, fp) != 1)
				{
					printf("无法保存!\n");
					system("pause"); //按任意键继续
				}
			}
			fclose(fp);
			printf("删除成功!\n");
			return;
		}
	}
	printf("没有该联系人记录!\n");
	return;
}

void display() //显示联系人信息
{
	menu();//调用主菜单
	FILE* fp;
	int i, record = 0;
	fp = fopen_s(&fp, "data.txt", "rb");//以读写的方式打开文件

	//读取通讯录记录
	while (feof(fp) == 0)
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)
		{
			record++;
		}
	}
	fclose(fp);//关闭文件
	printf("姓名 工作单位 电话号码 E-mail \t\n");
	for (i = 0; i < record; i++)
	{
		printf("%-s %-s% -s % -s\n", Link_s[i].name, Link_s[i].unit, Link_s[i].phone, Link_s[i].mail);
	}
}



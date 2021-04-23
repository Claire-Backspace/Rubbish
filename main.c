#include<stdio.h>
#include<stdlib.h> //��̬�ڴ����malloc��ͷ�ļ�
#include<string.h>
#define LEN sizeof(struct Link) //�ֽ���Ϊstruct Link�ֽ����ķ��ų���



struct Link //������ϵ����Ϣ�ṹ��
{
	char name[20]; //����
	char unit[20]; //������λ
	char phone[15]; //�绰����
	char mail[20]; //E-mail��ַ
}Link_s[100]; //�ɴ���100����ϵ����Ϣ

//����������Ҫ�õ��ĺ���

void input(); //�½���ϵ����Ϣ
void enquiry(); //��ѯ��ϵ����Ϣ
void alter(); //�޸���ϵ����Ϣ
void del(); //ɾ����ϵ����Ϣ
void display(); //��ʾ��ϵ����Ϣ
void menu(); //���˵�

void menu()//���˵�����
{
	system("pause");//����system(��pause��)������ս���
	printf("\n\n\n\n\n");//���������ܲ˵���ʾλ��
	printf("\t\t|***************ͨѶ¼����ϵͳ***************|\n");
	printf("\t\t| 1.�½���ϵ����Ϣ |\n");
	printf("\t\t| 2.��ѯ��ϵ����Ϣ |\n");
	printf("\t\t| 3.�޸���ϵ����Ϣ |\n");
	printf("\t\t| 4.ɾ����ϵ����Ϣ |\n");
	printf("\t\t| 5.��ʾ��ϵ����Ϣ |\n");
	printf("\t\t| 6.�˳�ϵͳ |\n");
	printf("\t\t|********************************************|\n");
	printf("��ѡ���ܣ�1~6����\n");
}

int main()//������
{
	int n;
	menu();//�������˵�
	scanf_s("%d", &n);//�û�ѡ����

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
		printf("��ѡ���ܣ�1~6����");
		scanf_s("%d", &n);//�û�ѡ����
	}
	return 0;
}

void input() //�½���ϵ��
{
	int i, record = 0;//����һ��ѭ�������Լ���¼ͨѶ¼����ϵ�˸����ı���
	char ch[2] = {0, 0};//�ַ�����������¼�û�������
	FILE *fp ;//����ָ���ļ���ָ�����

	if ((fp = fopen_s(&fp, "data.txt", "a+")) == NULL)//����fopen��������һ���µ��ı���������ϵ����Ϣ
	{
		printf("���ܴ��ļ���!\n");
		return;
	}
	while (feof(fp) == 0)//�ж��ļ��Ƿ����
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)//ʹ��fresd�������ļ��еļ�¼������ȡ���ṹ������
		{
			record++;
		}
	}
	fclose(fp);//�ر��ļ�
	if (record == 0)//�жϵ�ǰͨѶ¼�Ƿ�Ϊ��
	{
		printf("û����ϵ�˼�¼!\n");
	}
	else
	{
		system("pause");//����
		display();//��ʾ��ϵ�˵�������Ϣ
	}

	if ((fp = fopen_s(&fp, "data.txt", "wb")) == NULL)//������ļ�ʧ��
	{
		printf("�޷��򿪸��ļ�\n");
	}
	//��������д�����
	for (i = 0; i < record; i++)
	{
		fwrite(&Link_s[i], LEN, 1, fp);
	}
		printf("�Ƿ��½���ϵ��(y/n)");//��ʾ�û�����
	scanf_s("%s", ch, sizeof(ch));
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)//�ж��û��Ƿ���Ҫ�½�
	{
		printf("����:");
		scanf_s("%s", &Link_s[record].name, sizeof(Link_s[record].name));
		//�ж��û�����������ͨѶ¼���Ƿ����
		for (i = 0; i < record; i++)
		{
			if (strcmp(Link_s[i].name, Link_s[record].name) == 0)
			{
				printf("�����Ѿ����ڣ��밴�����������");
				system("pause");
				fclose(fp);
				return;
			}
		}
		printf("������λ:");
		scanf_s("%s", &Link_s[record].unit, sizeof(Link_s[record].unit));
		printf("�绰����:");
		scanf_s("%s", &Link_s[record].phone, sizeof(Link_s[record].phone));
		printf("E-mail:");
		scanf_s("%s", &Link_s[record].mail, sizeof(Link_s[record].mail));

			if (fwrite(&Link_s[record], LEN, 1, fp) != 1)//���½���ϵ����Ϣ���浽�����ļ�
			{
				printf("�޷������¼");
				system("pause"); //�����������
			}
			else
			{
				printf("%s ��Ϣ����ɹ�!\n", Link_s[record].name);
				record++;
			}

		printf("�Ƿ�����½���ϵ��?(y/n):");
		scanf_s("%s", ch, sizeof(ch));
	}
	if(fp)
	{ 
	fclose(fp);
	}
	printf("�½����!\n");
}

void enquiry() //��ѯ��ϵ��
{
	menu();//�������˵�
	FILE* fp;
	int i, n, record = 0;

	char ch[2], name[20], phone[15];//������������û���������Ϣ

	//�򿪴����ļ������������ļ��е�ͨѶ¼������ȡ���ڴ�ṹ������
	if ((fp = fopen_s(&fp, "data.txt", "rb")) == NULL)
	{
		printf("�޷��򿪸��ļ�\n");
		return;
	}

	while (feof(fp) == 0)//�ж��Ƿ񵽴��ļ���β��
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)
		{
			record++;//record��ֵΪͨѶ¼��Ŀ
		}
	}
	fclose(fp);

	if (record == 0)
	{
		printf("û�и���ϵ����Ϣ��\n");
		return;
	}
	printf("��������������1�����ֻ��Ų�������2��");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("����������:");
		scanf_s("%s", name, sizeof(name));
	}

	if (n == 2)
	{
		printf("������绰����:");
		scanf_s("%s", phone, sizeof(phone));
	}

	//ͨ��������绰�Ų���ͨѶ¼ָ����Ϣ�������ַ��ȽϺ���
	for (i = 0; i < record; i++)
	{
		if ((strcmp(name, Link_s[i].name) == 0) || (strcmp(phone, Link_s[i].phone) == 0))
		{
			printf("�ҵ���ϵ�ˣ��Ƿ���ʾ��(y/n):");
			scanf_s("%s", ch, sizeof(ch));
			if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
			{
				printf("���� ������λ �绰���� E-mail \t\n ");
				printf("%s %s %s %s\n", Link_s[i].name, Link_s[i].unit, Link_s[i].phone, Link_s[i].mail);
			}
			break;
		}
	}
	//�ж�ѭ����������Ϊû���ҵ���ϵ�˻�����Ϊ�ҵ��˵���û����ʾ��ϵ����Ϣ
	if (i == record)
		printf("�Ҳ�������ϵ��\n");
}

void alter() //�޸���ϵ����Ϣ
{
	menu();//�������˵�
	FILE* fp;
	int i, j, record = 0;
	char name[20];
	if ((fp = fopen_s(&fp, "data.txt", "r+")) == NULL)
	{
		printf("�޷����ļ�\n");
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
		printf("û����ϵ�˼�¼!\n");
		fclose(fp);
		return;
	}
	display();
	//�޸���ϵ����Ϣ//
	printf("��������Ҫ�޸ĵ���ϵ��������\n");
	scanf_s("%s", &name, sizeof(name));
	for (i = 0; i < record; i++)
	{
		if (strcmp(name, Link_s[i].name) == 0)
		{
			printf("�ҵ���ϵ�ˣ�������޸����ݣ�\n");
			printf("����:");
			scanf_s("%s", &Link_s[i].name, sizeof(Link_s[i].name));
			printf("������λ:");
			scanf_s("%s", &Link_s[i].unit, sizeof(Link_s[i].unit));
			printf("�绰����:");
			scanf_s("%s", &Link_s[i].phone, sizeof( Link_s[i].phone));
			printf("E-mail��ַ:");
			scanf_s("%s", &Link_s[i].mail, sizeof(Link_s[i].mail));
			printf("�޸ĳɹ���");
			//�򿪴��̣����޸ĺ����ϵ����Ϣд�����
			if ((fp = fopen_s(&fp, "data.txt", "wb")) == NULL)
			{
				printf("�޷����ļ�\n");
				return;
			}
			for (j = 0; j < record; j++)
			{
				if (fwrite(&Link_s[j], LEN, 1, fp) != 1)
				{
					printf("�޷����棡");
					system("pause"); //�����������
				}
			}
			fclose(fp);
			return;
		}
	}
	printf("û���ҵ�����ϵ����Ϣ\n");//û���ҵ�������ϵ����Ϣ
}

void del() //ɾ����ϵ����Ϣ
{
	menu();//�������˵�
	FILE* fp;
	int i, j, record = 0;
	char ch[2];
	char name[15];

	if ((fp = fopen_s(&fp, "data.txt", "r+")) == NULL)
	{
		printf("���ܴ򿪸��ļ�!\n");
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
		printf("û�и���ϵ�˼�¼!\n");
		return;
	}

	display();
	//ɾ����ϵ����Ϣ
	printf("������Ҫɾ������ϵ��������");
	scanf_s("%s", &name, sizeof(name));
	for (i = 0; i < record; i++)
	{
		if (strcmp(name, Link_s[i].name) == 0)
		{
			printf("���ҵ�����ϵ�ˣ��Ƿ�ɾ��?(y/n)");
			scanf_s("%s", ch, sizeof(ch));
			if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
			{
				for (j = i; j < record; j++)
				{
					Link_s[j] = Link_s[j + 1];
				}
				record--;
			}
			//��ɾ�����ͨѶ¼д���Ӧ�Ĵ������ļ�
			if ((fp = fopen_s(&fp, "data.txt", "wb")) == NULL)
			{
				printf("�޷����ļ�\n");
				return;
			}
			for (j = 0; j < record; j++)
			{
				if (fwrite(&Link_s[j], LEN, 1, fp) != 1)
				{
					printf("�޷�����!\n");
					system("pause"); //�����������
				}
			}
			fclose(fp);
			printf("ɾ���ɹ�!\n");
			return;
		}
	}
	printf("û�и���ϵ�˼�¼!\n");
	return;
}

void display() //��ʾ��ϵ����Ϣ
{
	menu();//�������˵�
	FILE* fp;
	int i, record = 0;
	fp = fopen_s(&fp, "data.txt", "rb");//�Զ�д�ķ�ʽ���ļ�

	//��ȡͨѶ¼��¼
	while (feof(fp) == 0)
	{
		if (fread(&Link_s[record], LEN, 1, fp) == 1)
		{
			record++;
		}
	}
	fclose(fp);//�ر��ļ�
	printf("���� ������λ �绰���� E-mail \t\n");
	for (i = 0; i < record; i++)
	{
		printf("%-s %-s% -s % -s\n", Link_s[i].name, Link_s[i].unit, Link_s[i].phone, Link_s[i].mail);
	}
}



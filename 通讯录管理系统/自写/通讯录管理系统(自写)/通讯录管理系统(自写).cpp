#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct person
{
	string m_name;
	int m_sex;   //1�� 2Ů
	int m_age;
	string m_phone;
	string m_addr;
};

struct addressbook
{
	struct person pArray[MAX];
	int m_size;
};

void showmenu();
void addPerson(struct addressbook* abs);
void showPerson(struct addressbook* abs);
int isExist(struct addressbook* abs, string name);
void delPerson(struct addressbook* abs);
void findPerson(struct addressbook* abs);
void modifyPerson(struct addressbook* abs);
void cleanPerson(struct addressbook* abs);

int main()
{
	char select = '0';
	struct addressbook abs;
	abs.m_size = 0;

	while (1)
	{
		showmenu();
		cin >> select;

		switch (select)
		{
		case '1':
			addPerson(&abs);
			break;
		case '2':
			showPerson(&abs);
			break;
		case '3':
			delPerson(&abs);
			break;
		case '4':
			findPerson(&abs);
			break;
		case '5':
			modifyPerson(&abs);
			break;
		case '6':
			cleanPerson(&abs);
			break;
		case '0':
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
		{
			cout << "���������0~6��" << endl;
			system("pause");
			system("cls");
		}
			break;
		}
	}

	system("pause");
	return 0;
}

void showmenu()
{
	cout << "*****************************" << endl;
	cout << "******  1�������ϵ��  ******" << endl;
	cout << "******  2����ʾ��ϵ��  ******" << endl;
	cout << "******  3��ɾ����ϵ��  ******" << endl;
	cout << "******  4��������ϵ��  ******" << endl;
	cout << "******  5���޸���ϵ��  ******" << endl;
	cout << "******  6�������ϵ��  ******" << endl;
	cout << "******  0���˳�ͨѶ¼  ******" << endl;
	cout << "*****************************" << endl << endl;
	cout << "���������Ĳ�����  ";
}

void addPerson(struct addressbook* abs)
{
	//����
	cout << "������������" << endl;
	string name;
	cin >> name;
	abs->pArray[abs->m_size].m_name = name;
	//�Ա�
	cout << "�������Ա�1����  2��Ů����" << endl;
	int sex;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->pArray[abs->m_size].m_sex = sex;
			break;
		}
		cout << "��������ȷ���Ա�" << endl;
	}
	//����
	cout << "���������䣺" << endl;
	int age;
	while (1)
	{
		cin >> age;
		if (age >= 0 && age <= 150)
		{
			abs->pArray[abs->m_size].m_age = age;
			break;
		}
		cout << "��������ȷ�����䣡" << endl;
	}
	//�绰
	cout << "������绰���룺" << endl;
	string phone;
	cin >> phone;
	abs->pArray[abs->m_size].m_phone = phone;
	//סַ
	cout << "�������ͥסַ��" << endl;
	string addr;
	cin >> addr;
	abs->pArray[abs->m_size].m_addr = addr;

	abs->m_size++;
	cout << "��ϵ����ӳɹ���" << endl;
	system("pause");
	system("cls");
}

void showPerson(struct addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->pArray[i].m_name << '\t';
			cout << "�Ա�" << (abs->pArray[i].m_sex == 1 ? "��" : "Ů") << '\t';
			cout << "���䣺" << abs->pArray[i].m_age << '\t';
			cout << "�绰��" << abs->pArray[i].m_phone << '\t';
			cout << "סַ��" << abs->pArray[i].m_addr << endl;
		}
	}

	system("pause");
	system("cls");
}

int isExist(struct addressbook* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (name == abs->pArray[i].m_name)
		{
			return i;
		}
	}
	return -1;
}

void delPerson(struct addressbook* abs)
{
	cout << "��������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);   //�����abs�Ѿ���ָ���ˣ����Բ���Ҫ��&��  �������е�abs�ǽṹ�壬��Ҫ��&s��
	
	if (index != -1)
	{
		for (int i = index; i < abs->m_size; i++)
		{
			abs->pArray[i] = abs->pArray[i + 1];
		}
		cout << "��ϵ��ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}

	abs->m_size--;

	system("pause");
	system("cls");
}

void findPerson(struct addressbook* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if (index != -1)
	{
		cout << "������" << abs->pArray[index].m_name << '\t';
		cout << "�Ա�" << (abs->pArray[index].m_sex == 1 ? "��" : "Ů") << '\t';
		cout << "���䣺" << abs->pArray[index].m_age << '\t';
		cout << "�绰��" << abs->pArray[index].m_phone << '\t';
		cout << "סַ��" << abs->pArray[index].m_addr << endl;
	}
	else
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(struct addressbook* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if (index != -1)
	{
		//����
		cout << "�������޸ĺ��������" << endl;
		string name2;
		cin >> name2;
		abs->pArray[index].m_name = name2;
		//�Ա�
		cout << "�������޸ĺ���Ա�" << endl;
		int sex2;
		cin >> sex2;
		abs->pArray[index].m_sex = sex2;
		//����
		cout << "�������޸ĺ�����䣺" << endl;
		int age2;
		cin >> age2;
		abs->pArray[index].m_age = age2;
		//�绰
		cout << "�������޸ĺ�ĵ绰��" << endl;
		string phone2;
		cin >> phone2;
		abs->pArray[index].m_phone = phone2;
		//��ַ
		cout << "�������޸ĺ�ĵ�ַ��" << endl;
		string addr2;
		cin >> addr2;
		abs->pArray[index].m_addr = addr2;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(struct addressbook* abs)
{
	cout << "��ȷ��Ҫ���ͨѶ¼��ȷ������1��" << endl;
	char sel;
	cin >> sel;
	if (sel == '1')
	{
		abs->m_size = 0;
		cout << "ͨѶ¼����գ�" << endl;
	}
	else
	{
		cout << "ȡ�����ͨѶ¼��" << endl;
	}

	system("pause");
	system("cls");
}
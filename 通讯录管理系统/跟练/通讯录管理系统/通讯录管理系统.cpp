#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

void showMenu();  //����˵�
void addPerson(struct Addressbooks* abs);   //�����ϵ��
void showPerson(struct Addressbooks* abs);  //��ʾ��ϵ��
int isExist(struct Addressbooks* abs, string name);  //�����ϵ���Ƿ���� ������ڷ�����ϵ����������λ�� �����ڷ���-1
void delPerson(struct Addressbooks* abs);   //ɾ����ϵ��
void findPerson(struct Addressbooks* abs);   //������ϵ��
void modifyPerson(struct Addressbooks* abs);  //�޸���ϵ��
void cleanPerson(struct Addressbooks* abs);   //�����ϵ��  ֻҪ��ͨѶ¼����ϵ��������Ϊ0�����߼���ռ���

struct Person
{
	string m_name;
	int m_sex;   //1��  2Ů
	int m_age;
	string m_phone;
	string m_addr;
};

struct Addressbooks
{
	struct Person parray[MAX];
	int m_size;   //ͨѶ¼�е�ǰ��ϵ�˸���
};

int main()
{
	struct Addressbooks abs;
	abs.m_size = 0;

	int select = 0;

	while (1)
	{
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1:    //1�������ϵ��
			addPerson(&abs);   //����ַ�������޸�ʵ��
			break;
		case 2:   //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:   //3��ɾ����ϵ��
			delPerson(&abs);
			break;
		case 4:   //4��������ϵ��
			findPerson(&abs);
			break;
		case 5:   //5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:   //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:   //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	};
	

	system("pause");
	return 0;
}

void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   5���޸���ϵ��   *****" << endl;
	cout << "*****   6�������ϵ��   *****" << endl;
	cout << "*****   0���˳�ͨѶ¼   *****" << endl;
	cout << "*****************************" << endl << endl;
}

void addPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//�������
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->parray[abs->m_size].m_name = name;

		//����Ա�
		cout << "�������Ա�" << endl;
		cout << "1������    2����Ů" << endl;
		int sex = 0;
		
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->parray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�Ա�������������������" << endl;
		}

		//�������
		cout << "���������䣺" << endl;
		int age = 0;

		while (1)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->parray[abs->m_size].m_age = age;
				break;
			}
			cout << "����������������������" << endl;
		}

		//����ֻ���
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->parray[abs->m_size].m_phone = phone;

		//��ӵ�ַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->parray[abs->m_size].m_addr = address;

		//����ͨѶ¼����
		abs->m_size++;

		cout << "��ϵ����ӳɹ���" << endl;

		system("pause");   //�밴���������
		system("cls");   //��������
	}
}

void showPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�����Ƿ�Ϊ0
	if (abs->m_size ==0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->parray[i].m_name << "\t";
			cout << "�Ա�" << (abs->parray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->parray[i].m_age << "\t";
			cout << "�绰��" << abs->parray[i].m_phone << "\t";
			cout << "��ͥסַ��" << abs->parray[i].m_addr << endl;
		}
	}

	system("pause");
	system("cls");
}

int isExist(struct Addressbooks* abs, string name)  //����1 ͨѶ¼  ����2 �Աȵ�����
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->parray[i].m_name == name)
		{
			return i;
		}
	}

	return -1;
}

void delPerson(struct Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result != -1)
	{
		for (int i = result; i < abs->m_size; i++)
		{
			//����ǰ��
			abs->parray[i] = abs->parray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(struct Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result != -1)
	{
		cout << "������" << abs->parray[result].m_name << "\t";
		cout << "�Ա�" << abs->parray[result].m_sex << "\t";
		cout << "���䣺" << abs->parray[result].m_age << "\t";
		cout << "�绰��" << abs->parray[result].m_phone << "\t";
		cout << "��ͥ��ַ��" << abs->parray[result].m_addr << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(struct Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result != -1)
	{
		//����
		string name;
		cout << "�������޸ĺ��������" << endl;
		cin >> name;
		abs->parray[result].m_name = name;
		//�Ա�
		cout << "�������޸ĺ���Ա�" << endl;
		cout << "1������    2����Ů" << endl;
		int sex = 0;

		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->parray[result].m_sex = sex;
				break;
			}
			cout << "�Ա�������������������" << endl;
		}
		
		//����
		cout << "�������޸ĺ�����䣺" << endl;
		int age = 0;

		while (1)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->parray[result].m_age = age;
				break;
			}
			cout << "����������������������" << endl;
		}

		//�绰
		cout << "�������޸ĺ����ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->parray[result].m_phone = phone;

		//��ַ
		cout << "�������޸ĺ�ļ�ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->parray[result].m_addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(struct Addressbooks* abs)
{
	char select;
	cout << "���Ƿ����Ҫ���ͨѶ¼��ȷ��������y" << endl;
	cin >> select;
	if (select == 'y')
	{
		abs->m_size = 0;   //����ǰ��¼��ϵ���������㣬���߼�����ղ���
		cout << "ͨѶ¼����գ�" << endl;
	}
	else
	{
		cout << "ȡ�����ͨѶ¼��" << endl;
	}
	
	system("pause");
	system("cls");
}
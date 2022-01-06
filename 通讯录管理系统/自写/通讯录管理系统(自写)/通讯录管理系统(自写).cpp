#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct person
{
	string m_name;
	int m_sex;   //1男 2女
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
		{
			cout << "请输入操作0~6！" << endl;
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
	cout << "******  1、添加联系人  ******" << endl;
	cout << "******  2、显示联系人  ******" << endl;
	cout << "******  3、删除联系人  ******" << endl;
	cout << "******  4、查找联系人  ******" << endl;
	cout << "******  5、修改联系人  ******" << endl;
	cout << "******  6、清空联系人  ******" << endl;
	cout << "******  0、退出通讯录  ******" << endl;
	cout << "*****************************" << endl << endl;
	cout << "请输入您的操作：  ";
}

void addPerson(struct addressbook* abs)
{
	//姓名
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	abs->pArray[abs->m_size].m_name = name;
	//性别
	cout << "请输入性别（1—男  2—女）：" << endl;
	int sex;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->pArray[abs->m_size].m_sex = sex;
			break;
		}
		cout << "请输入正确的性别！" << endl;
	}
	//年龄
	cout << "请输入年龄：" << endl;
	int age;
	while (1)
	{
		cin >> age;
		if (age >= 0 && age <= 150)
		{
			abs->pArray[abs->m_size].m_age = age;
			break;
		}
		cout << "请输入正确的年龄！" << endl;
	}
	//电话
	cout << "请输入电话号码：" << endl;
	string phone;
	cin >> phone;
	abs->pArray[abs->m_size].m_phone = phone;
	//住址
	cout << "请输入家庭住址：" << endl;
	string addr;
	cin >> addr;
	abs->pArray[abs->m_size].m_addr = addr;

	abs->m_size++;
	cout << "联系人添加成功！" << endl;
	system("pause");
	system("cls");
}

void showPerson(struct addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->pArray[i].m_name << '\t';
			cout << "性别：" << (abs->pArray[i].m_sex == 1 ? "男" : "女") << '\t';
			cout << "年龄：" << abs->pArray[i].m_age << '\t';
			cout << "电话：" << abs->pArray[i].m_phone << '\t';
			cout << "住址：" << abs->pArray[i].m_addr << endl;
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
	cout << "请输入您要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);   //这里的abs已经是指针了，所以不需要加&。  主函数中的abs是结构体，需要加&s。
	
	if (index != -1)
	{
		for (int i = index; i < abs->m_size; i++)
		{
			abs->pArray[i] = abs->pArray[i + 1];
		}
		cout << "联系人删除成功！" << endl;
	}
	else
	{
		cout << "联系人不存在！" << endl;
	}

	abs->m_size--;

	system("pause");
	system("cls");
}

void findPerson(struct addressbook* abs)
{
	cout << "请输入您要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if (index != -1)
	{
		cout << "姓名：" << abs->pArray[index].m_name << '\t';
		cout << "性别：" << (abs->pArray[index].m_sex == 1 ? "男" : "女") << '\t';
		cout << "年龄：" << abs->pArray[index].m_age << '\t';
		cout << "电话：" << abs->pArray[index].m_phone << '\t';
		cout << "住址：" << abs->pArray[index].m_addr << endl;
	}
	else
	{
		cout << "联系人不存在！" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(struct addressbook* abs)
{
	cout << "请输入您要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if (index != -1)
	{
		//姓名
		cout << "请输入修改后的姓名：" << endl;
		string name2;
		cin >> name2;
		abs->pArray[index].m_name = name2;
		//性别
		cout << "请输入修改后的性别：" << endl;
		int sex2;
		cin >> sex2;
		abs->pArray[index].m_sex = sex2;
		//年龄
		cout << "请输入修改后的年龄：" << endl;
		int age2;
		cin >> age2;
		abs->pArray[index].m_age = age2;
		//电话
		cout << "请输入修改后的电话：" << endl;
		string phone2;
		cin >> phone2;
		abs->pArray[index].m_phone = phone2;
		//地址
		cout << "请输入修改后的地址：" << endl;
		string addr2;
		cin >> addr2;
		abs->pArray[index].m_addr = addr2;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "联系人不存在！" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(struct addressbook* abs)
{
	cout << "您确定要清空通讯录吗？确定请输1。" << endl;
	char sel;
	cin >> sel;
	if (sel == '1')
	{
		abs->m_size = 0;
		cout << "通讯录已清空！" << endl;
	}
	else
	{
		cout << "取消清空通讯录！" << endl;
	}

	system("pause");
	system("cls");
}
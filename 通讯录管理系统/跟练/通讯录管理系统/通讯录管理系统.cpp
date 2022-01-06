#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

void showMenu();  //界面菜单
void addPerson(struct Addressbooks* abs);   //添加联系人
void showPerson(struct Addressbooks* abs);  //显示联系人
int isExist(struct Addressbooks* abs, string name);  //检测联系人是否存在 如果存在返回联系人在数组中位置 不存在返回-1
void delPerson(struct Addressbooks* abs);   //删除联系人
void findPerson(struct Addressbooks* abs);   //查找联系人
void modifyPerson(struct Addressbooks* abs);  //修改联系人
void cleanPerson(struct Addressbooks* abs);   //清空联系人  只要将通讯录的联系人数量置为0，做逻辑清空即可

struct Person
{
	string m_name;
	int m_sex;   //1男  2女
	int m_age;
	string m_phone;
	string m_addr;
};

struct Addressbooks
{
	struct Person parray[MAX];
	int m_size;   //通讯录中当前联系人个数
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
		case 1:    //1、添加联系人
			addPerson(&abs);   //传地址，可以修改实参
			break;
		case 2:   //2、显示联系人
			showPerson(&abs);
			break;
		case 3:   //3、删除联系人
			delPerson(&abs);
			break;
		case 4:   //4、查找联系人
			findPerson(&abs);
			break;
		case 5:   //5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:   //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:   //0、退出通讯录
			cout << "欢迎下次使用！" << endl;
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
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   5、修改联系人   *****" << endl;
	cout << "*****   6、清空联系人   *****" << endl;
	cout << "*****   0、退出通讯录   *****" << endl;
	cout << "*****************************" << endl << endl;
}

void addPerson(struct Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->parray[abs->m_size].m_name = name;

		//添加性别
		cout << "请输入性别：" << endl;
		cout << "1——男    2——女" << endl;
		int sex = 0;
		
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->parray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "性别输入有误，请重新输入" << endl;
		}

		//添加年龄
		cout << "请输入年龄：" << endl;
		int age = 0;

		while (1)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->parray[abs->m_size].m_age = age;
				break;
			}
			cout << "年龄输入有误，请重新输入" << endl;
		}

		//添加手机号
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->parray[abs->m_size].m_phone = phone;

		//添加地址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->parray[abs->m_size].m_addr = address;

		//更新通讯录人数
		abs->m_size++;

		cout << "联系人添加成功！" << endl;

		system("pause");   //请按任意键继续
		system("cls");   //清屏操作
	}
}

void showPerson(struct Addressbooks* abs)
{
	//判断通讯录人数是否为0
	if (abs->m_size ==0)
	{
		cout << "当前记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->parray[i].m_name << "\t";
			cout << "性别：" << (abs->parray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->parray[i].m_age << "\t";
			cout << "电话：" << abs->parray[i].m_phone << "\t";
			cout << "家庭住址：" << abs->parray[i].m_addr << endl;
		}
	}

	system("pause");
	system("cls");
}

int isExist(struct Addressbooks* abs, string name)  //参数1 通讯录  参数2 对比的姓名
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
	cout << "请输入您要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result != -1)
	{
		for (int i = result; i < abs->m_size; i++)
		{
			//数据前移
			abs->parray[i] = abs->parray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(struct Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result != -1)
	{
		cout << "姓名：" << abs->parray[result].m_name << "\t";
		cout << "性别：" << abs->parray[result].m_sex << "\t";
		cout << "年龄：" << abs->parray[result].m_age << "\t";
		cout << "电话：" << abs->parray[result].m_phone << "\t";
		cout << "家庭地址：" << abs->parray[result].m_addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(struct Addressbooks* abs)
{
	cout << "请输入您要修改的联系人姓名：" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result != -1)
	{
		//姓名
		string name;
		cout << "请输入修改后的姓名：" << endl;
		cin >> name;
		abs->parray[result].m_name = name;
		//性别
		cout << "请输入修改后的性别：" << endl;
		cout << "1——男    2——女" << endl;
		int sex = 0;

		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->parray[result].m_sex = sex;
				break;
			}
			cout << "性别输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入修改后的年龄：" << endl;
		int age = 0;

		while (1)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->parray[result].m_age = age;
				break;
			}
			cout << "年龄输入有误，请重新输入" << endl;
		}

		//电话
		cout << "请输入修改后的联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->parray[result].m_phone = phone;

		//地址
		cout << "请输入修改后的家庭住址：" << endl;
		string address;
		cin >> address;
		abs->parray[result].m_addr = address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(struct Addressbooks* abs)
{
	char select;
	cout << "您是否真的要清空通讯录？确定请输入y" << endl;
	cin >> select;
	if (select == 'y')
	{
		abs->m_size = 0;   //将当前记录联系人数量清零，做逻辑上清空操作
		cout << "通讯录已清空！" << endl;
	}
	else
	{
		cout << "取消清空通讯录！" << endl;
	}
	
	system("pause");
	system("cls");
}
#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	this->m_FileIsEmpty = false;

	//1、文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		this->m_Empnum = 0;
		ifs.close();
		return;
	}

	//2、文件存在但记录为空
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		//cout << "文件记录为空！" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		this->m_Empnum = 0;
		ifs.close();
		return;
	}

	//3、文件存在并且有数据
	int num = this->get_num();
	this->m_Empnum = num;
	this->m_FileIsEmpty = false;

	//根据职工数创建数组
	this->m_EmpArray = new Worker * [this->m_Empnum];
	//初始化职工
	init_emp();
}

//显示菜单
void WorkerManager::ShowMenu()
{
	cout << "***************************************************" << endl;
	cout << "********      欢迎使用职工管理系统！    ***********" << endl;
	cout << "**************    0.退出管理程序     **************" << endl;
	cout << "**************    1.增加职工信息     **************" << endl;
	cout << "**************    2.显示职工信息     **************" << endl;
	cout << "**************    3.删除离职职工     **************" << endl;
	cout << "**************    4.修改职工信息     **************" << endl;
	cout << "**************    5.查找职工信息     **************" << endl;
	cout << "**************    6.按照序号排序     **************" << endl;
	cout << "**************    7.清空所有文档     **************" << endl;
	cout << "***************************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::Exit_System()
{
	cout << "系统退出，欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//增加成员
void WorkerManager::Add_Emp()
{
	int addnum;
	cout << "请输入您要增加的职工人数：";
	cin >> addnum;

	if (addnum > 0)
	{
		int NewSize = this->m_Empnum + addnum;
		Worker** NewSpace = new Worker * [NewSize];

		//将原数据拷贝
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				NewSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//添加新数据
		for (int i = 0; i < addnum; i++)
		{
			int id=0;
			string name=" ";
			int dselect=0;

			cout << "请输入第"<<i+1<<"个职工编号：";
			while (1)
			{
				cin >> id;
				int ret = IsExist(id);
				if (ret != -1)
				{
					cout << "该职工编号已存在，请重新输入：";
				}
				else
				{
					break;
				}
			}
			
			cout << "请输入职工姓名：";
			cin >> name;
			cout << "请输入职工岗位：" << endl;
			cout << "1、职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;

			Worker* worker = NULL;

			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, dselect);
				break;
			case 2:
				worker = new Manager(id, name, dselect);
				break;
			case 3:
				worker = new Boss(id, name, dselect);
				break;
			default:
				break;
			}
			NewSpace[this->m_Empnum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NewSpace;
		this->m_Empnum = NewSize;

		this->m_FileIsEmpty = false;		//文件不为空

		cout << "成功添加" << addnum << "名职工" << endl;
		this->save();
	}
	else
	{
		cout << "您输入的人数有误！" << endl;
	}

	system("pause");
	system("cls");
}

//写文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_deptname << endl;
	}

	ofs.close();
}

//获取文件中的人数
int WorkerManager::get_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int num = 0;
	int id;
	string name;
	int dID;

	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化员工
void WorkerManager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1)
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manager(id, name, dID);
		}
		else
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;		//将文件中的数据放到数组中
		index++;
	}
	ifs.close();
}

//显示员工
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (id == this->m_EmpArray[i]->m_id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入您要删除的职工编号：";
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_Empnum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			if (this->m_Empnum == 0)
			{
				this->m_FileIsEmpty = true;
			}

			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "未找到该职工，删除失败！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入您要修改职工的编号：";
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			int new_id=0;
			string new_name=" ";
			int new_dselect=1;

			delete this->m_EmpArray[ret];
			cout << "已找到" << id << "号职工，请输入新的职工编号：";
			while (1)
			{
				cin >> new_id;
				int ret2 = this->IsExist(new_id);
				if (ret2 != -1)
				{
					cout << "该职工已存在，请重新输入职工编号：";
				}
				else
				{
					break;
				}
			}
			cout << "请输入新的职工姓名：";
			cin >> new_name;

			cout << "请输入新的职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> new_dselect;
			Worker* worker = NULL;
			switch(new_dselect)
			{
			case 1:
				worker = new Employee(new_id, new_name, 1);
				break;
			case 2:
				worker = new Manager(new_id, new_name, 1);
				break;
			case 3:
				worker = new Boss(new_id, new_name, 1);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			this->save();
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "未找到该员工，修改失败！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找员工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入您查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int select;
		cin >> select;

		if (select == 1)
		{
			cout << "请输入您要查找的职工编号：";
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if(select==2)
		{
			bool flag = false;		//是否找到标志
			string name;
			cout << "请输入您要查找的职工姓名：";
			cin >> name;

			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "查找成功！该职工编号为：" << this->m_EmpArray[i]->m_id << "号，职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1、职工编号升序排序" << endl;
		cout << "2、职工编号降序排序" << endl;
		int select;
		cin >> select;

		for (int i = 0; i < this->m_Empnum; i++)
		{
			for (int j = i + 1; j < this->m_Empnum; j++)
			{
				if (select == 1)		//升序
				{
					if (this->m_EmpArray[i]->m_id > this->m_EmpArray[j]->m_id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
				else if (select == 2)		//降序
				{
					if (this->m_EmpArray[i]->m_id < this->m_EmpArray[j]->m_id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
			}
		
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->save();
		this->show_Emp();		//已包含清屏操作		
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "是否确定清空文件？" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}

		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		cout << "文件清空成功！" << endl;
	}
	else
	{
		cout << "取消清空文件！" << endl;
	}
	system("pause");
	system("cls");
}

//析构
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
}
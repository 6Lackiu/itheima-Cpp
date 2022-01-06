#include "workerManager.h"

WorkerManager::WorkerManager()		//构造函数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);		//读文件
	this->m_FileIsEmpty = false;

	//1、文件不存在（文件未创建）
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;		//测试代码
		//初始化属性
		this->m_EmpNum = 0;		//初始化人数
		this->m_FileIsEmpty = true;		//初始化文件是否为空
		this->m_EmpArray = NULL;		//初始化数组指针
		ifs.close();
		return;
	}

	//2、文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())		//为真代表文件为空
	{
		//cout << "文件为空！" << endl;		//测试代码
		//初始化属性
		this->m_EmpNum = 0;		//初始化人数
		this->m_FileIsEmpty = true;		//初始化文件是否为空
		this->m_EmpArray = NULL;		//初始化数组指针
		ifs.close();
		return;
	}

	//3、文件存在，并且记录有数据
	int number = this->get_EmpNum();
	this->m_FileIsEmpty = false;		//初始化文件是否为空
	//cout << "职工人数为：" << number << endl;		//测试代码
	this->m_EmpNum = number;

	//根据职工数创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];		//开辟空间
	this->init_Emp();		//将文件中数据存入数组中
}

//展示菜单
void WorkerManager::Show_Menu()
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
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);		//不管在哪调用exit(0)，程序都会退出
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;		//保存用户的输入职工数量
	cin >> addNum;

	if (addNum > 0)		//添加职工
	{
		//计算添加的新空间大小
		int newSize = this->m_EmpNum + addNum;		//新空间人数=原来记录的人数+新增人数
		
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		
		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i=0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;		//职工编号
			string name = " ";		//职工姓名
			int dSelect = 0;		//部门选择

			cout << "请输入第"<<i+1<<"个新职工编号：";

			while (1)
			{
				cin >> id;
				int result = IsExist(id);
				if (result != -1)
				{
					cout << "该职工编号已存在，请重新输入职工编号：";
				}
				else
				{
					break;
				}
			}

			cout << "请输入第" << i + 1 << "个新职工姓名：";
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			
			Worker* worker = NULL;
				cin >> dSelect;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
				}
		
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;                                       

		//文件为空标志置为假
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;

		//成功添加后，保存数据到文件中 
		this->save();
	}
	else
	{
		cout << "输入有误！" << endl;
	}

	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);		//用输出方式打开文件（写文件）

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_deptname << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);		//读方式打开文件

	int ID;
	string name;
	int dID;

	int num = 0;		//统计人数
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		num++;
	}
	ifs.close();		//关闭文件

	return num;
}

//初始化职工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;

	int index = 0;
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;

		if (dID == 1)		//普通职工
		{
			worker = new Employee(ID, name, dID);
		}
		else if (dID == 2)		//经理
		{
			worker = new Manager(ID, name, dID);
		}
		else		//老板
		{
			worker = new Boss(ID, name, dID);
		}

		//将文件中数据存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();		//利用多态调用程序接口
		}
	}

	system("pause");
	system("cls");
}

//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)		//找到此职工
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
		//按照职工编号删除职工
		cout << "请输入想要删除的职工编号：";
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)			//说明职工存在，并且要删除掉index位置上的职工
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];			//数据前移
			}
			this->m_EmpNum--;		//更新数组中记录的职工个数
			if (m_EmpNum == 0)
			{
				m_FileIsEmpty = true;
			}

			this->save();			//数据同步更新到文件中
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
		cout << "请输入要修改职工的编号" << endl;
		int id;
		cin >> id;

		int result = this->IsExist(id);
		if (result != -1)
		{
			delete this->m_EmpArray[result];

			int newID = 0;
			string newName = " ";
			int dselect = 1;

			cout << "查到" << id << "号职工，请输入修改后的职工号：";
			cin >> newID;
			cout << "请输入修改后的姓名：";
			cin >> newName;
			cout << "请输入修改后的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(newID, newName, 1);
				break;
			case 2:
				worker = new Manager(newID, newName, 2);
				break;
			case 3:
				worker = new Boss(newID, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[result] = worker;			//更新数据到数组中
			cout << "修改成功！" << endl;
			this->save();			//保存到文件中
		}
		else
		{
			cout << "修改失败，职工不存在！" << endl;
		}
	}

	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "请输入查找的职工编号：";
			int id;
			cin >> id;

			int result = IsExist(id);
			if (result != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[result]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入查找的职工姓名：";
			string name;
			cin >> name;
			bool flag = false;			//判断是否查找到的标志，默认为未找到

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功！该职工编号为："<<
						this->m_EmpArray[i]->m_id<<"号，职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout<< "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
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
		cout << "请选择排序方式：" << endl;
		cout << "1、按照职工编号升序排列" << endl;
		cout << "2、按照职工编号降序排列" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;		//声明最小值或最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)			//升序
				{
					if (this->m_EmpArray[MinOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						MinOrMax = j;
					}
				}
				else			//降序
				{
					if (this->m_EmpArray[MinOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						MinOrMax = j;
					}
				}
			}

			//判断最开始认定的最小值或最大值是不是真实的最小值或最大值，如果不是，交换数据
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "排序成功！排序后的结果为：" << endl;
		this->save();
		this->Show_Emp();		//已包含清屏操作
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空文件？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);		//删除文件后重新创建，相当于清空
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区中每个职工对象
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;

			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()		//析构函数
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
}
#pragma once		//防止头文件重复包含
#include<iostream>		//包含输入输出流头文件
using namespace std;		//使用标准命名空间

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();			//构造函数

	void Show_Menu();			//展示菜单

	void ExitSystem();			//退出系统

	int m_EmpNum;			//记录职工人数

	Worker** m_EmpArray;			//职工数组指针

	void Add_Emp();			//添加职工

	void save();		//保存文件

	bool m_FileIsEmpty;		//判断文件是否为空标志

	int get_EmpNum();		//统计文件中人数

	void init_Emp();		//初始化职工

	void Show_Emp();		//显示职工

	int IsExist(int id);		//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
		
	void Del_Emp();		//删除职工

	void Mod_Emp();		//修改职工

	void Find_Emp();		//查找职工

	void Sort_Emp();		//排序职工

	void Clean_File();		//清空文件

	//析构函数
	~WorkerManager();
};
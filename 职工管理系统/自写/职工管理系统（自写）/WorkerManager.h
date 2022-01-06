#pragma once
#include<iostream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include<fstream>
#define FILENAME "emp.txt"

using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	void ShowMenu();		//显示菜单

	void Exit_System();		//退出系统

	int m_Empnum;

	Worker** m_EmpArray;

	void Add_Emp();		//增加成员

	void save();		//写文件

	bool m_FileIsEmpty;

	int get_num();		//获取文件中的人数

	void init_emp();		//初始化员工

	void show_Emp();		//显示员工

	int IsExist(int id);		//判断职工是否存在

	void Del_Emp();		//删除职工

	void Mod_Emp();		//修改职工

	void Find_Emp();		//查找员工

	void Sort_Emp();		//排序职工

	void Clean_File();		//清空文件

	~WorkerManager();
};
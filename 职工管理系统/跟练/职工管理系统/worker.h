//职工的分类为：普通员工、经理、老板
//将三种职工抽象到一个类(worker)中，利用多态管理不同职工种类
//职工的属性为：职工编号、职工姓名、职工所在部门编号
//职工的行为为：岗位职责信息描述，获取岗位名称

#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象类（基类）
class Worker
{
public:
	virtual void showInfo() = 0;			//显示个人信息
	virtual string getDeptName() = 0;			//获取岗位名称
	virtual string getTask() = 0;		//获取岗位职责

	int m_id;		//职工编号
	string m_name;		//职工姓名
	int m_deptname;		//部门编号
};


//////	！！！Worker类没有对象，因此不需要创建对应的cpp文件
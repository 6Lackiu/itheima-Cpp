#include<iostream>
#include "boss.h"

Boss::Boss(int ID, string name, int dID)
{
	this->m_id = ID;
	this->m_name = name;
	this->m_deptname = dID;
}

void Boss::showInfo()			//显示个人信息
{
	cout << "职工编号：" << this->m_id << '\t'
		<< "职工姓名：" << this->m_name << '\t'
		<< "职工岗位：" << this->getDeptName() << '\t'
		<< "岗位职责：" << this->getTask() << endl;
}

string Boss::getDeptName()			//获取岗位名称
{
	return string("总裁");
}

string Boss::getTask()		//获取岗位职责
{
	return string("管理公司所有事务");
}
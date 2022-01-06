#include<iostream>
#include "manager.h"

Manager::Manager(int ID, string name, int dID)
{
	this->m_id = ID;
	this->m_name = name;
	this->m_deptname = dID;
}

void Manager::showInfo()			//显示个人信息
{
	cout << "职工编号：" << this->m_id << '\t'
		<< "职工姓名：" << this->m_name << '\t'
		<< "职工岗位：" << this->getDeptName() << '\t'
		<< "岗位职责：" << this->getTask() << endl;
}

string Manager::getDeptName()			//获取岗位名称
{
	return string("经理");
}

string Manager::getTask()			//获取岗位职责
{
	return string("完成老板交给的任务，并下发任务给员工");
}
#include "worker.h"
#include "employee.h"

Employee::Employee(int ID,string name,int dID)			//构造函数
{
	this->m_id = ID;
	this->m_name = name;
	this->m_deptname = dID;
}

void Employee::showInfo()			//显示个人信息
{
	cout << "职工编号：" << this->m_id << '\t'
		<< "职工姓名：" << this->m_name << '\t'
		<< "职工岗位：" << this->getDeptName() << '\t'
		<< "岗位职责：" << this->getTask() << endl;
}

string Employee::getDeptName()			//获取岗位名称
{
	return string("员工");
}

string Employee::getTask()
{
	return string("完成经理交给的任务");
}
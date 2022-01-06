#include "Employee.h"
#include "Boss.h"

Boss::Boss(int id, string name, int dID)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptname = dID;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_id << '\t'
		<< "职工姓名：" << this->m_name << '\t'
		<< "岗位：" << this->GetDeptName() << '\t'
		<< "岗位职责：" << this->GetTask() << endl;
}

string Boss::GetDeptName()
{
	return string("总裁");
}

string Boss::GetTask()
{
	return string("管理公司所有事务");
}
#include "Worker.h"
#include "Manager.h"

Manager::Manager(int id, string name, int dID)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptname = dID;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_id << '\t'
		<< "职工姓名：" << this->m_name << '\t'
		<< "岗位：" << this->GetDeptName() << '\t'
		<< "岗位职责：" << this->GetTask() << endl;
}

string Manager::GetDeptName()
{
	return string("经理");
}

string Manager::GetTask()
{
	return string("完成老板交给的任务，并下发任务给员工");
}
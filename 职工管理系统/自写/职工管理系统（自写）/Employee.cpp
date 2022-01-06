#include "Employee.h"
#include "Worker.h"

Employee::Employee(int id, string name, int dID)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptname = dID;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_id << '\t'
		<< "职工姓名：" << this->m_name << '\t'
		<< "岗位：" << this->GetDeptName() << '\t'
		<< "岗位职责：" << this->GetTask() << endl;
}

string Employee::GetDeptName()
{
	return string("员工");
}

string Employee::GetTask()
{
	return string("完成经理交给的任务");
}
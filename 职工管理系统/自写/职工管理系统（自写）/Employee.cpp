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
	cout << "ְ����ţ�" << this->m_id << '\t'
		<< "ְ��������" << this->m_name << '\t'
		<< "��λ��" << this->GetDeptName() << '\t'
		<< "��λְ��" << this->GetTask() << endl;
}

string Employee::GetDeptName()
{
	return string("Ա��");
}

string Employee::GetTask()
{
	return string("��ɾ�����������");
}
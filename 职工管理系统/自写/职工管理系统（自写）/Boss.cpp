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
	cout << "ְ����ţ�" << this->m_id << '\t'
		<< "ְ��������" << this->m_name << '\t'
		<< "��λ��" << this->GetDeptName() << '\t'
		<< "��λְ��" << this->GetTask() << endl;
}

string Boss::GetDeptName()
{
	return string("�ܲ�");
}

string Boss::GetTask()
{
	return string("����˾��������");
}
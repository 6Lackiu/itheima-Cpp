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
	cout << "ְ����ţ�" << this->m_id << '\t'
		<< "ְ��������" << this->m_name << '\t'
		<< "��λ��" << this->GetDeptName() << '\t'
		<< "��λְ��" << this->GetTask() << endl;
}

string Manager::GetDeptName()
{
	return string("����");
}

string Manager::GetTask()
{
	return string("����ϰ彻�������񣬲��·������Ա��");
}
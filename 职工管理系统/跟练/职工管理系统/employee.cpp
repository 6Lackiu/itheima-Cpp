#include "worker.h"
#include "employee.h"

Employee::Employee(int ID,string name,int dID)			//���캯��
{
	this->m_id = ID;
	this->m_name = name;
	this->m_deptname = dID;
}

void Employee::showInfo()			//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id << '\t'
		<< "ְ��������" << this->m_name << '\t'
		<< "ְ����λ��" << this->getDeptName() << '\t'
		<< "��λְ��" << this->getTask() << endl;
}

string Employee::getDeptName()			//��ȡ��λ����
{
	return string("Ա��");
}

string Employee::getTask()
{
	return string("��ɾ�����������");
}
#include<iostream>
#include "manager.h"

Manager::Manager(int ID, string name, int dID)
{
	this->m_id = ID;
	this->m_name = name;
	this->m_deptname = dID;
}

void Manager::showInfo()			//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id << '\t'
		<< "ְ��������" << this->m_name << '\t'
		<< "ְ����λ��" << this->getDeptName() << '\t'
		<< "��λְ��" << this->getTask() << endl;
}

string Manager::getDeptName()			//��ȡ��λ����
{
	return string("����");
}

string Manager::getTask()			//��ȡ��λְ��
{
	return string("����ϰ彻�������񣬲��·������Ա��");
}
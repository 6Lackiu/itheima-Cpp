#include<iostream>
#include "boss.h"

Boss::Boss(int ID, string name, int dID)
{
	this->m_id = ID;
	this->m_name = name;
	this->m_deptname = dID;
}

void Boss::showInfo()			//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id << '\t'
		<< "ְ��������" << this->m_name << '\t'
		<< "ְ����λ��" << this->getDeptName() << '\t'
		<< "��λְ��" << this->getTask() << endl;
}

string Boss::getDeptName()			//��ȡ��λ����
{
	return string("�ܲ�");
}

string Boss::getTask()		//��ȡ��λְ��
{
	return string("����˾��������");
}
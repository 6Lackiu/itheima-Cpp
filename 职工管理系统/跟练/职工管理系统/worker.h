//ְ���ķ���Ϊ����ͨԱ���������ϰ�
//������ְ������һ����(worker)�У����ö�̬����ְͬ������
//ְ��������Ϊ��ְ����š�ְ��������ְ�����ڲ��ű��
//ְ������ΪΪ����λְ����Ϣ��������ȡ��λ����

#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ�������ࣨ���ࣩ
class Worker
{
public:
	virtual void showInfo() = 0;			//��ʾ������Ϣ
	virtual string getDeptName() = 0;			//��ȡ��λ����
	virtual string getTask() = 0;		//��ȡ��λְ��

	int m_id;		//ְ�����
	string m_name;		//ְ������
	int m_deptname;		//���ű��
};


//////	������Worker��û�ж�����˲���Ҫ������Ӧ��cpp�ļ�
//��ͨԱ���ļ�
#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int ID, string name, int dID);		//���캯��

	//��д�����еĴ��麯����virtual�ؼ��ֿ�д�ɲ�д
	void showInfo();			//��ʾ������Ϣ
	string getDeptName();			//��ȡ��λ����
	string getTask();		//��ȡ��λְ��
};
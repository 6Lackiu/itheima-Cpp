//�ϰ��ļ�
#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int ID, string name, int dID);

	void showInfo();			//��ʾ������Ϣ
	string getDeptName();			//��ȡ��λ����
	string getTask();		//��ȡ��λְ��
};
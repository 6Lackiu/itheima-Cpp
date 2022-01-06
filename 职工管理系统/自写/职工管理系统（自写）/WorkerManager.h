#pragma once
#include<iostream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include<fstream>
#define FILENAME "emp.txt"

using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	void ShowMenu();		//��ʾ�˵�

	void Exit_System();		//�˳�ϵͳ

	int m_Empnum;

	Worker** m_EmpArray;

	void Add_Emp();		//���ӳ�Ա

	void save();		//д�ļ�

	bool m_FileIsEmpty;

	int get_num();		//��ȡ�ļ��е�����

	void init_emp();		//��ʼ��Ա��

	void show_Emp();		//��ʾԱ��

	int IsExist(int id);		//�ж�ְ���Ƿ����

	void Del_Emp();		//ɾ��ְ��

	void Mod_Emp();		//�޸�ְ��

	void Find_Emp();		//����Ա��

	void Sort_Emp();		//����ְ��

	void Clean_File();		//����ļ�

	~WorkerManager();
};
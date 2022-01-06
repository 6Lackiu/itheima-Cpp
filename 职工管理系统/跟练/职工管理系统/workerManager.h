#pragma once		//��ֹͷ�ļ��ظ�����
#include<iostream>		//�������������ͷ�ļ�
using namespace std;		//ʹ�ñ�׼�����ռ�

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();			//���캯��

	void Show_Menu();			//չʾ�˵�

	void ExitSystem();			//�˳�ϵͳ

	int m_EmpNum;			//��¼ְ������

	Worker** m_EmpArray;			//ְ������ָ��

	void Add_Emp();			//���ְ��

	void save();		//�����ļ�

	bool m_FileIsEmpty;		//�ж��ļ��Ƿ�Ϊ�ձ�־

	int get_EmpNum();		//ͳ���ļ�������

	void init_Emp();		//��ʼ��ְ��

	void Show_Emp();		//��ʾְ��

	int IsExist(int id);		//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
		
	void Del_Emp();		//ɾ��ְ��

	void Mod_Emp();		//�޸�ְ��

	void Find_Emp();		//����ְ��

	void Sort_Emp();		//����ְ��

	void Clean_File();		//����ļ�

	//��������
	~WorkerManager();
};
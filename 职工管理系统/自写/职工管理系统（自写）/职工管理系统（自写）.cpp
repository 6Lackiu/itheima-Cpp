#include<iostream>
#include<string>
#include "WorkerManager.h"
using namespace std;

int main()
{
	WorkerManager wm;

	int choice;
	while (1)
	{
		wm.ShowMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:			//�˳�ϵͳ
			wm.Exit_System();
			break;
		case 1:			//���ְ��
			wm.Add_Emp();
			break;
		case 2:			//��ʾְ��
			wm.show_Emp();
			break;
		case 3:			//ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:			//�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:			//����ְ��
			wm.Find_Emp();
			break;
		case 6:			//����ְ��
			wm.Sort_Emp();
			break;
		case 7:			//����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("cls");
}
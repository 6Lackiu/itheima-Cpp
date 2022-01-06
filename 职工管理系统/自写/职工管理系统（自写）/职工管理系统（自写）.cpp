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
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:			//退出系统
			wm.Exit_System();
			break;
		case 1:			//添加职工
			wm.Add_Emp();
			break;
		case 2:			//显示职工
			wm.show_Emp();
			break;
		case 3:			//删除职工
			wm.Del_Emp();
			break;
		case 4:			//修改职工
			wm.Mod_Emp();
			break;
		case 5:			//查找职工
			wm.Find_Emp();
			break;
		case 6:			//排序职工
			wm.Sort_Emp();
			break;
		case 7:			//清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("cls");
}
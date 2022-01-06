//比赛规则
//学校举行一场演讲比赛，共12个人参加。比赛共两轮，第一轮为淘汰赛赛，第二轮为决赛。
//每名选手都有对应的编号，如10001~10012
//比赛方式：分组比赛，每组6个人；
//第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲。
//十个评委分别给每名选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩
//当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
//第二轮为決塞，前三名胜出
//每轮比过后需要显示晋级选手的信息

//程序功能
//开始演讲比塞：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
//查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
//清空比赛记录：将文件中数据清空
//退出比赛程序：可以退出当前程序

#include<iostream>
#include<string>
#include<ctime>
#include "speechManager.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	//创建管理类对象
	SpeechManager sm;


	////测试
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "编号：" << it->first
	//		<< "   姓名：" << it->second.m_name
	//		<< "   分数：" << it->second.m_score[0] << endl;
	//}

	int choice = 0;

	while (1)
	{
		sm.show_Menu();			//展示菜单

		cout << "请输入您的选择：";
		cin >> choice;

		switch (choice)
		{
		case 1:			//开始比赛
			sm.start_Speech();
			break;
		case 2:			//查看记录
			sm.showRecord();
			break;
		case 3:			//清空记录
			sm.clearRecord();
			break;
		case 0:			//退出系统
			sm.exit_System();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
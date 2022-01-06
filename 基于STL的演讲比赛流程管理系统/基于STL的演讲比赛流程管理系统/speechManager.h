#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include "speaker.h"

using namespace std;

//设计演讲管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();		//只做声明

	//展示菜单
	void show_Menu();

	//退出系统
	void exit_System();

	//初始化容器和属性
	void init_Speech();

	//创建选手
	void create_Speaker();

	//开始比赛  -  比赛流程控制
	void start_Speech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示比赛结果
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//显示往届得分
	void showRecord();

	//清空记录
	void clearRecord();

	//析构函数
	~SpeechManager();


	//成员属性
	vector<int> v1;		//第一轮比赛选手编号  12人
	vector<int> v2;		//第二轮比赛选手编号  6人
	vector<int> vVictory;			//最终前三名选手编号
	map<int, Speaker> m_Speaker;		//存放编号及对应选手
	int m_index;			//记录比赛轮数

	//判断文件是否为空
	bool FileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_record;		//key为某一届，value为读取的比赛信息（六个值组成的string）
};
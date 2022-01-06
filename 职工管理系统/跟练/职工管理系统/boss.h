//老板文件
#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int ID, string name, int dID);

	void showInfo();			//显示个人信息
	string getDeptName();			//获取岗位名称
	string getTask();		//获取岗位职责
};
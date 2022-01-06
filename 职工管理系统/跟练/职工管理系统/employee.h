//普通员工文件
#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int ID, string name, int dID);		//构造函数

	//重写父类中的纯虚函数，virtual关键字可写可不写
	void showInfo();			//显示个人信息
	string getDeptName();			//获取岗位名称
	string getTask();		//获取岗位职责
};
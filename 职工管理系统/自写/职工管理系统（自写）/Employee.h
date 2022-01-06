#pragma once
#include "Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id, string name, int dID);

	void showInfo();
	string GetDeptName();
	string GetTask();
};

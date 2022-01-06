#pragma once
#include<iostream>
using namespace std;
#include "point.h"

class Circle
{
public:
	void setCenter(Point center);   //设置圆心

	Point getCenter();   //获取圆心

	void setR(int R);   //设置半径

	int getR();   //获取半径

private:
	int m_R;

	//在类中可以让另一个类作为本类中的成员
	Point m_Center;  //圆心
};
#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
	void setX(int X);   //设置横坐标

	int getX();   //获取横坐标

	void setY(int Y);   //设置横坐标

	int getY();   //获取横坐标

private:
	int m_pointX;
	int m_pointY;
};
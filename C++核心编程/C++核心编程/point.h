#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
	void setX(int X);   //���ú�����

	int getX();   //��ȡ������

	void setY(int Y);   //���ú�����

	int getY();   //��ȡ������

private:
	int m_pointX;
	int m_pointY;
};
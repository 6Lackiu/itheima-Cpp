#pragma once
#include<iostream>
using namespace std;
#include "point.h"

class Circle
{
public:
	void setCenter(Point center);   //����Բ��

	Point getCenter();   //��ȡԲ��

	void setR(int R);   //���ð뾶

	int getR();   //��ȡ�뾶

private:
	int m_R;

	//�����п�������һ������Ϊ�����еĳ�Ա
	Point m_Center;  //Բ��
};
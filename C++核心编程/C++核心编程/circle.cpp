#include "circle.h"

void Circle::setCenter(Point center)   //设置圆心
{
	m_Center = center;
}
Point Circle::getCenter()   //获取圆心
{
	return m_Center;
}

void Circle::setR(int R)   //设置半径
{
	m_R = R;
}
int Circle::getR()   //获取半径
{
	return m_R;
}
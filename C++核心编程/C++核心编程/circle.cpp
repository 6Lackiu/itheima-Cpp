#include "circle.h"

void Circle::setCenter(Point center)   //����Բ��
{
	m_Center = center;
}
Point Circle::getCenter()   //��ȡԲ��
{
	return m_Center;
}

void Circle::setR(int R)   //���ð뾶
{
	m_R = R;
}
int Circle::getR()   //��ȡ�뾶
{
	return m_R;
}
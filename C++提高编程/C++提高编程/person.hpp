#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ģ����ļ���д�����Լ����
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();

	T1 m_name;
	T2 m_age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "������" << this->m_name << endl;
	cout << "���䣺" << this->m_age << endl;
}
//�Լ���ͨ��������
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)		//�вι��� ����Ϊ����
	{
		//cout << "MyArray���вι������" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}

	MyArray(const MyArray& arr)		//�������캯��
	{
		//cout << "MyArray�Ŀ����������" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->pAddress = arr.pAddress;		//ǳ�����ᵼ�¶��������ظ��ͷţ�����

		this->pAddress = new T[arr.m_capacity];		//���
		for (int i = 0; i < this->m_size; i++)		//��arr�е����ݶ���������
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= ��ֹǳ����
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray��operator=����" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
			this->m_capacity = 0;
			this->m_size = 0;
		}

		//���
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_size];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//β�巨
	void PushBack(const T& val)
	{
		//�ж������Ƿ��Ѿ����ڴ�С
		if (this->m_capacity == this->m_size)
		{
			cout << "��������" << endl;
			return;
		}
		this->pAddress[this->m_size] = val;	//������ĩβ��������
		this->m_size++;
	}
	//βɾ��
	void PopBack()
	{
		if (this->m_size == 0)
		{
			cout << "��С��Ϊ0" << endl;
			return;
		}
		this->m_size--;		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
	}

	//ͨ���±귽ʽ���������е�Ԫ��  ����[ ]
	T& operator[](int index)		//ͨ�����ÿ��Է������ݱ������������Ϊ��ֵ����ֵ
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_capacity;
	}

	//���������С
	int getSize()
	{
		return this->m_size;
	}

	~MyArray()		//����
	{
		if (this->pAddress != nullptr)
		{
			//cout << "MyArray����������" << endl;
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
	}

private:
	T* pAddress;		//ָ��ָ��������ٵ���ʵ����
	int m_capacity;		//��������
	int m_size;		//�����С
};
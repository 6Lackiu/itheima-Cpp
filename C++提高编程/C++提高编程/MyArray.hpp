//自己的通用数组类
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)		//有参构造 参数为容量
	{
		//cout << "MyArray的有参构造调用" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}

	MyArray(const MyArray& arr)		//拷贝构造函数
	{
		//cout << "MyArray的拷贝构造调用" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->pAddress = arr.pAddress;		//浅拷贝会导致堆区数据重复释放，报错

		this->pAddress = new T[arr.m_capacity];		//深拷贝
		for (int i = 0; i < this->m_size; i++)		//将arr中的数据都拷贝过来
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray的operator=调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
			this->m_capacity = 0;
			this->m_size = 0;
		}

		//深拷贝
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_size];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void PushBack(const T& val)
	{
		//判断容量是否已经等于大小
		if (this->m_capacity == this->m_size)
		{
			cout << "容量已满" << endl;
			return;
		}
		this->pAddress[this->m_size] = val;	//在数据末尾插入数据
		this->m_size++;
	}
	//尾删法
	void PopBack()
	{
		if (this->m_size == 0)
		{
			cout << "大小已为0" << endl;
			return;
		}
		this->m_size--;		//让用户访问不到最后一个元素，即为尾删，逻辑删除
	}

	//通过下标方式访问数组中的元素  重载[ ]
	T& operator[](int index)		//通过引用可以返回数据本身，令其可以作为左值被赋值
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_size;
	}

	~MyArray()		//析构
	{
		if (this->pAddress != nullptr)
		{
			//cout << "MyArray的析构调用" << endl;
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
	}

private:
	T* pAddress;		//指针指向堆区开辟的真实数组
	int m_capacity;		//数组容量
	int m_size;		//数组大小
};
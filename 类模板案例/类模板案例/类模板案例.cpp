//案例描述：实现一个通用的数组类，要求如下：
//		可以对内置数据类型以及自定义数据类型的数据进行存储
//		将数组中的数据存储到堆区
//		构造函数中可以传入数组的容量
//		提供对应的拷贝构造函数以及 operator=防止浅拷贝问题
//		提供尾插法和尾法对数组中的数据进行增加和删除
//		可以通过下标的方式访问数组中的元素
//		可以获取数组中当前元素个数和数组的容量

#include<iostream>
#include<string>
#include "MyArray.hpp"
using namespace std;

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test01()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.PushBack(i);
	}
	cout << "arr1的打印输出为：" << endl;
	printIntArray(arr1);

	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	printIntArray(arr2);

	arr2.PopBack();		//尾删
	cout << "arr2尾删后：" << endl;
	cout << "arr2的容量为：" << arr2.getCapacity() << endl;
	cout << "arr2的大小为：" << arr2.getSize() << endl << endl;

	//MyArray<int> arr2(arr1);

	//MyArray<int> arr3(100);
	//arr3 = arr1;
}

//测试自定义数据类型
class Person
{
public:
	Person() {};	//默认构造函数空实现即可
	Person(string name, int age)		//有参构造
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_name << '\t'
			<< "年龄" << arr[i].m_age << endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("孙悟空", 999);
	Person p2("刘备", 20);
	Person p3("Tom", 10);
	Person p4("Jerry", 8);
	Person p5("Liu Xiaoya", 23);

	//将数据插入到数组中
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);

	//打印数组
	printPersonArray(arr);

	cout << "数组容量为：" << arr.getCapacity() << endl;
	cout << "数组大小为：" << arr.getSize() << endl << endl;

	arr.PopBack();
	cout << "尾删后：" << endl;
	cout << "数组容量为：" << arr.getCapacity() << endl;
	cout << "数组大小为：" << arr.getSize() << endl;
}

int main()
{
	cout << "--------测试案例1--------" << endl;
	test01();
	cout << "--------测试案例2--------" << endl;
	test02();

	system("pause");
	return 0;
}
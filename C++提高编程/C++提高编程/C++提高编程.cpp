////////********   01 模板-模板的概念   *******//////////
//模板就是建立通用的工具，大大提高复用性
//模板的特点：
//		模板不可以直接使用，它只是一个框架
//		模板的通用并不是万能的



//C++除了有面向对象的编程，另一种思想称为泛型编程，主要利用的技术就是模板
//C++提供两种模板机制：函数模板和类模板

////////********   02 模板-函数模板基本用法    *******//////////
//函数模板的作用：
//		建立一个通用函数，其函数返回值类型和形参类型可以不具体定制，用一个虚拟的类型来代表
//总结：
//		1、函数模板利用关键字template
//		2、使用函数模板有两种方式：自动类型推导、显式指定类型
//		3、模板的目的是为了提高复用性，将类型参数化
/*
#include<iostream>
using namespace std;

//函数模板
//交换两个整形的函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型的函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>		//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	swapInt(a, b);
	cout << "a=" << a << "   b=" << b << endl;

	double c = 1.1;
	double d = 2.2;
	swapDouble(c, d);
	cout << "c=" << c << "   d=" << d << endl;

	//利用函数模板交换
	int x = 5, y = 10;
	//两种方式使用函数模板
	//		1、自动类型推导
	mySwap(x, y);
	cout << "x=" << x << "\ty=" << y << endl;

	//		2、显示指定类型
	mySwap<int>(x, y);
	cout << "x=" << x << "\ty=" << y << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



////////********    03 模板-函数模板注意事项   *******//////////
//注意事项：
//		1、自动类型推导，必须推导出一致的数据类型T，才可以使用
//		2、模板必须要确定出T的数据类型，才可以使用
//总结：
//		使用模板时必须确定出通用数据类型T，并且能够推导出一致的数据类型
/*
#include<iostream>
using namespace std;


template<typename T>		//typename可以替换为class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//	1、自动类型推导，必须推导出一致的数据类型T，才可以使用
void test01()
{
	int a = 10, b = 20;
	char c = 'c';
	mySwap(a, b);
	cout << "a=" << a << "\tb=" << b << endl;

	//mySwap(a, c);		//推导不出一致的T类型，报错
}

//		2、模板必须要确定出T的数据类型，才可以使用
template<typename T>
void func()
{
	cout << "func的调用" << endl;
}

void test02()
{
	//func();		//无法确定T的类型，无法自动推导，报错
	func<int>();		//显式指定int类型
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/




////////********   04 模板-函数模板案例-数组排序   *******//////////
//案例描述：
//・利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//・排序规则从大小，排序算法为选择排序
//・分别利用char数组和int数组进行测试
/*
#include<iostream>
using namespace std;
//交换函数模板
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				mySwap(arr[i], arr[j]);
			}
		}
	}
}

//打印数组模板
template<typename T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr);
	mySort(charArr, num);
	printArr(charArr,num);
}

void test02()
{
	//测试int数组
	int intArr[] = { 3,5,1,6,3,7 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArr(intArr, num);
}

using namespace std;
int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/



////////********  05 模板-普通函数与函数模板区别    *******//////////
//普通函数与函数模板区别：
//		普通函放调用时可以发生自动类型转换（隐式类型转换）
//		函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//		如果利用显示指定类型的方式，可以发生隐式类型转换
/*
#include<iostream>
using namespace std;

//普通函数
int myAdd01(int a,int b)
{
	return a + b;
}

template<typename T>
T myAdd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10, b = 20;
	char c = 'c';		//ASCII码为99
	cout << myAdd01(a, c) << endl;

	//自动类型推导
	//cout << myAdd02(a, c) << endl;		//无法进行隐式类型转换，报错
	
	//显式指定类型
	cout << myAdd02<int>(a, c) << endl;		//不报错
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   06 模板-普通函数与函数模板调用规则   *******//////////
//调用规则如下
//		1.如果函数模板和普通函数都可以实现，优先调用普通函数
//		2.可以通过空模板参数列表来强制调用函数模板
//		3.函数模板也可以发生函数重载
//		4.如果函数模板可以产生更好的匹配，优先调用函数模板
//总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
/*
#include<iostream>
using namespace std;

//普通函数与函数模板调用规则
//		1.如果函数模板和普通函数都可以调用，优先调用普通函数
void myPrint(int a,int b)
{
	cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}

//		3.函数模板也可以发生函数重载
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的函数模板" << endl;
}

void test01()
{
	int a = 10, b = 20;
	//myPrint(a, b);

	//通过空模板参数列表来强制调用函数模板
	//myPrint<>(a, b);

	//myPrint(a, b, 100);		//函数重载

	//		4.如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a', c2 = 'b';
	myPrint(c1, c2);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  07 模板-模板的局限性    *******//////////
//局限性：模板的通用性并不是万能的
//总结
//		・利用具体化的模板，可以解决自定义类型的通用化
//		・学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
/*
#include<iostream>
#include<string>
using namespace std;

//模板局限性
//模板并不是万能的，有些特定数据类型，需要具体化方式做特殊实现

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

//对比两个数据是否相等
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体化Person的版本实现代码
//以template<>开头，并通过名称来指出类型
//具体化要优先于常规模板
template<> bool myCompare(Person& a, Person& b)
{
	if (a.m_name == b.m_name && a.m_age == b.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10, b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a=b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}

void test02()
{
	Person p1("Tom", 20);
	Person p2("Tom", 22);
	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1=p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/




////////********  08 模板-类模板基本语法    *******//////////
//类模板作用
//		建立一个通用类，类中的成员、数据类型可以不具体指定，用一个虚拟的类型来代表
//总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板
/*
#include<iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	NameType m_name;
	AgeType m_age;
};

void test01()
{
	Person<string, int>p1("Tom", 20);
	cout << "姓名："<<p1.m_name << "  年龄：" << p1.m_age << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



////////********   09 模板-类模板与函数模板区别   *******//////////
//类模板与函数模板区别主要有两点：
//		1.类模板没有自动类型推导的使用方式
//		2.类模板在模板参数列表中可以有默认参数
/*
#include<iostream>
#include<string>
using namespace std;

template<class NameType,class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void showPerson()
	{
		cout << "姓名：" << this->m_name << '\t' << "年龄：" << this->m_age << endl;
	}

	NameType m_name;
	AgeType m_age;

};


//		1.类模板没有自动类型推导的使用方式
void test01()
{
	//Person p("Tom", 20);		//无法用自动类型推导，报错
	
	Person<string, int>p("Tom", 20);		//正确，只能用显示指定类型
	p.showPerson();
}

//		2.类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string>p("Jack", 30);		//age有默认参数int，不需要定义数据类型
	p.showPerson();
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/



////////********  10 模板-类模板中成员函数创建时机    *******//////////
//类模板中成员函数和普通类中成员函数创建时机是有区别的
//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时才创建
/*
#include<iostream>
#include<string>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class myClass
{
public:
	T obj;

	//类模板中的成员函数
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	myClass<Person1>m1;
	m1.func1();

	myClass<Person2>m2;
	m2.func2();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



////////********   11 模板-类模板对象做函数参数   *******//////////
//学习目标：
//		类模板实例化出的对象，向函数传参的方式
//一共有三种传入方式：
//		1.指定传入的类型   --直接显示对象的数据类型（最常用）
//		2.参数模板化         --将对象中的参数变为模板进行传递追
//		3.整个类模板化      --将这个对象类型模板化进行传递
/*
 #include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void showPerson()
	{
		cout << "name:" << this->m_name << "\tage:" << this->m_age << endl;
	}

	T1 m_name;
	T2 m_age;
};

//		1.指定传入的类型   --直接显示对象的数据类型（最常用）
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson1(p);
}

//		2.参数模板化         --将对象中的参数变为模板进行传递追
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p)
{
	p.showPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test02()
{
	Person<string, int>p("Jack", 30);
	printPerson2(p);
}

//		3.整个类模板化      --将这个对象类型模板化进行传递
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	cout << "T的数据类型为：" << typeid(T).name() << endl;
}

void test03()
{
	Person<string, int>p("Mary", 40);
	printPerson3(p);
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();

	system("pause");
	return 0;
}
*/



////////********   12 模板-类模板与继承   *******//////////
//当类模板碰到继承时，需要注意以下几点：
//		当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的数据类型
//		如果不指定，编译器无法给子类分配内存
//		如果想灵活指定出父类中T的类型，子类也需变为类模板
/*
#include<iostream>
using namespace std;

//类模板与继承
template<class T>
class Base
{
public:
	T m;
};

//class Son :public Base		//错误，必须要知道父类中T的数据类型 才能继承给子类
class Son:public Base<int>
{

};

void test01()
{
	Son s1;
}

//如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的类型为" << typeid(T1).name() << endl;
		cout << "T2的类型为" << typeid(T2).name() << endl;
	}

	T1 obj;
};

void test02()
{
	Son2<int, char> s2;		//子类中的T1为int，父类中的T即T2为char
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/



////////********  13 模板-类模板成员函数类外实现    *******//////////
//总结：
//		类模板中成员函数类外实现时，需要加上模板参数列表
/*
#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->m_name = name;
	//	this->m_age = age;
	//}

	void showPerson();
	//{
	//	cout << "姓名：" << this->m_name << endl;
	//	cout << "年龄：" << this->m_age << endl;
	//}

	T1 m_name;
	T2 m_age;
};

//构造函数类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}

//成员函数类外实现
template<class T1,class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << this->m_name << endl;
	cout << "年龄：" << this->m_age << endl;
}

void test01()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   14 模板-类模板分文件编写   *******//////////
//问题：
//		类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//解决：
//		解决方式1：直接包含.cpp源文件
//		解决方式2（主流方法）：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
/*
#include<iostream>
#include<string>
using namespace std;
//解决方式1：直接包含.cpp源文件
//#include "person.cpp"

//解决方式2（主流方法）：将声明.h和实现.cpp中的内容写到同一个文件中，并更改后缀名为.hpp
#include "person.hpp"

//类模板分文件编写问题以及解决
//template<class T1,class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//	T1 m_name;
//	T2 m_age;
//};

//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//
//template<class T1,class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名：" << this->m_name << endl;
//	cout << "年龄：" << this->m_age << endl;
//}

void test01()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  15 模板-类模板与友元    *******//////////
//学习目标：
//		掌握类模板配合友元函数的类内和类外实现

//全局函数类内实现：直接在类内声明友元即可
//全局函数类外实现：需要提前让编译器知道全局函数的存在

//总结：
//建议全局函数做类内实现，用法简单，而且编译器可以直接识别
/*
#include<iostream>
#include<string>
using namespace std;

//通过全局函数 打印Person信息

//提前让编译器知道Person类存在
template<class T1,class T2>
class Person;
//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "类外实现" << endl;
	cout << "姓名：" << p.m_name << endl;
	cout << "年龄：" << p.m_age << endl;
}

template<class T1,class T2>
class Person
{
	//全局函数，类内实现
	friend void printPerson(Person<T1,T2> &p)
	{
		cout << "类内实现" << endl;
		cout << "姓名：" << p.m_name << endl;
		cout << "年龄：" << p.m_age << endl;
	}

	//全局函数，类外实现
	//需要加空模板参数列表
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2>& p);

public:
	Person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}

private:
	T1 m_name;
	T2 m_age;
};

//1、全局函数在类内实现
void test01()
{
	Person<string, int> p("Tom", 20);
	printPerson(p);
}

//2、全局函数在类外实现
void test02()
{
	Person<string, int> p("Jerry", 30);
	printPerson2(p);
}

int main()
{
	test01();
	cout << endl;
	test02();

	system("pause");
	return 0;
}
*/




//案例描述：实现一个通用的数组类，要求如下：
//		可以对内置数据类型以及自定义数据类型的数据进行存储
//		将数组中的数据存储到堆区
//		构造函数中可以传入数组的容量
//		提供对应的拷贝构造函数以及 operator=防止浅拷贝问题
//		提供尾插法和尾法对数组中的数据进行增加和删除
//		可以通过下标的方式访问数组中的元素
//		可以获取数组中当前元素个数和数组的容量

////////********  16 类模板案例    *******//////////
/*
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
	//test01();
	test02();

	system("pause");
	return 0;
}
*/




////////********  19 STL初识-STL的基本概念    *******//////////

//STL的诞生
//		长久以来，软件界一直希望建立一种可重复利用的东西
//		C++的面向对象和泛型编程思想，目的就是复用性的提升
//		大多情况下，数据结构和算法都未能有一套标准导致被迫从事大量重复工作
//		为了建立数据结构和算法的一套标准，诞生了STL

// STL的基本概念
//		STL(Standard Template Library标准模板库)
//		STL从广义上分为：容器(container)算法(algorithm)迭代器(iterator)
//		容器和算法之间通过迭代器进行无缝连接
//		STL几乎所有的代码都采用了模板类或者模板函数

//STL六大组件
//STL大体分为六大组件，分别是容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
//		1.容器：各种数据结构，如 vector、 list、deque、set、map等，用来存放数据
//		2.算法：各种用的算法，如sot、find、copy、 for_each等
//		3.迭代器：扮演了容器与算法之间的胶合剂
//		4.仿函放（重载的()）：行为类似函数，可作为算法的某种策略
//		5.适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
//		6.空间配置器：负贵空间的配置与管理

//STL容器、算法、迭代器
//	容器：置物之所也
//	STL容器就是将运用最广泛的一些数据结构实现出来
//	常用的数据结构：数组、链表、树、栈、队列、集合，映射表 等
//	这些容器分为序列式容器和关联式容器两种：
//		序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
//		关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

//	算法：问题之解法也
//	有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法（Algorithms）
//	算法分为：质变算法和非质变算法
//		质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝、替换、删除 等
//		非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、导找极值 等

//	迭代器：容器和算法之间粘合剂
//	提供一种方法，使之能依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式
//	每个容器都有自己专属的迭代器
//	送代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针
//	迭代器种类：输入迭代器、输出迭代器、前向迭代器、双向迭代器、随机访问迭代器
//		常用的容器中迭代器种类为双向迭代器、随机访问迭代器





////////********   20 STL初识-vector存放内置数据类型   *******//////////
//	容器：vector
//	算法：for_each
//	迭代器：vector<int>::iterator
/*
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>		//标准算法头文件

//vector容器存放内置数据类型

void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	//创建了一个vector容器，可认为是一个数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();		//起始迭代器，指向容器中第一个元素
	//vector<int>::iterator itEnd = v.end();		//结束迭代器，指向容器中最后一个元素的下一个位置
	//
	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//第二种遍历方式（更常用）
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//第三种遍历方式  利用STL中提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);		//最后一个是指向函数的指针，所以不需要加括号
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



////////********   21 STL初识-vector存放自定义数据类型   *******//////////
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

void test01()
{
	vector<Person> v;

	Person p1("aa", 10);
	Person p2("bb", 20);
	Person p3("cc", 30);
	Person p4("dd", 40);
	Person p5("ee", 50);

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//两种均可
		// 技巧！ (*it)的数据类型即为<>中的数据类型
		//cout << "姓名：" << (*it).m_name << "  年龄：" << (*it).m_age << endl;
		cout << "姓名1：" << it->m_name << "  年龄1：" << it->m_age << endl;

	}
}

//存放自定义数据类型 指针
void test02()
{
	vector<Person*> v;

	Person p1("aa", 10);
	Person p2("bb", 20);
	Person p3("cc", 30);
	Person p4("dd", 40);
	Person p5("ee", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍历容器中的数据
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 技巧！ (*it)的数据类型即为<>中的数据类型
		cout << "姓名2：" << (*it)->m_name << "  年龄2：" << (*it)->m_age << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********  22 STL初识-容器嵌套容器    *******//////////
/*
#include<iostream>
#include<vector>
using namespace std;

//容器嵌套容器 

void test01()
{
	vector<vector<int>>v;

	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器把所有数据遍历一遍
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)是容器vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << "  ";
		}
		cout << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




//	本质：
//		string是C++风格的字符串，而 string本质上是一个类
//	string和char* 区别：
//		char* 是一个指针
//		string是一个类，类内部封装了char* ，管理这个字符串，是一个char* 型的容器
//	特点：
//		string类内部封装了很多成员方法
//		例如：查找find，拷贝copy，删除 delete，替换 replace，插入insert
//		string管理char* 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

////////********  22 string容器-构造函数    *******//////////
//构造函数原型：
//		string();		默认构造，创建一个空的字符串 例如：string str;
//		string(const char* s);		使用字符串s初始化
//		string (const string& str);		拷贝构造，使用一个string对象初始化另一个对象string对象
//		string (int n , char c)		使用n个字符串c初始化
//总结：
//		string的多种构造方式没有可比性，灵活使用即可
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string s1;		//默认构造 无参构造

	const char* str = "hello world!";
	string s2(str);
	cout << "s2=" << s2 << endl;

	string s3(s2);
	cout << "s3=" << s3 << endl;

	string s4(5, 'a');
	cout << "s4=" << s4 << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  23 string容器-赋值操作    *******//////////
//	赋值的函数原型：
//		string& operator=(const char* s);			char*类型字符串赋值给当前的字符串
//		string& operator=(const string& s);		把字符串s给当前的字符阜
//		string& operator=(char c);						字符赋值给当前的字符串
//		string& assign(const char* s);					把字符串s赋给当前的字符串
//		string& assign(const char* s, int n);		把字符串s的前n个字符赋给当前的字符串
//		string& assign(const string& s);				把字符串s赋给当前字符串
//		string& assign(int n, char c);					用n个字符c赋给当前字符串
//总结：
//		string的赋值方法很多，operator=这种方式是比较实用的
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string str1;
	str1 = "hello world!";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++", 7);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'a');
	cout << "str7 = " << str7 << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



////////********    24 string容器-字符串拼接   *******//////////
//	函数原型：
//		string& operator+=(const char* str);								重载 += 操作符
//		string & operator+=(const char c);									重载 += 操作符
//		string & operator+=(const string & str);						重载 += 操作符
//		string & append(const char* s);										把字符s连接到当前字符串结尾
//		string& append(const char* s, int n);								把字符串s的前n个字符连接到当前字符串结尾
//		string& append(const string& s);									同operator += (const string & str)
//		stringe & append(const string & s, int pos, int n);			 字符串s中从pos开始的n个字符连接到字符串结尾
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;

	str1 += ':';
	cout << "str1 = " << str1 << endl;

	string str2 = " CSGO,R6s";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love");
	cout << "str3 = " << str3 << endl;

	str3.append(" game abcd", 5);
	cout << "str3 = " << str3 << endl;

	//str3.append(str2, 0, 5);		//只从str2第0个位置开始截取到第5个位置
	//cout << "str3 = " << str3 << endl;

	str3.append(str2, 6, 9);		//只从str2第6个位置开始截取到第9个位置
	cout << "str3 = " << str3 << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  26 string容器-字符串查找和替换    *******//////////
/*
#include<iostream>
#include<string>
using namespace std;

//1、查找
void test01()
{
	string str1 = "abcdefgde";
	int pos1 = str1.find("de");		//找到字符串返回第一次找到的字符串位置
	int pos2 = str1.find("df");		//未找到字符串返回-1
	cout << "find pos1 = " << pos1 << endl;
	cout << "find pos2 = " << pos2 << endl;

	//rfind 和 find的区别
	//rfind从右往左找   find从左往右找
	int pos3 = str1.rfind("de");
	cout << "rfind pos3 = " << pos3 << endl;
}

//2、替换
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111");		//从1号位置起3个位置，替换为“1111”
	cout << "str1 = " << str1 << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/
//



////////********   27 string容器-字符串比较   *******//////////
//	字符串比较是按字符的ASCII码进行对比，=返回0，>返回1，<返回-1
// 函数原型：
//		int compare(const string &s) const;		与字符串s比较
//		int compare(const char *s) const;		与字符串s比较
//	总结：
//		字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小意义并不大
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string str1 = "hzllo";
	string str2 = "hello";

	if (str1.compare(str2) == 0)		//先比第一位，再比第二位，依次往后推
	{
		cout << "str1等于str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout<< "str1大于str2" << endl;
	}
	else
	{
		cout << "str1小于str2" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   28 string容器-字符存取   *******//////////
//	string中单个字符存取（读和写）方式有两种
//char& operator[](int n);		通过[ ]方式取字符
//char& at(int n);		通过at方式获取字符
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string str = "hello";
	cout << "str = " << str << endl;

	//1、通过[ ]方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << "  ";
	}
	cout << endl;
	
	//2、通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << "  ";
	}
	cout << endl;


	//修改单个字符
	str[0] = 'x';
	cout << "str = " << str << endl;

	str.at(4) = 'x';
	cout << "str = " << str << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   29 string容器-字符串插入和删除   *******//////////
//	插入insert		删除erase
//	总结：
//		注意插入和删除的起始下标都是从0开始
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string str = "hello";

	//插入
	str.insert(1, "234");
	cout << "str = " << str << endl;

	//删除
	str.erase(1, 2);		//从第1个位置删除到第2个位置
	cout << "str = " << str << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  30 string容器-子串获取    *******//////////
//	功能描述：
//		从字符串中获取想要的子串
//	函数原型：
//		string substr(int pos=0 , int n=npos) const;		返回由pos开始的n个字符组成的字符串
//	总结：
//		灵活的运用求子串功能，可以在实际开发中获取有效的信息
/*
#include<iostream>
#include<string>
using namespace std;

//string求子串
void test01()
{
	string str = "abcdef";

	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
}

//实用操作
void test02()
{
	string email = "Liu Xiaoya@163.com";

	//从邮件地址中获取用户名信息
	int pos = email.find("@");		//pos=10
	string userName = email.substr(0, pos);		//返回由0开始的pos个字符组成的字符串
	cout << "用户名为：" << userName << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/



//	vector基本概念
// 功能：
//		vector数据结构与数组非常相似，也称为 单端数组 (只有数组尾端可以插入删除数据)
// vector与普通数组区别：
//		不同之处在于数组是静态空间，而vector可以动态扩展
// 动态扩展：
//		并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
//	vector容器的迭代器是支持随机访问的迭代器

////////********   31 vector容器-构造函数   *******//////////
//函数原型：
//		vector<T> v;							采用模板实现类实现，默认构造函数
//		vector(v.begin(),v.end());			将 v[ begin(),end() ) 区间中的元素拷贝给本身
//		vector(n,elem);							构造函数将n个elem拷贝给本身
//		vector(const vector &vec);		拷贝构造函数
/*
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;		//默认构造 无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//通过区间方式进行构造
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem方式构造
	vector<int> v3(10, 2);
	printVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	printVector(v4);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  32 vector容器-赋值操作    *******//////////
/*
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//赋值
	vector<int> v2;
	v2 = v1;
	printVector(v2);

	//assign赋值
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector<int> v4;
	v4.assign(10, 2);
	printVector(v4);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  33 vector容器-容量和大小    *******//////////
//函数原型：
//empty();									//判断容器是否为空
//capacity();									//容器的容量
//size();										//返回容器中元素的个数
//resize(int num);							//重新指定容器的长度为num, 若容器变长，则以默认值填充新位置。
													//如果容器变短，则末尾超出容器长度的元素被删除。
//resize(int num, elem);				//重新指定容器的长度为num, 若容器变长，则以elem值填充新位置。
													//如果容器变短，则末尾超出容器长度的元素被删除
/*
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为：" << v1.size() << endl << endl;
	}

	//重新指定大小
	v1.resize(15);
	printVector(v1);
	cout << "v1的容量为：" << v1.capacity() << endl << endl;

	v1.resize(18, 5);
	printVector(v1);
	cout << "v1的容量为：" << v1.capacity() << endl << endl;

	v1.resize(5);
	printVector(v1);
	cout << "v1的容量为：" << v1.capacity() << endl << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   34 vector容器-插入和删除    *******//////////
/*
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	
	//尾插法
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	//遍历
	printVector(v1);

	//尾删
	v1.pop_back();
	printVector(v1);

	//插入  第一个参数是迭代器
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 500);
	printVector(v1);

	//删除	第一个参数也是迭代器
	v1.erase(v1.begin());
	printVector(v1);

	//清空
	v1.clear();
	//v1.erase(v1.begin(), v1.end());		//效果相同，也是清空
	printVector(v1);		//只打印出了换行符
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   35 vector容器-数据存取   *******//////////
//函数原型：
//		at(int idx);		返回索引idx所指的结果
//		operator[];		返回索引idx所指的数据
//		front();				返回容器中第一个数据元素
//		back();				返回容器中最后一个数据元素
/*
#include<iostream>
#include<vector>
using namespace std;

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		//cout << v1.at(i) << ' ';		//利用at方式访问数组中元素
		cout << v1[i] << ' ';		//利用[ ]方式访问数组中元素
	}
	cout << endl;

	cout << "第一个元素为：" << v1.front() << endl;
	cout << "最后一个元素为：" << v1.back() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   36 vector容器-互换容器   *******//////////
//	功能描述：
//		实现两个容器内元素进行互换
//	函数原型：
//		swap(vec);		//将vec与本身的元素互换
//总结：
//		swap可以使两个容器互换，可以达到实用的收缩内存效果
/*
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

// 1、基本使用
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "交换前：" << endl;
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "交换后：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

// 2、实际用途
// 巧用swap可以收缩内存空间
void test02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl << endl;

	v.resize(3);		//重新指定大小
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl << endl;

	//巧用swap收缩内存
	//vector<int>(v)是一个匿名对象。相当于运用拷贝构造函数按照v目前的大小构建了一个匿名容器
	//然后这个新的匿名容器与原容器v做互换。匿名对象在当前行执行完后会自动被回收
	vector<int>(v).swap(v);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********   37 vector容器-预留空间   *******//////////
//	功能描述：
//		减少vector在动态扩展容量时的扩展次数
//	函数原型：
//		reserve(int len);		//容器预留len个元素长度，预留位置不初始化，元素不可访问（和resize不同）。
//	总结：
//		如果数据量较大，可以一开始利用reserve预留空间
/*
#include<iostream>
#include<vector>
using namespace std;

void test01()
{
	vector<int> v;

	//利用reserve预留空间
	v.reserve(100000);

	int num = 0;		//统计开辟次数
	int* p = nullptr;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num = " << num << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




//功能：
//		双端数组，可以对头部进行插入和删除操作
//deque与vector区别：
//		vector对于头部的插入删除效率低，数据量越大，效率越低
//		deque相对而言，对头部的插入删除速度会比vector快
//		vector访问元素时的速度会比deque快，这和两者的内部实现有关
//deque内部工作原理：
//		deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//		中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
//	deque容器的迭代器也是支持随机访问的

////////********  38 deque容器-构造函数    *******//////////
/*
#include<iostream>
#include<deque>
using namespace std;

void printDeque(const deque<int>& d)		//加cosnt限定只读
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)		//迭代器也要改成只读迭代器
	{
		//*it=100;		//限定了只读，不可修改
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int> d3(10, 2);
	printDeque(d3);

	deque<int> d4(d3);
	printDeque(d4);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   39 deque容器-赋值操作   *******//////////
/*
#include<iostream>
#include<deque>
using namespace std;

void printDeque(const deque<int>& d)		//加cosnt限定只读
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)		//迭代器也要改成只读迭代器
	{
		//*it=100;		//限定了只读，不可修改
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//operator=赋值
	deque<int> d2 = d1;
	printDeque(d2);

	//assgin赋值
	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	deque<int> d4;
	d4.assign(10, 2);
	printDeque(d4);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  40 deque容器-大小操作    *******//////////
//deque没有容量capacity的概念
/*
#include<iostream>
#include<deque>
using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为：" << d1.size() << endl;
	}

	d1.resize(15);
	printDeque(d1);

	d1.resize(17, 3);
	printDeque(d1);

	d1.resize(4);
	printDeque(d1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  41 deque容器-插入和删除    *******//////////
/*
#include<iostream>
#include<deque>
using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//两端操作
void test01()
{
	deque<int> d1;

	//尾插
	d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	//尾删
	d1.pop_back();
	printDeque(d1);

	//头删
	d1.pop_front();
	printDeque(d1);
}

void test02()
{
	deque<int> d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//insert插入
	d1.insert(d1.begin(), 1000);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 3000);
	printDeque(d1);

	//按照区间进行插入
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	
	//要提供迭代器，提供诸如1、2、3等索引值是无法代表区间的
	d1.insert(d1.begin(), d2.begin(), d2.end());		// insert(pso, begin, end);
	printDeque(d1);
}

void test03()
{
	deque<int> d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//删除
	deque<int>::iterator it = d1.begin();
	it++;			//迭代器指向第2个位置
	d1.erase(it);
	printDeque(d1);

	//按照区间方式删除
	d1.clear();		//只剩下换行符
	//d1.erase(d1.begin(), d1.end());		//效果相同
	printDeque(d1);
}

int main()
{
	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}
*/




////////********   42 deque容器-数据存取    *******//////////
/*
#include<iostream>
#include<deque>
using namespace std;

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//通过[ ]方式访问元素
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;

	//通过at方式访问元素
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << ' ';
	}
	cout << endl;

	cout << "第一个元素为：" << d.front() << endl;
	cout << "最后一个元素为：" << d.back() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   43 deque容器-排序操作    *******//////////
/*
#include<iostream>
#include<deque>
#include<algorithm>		//标准算法头文件
using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	cout << "排序前：" << endl;
	printDeque(d);

	//排序		sort默认排序为升序
	//对于支持随机访问迭代器的容器，都可以利用sort算法直接对其进行排序
	sort(d.begin(), d.end());
	cout << "排序后：" << endl;
	printDeque(d);

	//vector容器也可以利用sort进行排序
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   44 STL案例1-评委打分    *******//////////
//案例描述：
//		有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分。
/*
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;
	int m_score;
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		//将创建的person对象放入到容器中
		v.push_back(p);
	}
}

//打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入deque容器中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;		// 60~100
			d.push_back(score);
		}

		//	测试
		//cout << "选手：" << (*it).m_name << "   打分：" << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << "  ";
		//}
		//cout << endl;

		//先排序
		sort(d.begin(), d.end());
		//去除最高和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		//将平均分赋值给选手
		(*it).m_score = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << "   平均分为：" << (*it).m_score << endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//1、创建五名选手
	vector<Person> v;
	createPerson(v);
	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名：" << (*it).m_name << "   平均分数：" << (*it).m_score << endl;
	//}

	//2、给五名选手打分
	setScore(v);

	//3、显示最后得分
	showScore(v);

	system("pause");
	return 0;
}
*/





////////********   45 stack容器-基本概念    *******//////////
// 概念：
//		stack是一种先进后出（First in Last Out，FILO）的数据结构，它只有一个出口
//		栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
//	栈中进入数据称为  入栈push
//	栈中弹出数据称为  出栈pop




////////********   46 stack容器-常用接口    *******//////////
//功能描述：栈容器常用的对外接口
/*
#include<iostream>
#include<stack>
using namespace std;

void test01()
{
	stack<int> s;

	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	//只要栈不为空，就查看栈顶，并且执行出栈操作
	while (!s.empty())
	{
		cout << "栈顶元素为：" << s.top() << endl;
		cout << "栈的大小：" << s.size() << endl;
		//出栈
		s.pop();
	}

	cout << endl << "栈的大小：" << s.size() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   47 queue容器-基本概念    *******//////////
//概念：
//		queue是一种先进先出（First in First out,FIFO）的数据结构，它有两个出口
//	队列容器允许从一端新增元素，从另一端移除元素
//	队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
//	队列中进数据称为  入队push
//	队列中出数据称为  出队pop





////////********   48 queue容器-常用接口    *******//////////
//	功能描述：队列容器常用的对外接口
/*
#include<iostream>
#include<queue>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

void test01()
{
	//创建队列
	queue<Person> q;
	
	//准备数据
	Person p1("唐僧", 50);
	Person p2("孙悟空", 100);
	Person p3("猪八戒", 200);
	Person p4("沙僧", 300);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//判断队列不为空，查看对头、队尾，出队
	while (!q.empty())
	{
		//查看队头
		cout << "队头元素——姓名：" << q.front().m_name << "   年龄" << q.front().m_age << endl;
		//查看队尾
		cout << "队尾元素——姓名：" << q.back().m_name << "   年龄" << q.back().m_age << endl;
		
		cout << "队列大小为：" << q.size() << endl << endl;
		//出队
		q.pop();
	}
	cout << "队列大小为：" << q.size() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   49 list容器-基本概念    *******//////////
//功能：将数据进行链式存储
//链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

//链表的组成：
//		链表由一系列 结点 组成
//结点的组成：
//		一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域

//STL中的链表是一个双向循环链表
//由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

//list的优点：
//		采用动态存储分配，不会造成内存浪费和溢出
//		链表执行插入和删除操作十分方便，修改指针即可，不需要大量移动元素
//list的缺点：
//		链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大

//list有一个重要的性质，插入和删除操作都不会造成原有list迭代器的失效，这在vector中是不成立的

//总结：
//STL中list和vector是两个最常被使用的容器，各有优缺点




////////********   50 list容器-构造函数   *******//////////
//总结：
//		list构造方式同其他几个STL常用容器，熟练掌握即可
/*
#include<iostream>
#include<list>
using namespace std;

void printList(const list<int> L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	list<int> L1;

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//遍历容器
	printList(L1);

	//按照区间方式构造
	list<int> L2(L1.begin(), L1.end());
	printList(L2);

	//拷贝构造
	list<int> L3(L2);
	printList(L3);

	//n个elem
	list<int> L4(5, 2);
	printList(L4);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  51 list容器-赋值和交换    *******//////////
// 赋值：operator=      assign
// 交换：swap
/*
#include<iostream>
#include<list>
using namespace std;

void printList(const list<int> L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//赋值
void test01()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int> L2;
	//operator= 赋值
	L2 = L1;
	printList(L2);

	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int> L4;
	L4.assign(5, 2);
	printList(L4);
}

//交换
void test02()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int> L2;
	L2.assign(5, 100);

	cout << "交换前：" << endl;
	printList(L1);
	printList(L2);

	L1.swap(L2);
	cout << "交换后：" << endl;
	printList(L1);
	printList(L2);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/





////////********   52 list容器-大小操作   *******//////////
/*
#include<iostream>
#include<list>
using namespace std;

void printList(const list<int> L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	//判断容器是否为空
	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1元素个数为：" << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	printList(L1);

	L1.resize(15, 6);
	printList(L1);

	L1.resize(3);
	printList(L1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   53 list容器-插入和删除   *******//////////
/*
#include<iostream>
#include<list>
using namespace std;

void printList(const list<int> L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	list<int> L;

	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);

	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//insert插入
	L.insert(L.begin(), 1000);
	printList(L);

	list<int>::iterator it = L.begin();
	it++;
	L.insert(it, 2, 9);
	printList(L);

	//删除
	it = L.begin();
	L.erase(it);
	printList(L);

	//remove(elem)移除   删除容器中所有与elem匹配的元素
	L.push_back(999);
	L.push_back(999);
	L.push_back(999);
	printList(L);
	L.remove(999);
	printList(L);

	//清空
	L.clear();
	printList(L);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  54 list容器-数据存取    *******//////////
//list本质链表，不是用连续线性空间存储数据，而且迭代器也是不支持随机访问的
//所以访问元素不能用 [ ] 或 at()，只能用 front() 和 back()
/*
#include<iostream>
#include<list>
using namespace std;

void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;

	//验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();
	//it = it + 1;		//不支持随机访问，报错，只能++或--
	it++;
	cout << *it << endl;
	it--;		//支持双向
	cout << *it << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  55 list容器-反转和排序    *******//////////
//	reverse()		反转链表
//	sort();		链表排序
/*
#include<iostream>
#include<list>
using namespace std;

void printList(const list<int> L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//反转
void test01()
{
	list<int> L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout << "反转前：" << endl;
	printList(L1);

	//反转
	L1.reverse();
	cout << "反转后：" << endl;
	printList(L1);
}

bool myCompare(int v1,int v2)
{
	//降序，就让第一个数>第二个数
	return v1 > v2;
}

//排序
void test02()
{
	list<int> L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);

	cout << "排序前：" << endl;
	printList(L1);

	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持的随机访问迭代器的容器，内部会提供对应的一些算法（成员函数）
	L1.sort();		//默认排序从小到大
	cout << "升序排序后：" << endl;
	printList(L1);

	L1.sort(myCompare);
	cout << "降序排序后：" << endl;
	printList(L1);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/





////////********   56 list容器-排序案例   *******//////////
//	案例描述：
//		将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
//	排序规则：
//		按照年龄进行升序，如果年龄相同按照身高进行降序
//	总结：
//		对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
//		高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
/*
#include<iostream>
#include<string>
#include<list>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}

	string m_name;
	int m_age;
	int m_height;
};

//指定排序规则
bool comparePerson(Person& p1, Person& p2)
{
	//按照年龄 升序
	if (p1.m_age == p2.m_age)
	{
		//年龄相同  按照身高降序
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
}

void test01()
{
	list<Person> L;		//创建容器

	//准备数据
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	//将容器中插入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << "  年龄：" << (*it).m_age << "  身高：" << (*it).m_height << endl;
	}

	//排序
	cout << "-----------------------------" << endl;
	cout << "排序后：" << endl;
	L.sort(comparePerson);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << "  年龄：" << (*it).m_age << "  身高：" << (*it).m_height << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




//set基本概念：
//简介：所有元素都会在插入时自动被排序
//本质：set/multiset属于关联式容器，底层结构是用二叉树实现
//set和multiset区别：
//		set不允许容器中有重复的元素
//		multiset允许容器中有重复的元素

////////********   57 set容器-构造和赋值   *******//////////
/*
#include<iostream>
#include<set>
using namespace std;

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	set<int> s1;

	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);

	//遍历容器
	//set容器特点：所有元素插入时候被自动排序
	//set容器不允许插入重复值，不会报错但插入不成功
	printSet(s1);	

	//拷贝构造
	set<int> s2(s1);
	printSet(s2);

	//赋值
	set<int> s3;
	s3 = s2;
	printSet(s3);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   58 set容器-大小和交换   *******//////////
//注意：
//		set()容器不支持resize
/*
#include<iostream>
#include<set>
using namespace std;

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//大小
void test01()
{
	set<int> s1;

	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);

	//判断是否为空
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		printSet(s1);
		cout << "s1的大小为：" << s1.size() << endl;
	}
}

//交换
void test02()
{
	set<int> s1;
	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);

	set<int> s2;
	s2.insert(200);
	s2.insert(100);
	s2.insert(400);
	s2.insert(300);

	cout << "交换前：" << endl;
	printSet(s1);
	printSet(s2);
	
	cout << "------------------------------" << endl;
	cout << "交换后：" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********   59 set容器-插入和删除   *******//////////
/*
#include<iostream>
#include<set>
using namespace std;

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	set<int> s1;

	//插入
	s1.insert(40);
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	printSet(s1);

	//删除	删除迭代器所指位置的元素，返回下一个元素的迭代器
	s1.erase(s1.begin());
	printSet(s1);

	//删除重载版本		直接删除容器中值的elem元素
	s1.erase(30);
	printSet(s1);

	//清空
	//.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  60 set容器-查找和统计    *******//////////
//		find(key)		//查找key是否存在，若存在返回该键的元素的迭代器；若不存在返回set.end()
//		count(key)		//统计key的元素个数，对于set而言无非是0或1。multiset容器可能返回别的int值
/*
#include<iostream>
#include<set>
using namespace std;

//查找
void test01()
{
	set<int> s1;

	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "找到元素" << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
}

//统计
void test02()
{
	set<int> s1;

	s1.insert(20);
	s1.insert(10);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);
	s1.insert(30);

	//统计30的个数
	//对于set而言count返回的数无非是0或1
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********   61 set容器-set和multiset区别   *******//////////
//区别：
//		set不可以插入重复数据，而 multiset可以
//		set插入数据的同时会返回插入结果，表示插入是否成功
//		multiset不会检测数据，因此可以插入重复数据
/*
#include<iostream>
#include<set>
using namespace std;

void test01()
{
	set<int> s;

	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	ret = s.insert(10);		//再次插入10
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}


	multiset<int> ms;
	//允许插入重复的值
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   62 pair使用-pair对组的创建   *******//////////
//	功能描述：
//		成对出现的数据，利用对组可以返回两个数据
//	两种创建方式：
//		pair<type,type> p(value1,value2);
//		pair<type,type> p=make_pair(value1,value2);
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	//第一种创建方式
	pair<string, int> p1("Tom", 20);
	cout << "姓名：" << p1.first << "  年龄：" << p1.second << endl;
	
	//第二种创建方式
	pair<string, int> p2 = make_pair("Jerry", 30);
	cout << "姓名：" << p2.first << "  年龄：" << p2.second << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




//	学习目标：
//		set容器默认排序规则为从小到大，掌握如何改变排序规则
//	主要技术点：
//		利用仿函数，可以改变排序规则
////////********  63 set容器-内置类型指定排序规则    *******//////////
/*
#include<iostream>
#include<set>
using namespace std;

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

class myCompare		//仿函数本质是一个类
{
public: 
	bool operator()(int v1,int v2)const 		//第一个()代表要重载小括号，第二个()代表这个函数的参数列表
	{
		return v1 > v2;
	}
};

void test01()
{
	set<int> s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	printSet(s1);

	//指定排序规则为从大到小
	set<int, myCompare> s2;
	s2.insert(30);
	s2.insert(10);
	s2.insert(20);
	s2.insert(50);
	s2.insert(40);
	for (set<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/






////////********  64 set容器-自定义数据类型指定排序规则    *******//////////
//	总结：
//		对于自定义数据类型，set必须指定排序规则才可以插入数据
/*
#include<iostream>
#include<set>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class ComparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2)const
	{
		//按照年龄 降序
		return p1.m_age > p2.m_age;
	}
};

void test01()
{
	//自定义数据类型 都会指定排序规则
	set<Person, ComparePerson> s;

	//创建Person对象
	Person p1("刘备", 35);
	Person p2("关羽", 30);
	Person p3("张飞", 25);
	Person p4("赵云", 40);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person ,ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名：" << it->m_name << "   年龄：" << it->m_age << endl;
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




//简介：
//		map中所有元素都是pair
//		pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
//		所有元素都会根据元素的键值自动排序
//本质：
//		map/multimap属于关联式容器，底层结构是用二叉树实现
//优点：
//		可以根据key值快速找到value值
//map和multimap区别：
//		map不允许容器中有重复key值元素
//		multimap允许容器中有重复key值元素

////////********  65 map容器-构造和赋值    *******//////////
/*
#include<iostream>
#include<map>
using namespace std;

void printMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << "   value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	//创建map容器
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));			//把匿名的对组放入容器中
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(3, 50));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	//拷贝构造
	map<int, int> m2(m);
	printMap(m2);

	//赋值
	map<int, int> m3;
	m3 = m2;
	printMap(m3);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  66 map容器-大小和交换    *******//////////
/*
#include<iostream>
#include<map>
using namespace std;

void printMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << "   value = " << it->second << endl;
	}
	cout << endl;
}

//大小
void test01()
{
	map<int, int> m;
	
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(4, 40));

	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为：" << m.size() << endl;
		printMap(m);
	}
}

//交换
void test02()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(4, 40));

	map<int, int> m2;
	m2.insert(pair<int, int>(5, 100));
	m2.insert(pair<int, int>(6, 300));
	m2.insert(pair<int, int>(7, 200));
	m2.insert(pair<int, int>(8, 400));

	cout << "交换前：" << endl;
	printMap(m);
	printMap(m2);

	cout << "----------------------" << endl;
	cout << "交换后：" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********  67 map容器-插入和删除    *******//////////
/*
#include<iostream>
#include<map>
using namespace std;

void printMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << "   value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int> m;

	//插入
	//第一种
	m.insert(pair<int, int>(1, 10));

	//第二种
	m.insert(make_pair(2, 20));

	//第三种  不建议用
	m.insert(map<int, int>::value_type(3, 30));

	//第四种  不建议用
	m[4] = 40;

	//不建议用[ ]插入，但是可以利用key访问value（主要用途）
	//cout << m[4] << endl;

	printMap(m);

	//删除
	m.erase(m.begin());		//删除迭代器所指位置的数据
	printMap(m);

	m.erase(3);		//按照key删除，删除key=3的数据
	printMap(m);
	
	m.erase(m.begin(), m.end());		//删除区间
	printMap(m);

	//清空
	m.clear();
	printMap(m);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  68 map容器-查找和统计    *******//////////
//		find(key)		//查找key是否存在，若存在返回该键的元素的迭代器；若不存在返回map.end()
//		count(key)		//统计key的元素个数，对于map而言无非是0或1。multimap容器可能返回别的int值
/*
#include<iostream>
#include<map>
using namespace std;

void test01()
{
	//查找
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(3, 40));			//map不允许插入重复的key的元素

	map<int, int>::iterator pos = m.find(2);		//返回迭代器
	if (pos != m.end())
	{
		cout << "查到了元素：key = " << pos->first << "   value = " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	int num = m.count(3);		//map无非是0或1
	cout << "num = " << num << endl;
	//multimap的count可能大于1
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  69 map容器-排序    *******//////////
//map默认按照key值从小到大排序
//总结：
//		利用仿函数可以指定map容器的排序规则
//		对于自定义数据类型，map必须要制定排序规则，同set容器
/*
#include<iostream>
#include<map>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class myCompare
{
public:
	bool operator()(int val1, int val2) const
	{
		return val1 > val2;		//降序
	}
};

class comparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_age > p2.m_age;			//按照年龄降序
	}
};

//内置类型排序
void test01()
{
	map<int, int, myCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(3, 20));
	m.insert(make_pair(5, 30));
	m.insert(make_pair(2, 40));
	m.insert(make_pair(4, 50));
	
	for (map<int, int, myCompare>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "   value = " << it->second << endl;
	}
	cout << endl;
}

//自定义类型排序
void test02()
{
	map<Person, int, comparePerson> m;

	//创建Person对象
	Person p1("刘备", 35);
	Person p2("关羽", 30);
	Person p3("张飞", 25);
	Person p4("赵云", 40);

	m.insert(make_pair(p1, 1));
	m.insert(make_pair(p2, 2));
	m.insert(make_pair(p3, 3));
	m.insert(make_pair(p4, 4));

	for (map<Person, int, myCompare>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "姓名：" << it->first.m_name << "   年龄：" << it->first.m_age << "   编号为：" << it->second << endl;
	}
	cout << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********   70 STL案例2-员工分组    *******//////////
//公司今天招了10个员工(ABCDEFGHIJ), 10名员工进入公司之后，需要指派员工在哪个部门工作
//员工信息有：姓名、工资组成；部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key（部门编号）、value（员工）
//分部门显示员工信息
/*
#include<iostream>
#include<map>
#include<vector>
#include<ctime>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_name;
	int m_salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];

		worker.m_salary = rand() % 10000 + 10000;		//10000~19999

		v.push_back(worker);		//将员工放入容器中
	}
}

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随即部分编号
		int deptID = rand() % 3;		//产生0 1 2三个随机数代表部门编号
		
		//将员工插入到分组中
		//key代表部门编号，value代表具体员工
		m.insert(make_pair(deptID, *it));
	}
}

//分组显示
void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);		//统计策划部门具体人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "   工资：" << pos->second.m_salary << endl;
	}

	cout << "---------------------------------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);		//统计策划部门具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "   工资：" << pos->second.m_salary << endl;
	}

	cout << "---------------------------------------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);		//统计策划部门具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "   工资：" << pos->second.m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	//1、创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);

	//2、员工分组
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	//3、分组显示员工
	showWorkerByGroup(mWorker);

	system("pause");
	return 0;
}
*/





////////********   STL案例2-员工分组（自写）    *******//////////
//公司今天招了10个员工(ABCDEFGHIJ), 10名员工进入公司之后，需要指派员工在哪个部门工作
//员工信息有：姓名、工资组成；部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key（部门编号）、value（员工）
//分部门显示员工信息
/*
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_name;
	int m_salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];

		worker.m_salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptID = rand() % 3;
		m.insert(make_pair(deptID, *it));
	}
}

void showWorker(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;
	int count = m.count(CEHUA);
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	for (int index = 0; index < count && pos != m.end(); pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "   工资：" << pos->second.m_salary << endl;
	}

	cout << "--------------------------------------------" << endl;
	cout << "美术部门" << endl;
	count = m.count(MEISHU);
	pos = m.find(MEISHU);
	for (int index = 0; index < count && pos != m.end(); pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "   工资：" << pos->second.m_salary << endl;
	}

	cout << "--------------------------------------------" << endl;
	cout << "研发部门" << endl;
	count = m.count(YANFA);
	pos = m.find(YANFA);
	for (int index = 0; index < count && pos != m.end(); pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "   工资：" << pos->second.m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Worker> vworker;
	createWorker(vworker);			//创建员工

	multimap<int, Worker> mworker;
	setGroup(vworker, mworker);			//员工分组

	showWorker(mworker);			//显示员工

	system("pause");
	return 0;
}
*/


   

//函数对象概念：
//		重载函数调用操作符的类，其对象常称为函数对象
//		函数对象使用重载的()时，行为类似函数调用，也叫仿函数
// 本质：
//		函数对象（仿函数）是一个类，不是一个函数

////////********  71 函数对象-函数对象基本使用    *******//////////
//特点：
//		函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//		函数对象超出普通函数的概念，函数对象可以有自己的状态
//		函数对象可以作为参数传递
/*
#include<iostream>
#include<string>
using namespace std;

class MyAdd
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};

//1、函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

//2、函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}

	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}

	int count;		//内部自己状态
};

void test02()
{
	MyPrint myPrint;
	myPrint("hello World!");
	myPrint("Liu!");
	myPrint("yes");
	cout << "myPrint调用次数为：" << myPrint.count << endl;
}

//3、函数对象可以作为参数传递
void doPrint(MyPrint &mp,string test)
{
	mp(test);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
*/





////////********   72 谓词-一元谓词   *******//////////
//概念：
//		返回bool类型的仿函数称为谓词
//		如果operator()接受一个参数，那么叫做一元谓词
//		如果operator()接受两个参数，那么叫做二元谓词
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中有没有大于5的数字
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());			//GreaterFive()匿名函数对象
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5的数字为：" << *it << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  73 谓词-二元谓词    *******//////////
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//二元谓词
class myCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//使用函数对象，改变算法策略，变为排序规则从大到小
	sort(v.begin(), v.end(), myCompare());
	cout << "---------------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//内建函数
//概念：STL内建了一些函数对象
//分类：算数仿函数、关系仿函数、逻辑仿函数
//用法：
//		这些仿函数所产生的对象，用法和一般函数完全相同
//		使用内建函数对象，需要引入头文件 #include<functional>

////////********   74 内建函数对象-算数仿函数    *******//////////
//功能描述：
//		实现四则运算
//		其中negate是一元运算，其他都是二元运算
// negate(取反)  plus  minus  multiplies  divides  modulus(取模)
/*
#include<iostream>
#include<functional>			//内建函数对象头文件
using namespace std;

//negate 一元仿函数 取反仿函数
void test01()
{
	negate<int> n;
	cout << n(50) << endl;
}

//plus 二元仿函数 加法
void test02()
{
	plus<int> p;

	cout << p(10, 20) << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
*/





////////********  75 内建函数对象-关系仿函数    *******//////////
//equal_to    not_equal_to   greater   greater_equal    less    less_equal
/*
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//降序
	//greater<int>()		内建函数对象
	sort(v.begin(), v.end(), greater<int>());
	cout << "-------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  76 内建函数对象-逻辑仿函数   *******//////////
//  logical_and 逻辑与       logical_or 逻辑或     logical_not 逻辑非
/*
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//利用逻辑非 将容器v搬运到容器v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v.size());			//先将空间开辟好

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//常用算法 概述：
//		算法主要是由头文件<algorithm> <functional> <numeric>组成
//		<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
//		<numeric	>体积很小，只包括几个在序列上面进行简单数学运算的函数模板
//		<functional>定义了一些模板类，用以声明函数对象

////////********  77 常用遍历算法-for_each    *******//////////
//函数原型：
//		for_each(iterator beg, iterator end, _func);
//		遍历算法 遍历容器元素
//		beg开始迭代器    end结束迭代器    _func函数或者函数对象
//总结：
//		for_each在实际开发中是最常用的遍历算法，需要熟练掌握
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//普通函数
void print01(int val)
{
	cout << val << "  ";
}

//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print01);		//普通函数  传的是函数名
	cout << endl;

	for_each(v.begin(), v.end(), print02());		//仿函数  传的是匿名函数对象
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   78 常用遍历算法-transform   *******//////////
// 函数原型：
//		transform(iterator beg1, iterator end1, iterator beg2, _func)
//		beg1源容器开始迭代器
//		end1源容器结東迭代器
//		beg2目标容器开始迭代器
//		_func函数或者函数对象
//	总结：
//		搬运的目标容器必须要提前开辟空间，否则无法正常搬运
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Transform
{
public:
	int operator()(int v)
	{
		return 2 * v;
	}
};

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << ' ';
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vtarget;
	vtarget.resize(v.size());			//目标容器需要提前开辟空间

	transform(v.begin(), v.end(), vtarget.begin(), Transform());		//传入匿名函数对象
	for_each(vtarget.begin(), vtarget.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  79 常用查找算法-find    *******//////////
//	功能描述：
//		查找指定元素，找到返回指定元素的迭代器，找不到返回结束送代器end()
//	函数原型：
//		find(iterator beg, iterator end, value);
//		按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//		beg开始迭代器
//		end结束迭代器
//		value查找的元素
//查找自定义数据类型，要重载==
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//查找内置数据类型
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找是否有5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到：" << *it << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	//重载==  让底层find知道如何对比person数据类型
	bool operator==(const Person &p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_name;
	int m_age;
};

//查找自定义数据类型
void test02()
{
	vector<Person> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person test_person("bbb", 10);

	vector<Person>::iterator it = find(v.begin(), v.end(), test_person);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到！姓名：" << it->m_name << "   年龄：" << it->m_age << endl;
	}
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/




////////********   80 常用查找算法-find_if   *******//////////
//	功能描述：
//		按条件查找元素
//	函数原型：
//		find_if(iterator beg, iterator end, _Pred);
//		按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//		beg开始迭代器
//		end结束迭代器
//		_Pred函数或者谓词(返回bool类型的仿函数)
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//1、查找内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到！数字为：" << *it << endl;
	}
}

//2、查找自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class Greater20
{
public:
	bool operator()(const Person &p)
	{
		//if (p.m_age > 20)
		//{
		//	return true;
		//}
		//else
		//{
		//	return false;
		//}
		return p.m_age > 20;
	}
};

void test02()
{
	vector<Person> v;
	
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//找年龄大于20的人
	vector<Person>::iterator it = find_if(v. begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到！年龄：" << it->m_name << "  年龄：" << it->m_age << endl;
	}
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********   81 常用查找算法-adjacent_if    *******//////////
//	功能描述：
//		查找相邻重复元素
//	函数原型：
//		adjacent_find(iterator beg, iterator end);
//		查找相邻重复元素，返回相邻元素的第一个位置的迭代器
//		beg开始迭代器
//		end结東迭代器
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void test01()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	v.push_back(6);
	v.push_back(5);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "没有找到相邻重复元素！" << endl;
	}
	else
	{
		cout << "找到相邻重复元素！数字为：" << *it << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  82 常用查找算法-binary_search    *******//////////
// 二分查找法，效率高速度快
//	功能描述：
//		查找指定元素是否存在
//	函数原型：
//		bool binary_search(iterator beg, iterator end, value)
//		查找指定的元素，查到 返回true，否则false
//		beg开始迭代器
//		end结束迭代器
//		value查找的元素
//	注意：在无序列中不可用！
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//v.push_back(3);			如果是无序序列，结果未知！

	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   83 常用查找算法-count    *******//////////
//	功能描述：
//		统计元素个数
//	函数原型：
//		count(iterator beg, iterator end, value);
//		统计元素出现次数
//		beg开始迭代器
//		end结束迭代器
//		value统计的元素
//	总结：
//		统计自定义数据类型时，需要配合重载operator==
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//1、统计内置数据类型
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);

	int num = count(v.begin(), v.end(), 40);
	cout << "40的元素个数为：" << num << endl;
}

//2、统计自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	//	重载--
	bool operator==(const Person& p)
	{
		if (this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_name;
	int m_age;
};



void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);
	cout << "和诸葛亮同岁的人的个数为：" << num << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
*/




////////********    84 常用查找算法-count_if   *******//////////
//	功能描述：
//		按条件统计元素个数
//	函数原型：
//		count_if(iterator beg, iterator end, _Pred);
//		按条件统计元素出现次数
//		beg开始迭代器
//		end结束迭代器
//		_Pred谓词
/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1、统计内置数据类型
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);

	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "大于20的元素个数为：" << num << endl;
}

//2、统计自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class AgeGreater30
{
public:
	bool operator()(const Person &p)
	{
		return p.m_age > 30;
	}
};

void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//统计大于30岁人员个数
	int num = count_if(v.begin(), v.end(), AgeGreater30());
	cout << "年龄大于30岁的人数有：" << num << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
*/




//排序算法
//sort		对容器内元素进行排序
//random_shuffle		洗牌，指定范围内的元素随机调整次序
//merge		容器元素合并，并存储到零一容器中
//reverse		反转指定范围的元素

////////********   85 常用排序算法-sort   *******//////////
// sort		对容器内元素进行排序
//sort(iterator beg, iterator end, _Pred);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//_Pred谓词 或 内建的关系仿函数greater或less
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void myPrint(const vector<int> &v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);

	//默认升序
	sort(v.begin(), v.end());
	myPrint(v);

	//降序
	sort(v.begin(), v.end(), greater<int>());
	myPrint(v);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  86 常用排序算法-random_shuffle    *******//////////
// random_shuffle		洗牌，指定范围内的元素随机调整次序
//random_shuffle(iterator beg, iterator end);
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	cout << "------------------------" << endl;
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	system("pause");
	return 0;
}
*/




////////********   87 常用排序算法-merge   *******//////////
//merge		容器元素合并，并存储到零一容器中
// merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//注意：两个容器必须是有序的
//beg1 容器1开始迭代器			end1 容器1结束迭代器
//beg2 容器2开始迭代器			end2 容器2结束迭代器
//dest 目标容器开始迭代器
//总结：
//		merge合并的必须是有序序列，目标容器要提前开辟空间！！！
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v1;
	vector<int> v2;
	
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	//目标容器
	vector<int> vtarget;
	vtarget.resize(v1.size()+v2.size());		//记得提前分配空间！！！

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********  88 常用排序算法-reverse    *******//////////
//reverse		反转指定范围的元素
//reverse(iterator beg, iterator end);
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	cout << "---------------" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




//拷贝和替换算法
// copy			容器内指定范围的元素拷贝到零一容器中
//	replace			将容器内指定范围的旧元素改为新元素
//	replace_if			容器内指定范围满足条件的元素替换为新元素
//	swap			互换两个容器的元素（必须同种类型的容器）

////////********  89 常用拷贝和替换算法-copy    *******//////////
// copy			容器内指定范围的元素拷贝到零一容器中
// copy(iterator beg, iterator end, iterator dest);
//	dest	目标起始迭代器
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v;
	vector<int> vtarget;

	v.push_back(10);
	v.push_back(30);
	v.push_back(60);

	vtarget.resize(v.size());			//开辟空间
	copy(v.begin(), v.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  90 常用拷贝和替换算法-replace    *******//////////
//	replace			将容器内指定范围的旧元素改为新元素
//replace(iterator beg, iterator end, oldvalue, newvalue);
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v;

	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	replace(v.begin(), v.end(), 20, 200);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   91 常用拷贝和替换算法-replace_if    *******//////////
//	replace_if			容器内指定范围满足条件的元素替换为新元素
// replace_if(iterator beg, iterator end, _pred, newvalue);
//	_pred 谓词			newvalue 替换的新元素
//总结：
//		replace_if 按条件查找，可以利用仿函数灵活筛选满足的条件
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << ' ';
	}
};

class Greater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//将大于等于30的替换为100
	replace_if(v.begin(), v.end(), Greater30(), 100);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





////////********   92 常用拷贝和替换算法-swap    *******//////////
//	swap			互换两个容器的元素（必须同种类型的容器）
// swap(container c1, container c2);
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << ' ';
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "交换前：" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl << endl;

	cout << "交换后：" << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//算数生成算法
//注意：
//		算数生成算法属于小型算法，使用前包含的头文件为 #include<numeric>
//算法简介：
//		accumulate			计算容器元素累计求和
//		fill				向容器中添加元素

////////********  93 常用算数生成算法-accumulate    *******//////////
//		accumulate			计算容器元素累计求和
//	accumulate(iterator beg, iterator end, value);
// value 起始的累加值
/*
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

void test01()
{
	vector<int> v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	//参数3 起始的累加值   不需要起始值的话写0即可
	int result = accumulate(v.begin(), v.end(), 0);
	cout << result << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   94 常用算数生成算法-fill   *******//////////
//		fill				向容器中添加元素
//	fill(iterator beg, iterator end, value);
//	value 填充的值
/*
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << ' ';
	}
};

void test01()
{
	vector<int> v;
	v.resize(5);			//目前容器内为5个0
	v.push_back(1);
	v.push_back(2);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//后期重新填充
	fill(v.begin(), v.end(), 9);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//常用集合算法
//	set_intersection		求两个容器的交集
//	set_union			求两个容器的并集
//	set_difference			求两个容器的差集

////////********   95 常用集合算法-set_intersection    *******//////////
//	set_intersection		求两个容器的交集
//	set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//	dest		目标容器的开始迭代器
//	注意：
//		两个集合必须是有序序列
//		目标容器开辟空间需要从两个容器中取小值
//		set_intersection返回值是 指向交集中最后一个元素位置的迭代器
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> vtarget;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);		// 0~9
		v2.push_back(i + 5);		// 5~14
	}

	//最特殊情况，大容器包含小容器
	vtarget.resize(min(v1.size(), v2.size()));

	//获取交集
	// 返回的是 指向交集中最后一个元素位置的迭代器
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());

	for_each(vtarget.begin(), itEnd, myPrint);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********  96  常用集合算法-set_union   *******//////////
//	set_union			求两个容器的并集
//	set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//	dest		目标容器的开始迭代器
//	注意：
//		两个集合必须是有序序列
//		目标容器开辟空间需要两个容器size相加
//		set_union返回值是 指向并集中最后一个元素位置的迭代器
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> vtarget;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i); 
		v2.push_back(i + 5);
	}

	//最特殊情况 两个容器无交集 并集就是两个容器size之和
	vtarget.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());

	for_each(vtarget.begin(), itEnd, myPrint);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********   97  常用集合算法-set_difference   *******//////////
//	set_difference			求两个容器的差集
//	set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//	dest		目标容器的开始迭代器
//注意：
//		差集是两个容器中不属于交集的部分
//		v1与v2的差集 和 v2与v1的差集是不同的！！！
//		求差集的两个容器必须是有序序列
//		目标容器的开辟空间需要从两个容器中取较大值
//		set_difference返回值是 指向差集中最后一个元素位置的迭代器
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << ' ';
}

void test01()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> vtarget;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);		// 0 1 2 3 4 5 6 7 8 9
		v2.push_back(i + 5);		// 5 6 7 8 9 10 11 12 13 14
	}

	//最特殊情况 两个容器没有交集 取两个容器中大的size作为目标容器开辟空间
	vtarget.resize(max(v1.size(), v2.size()));

	cout << "v1和v2的差集：" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), itEnd, myPrint);
	cout << endl << endl;

	cout << "v2和v1的差集：" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vtarget.begin());
	for_each(vtarget.begin(), itEnd, myPrint);
	cout << endl << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////////********      *******//////////
/*
#include<iostream>
using namespace std;

int main()
{


	system("pause");
	return 0;
}
*/




////////********      *******//////////
/*
#include<iostream>
using namespace std;

int main()
{


	system("pause");
	return 0;
}
*/



////////********      *******//////////
/*
#include<iostream>
using namespace std;

int main()
{


	system("pause");
	return 0;
}
*/




////////********      *******//////////
/*
#include<iostream>
using namespace std;

int main()
{


	system("pause");
	return 0;
}
*/
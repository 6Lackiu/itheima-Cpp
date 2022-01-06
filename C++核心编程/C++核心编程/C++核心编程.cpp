///////////   01程序的内存模型-内存四区-代码区



//////////   02程序的内存模型-内存四区-全局区
/*
#include<iostream>
#include<string>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量——全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
	//全局区
	//全局变量、静态变量、常量

	//创建普通局部变量
	int a = 10;
	int b = 10;
	cout << "局部变量a的地址为：" << (int)&a << endl;
	cout << "局部变量b的地址为：" << (int)&b << endl;

	//全局变量
	cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
	cout << "全局变量g_b的地址为：" << (int)&g_b << endl;

	//静态变量   在普通变量前加static，属于静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
	cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

	//常量
	//字符串常量
	cout << "字符串常量的地址为：" << (int)&"hello world" << endl;
	
	//const修饰的变量
	//const修饰的全局变量
	cout << "全局常量c_g_a的地址为：" << (int)&c_g_a << endl;
	cout << "全局常量c_g_b的地址为：" << (int)&c_g_b << endl;

	//const修饰的局部变量
	const int c_l_a = 10;    //c--const   g--global    l--local
	const int c_l_b = 10;
	cout << "局部常量c_l_a的地址为：" << (int)&c_l_a << endl;
	cout << "局部常量c_l_b的地址为：" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}
*/



//////////   03程序的内存模型-内存四区-栈区
//栈区：由编译器自动分配释放，存放函数的参数值、局部变量等
//注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
/*
#include<iostream>
#include<string>
using namespace std;
int* func(int b)  //形参数据也会放在栈区
{
	int a = 10;//局部变量  存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部变量地址

	b = 100;
}

int main()
{
	int* p = func(1);
	//不要这么做
	cout << *p << endl;  //第一次可以打印正确数据，是因为编译器做了保留
	cout << *p << endl;  //第二次数据就不保留了

	system("pause");
	return 0;
}
*/




//////////   04程序的内存模型-内存四区-堆区
//由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
//在C++中主要利用new在堆区开辟内存
/*
#include<iostream>
#include<string>
using namespace std;

int* func()
{
	//利用new关键字 可以将数据开辟到堆区
	//指针本身也是局部变量，放在栈上。指针保存的数据是放在堆区
	int* p = new int(10);   //new返回的是堆区的地址，用一个指针接收
	return p;
}

int main()
{
	//在堆区开辟数据
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}
*/





//////////   05程序的内存模型-new运算符
//C++中利用new操作符在堆区开辟数据
//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
/*
#include<iostream>
#include<string>
using namespace std;

//1、new的基本语法
int* func()
{
	int* p = new int(10);
	return p;
}

void test01()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区开辟的数据，由程序员手动开辟，手动释放
	//释放利用操作符delete
	delete p;
	//cout << *p << endl;   //内存已经被释放 再次访问就是非法操作，会报错
}

//2、在堆区利用new开辟数组


void test02()
{
	int* arr = new int[10];   //中括号10代表数组有10个元素

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放堆区数组
	//释放数组的时候，要加[ ]才可以
	delete[] arr;
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
 




//////////   06C++中的引用-引用的基本语法
//作用：给变量起别名
//语法：数据类型 &别名=原名
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}
*/





//////////   07C++中的引用-引用的注意事项
//引用必须初始化
//引用在初始化后，不可以改变
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 10;
	int c = 20;

	//int& b;  //未初始化 报错
	int& b = a; 

	//int& b = c;    //一旦初始化后，就不可以更改  报错

	b = c;  //赋值操作，而不是更改引用  把c赋值给b指向的内存

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}
*/





//////////   08C++中的引用-引用做函数参数
//作用：函数传参时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修改实参
/*
#include<iostream>
#include<string>
using namespace std;

//交换函数
//1、值传递
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01: a=" << a << "\tb=" << b << endl;
}

//2、地址传递
void swap02(int* c, int* d)
{
	int temp = *c;
	*c = *d;
	*d = temp;
	cout << "swap02: c=" << *c << "\td=" << *d<< endl;
}

//3、引用传递
void swap03(int& e, int& f)
{
	int temp = e;
	e = f;
	f = temp;
	cout << "swap03: e=" << e << "\tf=" << f << endl;
}

int main()
{
	int a = 10, b = 20;
	swap01(a, b);
	cout << "main: a=" << a << "\tb=" << b << endl << endl;

	int c = 10, d = 20;
	swap02(&c, &d);
	cout << "main: c=" << c << "\td=" << d << endl << endl;

	int e = 10, f = 20;
	swap03(e, f);   //引用传递，形参也会修饰实参
	cout << "swap03: e=" << e << "\tf=" << f << endl;

	system("pause");
	return 0;
}
*/




//////////   09C++中的引用-引用做函数返回值
//作用：引用是可以作为函数的返回值存在的
//注意：不要返回局部变量引用
//用法：函数调用作为左值
/*
#include<iostream>
#include<string>
using namespace std;

//1、不要返回局部变量引用
int& test01()
{
	int a = 10;  //局部变量存放在四区中的栈区
	return a;
}

//2、函数的调用可以作为左值
int& test02()
{
	static int a = 10;   //静态变量 存放在全局区 全局区上的数据在程序结束后系统释放
	return a;
}

int main()
{
	int& ref = test01();
	cout << "ref=" << ref << endl;  //第一次结果对 是因为编译器做了保留
	cout << "ref=" << ref << endl;  //第二次结果错误 因为a的内存已经释放
	cout << endl;

	int& ref2 = test02();
	cout << "ref2=" << ref2<< endl;
	cout << "ref2=" << ref2 << endl;

	test02() = 1000;   //如果函数的返回值是引用，这个函数调用可以做为左值
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;

	system("pause");
	return 0;
}
*/





//////////   10C++中的引用-引用的本质
//引用的本质在C++内部实现是一个指针常量
/*
#include<iostream>
#include<string>
using namespace std;

//发现是引用，转换为 int* const ref=&a
void func(int& ref)
{
	ref = 100;   //ref是引用，转换为*ref=100
}

int main()
{
	int a = 10;
	
	//自动转换为 int* const ref=&a；指针常量是指针指向不可以改，也说明为什么引用不可以更改
	int& ref = a;
	ref = 20;   //内部发现ref是引用，自动帮我们转换为：*ref=20；

	cout << "a=" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	cout << "a=" << a << endl;
	cout << "ref:" << ref << endl;

	system("pause");
	return 0;
}
*/




//////////   11C++中的引用-常量引用
//常量引用主要用来修饰形参，防止误操作
/*
#include<iostream>
#include<string>
using namespace std;

void showValue(const int& val)
{
	//val = 1000;  //形参加入const后，不允许修改  报错
	cout << "val=" << val << endl;
}

int main()
{
	//int& ref = 10;   //引用必须引一块合法的内存空间  报错
	//加上const之后，编译器优化代码为： int temp=10; const int& ref=temp;
	const int& ref1 = 10;
	//ref = 20;  //加入const之后变为可读，不可以修改  报错

	int a = 100;
	showValue(a);
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}
*/




//////////   12函数高级-函数的默认参数
//在C++中，函数的形参列表中的形参是可以有默认值的
/*
#include<iostream>
#include<string>
using namespace std;

//如果我们自己传入数据，就用自己的数据，反之用默认值
int func(int a,int b=20,int c=30)
{
	return a + b + c;
}

//注意事项：
//1、如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//int func2(int a, int b = 20, int c)
//{
//	return a + b + c;
//}

//2、如果函数声明有默认参数，那么函数实现就不能有默认参数。声明和实现只能有一个有默认参数
//int func3(int a = 10, int b = 10);  //声明
//func3(int a = 10, int b = 10)  //报错
//{
//	return a * b;
//}

int main()
{
	cout << func(10, 30) << endl;

	system("pause");
	return 0;
}
*/




//////////   13函数高级-函数的占位参数
//C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
//语法：返回值类型 函数名（数据类型）{ }
/*
#include<iostream>
#include<string>
using namespace std;

//目前阶段的占位参数我们还用不到，后面课程会用到
void func(int a,int)
{
	cout << "this is func" << endl;
}

//占位参数 还可以有默认参数
void func2(int = 50)
{
	cout << "this is func2" << endl;
}

int main()
{
	func(10, 20);
	func2();

	system("pause");
	return 0;
}
*/




//////////   14函数高级-函数重载-基本语法
//作用：函数名可以相同，提高复用性
//函数重载满足条件：
//1、同一个作用域下
//2、函数名称相同
//3、函数参数类型不同 或者 个数不同 或者 顺序不同
//注意：函数的返回值不可以作为函数重载的条件
/*
#include<iostream>
#include<string>
using namespace std;

//函数重载满足条件：
//1、同一个作用域下
//2、函数名称相同
//3、函数参数类型不同 或者 个数不同 或者 顺序不同
void func()
{
	cout << "func的调用" << endl;
}

void func(int a)  //参数个数不同
{
	cout << "func(int a)的调用" << endl;
}

void func(double a)  //参数类型不同
{
	cout << "func(double a)的调用" << endl;
}

void func(int a, double b)  //参数顺序不同
{
	cout << "func(int a, double b)的调用" << endl;
}

void func(double a, int b)  //参数顺序不同
{
	cout << "func(double a, int b)的调用" << endl;
}

//注意：函数的返回值不可以作为函数重载的条件
//int func(double a, int b)   //报错
//{
//	cout << "func(double a, int b)的调用" << endl;
//}

int main()
{
	func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);

	system("pause");
	return 0;
}
*/




//////////   15函数高级-函数重载-注意事项
//引用作为重载条件
//函数重载碰到函数默认参数
/*
#include<iostream>
#include<string>
using namespace std;

//函数重载的注意事项
//1、引用作为重载条件
void func(int& a)
{
	cout << "func(int& a)的调用" << endl;
}

void func(const int& a)
{
	cout << "func(const int& a)的调用" << endl;
}

//2、函数重载碰到函数默认参数
void func2(int a)
{
	cout << "func2(int a)的调用" << endl;
}

void func2(int a, int b=10)
{
	cout << "func2(int a, int b=10)的调用" << endl;
}

int main()
{
	int a = 10;
	func(a);   //调用无const
	func(10);   //调用const
	cout << endl;

	//func2(10);   //当函数重载碰到默认参数，出现二义性，报错，应尽量避免这种情况，重载时就不要写默认参数
	func2(10, 20);

	system("pause");
	return 0;
}
*/




//C++面向对象的三大特性为：封装、继承、多态
//C++认为万事万物都皆为对象，对象上有其属性和行为

//////////   16类和对象-封装-属性和行为作为整体
//封装的意义：
//1、将属性和行为作为一个整体，表现生活中的事物
//2、将属性和行为加以权限控制
/*
#include<iostream>
#include<string>
using namespace std;
const double PI = 3.14;

//设计一个圆类，求圆的周长
//class代表设计一个类
class Circle
{
	//访问权限
	//公共权限
public:
	//属性
	int m_r;  //半径
	//行为
	double calZC()  //获取圆的周长
	{
		return 2 * PI * m_r;
	}
};

int main()
{
	//通过圆类创建具体的圆（对象）   
	Circle c1;   //实例化
	//给圆对象的属性进行赋值
	c1.m_r = 10;

	cout << "圆的周长为：" << c1.calZC() << endl;

	system("pause");
	return 0;
}
*/




//类中的属性和行为，我们统一称为成员
//属性 也称为成员属性、成员变量
//行为 也称为成员函数、成员方法

//////////  17类和对象-封装-案例-设计学生类
//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学上的姓名和学号
/*
#include<iostream>
#include<string>
using namespace std;

class Stu
{
public:
	string m_name;
	string m_id;

	void showInfo()
	{
		cout << "学生姓名为：" << m_name << '\t';
		cout << "学号为：" << m_id << endl;
	}

	//通过行为给属性赋值
	//给姓名、学号赋值   
	void setName(string name)
	{
		m_name = name;
	}
	void setID(string ID)
	{
		m_id = ID;
	}
};

int main()
{
	Stu s1;
	s1.m_name = "张三";
	s1.m_id = "001";
	s1.showInfo();

	Stu s2;
	s2.setName("李四");
	s2.setID("002");
	s2.showInfo();

	system("pause");
	return 0;
}
*/





//////////   18类和对象-封装-访问权限
//类在设计时，可以把属性和行为放在不同的权限下，加以控制
//访问权限有三种：
//1、public 公共权限：成员类内可以访问 类外可以访问
//2、protected 保护权限：成员类内可以访问 类外不可以访问  儿子也可以访问父亲中的保护内容
//3、private 私有权限：成员类内可以访问 类外不可以访问  儿子不可以访问父亲的私有内容
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
	//公共权限
public:
	string m_name;

	//保护权限
protected:
	string m_car;

	//私有权限
private:
	string m_password;

public:
	void func1()
	{
		m_name = "张三";
		m_car = "拖拉机";
		m_password = "123456";
	}

private:
	void func2()
	{
		cout << "yes" << endl;
	}
};

int main()
{
	Person p1;

	p1.m_name = "李四";
	//p1.m_car = "奔驰";   //保护权限内容，在类外访问不到
	//p1.m_password = "987";   //私有权限内容，在类外访问不到
	p1.func1();
	//p1.func2();   //私有权限内容，在类外访问不到

	system("pause");
	return 0;
}
*/




//////////   19类和对象-封装-C++中class和struct的区别
//在C++中struct和class的唯一区别就在于 默认的访问权限不同
//区别：
//1、struct默认权限为公共public
//2、class默认权限为私有private
/*
#include<iostream>
#include<string>
using namespace std;

class C
{
	int m_A;   //默认权限为私有
};

struct S
{
	int m_A;   //默认权限为公共
};

int main()
{
	C c1;
	//c1.m_A = 100;   //私有权限不可访问 报错

	S s1;
	s1.m_A = 100;

	system("pause");
	return 0;
}
*/




//////////   20类和对象-封装-成员属性私有化
//优点1、将所有成员属性设置为私有，可以自己控制读写权限
//优点2、对于写权限，我们可以检测数据的有效性
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//写姓名（设置姓名）
	void setname(string name)
	{
		m_name = name;
	}
	//读姓名（获取姓名）
	string getname()
	{
		return m_name;
	}

	//设置年龄
	void setage(int age)
	{
		if (age < 0 || age>150)
		{
			m_age = 0;
			cout << "您输入年龄有误！" << endl;
			return;
		}
		m_age = age;
	}

	//获取年龄
	int getage()
	{
		//m_age = 0;  //初始化为0岁
		return m_age;
	}

	//设置情人
	void setlover(string lover)
	{
		m_lover = lover;
	}

private:
	//姓名  可读可写
	string m_name;
	//年龄  可读可写 （如果想修改，年龄范围必须是0~150之间）
	int m_age;
	//情人  只写
	string m_lover;
};

int main()
{
	Person p;
	p.setname("张三");

	cout << "姓名为：" << p.getname() << endl;

	p.setage(20);
	cout << "年龄为：" << p.getage() << endl;

	p.setlover("李四");
	//cout << "情人为：" << p.m_lover << endl;   //m_lover为私有权限不可以访问 报错

	system("pause");
	return 0;
}
*/



//////////   21类和对象-封装-设计案例1-立方体类
//设计立方体类（Cube）
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等
/*
#include<iostream>
#include<string>
using namespace std;

class Cube
{
public:
	//行为
	//设置获取长宽高
	void setL(int length)
	{
		m_L = length;
	}
	int getL()
	{
		return m_L;
	}

	void setW(int width)
	{
		m_W = width;
	}
	int getW()
	{
		return m_W;
	}

	void setH(int height)
	{
		m_H = height;
	}
	int getH()
	{
		return m_H;
	}

	//获取立方体面积
	int getS()
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	//获取立方体体积
	int getV()
	{
		return m_L * m_W * m_H;
	}

	//利用成员函数判断两个立方体是否相等
	bool isSamebyClass(Cube &c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	//属性
	int m_L;
	int m_W;
	int m_H;
};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1,Cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(9);

	cout << "c1的面积为：" << c1.getS() << endl;
	cout << "c1的体积为：" << c1.getV() << endl;


	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//利用全局函数判断两个立方体是否相等
	bool result = isSame(c1, c2);
	if (result)
	{
		cout << "两个立方体相等" << endl;
	}
	else
	{
		cout << "两个立方体不相等" << endl;
	}

	//利用成员函数判断两个立方体是否相等
	bool result2 = c1.isSamebyClass(c2);
	if (result)
	{
		cout << "两个立方体相等" << endl;
	}
	else
	{
		cout << "两个立方体不相等" << endl;
	}

	system("pause");
	return 0;
}
*/



//在类中可以让另一个类作为本类中的成员
//////////   22类和对象-封装-设计案例2-点和圆关系
//设计一个圆形类（Cirlce）和一个点类（Point），并计算点和圆的关系
/*
#include<iostream>
#include<string>
using namespace std;
#include "point.h"
#include "circle.h"

//点类
//class Point
//{
//public:
//	void setX(int X)   //设置横坐标
//	{
//		m_pointX = X;
//	}
//	int getX()   //获取横坐标
//	{
//		return m_pointX;
//	}
//
//	void setY(int Y)   //设置横坐标
//	{
//		m_pointY = Y;
//	}
//	int getY()   //获取横坐标
//	{
//		return m_pointY;
//	}
//
//
//private:
//	int m_pointX;
//	int m_pointY;
//};

//圆类
//class Circle
//{
//public:
//	void setCenter(Point center)   //设置圆心
//	{
//		m_Center = center;
//	}
//	Point getCenter()   //获取圆心
//	{
//		return m_Center;
//	}
//
//	void setR(int R)   //设置半径
//	{
//		m_R = R;
//	}
//	int getR()   //获取半径
//	{
//		return m_R;
//	}
//
//private:
//	int m_R;
//
//	//在类中可以让另一个类作为本类中的成员
//	Point m_Center;  //圆心
//};

void Info(Circle& c, Point& p)   //判断点和圆的关系
{
	int dis2 = pow(c.getCenter().getX() - p.getX(), 2) + pow(c.getCenter().getY() - p.getY(), 2);  //点与圆心距离的平方
	if (dis2 == pow(c.getR(), 2))
	{
		cout << "点在圆上" << endl;
	}
	else if (dis2 > pow(c.getR(), 2))
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	Circle c;
	Point center;
	center.setX(0);
	center.setY(0);
	c.setCenter(center);
	c.setR(10);

	Point p;
	p.setX(3);
	p.setY(4);

	cout << "圆心坐标为：" << "(" << c.getCenter().getX() << "," << c.getCenter().getY() << ")" << "   ";
	cout << "圆的半径为：" << c.getR() << endl;
	cout << "点的坐标为：" << "(" << p.getX() << "," << p.getY() << ")" << endl;
	Info(c, p);

	system("pause");
	return 0;
}
*/





////*********   23类和对象-对象特性-构造函数和析构函数   ***********
//构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用
//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作

//构造函数语法：类名( ){ }
//1.构造函数，没有返回值也不写void
//2.函数名称与类名相同
//3.构造函数可以有参数，因此可以发生重载
//4.程序在调用对象时会自动调用构造，无须手动调用，而且只会调用一次

//析构函数语法：~类名( ){ }
//1.析构函数，没有返回值也不写void
//2.函数名称与类名相同，在名称前加上符号~
//3.析构函数不可以有参数，因此不可以发生重载
//4.程序在调用对象时会自动调用析构，无须手动调用，而且只会调用一次
/*
#include<iostream>
#include<string>
using namespace std;

//对象的初始化和清理
class Person
{
public:
	//1、构造函数 进行初始化操作
	Person()
	{
		cout << "Person构造函数的调用" << endl;
	}

	//2、析构函数 进行清理操作
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
};

//构造和析构函数都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01()
{
	Person p;   //在栈上的数据，test01执行完毕后，释放这个对象
}

int main()
{
	test01();
	cout << endl;
	Person p;

	system("pause");
	return 0;
}
*/





/////*******   24类和对象-对象特性-构造函数的分类以及调用   ********
//两种分类方式：
//1.按参数分为：有参构造和无参构造
//2.按类型分为：普通构造和拷贝构造
//三种调用方式：
//1.括号法
//2.显示法
//3.隐式转换法
/*
#include<iostream>
#include<string>
using namespace std;

//构造函数的分类及调用
//分类
class Person
{
public:
	Person()
	{
		cout << "Person的无参构造（默认构造）函数调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int age;
};

//调用
void test01()
{
	//括号法
	//Person p1;   //默认构造函数的调用
	//Person p2(10);   //有参构造函数的调用
	//Person p3(p2);   //拷贝构造函数的调用

	//注意事项1
	//调用默认构造函数时，不要加( )
	//因为下面这行代码，编译器会认为是一个函数的声明，所以不会认为在创建对象
	//Person p1();

	//cout << "p2的年龄为：" << p2.age << endl;
	//cout << "p3的年龄为：" << p3.age << endl;


	//显示法
	//Person p1;   //默认构造函数的调用
	//Person p2 = Person(10);   //有参构造函数的调用
	//Person p3 = Person(p2);   //拷贝构造函数的调用
	//等号右边例如Person(10)是一个匿名对象。特点：当前执行结束后，系统会立即回收掉匿名对象

	//注意事项2
	//不要利用拷贝构造函数初始化匿名对象
	//Person(p2);   //编译器会认为Person(p2)==Person p2，这是对象的声明，与上面重复  报错


	//隐式转换法
	Person p4 = 10;    //相当于Person p4=Person(10);     //有参构造函数的调用
	Person p5 = p4;    //拷贝构造函数的调用
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////***********   25类和对象-对象特性-拷贝构造函数调用时机   *********
//1、使用一个已经创建完毕的对象来初始化一个新对象
//2、值传递的方式给函数参数传值
//3、以值方式返回局部对象
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age)
	{
		m_age = age;
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_age;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << endl;
}

//2、值传递的方式给函数参数传值
void doWork(Person p)   //值传递的本质是拷贝一份数据 这其实也是拷贝构造函数
{

}

void test02()
{
	Person p;
	doWork(p);
}

//3、以值方式返回局部对象
Person doWork2()
{
	Person p1;   //当doWork2执行完后p1就被析构了
	cout << (int)&p1 << endl;
	return p1;   //这里返回的不是p1而是复制的一个数据副本，相当于拷贝，因此会调用拷贝构造函数
}

void test03()
{
	Person p = doWork2();
	cout << (int)&p << endl;
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





///***********   26类和对象-对象特性-构造函数调用规则   *********
//默认情况下，C++编译器至少给一个类添加3个函数
//1.默认构造函数（无参，函数体为空）
//2.默认析构函数（无参，函数体为空）
//3.默认拷贝函数，对属性进行值拷贝

//构造函数调用规则如下：
//如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
//如果用户定义拷贝构造函数，C++就不会再提供其他构造函数
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age)
	{
		m_age = age;
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_age;
};

void test01()
{
	Person p;
	p.m_age = 18;

	Person p2(p);
	cout << "p2的年龄为：" << p2.m_age << endl;
}

void test02()
{
	Person p(20);
	Person p2(p);
	cout << "p2的年龄为：" << p2.m_age << endl;
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





///********   27类和对象-对象特性-深拷贝和浅拷贝   ********
//深浅拷贝是面试经典问题，也是常见的一个坑
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作
//注意：如果有属性在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height);   //new返回的是指针
		cout << "Person的有参构造函数调用" << endl;
	}

	//自己实现拷贝函数，解决浅拷贝带来的内存重复释放问题
	Person(const Person& p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;  //编译器默认实现就是这行代码
		//实现深拷贝操作
		m_height = new int(*p.m_height);   //相当于new int(160)，然后返回new出来的内存首地址
	}

	~Person()
	{
		//析构代码，将堆区开辟的数据释放操作
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18,160);
	cout << "p1的年龄为：" << p1.m_age << "   身高为：" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << "   身高为：" << *p2.m_height << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///********   28类和对象-对象特性-初始化列表   ***********
//作用：C++提供了初始化列表语法，用来初始化属性
//语法：构造函数( ) : 属性1(值1) , 属性2(值2) ... { }
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//传统初始化操作
	//Person(int a, int b, int c)
	//{
	//	m_a = a;
	//	m_b = b;
	//	m_c = c;
	//}

	//利用初始化列表初始化属性
	Person(int a,int b,int c) :m_a(a), m_b(b), m_c(c)
	{
		cout << "利用初始化列表初始化属性" << endl;
	}

	int m_a;
	int m_b;
	int m_c;
};

void test01()
{
	//Person p(10, 20, 30);

	Person p(5, 7, 9);
	cout << "m_a=" << p.m_a << endl;
	cout << "m_b=" << p.m_b << endl;
	cout << "m_c=" << p.m_c << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///*******   29类和对象-对象特性-类对象作为类成员   ***********
//C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
//当其他类的对象作为本类的成员，构造时先构造其他类的对象，再构造本类；析构顺序与构造顺序相反（因为栈先进后出）。
/*
#include<iostream>
#include<string>
using namespace std;

//类对象作为类成员
class Phone
{
public:
	Phone(string pname)
	{
		cout << "Phone构造函数调用" << endl;
		m_pname = pname;
	}

	~Phone()
	{
		cout << "Phone析构函数调用" << endl;
	}

	string m_pname;   //手机品牌名
};

class Person
{
public:
	//Phone m_phone=pname  隐式转换法
	Person(string name, string pname): m_name(name),m_phone(pname)
	{
		cout << "Person构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}

	//姓名
	string m_name;
	//手机
	Phone m_phone;
};

//当其他类的对象作为本类的成员，构造时候先构造其他类的对象，再构造自身；析构顺序与构造顺序相反
void test01()
{
	Person p("张三", "华为");
	cout << p.m_name << "用" << p.m_phone.m_pname << "手机" << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
//静态成员分为：
//		静态成员变量
//				所有对象共享同一份数据
//				在编译阶段分配内存（全局区）
//				类内声明，类外初始化
//		静态成员函数
//				所有对象共享同一个函数
//				静态成员函数只能访问静态成员变量

///***********   30类和对象-对象特性-静态成员变量   **********
/*
#include<iostream>
#include<string>
using namespace std;

//静态成员变量
class Person
{
public:

	//1.所有对象都共享同一份数据
	//2.在编译阶段分配内存（全局区）
	//3.类内声明，类外初始化
	static int m_a;

	//静态成员变量也有访问权限
private:
	static int m_b;
};

int Person::m_a = 100;
int Person::m_b = 50;

void test01()
{
	Person p;
	cout << p.m_a << endl;

	Person p2;
	p2.m_a = 200;
	cout << p.m_a << endl;   //用p2更改数据，但还是用p访问输出。可以说明数据是共享的
}

void test02()
{
	//静态成员变量不属于某个对象上，因为所有对象都共享同一份数据
	//因此静态变量有两种访问方式
	//1、通过对象进行访问
	Person p;
	cout << p.m_a << endl;
	//2、通过类名进行访问
	cout << Person::m_a << endl;

	//cout << Person::m_b << endl;   //私有权限下类外不可访问 报错
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/





///***********   31类和对象-对象特性-静态成员函数   **********
//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
/*
#include<iostream>
#include<string>
using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person
{
public:
	static void func()
	{
		m_a = 100;  //静态成员函数可以访问静态成员变量
		//m_b = 200;    //静态成员函数不可以访问非静态成员变量

		cout << "static void func( )的调用" << endl;
	}

	static int m_a;  //静态成员变量
	int m_b;  //非静态成员变量

	//静态成员函数也有访问权限
private:
	static void func2()
	{
		cout << "static void func2( )的调用" << endl;
	}
};

int Person::m_a = 0;

//有两种访问方式
void test01()
{
	//1、通过对象访问
	Person p;
	p.func();

	//2、通过类名访问
	Person::func();

	//Person::func2();  //类外访问不到私有权限下的静态成员函数 报错
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///**********   32类和对象-对象特性-成员变量和成员函数分开存储   ***********
//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//只有非静态成员变量才属于类的对象上
	int m_a;  //非静态成员变量  属于类的对象上
	static int m_b;  //静态成员变量  不属于类的对象上

	void func()   //非静态成员函数  不属于类的对象上
	{

	}
	
	static void func2()   //静态成员函数  不属于类的对象上
	{

	}
};

int Person::m_b = 1;

void test01()
{
	Person p;

	//空对象占用的内存空间为1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "size of p=" << sizeof(p) << endl;
}

void test02()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}


int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/





///*********   33类和对象-对象特性-this指针的用途   *************
//this指针指向被调用的成员函数所属的对象
//this指针是隐含在每一个非静态成员函数内的一种指针。this指针不需要定义，直接使用即可。
//this指针的用途：
//		在形参和成员变量同名时，可用this指针来区分
//		在类的非静态成员函数中返回对象本身，可使用return* this
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		//this指针指向的是 被调用的成员函数所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person &p)   //如果这里返回值类型不是Person&而是Person，则相当于用值的方式返回，这符合拷贝构造函数的调用时机，因此返回的是一个拷贝的值而不是本体对象
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

//用途
//1、当形参和成员变量同名时，解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的年龄为：" << p1.age << endl;
}

//2、返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(20);
	Person p3(30);

	p2.PersonAddAge(p1);
	cout << "p2的年龄为：" << p2.age << endl;

	//链式编程思想
	p3.PersonAddAge(p1).PersonAddAge(p2);
	cout << "p3的年龄为：" << p3.age << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/




///*******   34类和对象-对象特性-空指针访问成员函数   *************
//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性
/*
#include<iostream>
#include<string>
using namespace std;

//空指针调用成员函数
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		//报错原因是传入的指针为NULL
		//cout << "age=" << m_age << endl;  //相当于cout << "age=" << this->m_age << endl; 
		
		if (this == NULL)  //提高代码健壮性
		{
			return;
		}
		cout << "age=" << m_age << endl;
	}

	int m_age;
};

void test01()
{
	Person* p = NULL;

	p->showClassName();
	p->showPersonAge();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///********   35类和对象-对象特性-const修饰成员函数   ***********
//常函数：
//		成员函数后加const后我们称这个函数为常函数
//		常函数内不可以修改成员属性
//		成员属性声明时加关键字mutable后，在常函数中依然可以修改
//常对象：
//		声明对象前加const称该对象为常对象
//		常对象只能调用常函数
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//this指针的本质是指针常量  指针的指向是不可以修改的
	//在成员函数后加const，修饰的是this指针，让指针指向的值也不可以修改
	//const Person* const this;
	void showPerson() const
	{
		//this->m_a = 100;   //报错
		this->m_b = 100;
	}

	void func()
	{
		m_a = 100;
	}
	
	int m_a;
	mutable int m_b;   //特殊变量，即使在常函数中，也可以修改这个值。要加mutable关键字
};

void test01()
{
	Person p;
	p.showPerson();
}

//常对象
void test02()
{
	const Person p;   //在对象前加const，变为常对象
	//p.m_a = 100;   //报错
	p.m_b = 100;   //在常对象下也可以修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func();   //常对象不能调用普通成员函数，因为普通成员函数可以修改成员属性  报错
}

int main()
{


	system("pause");
	return 0;
}
*/





//友元的目的就是让一个函数或者类，访问另一个类中私有成员，关键字为friend
//友元的三种实现：
//		全局函数做友元
//		类做友元
//		成员函数做友元
///********   36类和对象-友元-全局函数做友元   ***********
/*
#include<iostream>
#include<string>
using namespace std;

//全局函数做友元
class Building
{
	//goodGay全局函数是Building类的友元，可以访问Building中的私有成员
	friend void goodGay(Building& building);

public:
	Building()
	{
		m_settingRoom = "客厅";
		m_bedRoom = "卧室";
	}


public:
	string m_settingRoom;

private:
	string m_bedRoom;
};

//全局函数
void goodGay(Building& building)
{
	cout << "好基友全局函数 正在访问：" << building.m_settingRoom << endl;
	cout << "好基友全局函数 正在访问：" << building.m_bedRoom << endl;    //访问私有成员，需要在Building类中声明friend
}

void test01()
{
	Building building;
	goodGay(building);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///************   37类和对象-友元-友元类   ***************
/*
#include<iostream>
#include<string>
using namespace std;

//类做友元
class Building;

class GoodGay
{
public:
	GoodGay();   //构造函数

	void visit();   //参观函数 访问building中的属性

	Building* building;
};

class Building
{
	//GoodGay类是本类的友元，可以访问本类中的私有成员
	friend class GoodGay;

public:
	Building();   //构造函数

public:
	string m_sittingRoom;

private:
	string m_bedRoom;
};

//类外写成员函数，和在类内写效果一样
Building::Building()
{
	m_sittingRoom = "客厅";
	m_bedRoom = "卧室";
}
GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;  //堆区

}

//类外实现成员函数
void GoodGay::visit()
{
	cout << "好基友类 正在访问：" << building->m_sittingRoom << endl;
	cout << "好基友类 正在访问：" << building->m_bedRoom << endl;   //友元访问私有成员
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///**********   38类和对象-友元-成员函数做友元   **********
/*
#include<iostream>
#include<string>
using namespace std;

//成员函数做友元
class Building;

class GoodGay
{
public:
	//类外实现成员函数
	GoodGay(); 
	void visit();   //让visit函数 可以 访问Building中私有成员
	void visit2();   //让visit2函数 不可以 访问Building中私有成员
	
	Building* building;
};

class Building
{
	//告诉编译器，GoodGay类下的visit成员函数作为本类的友元，可以访问本类的私有成员
	friend void GoodGay::visit();   //若不加 GoodGay:: 编译器会认为是全局函数

public:
	//类外实现成员函数
	Building(); 

public:
	string m_sittingRoom;
private:
	string m_bedRoom;
};

Building::Building()
{
	m_sittingRoom = "客厅";
	m_bedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit函数正在访问：" << building->m_sittingRoom << endl;
	cout << "visit函数正在访问：" << building->m_bedRoom << endl;   //成员函数作友元可以访问私有成员
}
void GoodGay::visit2()
{
	cout << "visit2函数正在访问：" << building->m_sittingRoom << endl;
	//cout << "visit2函数正在访问：" << building->m_bedRoom << endl;   //私有成员不能访问  报错
}

void test01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//运算重载符概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
///***********   39类和对象-C++运算符重载-加号运算符重载   ***********
//作用：实现两个自定义数据类型相加的运算
//总结1、对于内置的数据类型的表达式的运算符是不可以改变的
//总结2、不要滥用运算符重载
/*
#include<iostream>
#include<string>
using namespace std;

//加号运算符重载
class Person
{
public:
	//1、成员函数重载+号
	//Person operator+(Person& p)
	//{
	//	Person temp;
	//	temp.m_a = this->m_a + p.m_a;
	//	temp.m_b = this->m_b + p.m_b;
	//	return temp;
	//}

	int m_a;
	int m_b;
};

//2、全局函数重载+号
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_a = p1.m_a + p2.m_b;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

//函数重载的版本
Person operator+(Person& p, int num)
{
	Person temp;
	temp.m_a = p.m_a + num;
	temp.m_b = p.m_b + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 20;
	Person p2;
	p2.m_a = 30;
	p2.m_b = 40;

	//成员函数重载本质调用
	//Person p3 = p1.operator+(p2);
	//全局函数重载本质调用
	//Person p3 = operator+(p1, p2);

	Person p3 = p1 + p2;   //简化版本
	cout << "p3.m_a=" << p3.m_a << endl;
	cout << "p3.m_b=" << p3.m_b << endl;

	//运算符重载 也可以发生函数重载
	Person p4 = p1 + 100;
	cout << "p4.m_a=" << p4.m_a << endl;
	cout << "p4.m_b=" << p4.m_b << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///**********   40类和对象-C++运算符重载-左移运算符重载   **********
//作用：可以输出自定义数据类型
//总结：重载左移运算符配合友元可以实现输出自定义数据类型
/*
#include<iostream>
#include<string>
using namespace std;

//左移运算符重载
class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

private:
	//利用成员函数重载左移运算符
	//不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	//void operator<<(cout)
	//{

	//}

	int m_a;
	int m_b;
};

//只能利用全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p)  //本质operator<<(cout,p)  简化cout<<p
{
	cout << "m_a=" << p.m_a << "   m_b" << p.m_b;
	return cout;
}

void test01()
{
	Person p(10, 10);

	cout << p <<"   hello world" << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*********   41类和对象-C++运算符重载-递增运算符重载   ***********
//作用：通过重载递增运算符，实现自己的数据类型
//总结：：前置递增返回引用，后置递增返回值
/*
#include<iostream>
#include<string>
using namespace std;

//重载递增运算符
//自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_num = 0;
	}

	//重载前置递增运算符
	MyInteger& operator++()
	{
		//先进性++运算
		m_num++;
		//再将自身返回
		return *this;
	}

	//重载后置递增运算符
	//int代表占位参数，可以用于区分前置和后置递增
	//后置递增返回的是值，不是引用
	MyInteger operator++(int)
	{
		//先记录当时的结果
		MyInteger temp = *this;
		//再进行++运算
		m_num++;
		//最后将之前记录的结果返回
		return temp;
	}

private:
	int m_num;
};

//重载左移运算符  返回引用是为了一直对一个数据进行递增操作
//这里的MyInteger不加&的原因是，重载后置递增返回的是一个局部变量的值，
//因此如果加引用&相当于返回局部对象的引用，而在MyInteger operator++(int)这个构造函数执行完后局部对象temp就会被销毁，再return的话就是非法操作
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_num;
	return cout;
}

void test01()
{
	MyInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02()
{
	MyInteger myint;
	cout << myint++ << endl;   //C++不支持后置递增链式法则 也就是(a++)++会报错
	cout << myint << endl;
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




///*******   42类和对象-C++运算符重载-赋值运算符重载   *********
//C++编译器至少给一个类添加4个函数
//		1、默认构造函数（无参，函数体为空）
//		2、默认析构函数（无参，函数体为空）
//		3、默认拷贝构造函数，对属性进行只拷贝
//		4、赋值运算符operator=，对属性进行值拷贝
//如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
/*
#include<iostream>
#include<string>
using namespace std;

//赋值运算符重载
class Person
{
public:
	Person(int age)
	{
		m_age = new int(age);
	}
	~Person()   //在析构函数中释放堆区数据
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	//重载赋值运算符
	Person& operator=(Person& p)
	{
		 //编译器提供的是浅拷贝
		//m_age = p.m_age;

		//应该先判断是否有属性在堆区，如果有，先释放干净，然后再深拷贝
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);

		return *this;  //返回对象本身
	}

	int* m_age;
};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p2 = p1;   //赋值操作
	cout << "p1的年龄为：" << *p1.m_age << endl;
	cout << "p2的年龄为：" << *p2.m_age << endl << endl;

	p3 = p2 = p1;
	cout << "p1的年龄为：" << *p1.m_age << endl;
	cout << "p2的年龄为：" << *p2.m_age << endl;
	cout << "p3的年龄为：" << *p3.m_age << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///*******   43类和对象-C++运算符重载-关系运算符重载   *********
//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
/*
#include<iostream>
#include<string>
using namespace std;

//重载关系运算符
class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	//重载关系运算符==
	bool operator==(Person& p)
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//重载关系运算符!=
	bool operator!=(Person& p)
	{
		if (this->m_age != p.m_age || this->m_name != p.m_name)
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

void test01()
{
	Person p1("Tom", 18);
	Person p2("Tom", 19);

	if (p1 == p2)
	{
		cout << "p1与p2相等" << endl;
	}
	else
	{
		cout << "p1与p2不相等" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1与p2不相等" << endl;
	}
	else
	{
		cout << "p1与p2相等" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   44类和对象-C++运算符重载-函数调用运算符重载   *********
//函数调用运算符( )也可以重载
//由于重载后使用的方式非常像函数的调用，因此成为仿函数
//仿函数没有固定写法，非常灵活（返回值类型无要求，函数参数也无要求）
/*
#include<iostream>
#include<string>
using namespace std;

//函数调用运算符重载
class MyPrint
{
public:

	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void MyPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myprint;
	myprint("hello world");  //由于使用起来非常类似于函数调用，因此称为仿函数

	MyPrint02("hello world");  //普通的函数调用
}

void test02()
{
	MyAdd myadd;
	int result= myadd(10, 20);
	cout << "result=" << result << endl;

	//匿名函数对象
	//因为创建的对象使用完就被销毁了，没什么用，其实直接可以使用匿名对象
	cout << "MyAdd()(5,10)=" << MyAdd()(5, 10) << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/




//继承是面向对象的三大特征之一
///*******   45类和对象-继承-基本语法   ************
//继承的好处：减少代码重复
//语法：class 子类：继承方式 父类
//子类 也称为 派生类
//父类 也成为 基类
//派生类中的成员包含两大部分：一部分是从基类继承过来的，一部分是自己增加的成员
//从基类继承过来的表现其共性，而新增的成员体现了其个性
/*
#include<iostream>
#include<string>
using namespace std;

//普通实现页面
//Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void cotent()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//
////Python页面
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void cotent()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//
////C++页面
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void cotent()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};//

//继承实现页面
//公共页面类
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...（公共分类列表）" << endl;
	}
};

//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};
//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};
//C++页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01()   //测试代码不变
{
	Java ja;
	Python py;
	CPP cpp;

	cout << "Java下载视频界面如下：" << endl;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "---------------------------------------------" << endl;
	cout << "Python下载视频界面如下：" << endl;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "---------------------------------------------" << endl;
	cout << "C++下载视频界面如下：" << endl;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///*******   46类和对象-继承-继承方式   **********
////继承的语法：class 子类：继承方式 父类
//继承方式一共有三种：
//		公共继承
//		保护继承
//		私有继承
/*
#include<iostream>
#include<string>
using namespace std;

//继承方式
//		公共继承
class Base1
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_a = 10;   //父类中的公共权限成员 到子类中依然是公共权限
		m_b = 10;   //父类中的保护权限成员 到子类中依然是保护权限
		//m_c = 10;  //父类中的私有权限成员 子类访问不到 报错
	}
};

void test01()
{
	Son1 s1;
	s1.m_a = 100;   //公共权限成员 类内可以访问 类外不可以访问
	//s1.m_b = 100;  //到Son1中 m_b是保护权限 类内可以访问 类外访问不到 报错
}

//		保护继承
class Base2
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_a = 100;  //父类中的公共权限成员 到子类中变为保护权限
		m_b = 100;  //父类中的保护权限成员 到子类中依然为保护权限
		//m_c = 100;   //父类中的私有权限成员 子类访问不到 报错
	}
};

void test02()
{
	Son2 s1;
	//s1.m_a = 10;   //在Son2中，m_a变为保护权限，类外访问不到 报错
	//s1.m_b = 10;  //m_b为保护权限，类外访问不到 报错
}

//		私有继承
class Base3
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_a = 100;  //父类中的公共权限成员 到子类中变为私有权限成员
		m_b = 100;   //父类中的保护权限成员 到子类中变为私有权限成员
		//m_c = 100;   //父类中的私有权限成员 子类访问不到 报错
	}
};

void test03()
{
	Son3 s1;
	//s1.m_a = 10;  //到了Son3中，m_a变为私有成员，类外访问不到 报错
	//s1.m_b = 10;  //到了Son3中，m_a变为私有成员，类外访问不到 报错
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_a = 10;  //到了Son3中，m_a变为私有权限成员，类外不可访问 报错
		//m_b = 10;  //到了Son3中，m_b变为私有权限成员，类外不可访问 报错
	}
};

int main()
{

	system("pause");
	return 0;
}
*/




//利用开发人员命令提示工具查看对象模型
//跳转盘符
//跳转文件路径到具体路径下
//查看命名
//  c1 /d1 reportSingleClassLayout类名 文件名
//比如：D:\C++Projects\C++核心编程\C++核心编程>cl /d1 reportSingleClassLayoutSon "C++核心编程.cpp"

///*******   47类和对象-继承-继承中的对象模型   **********
//问题：从父类继承过来的成员，哪些属于子类对象？
//结论：父类中私有成员也是被子类继承下去了，只是被编译器隐藏后访问不到而已
/*
#include<iostream>
#include<string>
using namespace std;

//继承中的对象模型
class Base
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son :public Base
{
public:
	int m_d;
};

//利用开发人员命令提示工具查看对象模型
//跳转盘符
//跳转文件路径到具体路径下
//查看命名
//  c1 /d1 reportSingleClassLayout类名 文件名
//比如：D:\C++Projects\C++核心编程\C++核心编程>cl /d1 reportSingleClassLayoutSon "C++核心编程.cpp"


void test01()
{
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器隐藏了 因此访问不到 但是确实被继承下去了
	//16
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   48类和对象-继承-构造和析构顺序   *********
//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//问题：父类和子类的构造和析构顺序是谁先谁后？
//结论：继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
/*
#include<iostream>
#include<string>
using namespace std;

//继承中的构造和析构顺序
class Base
{
public:
	Base()
	{
		cout << "Base构造函数" << endl;
	}
	~Base()
	{
		cout << "Base析构函数" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son构造函数" << endl;
	}
	~Son()
	{
		cout << "Son析构函数" << endl;
	}
};

void test01()
{
	//Base b;

	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构顺序与构造顺序相反
	Son s;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



///*******   49类和对象-继承-同名成员处理   **********
//问题：当子类与父类出现同名成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
//访问子类同名成员：直接访问即可
//访问父类同名成员：需要加作用域
/*
#include<iostream>
#include<string>
using namespace std;

//继承中同名成员处理
class Base
{
public:
	Base()
	{
		m_a = 100;
	}

	void func()
	{
		cout << "Base下func()调用" << endl;
	}
	void func(int a)   //重载
	{
		cout << "Base下func(int a)调用" << endl;
	}

	int m_a;
};

class Son :public Base
{
public:
	Son()
	{
		m_a = 200;
	}

	void func()
	{
		cout << "Son下func()调用" << endl;
	}

	int m_a;
};

//同名成员属性处理
void test01()
{
	Son s;
	Base b;

	cout << "Son下m_a = " << s.m_a << endl;
	//如果通过子类对象，访问到父类中同名成员，需要加作用域
	cout << "Base下m_a = " << s.Base::m_a << endl;
}

//同名成员函数处理
void test02()
{
	Son s;
	Base b;

	s.func();
	s.Base::func();

	//如果子类中出现和父类同名的成员函数，那么子类的同名成员会隐藏掉父类中所有的同名成员函数（包括重载的）
	//s.func(100);  //只要名字一样就算同名成员函数 无法直接访问 报错
	s.Base::func(100);   //要加作用域
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




///*******   50类和对象-继承-同名静态成员处理   **********
//问题：继承中同名的静态成员在子类对象上如何进行访问？（静态成员回看P31）
//静态成员和非静态成员出现同名，处理方式一致，只不过静态成员有两种访问方式（通过对象和通过类名）
//访问子类同名成员：直接访问即可
//访问父类同名成员：需要加作用域
/*
#include<iostream>
#include<string>
using namespace std;

//继承中的同名静态成员处理方式
class Base
{
public:
	static int m_a;

	static void func()
	{
		cout << "Base-static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base-static void func(int a)" << endl;
	}
};

int Base::m_a = 100;

class Son :public Base
{
public:
	static int m_a;

	static void func()
	{
		cout << "Son-static void func()" << endl;
	}
};

int Son::m_a = 200;

//同名静态成员属性
void test01()
{
	//静态成员1、通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	cout << "Son下m_a = " << s.m_a << endl;
	cout << "Base下m_a = " << s.Base::m_a << endl;

	//静态成员2、通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son下m_a = " << Son::m_a << endl;
	//第一个 :: 代表通过类名方式访问，第二个 :: 代表访问父类作用于下
	cout << "Base下m_a = " << Son::Base::m_a << endl;
}

//同名静态成员函数
void test02()
{
	//静态成员1、通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.Base::func();

	//静态成员2、通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();

	//Son::func(100);   //父类中同名成员都被隐藏，需要加作用域才能访问  报错
	Son::Base::func(100);
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




///*******   51类和对象-继承-多继承语法   **********
//    C++允许一个类继承多个类
//    语法：class 子类：继承方式 父类1，继承方式 父类2...
//    多继承可能会引发父类中同名成员出现，需要加作用域区分
//     *** C++实际开发中不建议使用多继承 ***
/*
#include<iostream>
#include<string>
using namespace std;

//多继承语法
class Base1
{
public:
	Base1()
	{
		m_a = 100;
	}

	int m_a;
};

class Base2
{
public:
	Base2()
	{
		m_a = 200;
	}

	int m_a;
};

//子类 需要继承Base1和Base2
class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_c = 300;
		m_d = 400;
	}

	int m_c;
	int m_d;
};

void test01()
{
	Son s;
	cout << "sizeof Son = " << sizeof(Son) << endl;

	//当父类中出现同名成员，需要加作用于区分
	cout << "Base1下m_a = " << s.Base1::m_a << endl;
	cout << "Base2下m_a = " << s.Base2::m_a << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   52类和对象-继承-菱形继承   **********
// 菱形继承概念：
// 两个派生类继承同一个积累
//	又有某个类同时继承这两个派生类
//	这种继承被称为菱形继承，或者钻石继承
//利用虚继承可以解决菱形继承问题
/*
#include<iostream>
#include<string>
using namespace std;

//动物类
class Animal
{
public:
	int m_age;
};

//利用虚继承，可以解决菱形继承的问题
// 继承之前，加上关键字 virtual 变为虚继承
// Animal动物类称为 虚基类
//羊类
class Sheep :virtual  public Animal
{};

//驼类
class Tuo :virtual public Animal
{};

//羊驼类
class SheepTuo :public Sheep, public Tuo
{};

void test01()
{
	SheepTuo st;
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;

	//当出现菱形继承时，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_age = " << st.Sheep::m_age << endl;
	cout << "st.Tuo::m_age = " << st.Tuo::m_age << endl;
	
	//这份数据我们知道，只要有一份就够了，菱形继承导致数据有两份，资源浪费
	cout << "st.m_age = " << st.m_age << endl;   //变为虚继承之后，数据就只有一份，不需要加作用域
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   53类和对象-多态-多态的基本语法   ********
//多态分为两类
//		静态多态：函数重载和运算符重载属于静态多态，复用函数名
//		动态多态：派生类和虚函数实现运行时多态
//静态多态和动态多态区别
//		静态多态的函数地址早绑定：编译阶段确定函数地址
//		动态多态的函数地址晚绑定：运行阶段确定函数地址

//动态多态满足条件：
//		1、有继承关系
//		2、子类要重写父类的虚函数（重写：函数返回值类型、函数名、参数列表完全相同称为重写）

//动态多态使用
// 父类的指针或引用指向执行子类对象
/*
#include<iostream>
#include<string>
using namespace std;

//多态
//动物类
class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定 在编译阶段就确定了函数地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定

//动态多态满足条件：
//		1、有继承关系
//		2、子类要重写父类的虚函数（重写：函数返回值类型、函数名、参数列表完全相同）

//动态多态使用：
//		父类的指针或引用指向执行子类对象

void doSpeak(Animal &animal)   //Animal &animal = cat;
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///*******   54类和对象-多态-多态的原理剖析   *********
/*
#include<iostream>
#include<string>
using namespace std;

//多态
//动物类
class Animal
{
public:
	//虚函数
	 virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定 在编译阶段就确定了函数地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定

//动态多态满足条件：
//		1、有继承关系
//		2、子类要重写父类的虚函数（重写：函数返回值类型、函数名、参数列表完全相同）

//动态多态使用
// 父类的指针或引用指向执行子类对象

void doSpeak(Animal& animal)   //Animal &animal = cat;
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02()
{
	cout << "sizeof Animal = " << sizeof(Animal) << endl;
}

int main()
{
	//test01();
	test02();  //size为4，多了一个虚函数表指针

	system("pause");
	return 0;
}
*/
///////////






///********   55类和对象-多态-案例1-计算器类   ********
//案例描述：
//		分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
//多态的优点：
//		代码组织结构清晰
//		可读性强
//		利用前期和后期的扩展以及维护
//C++开发提倡利用多态设计程序架构，因为多态优点很多
/*
#include<iostream>
#include<string>
using namespace std;

//分别利用普通写法和多态技术实现计算器
//普通写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_num1 + m_num2;
		}
		else if (oper == "-")
		{
			return m_num1 - m_num2;
		}
		else if (oper == "*")
		{
			return m_num1 * m_num2;
		}
		//如果像扩展新的功能，需要修改源码
		//在真实的开发中，提倡开闭原则
		//开闭原则：对扩展进行开放，对修改进行关闭
	}

	int m_num1;	//操作数1
	int m_num2;	//操作数2
};

void test01()
{
	//创建计算器对象
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 20;

	cout << c.m_num1 << " + " << c.m_num2 << " = " << c.getResult("+") << endl;
	cout << c.m_num1 << " - " << c.m_num2 << " = " << c.getResult("-") << endl;
	cout << c.m_num1 << " * " << c.m_num2 << " = " << c.getResult("*") << endl;
}

//利用多态实现计算器
// 多态带来的好处：
//		1、组织结构清晰
//		2、可读性强
//		3、利用前期和后期的扩展以及维护

//实现计算器的抽象类（基类）
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_num1;
	int m_num2;
};
//加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1+m_num2;
	}
};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 * m_num2;
	}
};

void test02()
{
	//多态使用条件
	//父类指针或引用指向子类的对象

	//加法
	AbstractCalculator* abc = new AddCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//用完后记得销毁堆区数据
	delete abc;

	//减法
	abc = new SubCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;

	//乘法
	abc = new MulCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/




///*******   类和对象-多态-案例1-计算器类（自写）   *************
/*
#include<iostream>
#include<string>
using namespace std;

class AbstractCalculator
{
public:
	virtual int func()
	{
		return 0;
	}

	int m_num1 = 0;
	int m_num2 = 0;
};

class AddCalculator :public AbstractCalculator
{
public:
	int func()
	{
		return m_num1 + m_num2;
	}
};

class SubCalculator :public AbstractCalculator
{
public:
	int func()
	{
		return m_num1 - m_num2;
	}
};

class MulCalculator :public AbstractCalculator
{
public:
	int func()
	{
		return m_num1 * m_num2;
	}
};

class DivCalculator :public AbstractCalculator
{
public:
	int func()
	{
		return m_num1 / m_num2;
	}
};

int Calculator(AbstractCalculator& abs)
{
	return abs.func();
}

int* getnum()
{
	int arr[3];
	cout << "请输入被操作数：";
	cin >> arr[0];
	cout << "请输入操作数：";
	cin >> arr[1];
	return arr;
}


void test01()
{
	//******使用指针
	//AbstractCalculator* abs = new AddCalculator;
	////加法
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " + " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;
	////减法
	//abs =new SubCalculator;
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " - " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;
	////乘法
	//abs = new MulCalculator;
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " * " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;
	////除法
	//abs = new DivCalculator;
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " / " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;

	//******使用引用
	int* arr = getnum();
	int num1 = arr[0];
	int num2 = arr[1];
	//加法
	AddCalculator addcal;
	addcal.m_num1 = num1;
	addcal.m_num2 = num2;
	cout << addcal.m_num1 << " + " << addcal.m_num2 << " = " << Calculator(addcal) << endl;
	//减法
	SubCalculator subcal;
	subcal.m_num1 = num1;
	subcal.m_num2 = num2;
	cout << subcal.m_num1 << " - " << subcal.m_num2 << " = " << Calculator(subcal) << endl;
	//乘法
	MulCalculator mulcal;
	mulcal.m_num1 = num1;
	mulcal.m_num2 = num2;
	cout << mulcal.m_num1 << " * " << mulcal.m_num2 << " = " << Calculator(mulcal) << endl;
	//除法
	DivCalculator divcal;
	divcal.m_num1 = num1;
	divcal.m_num2 = num2;
	cout << divcal.m_num1 << " / " << divcal.m_num2 << " = " << Calculator(divcal) << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



///*******   56类和对象-多态-纯虚函数和抽象类   ********
//在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容，因此可以将虚函数改为纯虚函数
//纯虚函数语法：virtual 返回值类型 函数名（参数列表）=0 ；
//当类中有了纯虚函数，这个类也成为抽象类
//抽象类特点
//		无法实例化对象
//		子类必须重写抽象类中的纯虚函数，否则也属于抽象类
/*
#include<iostream>
#include<string>
using namespace std;

//纯虚函数和抽象类
class Base
{
public:
	//纯虚函数
	//只要有一个纯虚函数，这个类就称为抽象类
	//抽象类特点
	//  1、无法实例化对象
	//  2、抽象类子类必须重写抽象类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;  

};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func函数调用" << endl;
	};
};

void test01()
{
	//Base b;  //抽象类无法实例化对象 报错
	//new Base;   //抽象类无法实例化对象 报错
	Son s;  //子类必须重写父类中的纯虚函数，否则无法实例化对象

	Base* p = new Son;
	p->func();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



///*******   57类和对象-多态-案例2-制作饮品   ********
//案例描述：
//制作饮品的大致流程为：煮水-冲泡-倒入杯中-加入辅料
//利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
/*
#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//制作饮品（相当于把函数集合，方便调用）
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入咖啡杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

//制作茶叶
class Tea :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入茶杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入柠檬" << endl;
	}
};

//制作饮品函数（可要可不要）
void doWork(AbstractDrinking* abs)   //AbstractDrinking* abs=new Coffee;
{
	abs->makeDrink();
	delete abs;   //记得释放堆区数据！！
}

void test01()
{
	//制作咖啡
	doWork(new Coffee);
	cout << "咖啡制作完成！" << endl << endl;
	//制作茶叶
	doWork(new Tea);
	cout << "茶叶制作完成！" << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   58 类和对象-多态-虚析构和纯虚析构   *********
//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方式：将父类中的析构函数改为虚析构或者纯虚析构
//虚析构和纯虚析构共性：
//		可以解决父类指针释放子类对象
//		都需要有具体的函数实现
//虚析构和纯虚析构区别：
//		如果是纯虚析构，该类属于抽象类，无法实例化对象
/*
#include<iostream>
#include<string>
using namespace std;

//虚析构和纯虚析构
class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}

	//利用虚析构，可以解决父类指针释放子类对象不干净的问题
	//virtual ~Animal()
	//{
	//	cout << "Animal析构函数调用" << endl;
	//}

	//纯虚析构 纯虚析构也需要具体实现，在类外
	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;

	virtual void speak() = 0;

};

Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_name = new string(name);
	}

	void speak()
	{
		cout << *m_name << "小猫在说话" << endl;
	}

	~Cat()
	{
		if (m_name != NULL)
		{
			cout << "Cat析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	//在子类中，有属性开辟在了堆区，所以要走析构代码，如果是多态则不需要走析构
	string *m_name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构时，不会调用子类中析构函数，导致子类如果有堆区数据，会出现内存泄漏
	delete animal;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   59&60 类和对象-多态-案例3-电脑组装需求分析   *******
//电脑主要组成部件为CPU、显卡、内存条
//将每个零件封装成抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
//创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
//测试时组装三台不同的电脑进行工作
/*
#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//提供工作的函数
	void work()
	{
		//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//提供析构函数 释放3个电脑零件
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;	//CPU零件指针
	VideoCard* m_vc;		//显卡零件指针
	Memory* m_mem;		//内存条零件指针
};

//具体厂商
//Intel
class IntelCPU:public CPU
{
	void calculate()
	{
		cout << "Intel的CPU开始计算了！" << endl;
	}
};
class IntelVC :public VideoCard
{
	void display()
	{
		cout << "Intel的显卡开始显示了！" << endl;
	}
};
class IntelMEM :public Memory
{
	void storage()
	{
		cout << "Intel的内存条开始存储了！" << endl;
	}
};

//Lenovo
class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "联想的CPU开始计算了！" << endl;
	}
};
class LenovoVC :public VideoCard
{
	void display()
	{
		cout << "联想的显卡开始显示了！" << endl;
	}
};
class LenovoMEM :public Memory
{
	void storage()
	{
		cout << "联想的内存条开始存储了！" << endl;
	}
};

void test01()
{
	//第一台电脑组装
	//第一台电脑零件
	CPU* cpu = new IntelCPU;   //父类指针指向子类
	VideoCard* vc = new IntelVC;
	Memory* mem = new LenovoMEM;
	//创建第一台电脑
	cout << "第一台电脑开始工作：" << endl;
	Computer* computer1 = new Computer(cpu, vc, mem);
	computer1->work();
	delete computer1;
	cout << endl;

	//第二台电脑组装
	cout << "第二台电脑开始工作：" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new IntelVC, new LenovoMEM);
	computer2->work();
	delete computer2;
	cout << endl;

	//第三台电脑组装
	cout << "第三台电脑开始工作：" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVC, new LenovoMEM);
	computer3->work();
	delete computer3;
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///*******   类和对象-多态-案例3-电脑组装需求分析（自写）   *********
/*
#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class Videocard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu,Videocard* vc,Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void dowork()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;
	Videocard* m_vc;
	Memory* m_mem;
};

//Intel
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel的CPU正在计算！" << endl;
	}
};
class IntelVideocard :public Videocard
{
public:
	void display()
	{
		cout << "Intel的显卡正在显示！" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel的内存条正在存储！" << endl;
	}
};

//联想
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo的CPU正在计算！" << endl;
	}
};
class LenovoVideocard :public Videocard
{
public:
	void display()
	{
		cout << "Lenovo的显卡正在显示！" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo的内存条正在存储！" << endl;
	}
};

void test()
{
	Computer* c1 = new Computer(new IntelCPU, new LenovoVideocard, new LenovoMemory);
	c1->dowork();
	delete c1;
	cout << endl;

	Computer* c2 = new Computer(new LenovoCPU, new IntelVideocard, new LenovoMemory);
	c2->dowork();
	delete c2;
	cout << endl;

	Computer* c3 = new Computer(new LenovoCPU, new IntelVideocard, new IntelMemory);
	c3->dowork();
	delete c3;
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
*/




//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
//通过文件可以将数据持久化
//C++中对文件操作需要包含头文件<fstream>

//文件类型分为两种：
//		1、文本文件：文件以文本的ASCII码形式存储在计算机中
//		2、二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

//操作文件的三大类：
//		1、ofstream：写操作
//		2、ifstream：读操作
//		3、fstream：读写操作

///*******   61 C++文件操作-文本文件-写文件   **********
//写文件步骤如下：
//		1、包含头文件   #include<fstream>
//		2、创建流对象   ofstream ofs;
//		3、打开文件   ofs.open("文件路径"，打开方式)
//		4、写数据   ofs<<"写入的数据";
//		5、关闭文件   ofs.close();

//文件打开方式：
//		ios::in			为读文件而打开文件
//		ios::out			为写文件而打开文件
//		ios::ate			初始位置：文件尾
//		ios::app		追加方式写文件
//		ios::trunc		如果文件存在先删除，再创建
//		ios::binary	二进制方式
//注意：文件打开方式可以配合使用，利用 | 操作符
//例如：用二进制方式写文件：ios::binary | ios::out
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//文本文件 写文件
void test01()
{
//		1、包含头文件   #include<fstream>
//		2、创建流对象   ofstream ofs;
	ofstream ofs;
//		3、打开文件   ofs.open("文件路径"，打开方式)
	ofs.open("text.txt", ios::out);   //绝对路径和相对路径均可
//		4、写数据   ofs<<"写入的数据";
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
//		5、关闭文件   ofs.close();
	ofs.close();
}

int main()
{
	test01();
	cout << "文件写入完成！" << endl;

	system("pause");
	return 0;
}
*/



///*******   62 C++文件操作-文本文件-读文件   **********
//读文件与写文件步骤相似，但读取方式相对较多
//读文件步骤如下：
//		1、包含头文件   #include<fstream>
//		2、创建流对象   ifstream ifs;
//		3、打开文件并判断文件是否打开成功   ifs.open("文件路径"，打开方式);
//		4、读数据   四种方式读取
//		5、关闭文件   ifs.close();
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//文本文件 读文件
void test01()
{
//		1、包含头文件   #include<fstream>
//		2、创建流对象   ifstream ifs;
	ifstream ifs;
//		3、打开文件并判断文件是否打开成功   ifs.open("文件路径"，打开方式);
	ifs.open("D:\\C++Projects\\C++核心编程\\C++核心编程\\text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
//		4、读数据   四种方式读取
//第一种
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
//第三种
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}
//第四种（不推荐）
	//char c;
	//while ((c = ifs.get()) != EOF)   //EOF：end of file
	//{
	//	cout << c;
	//}
//		5、关闭文件   ifs.close();
	ifs.close();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



///*******   63 C++文件操作-二进制文件-写文件   ********
//以二进制的方式对文件进行读写操作
//打开方式要指定为 ios::binary
//二进制方式写文件主要利用流对象调用成员函数write
//函数原型：ostream& write(const char* buffer, int len);
//参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//二进制文件 写文件
//二进制不仅可以操作内置数据类型如int等，也可以操作自定义数据类型，例如将自己创建的类写入文件中
class Person
{
public:
	char m_name[64];   //操作二进制文件十最好不用string，直接用char字符数组
	int m_age;
};

void test01()
{
//1、包含头文件
//2、创建对象流
	ofstream ofs("person.txt", ios::out | ios::binary);
//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);
//4、写文件
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));
//5、关闭文件
	ofs.close();
}

void test02()
{
	ofstream ofs2("liu.txt", ios::out | ios::binary);
	char myInfo[64] = { "姓名：刘啸亚\n年龄：23\n性别：男" };
	ofs2.write((const char*)&myInfo, sizeof(myInfo));
	ofs2.close();
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
*/




///*******   64 C++文件操作-二进制文件-读文件   ********
//二进制方式读文件主要利用流对象调用成员函数read
//函数原型：istream& read(char* buffer, int len);
//参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
public:
	char m_name[64];   //操作二进制文件十最好不用string，直接用char字符数组
	int m_age;
};

//二进制文件 读文件
void test01()
{
//1、包含头文件
//2、创建流对象
	ifstream ifs;
//3、打开文件并判断文件是否打开成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
//4、读文件
	Person p;
	ifs.read((char*) &p, sizeof(Person));
	cout << "姓名：" << p.m_name << endl;
	cout << "年龄：" << p.m_age << endl;
//5、关闭文件
	ifs.close();
}

void test02()
{
	char myInfo[64] = { 0 };

	ifstream ifs2("liu.txt", ios::in | ios::binary);
	if (!ifs2.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	ifs2.read((char*)&myInfo, sizeof(myInfo));
	cout << myInfo << endl;
}

int main()
{
	test01();
	cout << "-------------------------------" << endl;
	test02();

	system("pause");
	return 0;
}
*/
///////////   01������ڴ�ģ��-�ڴ�����-������



//////////   02������ڴ�ģ��-�ڴ�����-ȫ����
/*
#include<iostream>
#include<string>
using namespace std;

//ȫ�ֱ���
int g_a = 10;
int g_b = 10;

//const���ε�ȫ�ֱ�������ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
	//ȫ����
	//ȫ�ֱ�������̬����������

	//������ͨ�ֲ�����
	int a = 10;
	int b = 10;
	cout << "�ֲ�����a�ĵ�ַΪ��" << (int)&a << endl;
	cout << "�ֲ�����b�ĵ�ַΪ��" << (int)&b << endl;

	//ȫ�ֱ���
	cout << "ȫ�ֱ���g_a�ĵ�ַΪ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַΪ��" << (int)&g_b << endl;

	//��̬����   ����ͨ����ǰ��static�����ھ�̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a�ĵ�ַΪ��" << (int)&s_a << endl;
	cout << "��̬����s_b�ĵ�ַΪ��" << (int)&s_b << endl;

	//����
	//�ַ�������
	cout << "�ַ��������ĵ�ַΪ��" << (int)&"hello world" << endl;
	
	//const���εı���
	//const���ε�ȫ�ֱ���
	cout << "ȫ�ֳ���c_g_a�ĵ�ַΪ��" << (int)&c_g_a << endl;
	cout << "ȫ�ֳ���c_g_b�ĵ�ַΪ��" << (int)&c_g_b << endl;

	//const���εľֲ�����
	const int c_l_a = 10;    //c--const   g--global    l--local
	const int c_l_b = 10;
	cout << "�ֲ�����c_l_a�ĵ�ַΪ��" << (int)&c_l_a << endl;
	cout << "�ֲ�����c_l_b�ĵ�ַΪ��" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}
*/



//////////   03������ڴ�ģ��-�ڴ�����-ջ��
//ջ�����ɱ������Զ������ͷţ���ź����Ĳ���ֵ���ֲ�������
//ע�������Ҫ���ؾֲ������ĵ�ַ��ջ�����ٵ������ɱ������Զ��ͷ�
/*
#include<iostream>
#include<string>
using namespace std;
int* func(int b)  //�β�����Ҳ�����ջ��
{
	int a = 10;//�ֲ�����  �����ջ����ջ���������ں���ִ������Զ��ͷ�
	return &a;//���ؾֲ�������ַ

	b = 100;
}

int main()
{
	int* p = func(1);
	//��Ҫ��ô��
	cout << *p << endl;  //��һ�ο��Դ�ӡ��ȷ���ݣ�����Ϊ���������˱���
	cout << *p << endl;  //�ڶ������ݾͲ�������

	system("pause");
	return 0;
}
*/




//////////   04������ڴ�ģ��-�ڴ�����-����
//�ɳ���Ա�����ͷţ�������Ա���ͷţ��������ʱ�ɲ���ϵͳ����
//��C++����Ҫ����new�ڶ��������ڴ�
/*
#include<iostream>
#include<string>
using namespace std;

int* func()
{
	//����new�ؼ��� ���Խ����ݿ��ٵ�����
	//ָ�뱾��Ҳ�Ǿֲ�����������ջ�ϡ�ָ�뱣��������Ƿ��ڶ���
	int* p = new int(10);   //new���ص��Ƕ����ĵ�ַ����һ��ָ�����
	return p;
}

int main()
{
	//�ڶ�����������
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}
*/





//////////   05������ڴ�ģ��-new�����
//C++������new�������ڶ�����������
//�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷţ��ͷ����ò�����delete
/*
#include<iostream>
#include<string>
using namespace std;

//1��new�Ļ����﷨
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
	//�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷ�
	//�ͷ����ò�����delete
	delete p;
	//cout << *p << endl;   //�ڴ��Ѿ����ͷ� �ٴη��ʾ��ǷǷ��������ᱨ��
}

//2���ڶ�������new��������


void test02()
{
	int* arr = new int[10];   //������10����������10��Ԫ��

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//�ͷŶ�������
	//�ͷ������ʱ��Ҫ��[ ]�ſ���
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
 




//////////   06C++�е�����-���õĻ����﷨
//���ã������������
//�﷨���������� &����=ԭ��
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





//////////   07C++�е�����-���õ�ע������
//���ñ����ʼ��
//�����ڳ�ʼ���󣬲����Ըı�
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 10;
	int c = 20;

	//int& b;  //δ��ʼ�� ����
	int& b = a; 

	//int& b = c;    //һ����ʼ���󣬾Ͳ����Ը���  ����

	b = c;  //��ֵ�����������Ǹ�������  ��c��ֵ��bָ����ڴ�

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}
*/





//////////   08C++�е�����-��������������
//���ã���������ʱ�������������õļ������β�����ʵ��
//�ŵ㣺���Լ�ָ���޸�ʵ��
/*
#include<iostream>
#include<string>
using namespace std;

//��������
//1��ֵ����
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01: a=" << a << "\tb=" << b << endl;
}

//2����ַ����
void swap02(int* c, int* d)
{
	int temp = *c;
	*c = *d;
	*d = temp;
	cout << "swap02: c=" << *c << "\td=" << *d<< endl;
}

//3�����ô���
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
	swap03(e, f);   //���ô��ݣ��β�Ҳ������ʵ��
	cout << "swap03: e=" << e << "\tf=" << f << endl;

	system("pause");
	return 0;
}
*/




//////////   09C++�е�����-��������������ֵ
//���ã������ǿ�����Ϊ�����ķ���ֵ���ڵ�
//ע�⣺��Ҫ���ؾֲ���������
//�÷�������������Ϊ��ֵ
/*
#include<iostream>
#include<string>
using namespace std;

//1����Ҫ���ؾֲ���������
int& test01()
{
	int a = 10;  //�ֲ���������������е�ջ��
	return a;
}

//2�������ĵ��ÿ�����Ϊ��ֵ
int& test02()
{
	static int a = 10;   //��̬���� �����ȫ���� ȫ�����ϵ������ڳ��������ϵͳ�ͷ�
	return a;
}

int main()
{
	int& ref = test01();
	cout << "ref=" << ref << endl;  //��һ�ν���� ����Ϊ���������˱���
	cout << "ref=" << ref << endl;  //�ڶ��ν������ ��Ϊa���ڴ��Ѿ��ͷ�
	cout << endl;

	int& ref2 = test02();
	cout << "ref2=" << ref2<< endl;
	cout << "ref2=" << ref2 << endl;

	test02() = 1000;   //��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;

	system("pause");
	return 0;
}
*/





//////////   10C++�е�����-���õı���
//���õı�����C++�ڲ�ʵ����һ��ָ�볣��
/*
#include<iostream>
#include<string>
using namespace std;

//���������ã�ת��Ϊ int* const ref=&a
void func(int& ref)
{
	ref = 100;   //ref�����ã�ת��Ϊ*ref=100
}

int main()
{
	int a = 10;
	
	//�Զ�ת��Ϊ int* const ref=&a��ָ�볣����ָ��ָ�򲻿��Ըģ�Ҳ˵��Ϊʲô���ò����Ը���
	int& ref = a;
	ref = 20;   //�ڲ�����ref�����ã��Զ�������ת��Ϊ��*ref=20��

	cout << "a=" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	cout << "a=" << a << endl;
	cout << "ref:" << ref << endl;

	system("pause");
	return 0;
}
*/




//////////   11C++�е�����-��������
//����������Ҫ���������βΣ���ֹ�����
/*
#include<iostream>
#include<string>
using namespace std;

void showValue(const int& val)
{
	//val = 1000;  //�βμ���const�󣬲������޸�  ����
	cout << "val=" << val << endl;
}

int main()
{
	//int& ref = 10;   //���ñ�����һ��Ϸ����ڴ�ռ�  ����
	//����const֮�󣬱������Ż�����Ϊ�� int temp=10; const int& ref=temp;
	const int& ref1 = 10;
	//ref = 20;  //����const֮���Ϊ�ɶ����������޸�  ����

	int a = 100;
	showValue(a);
	cout << "a=" << a << endl;

	system("pause");
	return 0;
}
*/




//////////   12�����߼�-������Ĭ�ϲ���
//��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ��
/*
#include<iostream>
#include<string>
using namespace std;

//��������Լ��������ݣ������Լ������ݣ���֮��Ĭ��ֵ
int func(int a,int b=20,int c=30)
{
	return a + b + c;
}

//ע�����
//1�����ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴����Ҷ�������Ĭ��ֵ
//int func2(int a, int b = 20, int c)
//{
//	return a + b + c;
//}

//2���������������Ĭ�ϲ�������ô����ʵ�־Ͳ�����Ĭ�ϲ�����������ʵ��ֻ����һ����Ĭ�ϲ���
//int func3(int a = 10, int b = 10);  //����
//func3(int a = 10, int b = 10)  //����
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




//////////   13�����߼�-������ռλ����
//C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��
//�﷨������ֵ���� ���������������ͣ�{ }
/*
#include<iostream>
#include<string>
using namespace std;

//Ŀǰ�׶ε�ռλ�������ǻ��ò���������γ̻��õ�
void func(int a,int)
{
	cout << "this is func" << endl;
}

//ռλ���� ��������Ĭ�ϲ���
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




//////////   14�����߼�-��������-�����﷨
//���ã�������������ͬ����߸�����
//������������������
//1��ͬһ����������
//2������������ͬ
//3�������������Ͳ�ͬ ���� ������ͬ ���� ˳��ͬ
//ע�⣺�����ķ���ֵ��������Ϊ�������ص�����
/*
#include<iostream>
#include<string>
using namespace std;

//������������������
//1��ͬһ����������
//2������������ͬ
//3�������������Ͳ�ͬ ���� ������ͬ ���� ˳��ͬ
void func()
{
	cout << "func�ĵ���" << endl;
}

void func(int a)  //����������ͬ
{
	cout << "func(int a)�ĵ���" << endl;
}

void func(double a)  //�������Ͳ�ͬ
{
	cout << "func(double a)�ĵ���" << endl;
}

void func(int a, double b)  //����˳��ͬ
{
	cout << "func(int a, double b)�ĵ���" << endl;
}

void func(double a, int b)  //����˳��ͬ
{
	cout << "func(double a, int b)�ĵ���" << endl;
}

//ע�⣺�����ķ���ֵ��������Ϊ�������ص�����
//int func(double a, int b)   //����
//{
//	cout << "func(double a, int b)�ĵ���" << endl;
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




//////////   15�����߼�-��������-ע������
//������Ϊ��������
//����������������Ĭ�ϲ���
/*
#include<iostream>
#include<string>
using namespace std;

//�������ص�ע������
//1��������Ϊ��������
void func(int& a)
{
	cout << "func(int& a)�ĵ���" << endl;
}

void func(const int& a)
{
	cout << "func(const int& a)�ĵ���" << endl;
}

//2������������������Ĭ�ϲ���
void func2(int a)
{
	cout << "func2(int a)�ĵ���" << endl;
}

void func2(int a, int b=10)
{
	cout << "func2(int a, int b=10)�ĵ���" << endl;
}

int main()
{
	int a = 10;
	func(a);   //������const
	func(10);   //����const
	cout << endl;

	//func2(10);   //��������������Ĭ�ϲ��������ֶ����ԣ�����Ӧ���������������������ʱ�Ͳ�ҪдĬ�ϲ���
	func2(10, 20);

	system("pause");
	return 0;
}
*/




//C++����������������Ϊ����װ���̳С���̬
//C++��Ϊ�������ﶼ��Ϊ���󣬶������������Ժ���Ϊ

//////////   16��Ͷ���-��װ-���Ժ���Ϊ��Ϊ����
//��װ�����壺
//1�������Ժ���Ϊ��Ϊһ�����壬���������е�����
//2�������Ժ���Ϊ����Ȩ�޿���
/*
#include<iostream>
#include<string>
using namespace std;
const double PI = 3.14;

//���һ��Բ�࣬��Բ���ܳ�
//class�������һ����
class Circle
{
	//����Ȩ��
	//����Ȩ��
public:
	//����
	int m_r;  //�뾶
	//��Ϊ
	double calZC()  //��ȡԲ���ܳ�
	{
		return 2 * PI * m_r;
	}
};

int main()
{
	//ͨ��Բ�ഴ�������Բ������   
	Circle c1;   //ʵ����
	//��Բ��������Խ��и�ֵ
	c1.m_r = 10;

	cout << "Բ���ܳ�Ϊ��" << c1.calZC() << endl;

	system("pause");
	return 0;
}
*/




//���е����Ժ���Ϊ������ͳһ��Ϊ��Ա
//���� Ҳ��Ϊ��Ա���ԡ���Ա����
//��Ϊ Ҳ��Ϊ��Ա��������Ա����

//////////  17��Ͷ���-��װ-����-���ѧ����
//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ�ϵ�������ѧ��
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
		cout << "ѧ������Ϊ��" << m_name << '\t';
		cout << "ѧ��Ϊ��" << m_id << endl;
	}

	//ͨ����Ϊ�����Ը�ֵ
	//��������ѧ�Ÿ�ֵ   
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
	s1.m_name = "����";
	s1.m_id = "001";
	s1.showInfo();

	Stu s2;
	s2.setName("����");
	s2.setID("002");
	s2.showInfo();

	system("pause");
	return 0;
}
*/





//////////   18��Ͷ���-��װ-����Ȩ��
//�������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���
//����Ȩ�������֣�
//1��public ����Ȩ�ޣ���Ա���ڿ��Է��� ������Է���
//2��protected ����Ȩ�ޣ���Ա���ڿ��Է��� ���ⲻ���Է���  ����Ҳ���Է��ʸ����еı�������
//3��private ˽��Ȩ�ޣ���Ա���ڿ��Է��� ���ⲻ���Է���  ���Ӳ����Է��ʸ��׵�˽������
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
	//����Ȩ��
public:
	string m_name;

	//����Ȩ��
protected:
	string m_car;

	//˽��Ȩ��
private:
	string m_password;

public:
	void func1()
	{
		m_name = "����";
		m_car = "������";
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

	p1.m_name = "����";
	//p1.m_car = "����";   //����Ȩ�����ݣ���������ʲ���
	//p1.m_password = "987";   //˽��Ȩ�����ݣ���������ʲ���
	p1.func1();
	//p1.func2();   //˽��Ȩ�����ݣ���������ʲ���

	system("pause");
	return 0;
}
*/




//////////   19��Ͷ���-��װ-C++��class��struct������
//��C++��struct��class��Ψһ��������� Ĭ�ϵķ���Ȩ�޲�ͬ
//����
//1��structĬ��Ȩ��Ϊ����public
//2��classĬ��Ȩ��Ϊ˽��private
/*
#include<iostream>
#include<string>
using namespace std;

class C
{
	int m_A;   //Ĭ��Ȩ��Ϊ˽��
};

struct S
{
	int m_A;   //Ĭ��Ȩ��Ϊ����
};

int main()
{
	C c1;
	//c1.m_A = 100;   //˽��Ȩ�޲��ɷ��� ����

	S s1;
	s1.m_A = 100;

	system("pause");
	return 0;
}
*/




//////////   20��Ͷ���-��װ-��Ա����˽�л�
//�ŵ�1�������г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
//�ŵ�2������дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//д����������������
	void setname(string name)
	{
		m_name = name;
	}
	//����������ȡ������
	string getname()
	{
		return m_name;
	}

	//��������
	void setage(int age)
	{
		if (age < 0 || age>150)
		{
			m_age = 0;
			cout << "��������������" << endl;
			return;
		}
		m_age = age;
	}

	//��ȡ����
	int getage()
	{
		//m_age = 0;  //��ʼ��Ϊ0��
		return m_age;
	}

	//��������
	void setlover(string lover)
	{
		m_lover = lover;
	}

private:
	//����  �ɶ���д
	string m_name;
	//����  �ɶ���д ��������޸ģ����䷶Χ������0~150֮�䣩
	int m_age;
	//����  ֻд
	string m_lover;
};

int main()
{
	Person p;
	p.setname("����");

	cout << "����Ϊ��" << p.getname() << endl;

	p.setage(20);
	cout << "����Ϊ��" << p.getage() << endl;

	p.setlover("����");
	//cout << "����Ϊ��" << p.m_lover << endl;   //m_loverΪ˽��Ȩ�޲����Է��� ����

	system("pause");
	return 0;
}
*/



//////////   21��Ͷ���-��װ-��ư���1-��������
//����������ࣨCube��
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
/*
#include<iostream>
#include<string>
using namespace std;

class Cube
{
public:
	//��Ϊ
	//���û�ȡ�����
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

	//��ȡ���������
	int getS()
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	//��ȡ���������
	int getV()
	{
		return m_L * m_W * m_H;
	}

	//���ó�Ա�����ж������������Ƿ����
	bool isSamebyClass(Cube &c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	//����
	int m_L;
	int m_W;
	int m_H;
};

//����ȫ�ֺ����ж������������Ƿ����
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

	cout << "c1�����Ϊ��" << c1.getS() << endl;
	cout << "c1�����Ϊ��" << c1.getV() << endl;


	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//����ȫ�ֺ����ж������������Ƿ����
	bool result = isSame(c1, c2);
	if (result)
	{
		cout << "�������������" << endl;
	}
	else
	{
		cout << "���������岻���" << endl;
	}

	//���ó�Ա�����ж������������Ƿ����
	bool result2 = c1.isSamebyClass(c2);
	if (result)
	{
		cout << "�������������" << endl;
	}
	else
	{
		cout << "���������岻���" << endl;
	}

	system("pause");
	return 0;
}
*/



//�����п�������һ������Ϊ�����еĳ�Ա
//////////   22��Ͷ���-��װ-��ư���2-���Բ��ϵ
//���һ��Բ���ࣨCirlce����һ�����ࣨPoint������������Բ�Ĺ�ϵ
/*
#include<iostream>
#include<string>
using namespace std;
#include "point.h"
#include "circle.h"

//����
//class Point
//{
//public:
//	void setX(int X)   //���ú�����
//	{
//		m_pointX = X;
//	}
//	int getX()   //��ȡ������
//	{
//		return m_pointX;
//	}
//
//	void setY(int Y)   //���ú�����
//	{
//		m_pointY = Y;
//	}
//	int getY()   //��ȡ������
//	{
//		return m_pointY;
//	}
//
//
//private:
//	int m_pointX;
//	int m_pointY;
//};

//Բ��
//class Circle
//{
//public:
//	void setCenter(Point center)   //����Բ��
//	{
//		m_Center = center;
//	}
//	Point getCenter()   //��ȡԲ��
//	{
//		return m_Center;
//	}
//
//	void setR(int R)   //���ð뾶
//	{
//		m_R = R;
//	}
//	int getR()   //��ȡ�뾶
//	{
//		return m_R;
//	}
//
//private:
//	int m_R;
//
//	//�����п�������һ������Ϊ�����еĳ�Ա
//	Point m_Center;  //Բ��
//};

void Info(Circle& c, Point& p)   //�жϵ��Բ�Ĺ�ϵ
{
	int dis2 = pow(c.getCenter().getX() - p.getX(), 2) + pow(c.getCenter().getY() - p.getY(), 2);  //����Բ�ľ����ƽ��
	if (dis2 == pow(c.getR(), 2))
	{
		cout << "����Բ��" << endl;
	}
	else if (dis2 > pow(c.getR(), 2))
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
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

	cout << "Բ������Ϊ��" << "(" << c.getCenter().getX() << "," << c.getCenter().getY() << ")" << "   ";
	cout << "Բ�İ뾶Ϊ��" << c.getR() << endl;
	cout << "�������Ϊ��" << "(" << p.getX() << "," << p.getY() << ")" << endl;
	Info(c, p);

	system("pause");
	return 0;
}
*/





////*********   23��Ͷ���-��������-���캯������������   ***********
//���캯������Ҫ�������ڴ�������ʱΪ����ĳ�Ա���Ը�ֵ�����캯���ɱ������Զ����ã������ֶ�����
//������������Ҫ�������ڶ�������ǰϵͳ�Զ����ã�ִ��һЩ������

//���캯���﷨������( ){ }
//1.���캯����û�з���ֵҲ��дvoid
//2.����������������ͬ
//3.���캯�������в�������˿��Է�������
//4.�����ڵ��ö���ʱ���Զ����ù��죬�����ֶ����ã�����ֻ�����һ��

//���������﷨��~����( ){ }
//1.����������û�з���ֵҲ��дvoid
//2.����������������ͬ��������ǰ���Ϸ���~
//3.���������������в�������˲����Է�������
//4.�����ڵ��ö���ʱ���Զ����������������ֶ����ã�����ֻ�����һ��
/*
#include<iostream>
#include<string>
using namespace std;

//����ĳ�ʼ��������
class Person
{
public:
	//1�����캯�� ���г�ʼ������
	Person()
	{
		cout << "Person���캯���ĵ���" << endl;
	}

	//2���������� �����������
	~Person()
	{
		cout << "Person���������ĵ���" << endl;
	}
};

//����������������Ǳ����е�ʵ�֣���������Լ����ṩ�����������ṩһ����ʵ�ֵĹ��������
void test01()
{
	Person p;   //��ջ�ϵ����ݣ�test01ִ����Ϻ��ͷ��������
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





/////*******   24��Ͷ���-��������-���캯���ķ����Լ�����   ********
//���ַ��෽ʽ��
//1.��������Ϊ���вι�����޲ι���
//2.�����ͷ�Ϊ����ͨ����Ϳ�������
//���ֵ��÷�ʽ��
//1.���ŷ�
//2.��ʾ��
//3.��ʽת����
/*
#include<iostream>
#include<string>
using namespace std;

//���캯���ķ��༰����
//����
class Person
{
public:
	Person()
	{
		cout << "Person���޲ι��죨Ĭ�Ϲ��죩��������" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person���вι��캯������" << endl;
	}
	//�������캯��
	Person(const Person &p)
	{
		//������������ϵ��������ԣ�������������
		age = p.age;
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int age;
};

//����
void test01()
{
	//���ŷ�
	//Person p1;   //Ĭ�Ϲ��캯���ĵ���
	//Person p2(10);   //�вι��캯���ĵ���
	//Person p3(p2);   //�������캯���ĵ���

	//ע������1
	//����Ĭ�Ϲ��캯��ʱ����Ҫ��( )
	//��Ϊ�������д��룬����������Ϊ��һ�����������������Բ�����Ϊ�ڴ�������
	//Person p1();

	//cout << "p2������Ϊ��" << p2.age << endl;
	//cout << "p3������Ϊ��" << p3.age << endl;


	//��ʾ��
	//Person p1;   //Ĭ�Ϲ��캯���ĵ���
	//Person p2 = Person(10);   //�вι��캯���ĵ���
	//Person p3 = Person(p2);   //�������캯���ĵ���
	//�Ⱥ��ұ�����Person(10)��һ�����������ص㣺��ǰִ�н�����ϵͳ���������յ���������

	//ע������2
	//��Ҫ���ÿ������캯����ʼ����������
	//Person(p2);   //����������ΪPerson(p2)==Person p2�����Ƕ�����������������ظ�  ����


	//��ʽת����
	Person p4 = 10;    //�൱��Person p4=Person(10);     //�вι��캯���ĵ���
	Person p5 = p4;    //�������캯���ĵ���
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




////***********   25��Ͷ���-��������-�������캯������ʱ��   *********
//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//2��ֵ���ݵķ�ʽ������������ֵ
//3����ֵ��ʽ���ؾֲ�����
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age)
	{
		m_age = age;
		cout << "Person���вι��캯������" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int m_age;
};

//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << endl;
}

//2��ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p)   //ֵ���ݵı����ǿ���һ������ ����ʵҲ�ǿ������캯��
{

}

void test02()
{
	Person p;
	doWork(p);
}

//3����ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;   //��doWork2ִ�����p1�ͱ�������
	cout << (int)&p1 << endl;
	return p1;   //���ﷵ�صĲ���p1���Ǹ��Ƶ�һ�����ݸ������൱�ڿ�������˻���ÿ������캯��
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





///***********   26��Ͷ���-��������-���캯�����ù���   *********
//Ĭ������£�C++���������ٸ�һ�������3������
//1.Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//2.Ĭ�������������޲Σ�������Ϊ�գ�
//3.Ĭ�Ͽ��������������Խ���ֵ����

//���캯�����ù������£�
//����û������вι��캯����C++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������
//����û����忽�����캯����C++�Ͳ������ṩ�������캯��
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age)
	{
		m_age = age;
		cout << "Person���вι��캯������" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int m_age;
};

void test01()
{
	Person p;
	p.m_age = 18;

	Person p2(p);
	cout << "p2������Ϊ��" << p2.m_age << endl;
}

void test02()
{
	Person p(20);
	Person p2(p);
	cout << "p2������Ϊ��" << p2.m_age << endl;
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





///********   27��Ͷ���-��������-�����ǳ����   ********
//��ǳ���������Ծ������⣬Ҳ�ǳ�����һ����
//ǳ�������򵥵ĸ�ֵ��������
//������ڶ�����������ռ䣬���п�������
//ע�⣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height);   //new���ص���ָ��
		cout << "Person���вι��캯������" << endl;
	}

	//�Լ�ʵ�ֿ������������ǳ�����������ڴ��ظ��ͷ�����
	Person(const Person& p)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;  //������Ĭ��ʵ�־������д���
		//ʵ���������
		m_height = new int(*p.m_height);   //�൱��new int(160)��Ȼ�󷵻�new�������ڴ��׵�ַ
	}

	~Person()
	{
		//�������룬���������ٵ������ͷŲ���
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "Person��������������" << endl;
	}

	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18,160);
	cout << "p1������Ϊ��" << p1.m_age << "   ���Ϊ��" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << "   ���Ϊ��" << *p2.m_height << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///********   28��Ͷ���-��������-��ʼ���б�   ***********
//���ã�C++�ṩ�˳�ʼ���б��﷨��������ʼ������
//�﷨�����캯��( ) : ����1(ֵ1) , ����2(ֵ2) ... { }
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//��ͳ��ʼ������
	//Person(int a, int b, int c)
	//{
	//	m_a = a;
	//	m_b = b;
	//	m_c = c;
	//}

	//���ó�ʼ���б��ʼ������
	Person(int a,int b,int c) :m_a(a), m_b(b), m_c(c)
	{
		cout << "���ó�ʼ���б��ʼ������" << endl;
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





///*******   29��Ͷ���-��������-�������Ϊ���Ա   ***********
//C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ�����Ա
//��������Ķ�����Ϊ����ĳ�Ա������ʱ�ȹ���������Ķ����ٹ��챾�ࣻ����˳���빹��˳���෴����Ϊջ�Ƚ��������
/*
#include<iostream>
#include<string>
using namespace std;

//�������Ϊ���Ա
class Phone
{
public:
	Phone(string pname)
	{
		cout << "Phone���캯������" << endl;
		m_pname = pname;
	}

	~Phone()
	{
		cout << "Phone������������" << endl;
	}

	string m_pname;   //�ֻ�Ʒ����
};

class Person
{
public:
	//Phone m_phone=pname  ��ʽת����
	Person(string name, string pname): m_name(name),m_phone(pname)
	{
		cout << "Person���캯������" << endl;
	}

	~Person()
	{
		cout << "Person������������" << endl;
	}

	//����
	string m_name;
	//�ֻ�
	Phone m_phone;
};

//��������Ķ�����Ϊ����ĳ�Ա������ʱ���ȹ���������Ķ����ٹ�����������˳���빹��˳���෴
void test01()
{
	Person p("����", "��Ϊ");
	cout << p.m_name << "��" << p.m_phone.m_pname << "�ֻ�" << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





//��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
//��̬��Ա��Ϊ��
//		��̬��Ա����
//				���ж�����ͬһ������
//				�ڱ���׶η����ڴ棨ȫ������
//				���������������ʼ��
//		��̬��Ա����
//				���ж�����ͬһ������
//				��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

///***********   30��Ͷ���-��������-��̬��Ա����   **********
/*
#include<iostream>
#include<string>
using namespace std;

//��̬��Ա����
class Person
{
public:

	//1.���ж��󶼹���ͬһ������
	//2.�ڱ���׶η����ڴ棨ȫ������
	//3.���������������ʼ��
	static int m_a;

	//��̬��Ա����Ҳ�з���Ȩ��
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
	cout << p.m_a << endl;   //��p2�������ݣ���������p�������������˵�������ǹ����
}

void test02()
{
	//��̬��Ա����������ĳ�������ϣ���Ϊ���ж��󶼹���ͬһ������
	//��˾�̬���������ַ��ʷ�ʽ
	//1��ͨ��������з���
	Person p;
	cout << p.m_a << endl;
	//2��ͨ���������з���
	cout << Person::m_a << endl;

	//cout << Person::m_b << endl;   //˽��Ȩ�������ⲻ�ɷ��� ����
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/





///***********   31��Ͷ���-��������-��̬��Ա����   **********
//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
/*
#include<iostream>
#include<string>
using namespace std;

//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person
{
public:
	static void func()
	{
		m_a = 100;  //��̬��Ա�������Է��ʾ�̬��Ա����
		//m_b = 200;    //��̬��Ա���������Է��ʷǾ�̬��Ա����

		cout << "static void func( )�ĵ���" << endl;
	}

	static int m_a;  //��̬��Ա����
	int m_b;  //�Ǿ�̬��Ա����

	//��̬��Ա����Ҳ�з���Ȩ��
private:
	static void func2()
	{
		cout << "static void func2( )�ĵ���" << endl;
	}
};

int Person::m_a = 0;

//�����ַ��ʷ�ʽ
void test01()
{
	//1��ͨ���������
	Person p;
	p.func();

	//2��ͨ����������
	Person::func();

	//Person::func2();  //������ʲ���˽��Ȩ���µľ�̬��Ա���� ����
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///**********   32��Ͷ���-��������-��Ա�����ͳ�Ա�����ֿ��洢   ***********
//��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//ֻ�зǾ�̬��Ա������������Ķ�����
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//ֻ�зǾ�̬��Ա������������Ķ�����
	int m_a;  //�Ǿ�̬��Ա����  ������Ķ�����
	static int m_b;  //��̬��Ա����  ��������Ķ�����

	void func()   //�Ǿ�̬��Ա����  ��������Ķ�����
	{

	}
	
	static void func2()   //��̬��Ա����  ��������Ķ�����
	{

	}
};

int Person::m_b = 1;

void test01()
{
	Person p;

	//�ն���ռ�õ��ڴ�ռ�Ϊ1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
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





///*********   33��Ͷ���-��������-thisָ�����;   *************
//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
//thisָ����������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ�롣thisָ�벻��Ҫ���壬ֱ��ʹ�ü��ɡ�
//thisָ�����;��
//		���βκͳ�Ա����ͬ��ʱ������thisָ��������
//		����ķǾ�̬��Ա�����з��ض�������ʹ��return* this
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		//thisָ��ָ����� �����õĳ�Ա���������Ķ���
		this->age = age;
	}

	Person& PersonAddAge(Person &p)   //������ﷵ��ֵ���Ͳ���Person&����Person�����൱����ֵ�ķ�ʽ���أ�����Ͽ������캯���ĵ���ʱ������˷��ص���һ��������ֵ�����Ǳ������
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

//��;
//1�����βκͳ�Ա����ͬ��ʱ��������Ƴ�ͻ
void test01()
{
	Person p1(18);
	cout << "p1������Ϊ��" << p1.age << endl;
}

//2�����ض�������*this
void test02()
{
	Person p1(10);
	Person p2(20);
	Person p3(30);

	p2.PersonAddAge(p1);
	cout << "p2������Ϊ��" << p2.age << endl;

	//��ʽ���˼��
	p3.PersonAddAge(p1).PersonAddAge(p2);
	cout << "p3������Ϊ��" << p3.age << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
*/




///*******   34��Ͷ���-��������-��ָ����ʳ�Ա����   *************
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
/*
#include<iostream>
#include<string>
using namespace std;

//��ָ����ó�Ա����
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		//����ԭ���Ǵ����ָ��ΪNULL
		//cout << "age=" << m_age << endl;  //�൱��cout << "age=" << this->m_age << endl; 
		
		if (this == NULL)  //��ߴ��뽡׳��
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





///********   35��Ͷ���-��������-const���γ�Ա����   ***********
//��������
//		��Ա�������const�����ǳ��������Ϊ������
//		�������ڲ������޸ĳ�Ա����
//		��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
//������
//		��������ǰ��const�Ƹö���Ϊ������
//		������ֻ�ܵ��ó�����
/*
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//thisָ��ı�����ָ�볣��  ָ���ָ���ǲ������޸ĵ�
	//�ڳ�Ա�������const�����ε���thisָ�룬��ָ��ָ���ֵҲ�������޸�
	//const Person* const this;
	void showPerson() const
	{
		//this->m_a = 100;   //����
		this->m_b = 100;
	}

	void func()
	{
		m_a = 100;
	}
	
	int m_a;
	mutable int m_b;   //�����������ʹ�ڳ������У�Ҳ�����޸����ֵ��Ҫ��mutable�ؼ���
};

void test01()
{
	Person p;
	p.showPerson();
}

//������
void test02()
{
	const Person p;   //�ڶ���ǰ��const����Ϊ������
	//p.m_a = 100;   //����
	p.m_b = 100;   //�ڳ�������Ҳ�����޸�

	//������ֻ�ܵ��ó�����
	p.showPerson();
	//p.func();   //�������ܵ�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸ĳ�Ա����  ����
}

int main()
{


	system("pause");
	return 0;
}
*/





//��Ԫ��Ŀ�ľ�����һ�����������࣬������һ������˽�г�Ա���ؼ���Ϊfriend
//��Ԫ������ʵ�֣�
//		ȫ�ֺ�������Ԫ
//		������Ԫ
//		��Ա��������Ԫ
///********   36��Ͷ���-��Ԫ-ȫ�ֺ�������Ԫ   ***********
/*
#include<iostream>
#include<string>
using namespace std;

//ȫ�ֺ�������Ԫ
class Building
{
	//goodGayȫ�ֺ�����Building�����Ԫ�����Է���Building�е�˽�г�Ա
	friend void goodGay(Building& building);

public:
	Building()
	{
		m_settingRoom = "����";
		m_bedRoom = "����";
	}


public:
	string m_settingRoom;

private:
	string m_bedRoom;
};

//ȫ�ֺ���
void goodGay(Building& building)
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building.m_settingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building.m_bedRoom << endl;    //����˽�г�Ա����Ҫ��Building��������friend
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





///************   37��Ͷ���-��Ԫ-��Ԫ��   ***************
/*
#include<iostream>
#include<string>
using namespace std;

//������Ԫ
class Building;

class GoodGay
{
public:
	GoodGay();   //���캯��

	void visit();   //�ιۺ��� ����building�е�����

	Building* building;
};

class Building
{
	//GoodGay���Ǳ������Ԫ�����Է��ʱ����е�˽�г�Ա
	friend class GoodGay;

public:
	Building();   //���캯��

public:
	string m_sittingRoom;

private:
	string m_bedRoom;
};

//����д��Ա��������������дЧ��һ��
Building::Building()
{
	m_sittingRoom = "����";
	m_bedRoom = "����";
}
GoodGay::GoodGay()
{
	//�������������
	building = new Building;  //����

}

//����ʵ�ֳ�Ա����
void GoodGay::visit()
{
	cout << "�û����� ���ڷ��ʣ�" << building->m_sittingRoom << endl;
	cout << "�û����� ���ڷ��ʣ�" << building->m_bedRoom << endl;   //��Ԫ����˽�г�Ա
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





///**********   38��Ͷ���-��Ԫ-��Ա��������Ԫ   **********
/*
#include<iostream>
#include<string>
using namespace std;

//��Ա��������Ԫ
class Building;

class GoodGay
{
public:
	//����ʵ�ֳ�Ա����
	GoodGay(); 
	void visit();   //��visit���� ���� ����Building��˽�г�Ա
	void visit2();   //��visit2���� ������ ����Building��˽�г�Ա
	
	Building* building;
};

class Building
{
	//���߱�������GoodGay���µ�visit��Ա������Ϊ�������Ԫ�����Է��ʱ����˽�г�Ա
	friend void GoodGay::visit();   //������ GoodGay:: ����������Ϊ��ȫ�ֺ���

public:
	//����ʵ�ֳ�Ա����
	Building(); 

public:
	string m_sittingRoom;
private:
	string m_bedRoom;
};

Building::Building()
{
	m_sittingRoom = "����";
	m_bedRoom = "����";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit�������ڷ��ʣ�" << building->m_sittingRoom << endl;
	cout << "visit�������ڷ��ʣ�" << building->m_bedRoom << endl;   //��Ա��������Ԫ���Է���˽�г�Ա
}
void GoodGay::visit2()
{
	cout << "visit2�������ڷ��ʣ�" << building->m_sittingRoom << endl;
	//cout << "visit2�������ڷ��ʣ�" << building->m_bedRoom << endl;   //˽�г�Ա���ܷ���  ����
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





//�������ط���������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
///***********   39��Ͷ���-C++���������-�Ӻ����������   ***********
//���ã�ʵ�������Զ�������������ӵ�����
//�ܽ�1���������õ��������͵ı��ʽ��������ǲ����Ըı��
//�ܽ�2����Ҫ�������������
/*
#include<iostream>
#include<string>
using namespace std;

//�Ӻ����������
class Person
{
public:
	//1����Ա��������+��
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

//2��ȫ�ֺ�������+��
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_a = p1.m_a + p2.m_b;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}

//�������صİ汾
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

	//��Ա�������ر��ʵ���
	//Person p3 = p1.operator+(p2);
	//ȫ�ֺ������ر��ʵ���
	//Person p3 = operator+(p1, p2);

	Person p3 = p1 + p2;   //�򻯰汾
	cout << "p3.m_a=" << p3.m_a << endl;
	cout << "p3.m_b=" << p3.m_b << endl;

	//��������� Ҳ���Է�����������
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





///**********   40��Ͷ���-C++���������-�������������   **********
//���ã���������Զ�����������
//�ܽ᣺������������������Ԫ����ʵ������Զ�����������
/*
#include<iostream>
#include<string>
using namespace std;

//�������������
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
	//���ó�Ա�����������������
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
	//void operator<<(cout)
	//{

	//}

	int m_a;
	int m_b;
};

//ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream& cout, Person& p)  //����operator<<(cout,p)  ��cout<<p
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




///*********   41��Ͷ���-C++���������-�������������   ***********
//���ã�ͨ�����ص����������ʵ���Լ�����������
//�ܽ᣺��ǰ�õ����������ã����õ�������ֵ
/*
#include<iostream>
#include<string>
using namespace std;

//���ص��������
//�Զ�������
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_num = 0;
	}

	//����ǰ�õ��������
	MyInteger& operator++()
	{
		//�Ƚ���++����
		m_num++;
		//�ٽ�������
		return *this;
	}

	//���غ��õ��������
	//int����ռλ������������������ǰ�úͺ��õ���
	//���õ������ص���ֵ����������
	MyInteger operator++(int)
	{
		//�ȼ�¼��ʱ�Ľ��
		MyInteger temp = *this;
		//�ٽ���++����
		m_num++;
		//���֮ǰ��¼�Ľ������
		return temp;
	}

private:
	int m_num;
};

//�������������  ����������Ϊ��һֱ��һ�����ݽ��е�������
//�����MyInteger����&��ԭ���ǣ����غ��õ������ص���һ���ֲ�������ֵ��
//������������&�൱�ڷ��ؾֲ���������ã�����MyInteger operator++(int)������캯��ִ�����ֲ�����temp�ͻᱻ���٣���return�Ļ����ǷǷ�����
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
	cout << myint++ << endl;   //C++��֧�ֺ��õ�����ʽ���� Ҳ����(a++)++�ᱨ��
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




///*******   42��Ͷ���-C++���������-��ֵ���������   *********
//C++���������ٸ�һ�������4������
//		1��Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//		2��Ĭ�������������޲Σ�������Ϊ�գ�
//		3��Ĭ�Ͽ������캯���������Խ���ֻ����
//		4����ֵ�����operator=�������Խ���ֵ����
//�������������ָ�����������ֵ����ʱҲ�������ǳ��������
/*
#include<iostream>
#include<string>
using namespace std;

//��ֵ���������
class Person
{
public:
	Person(int age)
	{
		m_age = new int(age);
	}
	~Person()   //�������������ͷŶ�������
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	//���ظ�ֵ�����
	Person& operator=(Person& p)
	{
		 //�������ṩ����ǳ����
		//m_age = p.m_age;

		//Ӧ�����ж��Ƿ��������ڶ���������У����ͷŸɾ���Ȼ�������
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);

		return *this;  //���ض�����
	}

	int* m_age;
};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p2 = p1;   //��ֵ����
	cout << "p1������Ϊ��" << *p1.m_age << endl;
	cout << "p2������Ϊ��" << *p2.m_age << endl << endl;

	p3 = p2 = p1;
	cout << "p1������Ϊ��" << *p1.m_age << endl;
	cout << "p2������Ϊ��" << *p2.m_age << endl;
	cout << "p3������Ϊ��" << *p3.m_age << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/





///*******   43��Ͷ���-C++���������-��ϵ���������   *********
//���ã����ع�ϵ������������������Զ������Ͷ�����жԱȲ���
/*
#include<iostream>
#include<string>
using namespace std;

//���ع�ϵ�����
class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	//���ع�ϵ�����==
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
	//���ع�ϵ�����!=
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
		cout << "p1��p2���" << endl;
	}
	else
	{
		cout << "p1��p2�����" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1��p2�����" << endl;
	}
	else
	{
		cout << "p1��p2���" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   44��Ͷ���-C++���������-�����������������   *********
//�������������( )Ҳ��������
//�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//�º���û�й̶�д�����ǳ�������ֵ������Ҫ�󣬺�������Ҳ��Ҫ��
/*
#include<iostream>
#include<string>
using namespace std;

//�����������������
class MyPrint
{
public:

	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};

//�º����ǳ���û�й̶���д��
//�ӷ���
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
	myprint("hello world");  //����ʹ�������ǳ������ں������ã���˳�Ϊ�º���

	MyPrint02("hello world");  //��ͨ�ĺ�������
}

void test02()
{
	MyAdd myadd;
	int result= myadd(10, 20);
	cout << "result=" << result << endl;

	//������������
	//��Ϊ�����Ķ���ʹ����ͱ������ˣ�ûʲô�ã���ʵֱ�ӿ���ʹ����������
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




//�̳�������������������֮һ
///*******   45��Ͷ���-�̳�-�����﷨   ************
//�̳еĺô������ٴ����ظ�
//�﷨��class ���ࣺ�̳з�ʽ ����
//���� Ҳ��Ϊ ������
//���� Ҳ��Ϊ ����
//�������еĳ�Ա�������󲿷֣�һ�����Ǵӻ���̳й����ģ�һ�������Լ����ӵĳ�Ա
//�ӻ���̳й����ı����乲�ԣ��������ĳ�Ա�����������
/*
#include<iostream>
#include<string>
using namespace std;

//��ͨʵ��ҳ��
//Javaҳ��
//class Java
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void cotent()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//
////Pythonҳ��
//class Python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void cotent()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//};
//
////C++ҳ��
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void cotent()
//	{
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//};//

//�̳�ʵ��ҳ��
//����ҳ����
class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void left()
	{
		cout << "Java��Python��C++...�����������б�" << endl;
	}
};

//Javaҳ��
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};
//Pythonҳ��
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
//C++ҳ��
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

void test01()   //���Դ��벻��
{
	Java ja;
	Python py;
	CPP cpp;

	cout << "Java������Ƶ�������£�" << endl;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "---------------------------------------------" << endl;
	cout << "Python������Ƶ�������£�" << endl;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "---------------------------------------------" << endl;
	cout << "C++������Ƶ�������£�" << endl;
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





///*******   46��Ͷ���-�̳�-�̳з�ʽ   **********
////�̳е��﷨��class ���ࣺ�̳з�ʽ ����
//�̳з�ʽһ�������֣�
//		�����̳�
//		�����̳�
//		˽�м̳�
/*
#include<iostream>
#include<string>
using namespace std;

//�̳з�ʽ
//		�����̳�
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
		m_a = 10;   //�����еĹ���Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
		m_b = 10;   //�����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
		//m_c = 10;  //�����е�˽��Ȩ�޳�Ա ������ʲ��� ����
	}
};

void test01()
{
	Son1 s1;
	s1.m_a = 100;   //����Ȩ�޳�Ա ���ڿ��Է��� ���ⲻ���Է���
	//s1.m_b = 100;  //��Son1�� m_b�Ǳ���Ȩ�� ���ڿ��Է��� ������ʲ��� ����
}

//		�����̳�
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
		m_a = 100;  //�����еĹ���Ȩ�޳�Ա �������б�Ϊ����Ȩ��
		m_b = 100;  //�����еı���Ȩ�޳�Ա ����������ȻΪ����Ȩ��
		//m_c = 100;   //�����е�˽��Ȩ�޳�Ա ������ʲ��� ����
	}
};

void test02()
{
	Son2 s1;
	//s1.m_a = 10;   //��Son2�У�m_a��Ϊ����Ȩ�ޣ�������ʲ��� ����
	//s1.m_b = 10;  //m_bΪ����Ȩ�ޣ�������ʲ��� ����
}

//		˽�м̳�
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
		m_a = 100;  //�����еĹ���Ȩ�޳�Ա �������б�Ϊ˽��Ȩ�޳�Ա
		m_b = 100;   //�����еı���Ȩ�޳�Ա �������б�Ϊ˽��Ȩ�޳�Ա
		//m_c = 100;   //�����е�˽��Ȩ�޳�Ա ������ʲ��� ����
	}
};

void test03()
{
	Son3 s1;
	//s1.m_a = 10;  //����Son3�У�m_a��Ϊ˽�г�Ա��������ʲ��� ����
	//s1.m_b = 10;  //����Son3�У�m_a��Ϊ˽�г�Ա��������ʲ��� ����
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_a = 10;  //����Son3�У�m_a��Ϊ˽��Ȩ�޳�Ա�����ⲻ�ɷ��� ����
		//m_b = 10;  //����Son3�У�m_b��Ϊ˽��Ȩ�޳�Ա�����ⲻ�ɷ��� ����
	}
};

int main()
{

	system("pause");
	return 0;
}
*/




//���ÿ�����Ա������ʾ���߲鿴����ģ��
//��ת�̷�
//��ת�ļ�·��������·����
//�鿴����
//  c1 /d1 reportSingleClassLayout���� �ļ���
//���磺D:\C++Projects\C++���ı��\C++���ı��>cl /d1 reportSingleClassLayoutSon "C++���ı��.cpp"

///*******   47��Ͷ���-�̳�-�̳��еĶ���ģ��   **********
//���⣺�Ӹ���̳й����ĳ�Ա����Щ�����������
//���ۣ�������˽�г�ԱҲ�Ǳ�����̳���ȥ�ˣ�ֻ�Ǳ����������غ���ʲ�������
/*
#include<iostream>
#include<string>
using namespace std;

//�̳��еĶ���ģ��
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

//���ÿ�����Ա������ʾ���߲鿴����ģ��
//��ת�̷�
//��ת�ļ�·��������·����
//�鿴����
//  c1 /d1 reportSingleClassLayout���� �ļ���
//���磺D:\C++Projects\C++���ı��\C++���ı��>cl /d1 reportSingleClassLayoutSon "C++���ı��.cpp"


void test01()
{
	//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	//������˽�г�Ա���� �Ǳ������������� ��˷��ʲ��� ����ȷʵ���̳���ȥ��
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




///*******   48��Ͷ���-�̳�-���������˳��   *********
//����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
//���⣺���������Ĺ��������˳����˭��˭��
//���ۣ��̳����ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴
/*
#include<iostream>
#include<string>
using namespace std;

//�̳��еĹ��������˳��
class Base
{
public:
	Base()
	{
		cout << "Base���캯��" << endl;
	}
	~Base()
	{
		cout << "Base��������" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son���캯��" << endl;
	}
	~Son()
	{
		cout << "Son��������" << endl;
	}
};

void test01()
{
	//Base b;

	//�̳��еĹ��������˳�����£�
	//�ȹ��츸�࣬�ٹ������࣬����˳���빹��˳���෴
	Son s;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



///*******   49��Ͷ���-�̳�-ͬ����Ա����   **********
//���⣺�������븸�����ͬ����Ա�����ͨ��������󣬷��ʵ����������ͬ���������أ�
//��������ͬ����Ա��ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա����Ҫ��������
/*
#include<iostream>
#include<string>
using namespace std;

//�̳���ͬ����Ա����
class Base
{
public:
	Base()
	{
		m_a = 100;
	}

	void func()
	{
		cout << "Base��func()����" << endl;
	}
	void func(int a)   //����
	{
		cout << "Base��func(int a)����" << endl;
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
		cout << "Son��func()����" << endl;
	}

	int m_a;
};

//ͬ����Ա���Դ���
void test01()
{
	Son s;
	Base b;

	cout << "Son��m_a = " << s.m_a << endl;
	//���ͨ��������󣬷��ʵ�������ͬ����Ա����Ҫ��������
	cout << "Base��m_a = " << s.Base::m_a << endl;
}

//ͬ����Ա��������
void test02()
{
	Son s;
	Base b;

	s.func();
	s.Base::func();

	//��������г��ֺ͸���ͬ���ĳ�Ա��������ô�����ͬ����Ա�����ص����������е�ͬ����Ա�������������صģ�
	//s.func(100);  //ֻҪ����һ������ͬ����Ա���� �޷�ֱ�ӷ��� ����
	s.Base::func(100);   //Ҫ��������
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




///*******   50��Ͷ���-�̳�-ͬ����̬��Ա����   **********
//���⣺�̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�����̬��Ա�ؿ�P31��
//��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ�£�ֻ������̬��Ա�����ַ��ʷ�ʽ��ͨ�������ͨ��������
//��������ͬ����Ա��ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա����Ҫ��������
/*
#include<iostream>
#include<string>
using namespace std;

//�̳��е�ͬ����̬��Ա����ʽ
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

//ͬ����̬��Ա����
void test01()
{
	//��̬��Ա1��ͨ���������
	cout << "ͨ���������" << endl;
	Son s;
	cout << "Son��m_a = " << s.m_a << endl;
	cout << "Base��m_a = " << s.Base::m_a << endl;

	//��̬��Ա2��ͨ����������
	cout << "ͨ����������" << endl;
	cout << "Son��m_a = " << Son::m_a << endl;
	//��һ�� :: ����ͨ��������ʽ���ʣ��ڶ��� :: ������ʸ�����������
	cout << "Base��m_a = " << Son::Base::m_a << endl;
}

//ͬ����̬��Ա����
void test02()
{
	//��̬��Ա1��ͨ���������
	cout << "ͨ���������" << endl;
	Son s;
	s.func();
	s.Base::func();

	//��̬��Ա2��ͨ����������
	cout << "ͨ����������" << endl;
	Son::func();
	Son::Base::func();

	//Son::func(100);   //������ͬ����Ա�������أ���Ҫ����������ܷ���  ����
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




///*******   51��Ͷ���-�̳�-��̳��﷨   **********
//    C++����һ����̳ж����
//    �﷨��class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2...
//    ��̳п��ܻ�����������ͬ����Ա���֣���Ҫ������������
//     *** C++ʵ�ʿ����в�����ʹ�ö�̳� ***
/*
#include<iostream>
#include<string>
using namespace std;

//��̳��﷨
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

//���� ��Ҫ�̳�Base1��Base2
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

	//�������г���ͬ����Ա����Ҫ������������
	cout << "Base1��m_a = " << s.Base1::m_a << endl;
	cout << "Base2��m_a = " << s.Base2::m_a << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   52��Ͷ���-�̳�-���μ̳�   **********
// ���μ̳и��
// ����������̳�ͬһ������
//	����ĳ����ͬʱ�̳�������������
//	���ּ̳б���Ϊ���μ̳У�������ʯ�̳�
//������̳п��Խ�����μ̳�����
/*
#include<iostream>
#include<string>
using namespace std;

//������
class Animal
{
public:
	int m_age;
};

//������̳У����Խ�����μ̳е�����
// �̳�֮ǰ�����Ϲؼ��� virtual ��Ϊ��̳�
// Animal�������Ϊ �����
//����
class Sheep :virtual  public Animal
{};

//����
class Tuo :virtual public Animal
{};

//������
class SheepTuo :public Sheep, public Tuo
{};

void test01()
{
	SheepTuo st;
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;

	//���������μ̳�ʱ����������ӵ����ͬ���ݣ���Ҫ��������������
	cout << "st.Sheep::m_age = " << st.Sheep::m_age << endl;
	cout << "st.Tuo::m_age = " << st.Tuo::m_age << endl;
	
	//�����������֪����ֻҪ��һ�ݾ͹��ˣ����μ̳е������������ݣ���Դ�˷�
	cout << "st.m_age = " << st.m_age << endl;   //��Ϊ��̳�֮�����ݾ�ֻ��һ�ݣ�����Ҫ��������
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   53��Ͷ���-��̬-��̬�Ļ����﷨   ********
//��̬��Ϊ����
//		��̬��̬���������غ�������������ھ�̬��̬�����ú�����
//		��̬��̬����������麯��ʵ������ʱ��̬
//��̬��̬�Ͷ�̬��̬����
//		��̬��̬�ĺ�����ַ��󶨣�����׶�ȷ��������ַ
//		��̬��̬�ĺ�����ַ��󶨣����н׶�ȷ��������ַ

//��̬��̬����������
//		1���м̳й�ϵ
//		2������Ҫ��д������麯������д����������ֵ���͡��������������б���ȫ��ͬ��Ϊ��д��

//��̬��̬ʹ��
// �����ָ�������ָ��ִ���������
/*
#include<iostream>
#include<string>
using namespace std;

//��̬
//������
class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

//è��
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

//ִ��˵���ĺ���
//��ַ��� �ڱ���׶ξ�ȷ���˺�����ַ
//�����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�Ҳ���ǵ�ַ���

//��̬��̬����������
//		1���м̳й�ϵ
//		2������Ҫ��д������麯������д����������ֵ���͡��������������б���ȫ��ͬ��

//��̬��̬ʹ�ã�
//		�����ָ�������ָ��ִ���������

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





///*******   54��Ͷ���-��̬-��̬��ԭ������   *********
/*
#include<iostream>
#include<string>
using namespace std;

//��̬
//������
class Animal
{
public:
	//�麯��
	 virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

//è��
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

//ִ��˵���ĺ���
//��ַ��� �ڱ���׶ξ�ȷ���˺�����ַ
//�����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�Ҳ���ǵ�ַ���

//��̬��̬����������
//		1���м̳й�ϵ
//		2������Ҫ��д������麯������д����������ֵ���͡��������������б���ȫ��ͬ��

//��̬��̬ʹ��
// �����ָ�������ָ��ִ���������

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
	test02();  //sizeΪ4������һ���麯����ָ��

	system("pause");
	return 0;
}
*/
///////////






///********   55��Ͷ���-��̬-����1-��������   ********
//����������
//		�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������
//��̬���ŵ㣺
//		������֯�ṹ����
//		�ɶ���ǿ
//		����ǰ�ںͺ��ڵ���չ�Լ�ά��
//C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�ŵ�ܶ�
/*
#include<iostream>
#include<string>
using namespace std;

//�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����
//��ͨд��
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
		//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
		//����ʵ�Ŀ����У��ᳫ����ԭ��
		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
	}

	int m_num1;	//������1
	int m_num2;	//������2
};

void test01()
{
	//��������������
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 20;

	cout << c.m_num1 << " + " << c.m_num2 << " = " << c.getResult("+") << endl;
	cout << c.m_num1 << " - " << c.m_num2 << " = " << c.getResult("-") << endl;
	cout << c.m_num1 << " * " << c.m_num2 << " = " << c.getResult("*") << endl;
}

//���ö�̬ʵ�ּ�����
// ��̬�����ĺô���
//		1����֯�ṹ����
//		2���ɶ���ǿ
//		3������ǰ�ںͺ��ڵ���չ�Լ�ά��

//ʵ�ּ������ĳ����ࣨ���ࣩ
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
//�ӷ���������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1+m_num2;
	}
};
//������������
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//�˷���������
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
	//��̬ʹ������
	//����ָ�������ָ������Ķ���

	//�ӷ�
	AbstractCalculator* abc = new AddCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//�����ǵ����ٶ�������
	delete abc;

	//����
	abc = new SubCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;

	//�˷�
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




///*******   ��Ͷ���-��̬-����1-�������ࣨ��д��   *************
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
	cout << "�����뱻��������";
	cin >> arr[0];
	cout << "�������������";
	cin >> arr[1];
	return arr;
}


void test01()
{
	//******ʹ��ָ��
	//AbstractCalculator* abs = new AddCalculator;
	////�ӷ�
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " + " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;
	////����
	//abs =new SubCalculator;
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " - " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;
	////�˷�
	//abs = new MulCalculator;
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " * " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;
	////����
	//abs = new DivCalculator;
	//abs->m_num1 = 10;
	//abs->m_num2 = 20;
	//cout << abs->m_num1 << " / " << abs->m_num2 << " = " << abs->func() << endl;
	//delete abs;

	//******ʹ������
	int* arr = getnum();
	int num1 = arr[0];
	int num2 = arr[1];
	//�ӷ�
	AddCalculator addcal;
	addcal.m_num1 = num1;
	addcal.m_num2 = num2;
	cout << addcal.m_num1 << " + " << addcal.m_num2 << " = " << Calculator(addcal) << endl;
	//����
	SubCalculator subcal;
	subcal.m_num1 = num1;
	subcal.m_num2 = num2;
	cout << subcal.m_num1 << " - " << subcal.m_num2 << " = " << Calculator(subcal) << endl;
	//�˷�
	MulCalculator mulcal;
	mulcal.m_num1 = num1;
	mulcal.m_num2 = num2;
	cout << mulcal.m_num1 << " * " << mulcal.m_num2 << " = " << Calculator(mulcal) << endl;
	//����
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



///*******   56��Ͷ���-��̬-���麯���ͳ�����   ********
//�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д�����ݣ���˿��Խ��麯����Ϊ���麯��
//���麯���﷨��virtual ����ֵ���� �������������б�=0 ��
//���������˴��麯���������Ҳ��Ϊ������
//�������ص�
//		�޷�ʵ��������
//		���������д�������еĴ��麯��������Ҳ���ڳ�����
/*
#include<iostream>
#include<string>
using namespace std;

//���麯���ͳ�����
class Base
{
public:
	//���麯��
	//ֻҪ��һ�����麯���������ͳ�Ϊ������
	//�������ص�
	//  1���޷�ʵ��������
	//  2�����������������д�������еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;  

};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func��������" << endl;
	};
};

void test01()
{
	//Base b;  //�������޷�ʵ�������� ����
	//new Base;   //�������޷�ʵ�������� ����
	Son s;  //���������д�����еĴ��麯���������޷�ʵ��������

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



///*******   57��Ͷ���-��̬-����2-������Ʒ   ********
//����������
//������Ʒ�Ĵ�������Ϊ����ˮ-����-���뱭��-���븨��
//���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ
/*
#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//������Ʒ���൱�ڰѺ������ϣ�������ã�
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뿧�ȱ���" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

//������Ҷ
class Tea :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "����豭��" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "��������" << endl;
	}
};

//������Ʒ��������Ҫ�ɲ�Ҫ��
void doWork(AbstractDrinking* abs)   //AbstractDrinking* abs=new Coffee;
{
	abs->makeDrink();
	delete abs;   //�ǵ��ͷŶ������ݣ���
}

void test01()
{
	//��������
	doWork(new Coffee);
	cout << "����������ɣ�" << endl << endl;
	//������Ҷ
	doWork(new Tea);
	cout << "��Ҷ������ɣ�" << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   58 ��Ͷ���-��̬-�������ʹ�������   *********
//��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
//�����ʽ���������е�����������Ϊ���������ߴ�������
//�������ʹ����������ԣ�
//		���Խ������ָ���ͷ��������
//		����Ҫ�о���ĺ���ʵ��
//�������ʹ�����������
//		����Ǵ����������������ڳ����࣬�޷�ʵ��������
/*
#include<iostream>
#include<string>
using namespace std;

//�������ʹ�������
class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}

	//���������������Խ������ָ���ͷ�������󲻸ɾ�������
	//virtual ~Animal()
	//{
	//	cout << "Animal������������" << endl;
	//}

	//�������� ��������Ҳ��Ҫ����ʵ�֣�������
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;

	virtual void speak() = 0;

};

Animal::~Animal()
{
	cout << "Animal����������������" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat���캯������" << endl;
		m_name = new string(name);
	}

	void speak()
	{
		cout << *m_name << "Сè��˵��" << endl;
	}

	~Cat()
	{
		if (m_name != NULL)
		{
			cout << "Cat������������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	//�������У������Կ������˶���������Ҫ���������룬����Ƕ�̬����Ҫ������
	string *m_name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ��������ʱ�������������������������������������ж������ݣ�������ڴ�й©
	delete animal;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/




///*******   59&60 ��Ͷ���-��̬-����3-������װ�������   *******
//������Ҫ��ɲ���ΪCPU���Կ����ڴ���
//��ÿ�������װ�ɳ�����࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����
//�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
//����ʱ��װ��̨��ͬ�ĵ��Խ��й���
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

	//�ṩ�����ĺ���
	void work()
	{
		//������������������ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//�ṩ�������� �ͷ�3���������
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
	CPU* m_cpu;	//CPU���ָ��
	VideoCard* m_vc;		//�Կ����ָ��
	Memory* m_mem;		//�ڴ������ָ��
};

//���峧��
//Intel
class IntelCPU:public CPU
{
	void calculate()
	{
		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};
class IntelVC :public VideoCard
{
	void display()
	{
		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};
class IntelMEM :public Memory
{
	void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};

//Lenovo
class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "�����CPU��ʼ�����ˣ�" << endl;
	}
};
class LenovoVC :public VideoCard
{
	void display()
	{
		cout << "������Կ���ʼ��ʾ�ˣ�" << endl;
	}
};
class LenovoMEM :public Memory
{
	void storage()
	{
		cout << "������ڴ�����ʼ�洢�ˣ�" << endl;
	}
};

void test01()
{
	//��һ̨������װ
	//��һ̨�������
	CPU* cpu = new IntelCPU;   //����ָ��ָ������
	VideoCard* vc = new IntelVC;
	Memory* mem = new LenovoMEM;
	//������һ̨����
	cout << "��һ̨���Կ�ʼ������" << endl;
	Computer* computer1 = new Computer(cpu, vc, mem);
	computer1->work();
	delete computer1;
	cout << endl;

	//�ڶ�̨������װ
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new IntelVC, new LenovoMEM);
	computer2->work();
	delete computer2;
	cout << endl;

	//����̨������װ
	cout << "����̨���Կ�ʼ������" << endl;
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





///*******   ��Ͷ���-��̬-����3-������װ�����������д��   *********
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
		cout << "Intel��CPU���ڼ��㣡" << endl;
	}
};
class IntelVideocard :public Videocard
{
public:
	void display()
	{
		cout << "Intel���Կ�������ʾ��" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel���ڴ������ڴ洢��" << endl;
	}
};

//����
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo��CPU���ڼ��㣡" << endl;
	}
};
class LenovoVideocard :public Videocard
{
public:
	void display()
	{
		cout << "Lenovo���Կ�������ʾ��" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo���ڴ������ڴ洢��" << endl;
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




//��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�
//ͨ���ļ����Խ����ݳ־û�
//C++�ж��ļ�������Ҫ����ͷ�ļ�<fstream>

//�ļ����ͷ�Ϊ���֣�
//		1���ı��ļ����ļ����ı���ASCII����ʽ�洢�ڼ������
//		2���������ļ����ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������

//�����ļ��������ࣺ
//		1��ofstream��д����
//		2��ifstream��������
//		3��fstream����д����

///*******   61 C++�ļ�����-�ı��ļ�-д�ļ�   **********
//д�ļ��������£�
//		1������ͷ�ļ�   #include<fstream>
//		2������������   ofstream ofs;
//		3�����ļ�   ofs.open("�ļ�·��"���򿪷�ʽ)
//		4��д����   ofs<<"д�������";
//		5���ر��ļ�   ofs.close();

//�ļ��򿪷�ʽ��
//		ios::in			Ϊ���ļ������ļ�
//		ios::out			Ϊд�ļ������ļ�
//		ios::ate			��ʼλ�ã��ļ�β
//		ios::app		׷�ӷ�ʽд�ļ�
//		ios::trunc		����ļ�������ɾ�����ٴ���
//		ios::binary	�����Ʒ�ʽ
//ע�⣺�ļ��򿪷�ʽ�������ʹ�ã����� | ������
//���磺�ö����Ʒ�ʽд�ļ���ios::binary | ios::out
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�ı��ļ� д�ļ�
void test01()
{
//		1������ͷ�ļ�   #include<fstream>
//		2������������   ofstream ofs;
	ofstream ofs;
//		3�����ļ�   ofs.open("�ļ�·��"���򿪷�ʽ)
	ofs.open("text.txt", ios::out);   //����·�������·������
//		4��д����   ofs<<"д�������";
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
//		5���ر��ļ�   ofs.close();
	ofs.close();
}

int main()
{
	test01();
	cout << "�ļ�д����ɣ�" << endl;

	system("pause");
	return 0;
}
*/



///*******   62 C++�ļ�����-�ı��ļ�-���ļ�   **********
//���ļ���д�ļ��������ƣ�����ȡ��ʽ��Խ϶�
//���ļ��������£�
//		1������ͷ�ļ�   #include<fstream>
//		2������������   ifstream ifs;
//		3�����ļ����ж��ļ��Ƿ�򿪳ɹ�   ifs.open("�ļ�·��"���򿪷�ʽ);
//		4��������   ���ַ�ʽ��ȡ
//		5���ر��ļ�   ifs.close();
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�ı��ļ� ���ļ�
void test01()
{
//		1������ͷ�ļ�   #include<fstream>
//		2������������   ifstream ifs;
	ifstream ifs;
//		3�����ļ����ж��ļ��Ƿ�򿪳ɹ�   ifs.open("�ļ�·��"���򿪷�ʽ);
	ifs.open("D:\\C++Projects\\C++���ı��\\C++���ı��\\text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
//		4��������   ���ַ�ʽ��ȡ
//��һ��
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
//�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
//������
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}
//�����֣����Ƽ���
	//char c;
	//while ((c = ifs.get()) != EOF)   //EOF��end of file
	//{
	//	cout << c;
	//}
//		5���ر��ļ�   ifs.close();
	ifs.close();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
*/



///*******   63 C++�ļ�����-�������ļ�-д�ļ�   ********
//�Զ����Ƶķ�ʽ���ļ����ж�д����
//�򿪷�ʽҪָ��Ϊ ios::binary
//�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
//����ԭ�ͣ�ostream& write(const char* buffer, int len);
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�������ļ� д�ļ�
//�����Ʋ������Բ�����������������int�ȣ�Ҳ���Բ����Զ����������ͣ����罫�Լ���������д���ļ���
class Person
{
public:
	char m_name[64];   //�����������ļ�ʮ��ò���string��ֱ����char�ַ�����
	int m_age;
};

void test01()
{
//1������ͷ�ļ�
//2������������
	ofstream ofs("person.txt", ios::out | ios::binary);
//3�����ļ�
	//ofs.open("person.txt", ios::out | ios::binary);
//4��д�ļ�
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(Person));
//5���ر��ļ�
	ofs.close();
}

void test02()
{
	ofstream ofs2("liu.txt", ios::out | ios::binary);
	char myInfo[64] = { "��������Х��\n���䣺23\n�Ա���" };
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




///*******   64 C++�ļ�����-�������ļ�-���ļ�   ********
//�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
//����ԭ�ͣ�istream& read(char* buffer, int len);
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
/*
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
public:
	char m_name[64];   //�����������ļ�ʮ��ò���string��ֱ����char�ַ�����
	int m_age;
};

//�������ļ� ���ļ�
void test01()
{
//1������ͷ�ļ�
//2������������
	ifstream ifs;
//3�����ļ����ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
//4�����ļ�
	Person p;
	ifs.read((char*) &p, sizeof(Person));
	cout << "������" << p.m_name << endl;
	cout << "���䣺" << p.m_age << endl;
//5���ر��ļ�
	ifs.close();
}

void test02()
{
	char myInfo[64] = { 0 };

	ifstream ifs2("liu.txt", ios::in | ios::binary);
	if (!ifs2.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
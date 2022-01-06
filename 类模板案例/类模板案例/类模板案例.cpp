//����������ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//		���Զ��������������Լ��Զ����������͵����ݽ��д洢
//		�������е����ݴ洢������
//		���캯���п��Դ������������
//		�ṩ��Ӧ�Ŀ������캯���Լ� operator=��ֹǳ��������
//		�ṩβ�巨��β���������е����ݽ������Ӻ�ɾ��
//		����ͨ���±�ķ�ʽ���������е�Ԫ��
//		���Ի�ȡ�����е�ǰԪ�ظ��������������

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
		//����β�巨�������в�������
		arr1.PushBack(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr1);

	cout << "arr1������Ϊ��" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ��" << arr1.getSize() << endl << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr2);

	arr2.PopBack();		//βɾ
	cout << "arr2βɾ��" << endl;
	cout << "arr2������Ϊ��" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ��" << arr2.getSize() << endl << endl;

	//MyArray<int> arr2(arr1);

	//MyArray<int> arr3(100);
	//arr3 = arr1;
}

//�����Զ�����������
class Person
{
public:
	Person() {};	//Ĭ�Ϲ��캯����ʵ�ּ���
	Person(string name, int age)		//�вι���
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
		cout << "������" << arr[i].m_name << '\t'
			<< "����" << arr[i].m_age << endl;
	}
}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("�����", 999);
	Person p2("����", 20);
	Person p3("Tom", 10);
	Person p4("Jerry", 8);
	Person p5("Liu Xiaoya", 23);

	//�����ݲ��뵽������
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);

	//��ӡ����
	printPersonArray(arr);

	cout << "��������Ϊ��" << arr.getCapacity() << endl;
	cout << "�����СΪ��" << arr.getSize() << endl << endl;

	arr.PopBack();
	cout << "βɾ��" << endl;
	cout << "��������Ϊ��" << arr.getCapacity() << endl;
	cout << "�����СΪ��" << arr.getSize() << endl;
}

int main()
{
	cout << "--------���԰���1--------" << endl;
	test01();
	cout << "--------���԰���2--------" << endl;
	test02();

	system("pause");
	return 0;
}
//////////////  01 C++��дHelloWorld
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	system("pause");

	return 0;
}
*/




/////////////////   02  ע��
/*
#include<iostream>
using namespace std;

//�е���ע�ͺͶ���ע��

int main()
{
	//���Hello World!
	cout << "Hello World!" << endl;
	system("pause");

	return 0;
}
*/



///////////////    03  ����
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	cout << "a=" << a << endl;

	system("pause");

	return 0;
}
*/




///////////   04 ���������������
/*
#include<iostream>
using namespace std;

//�����Ķ��巽ʽ
//1��#define �곣��
//2��const���εı���

//1��#define �곣��
#define Day 7
int main()
{
	cout << "һ�ܹ���" << Day << "��" << endl;

	//2��const���εı���
	const int month = 12;
	cout << "һ����" << month << "��" << endl;

	system("pause");
	return 0;
}
*/





////////////   05 �ؼ���
/*
������������ʱ����Ҫ�ùؼ���������
*/





/////////////  06 ��ʶ����������
/*
��ʶ�������ǹؼ���
��ʶ��ֻ������ĸ�����֡��»������
��ʶ����һ���ַ�ֻ������ĸ���»���
��ʶ�����ִ�Сд
*/





////////////////   07 ��������-����
/*
//�������͵Ĵ������壺������������ʵ��ڴ�ռ�
#include<iostream>
using namespace std;

int main()
{
	//����
	//1��������
	short num1 = 10;
	//2������
	int num2 = 10;
	//3��������
	long num3 = 10;
	//4����������
	long long num4 = 10;

	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;

	system("pause");
	return 0;
}
*/




///////////   09 ��������-sizeof�ؼ���
/*
//sizeof����ͳ������������ռ�ڴ��С size(��������/����)

#include<iostream>
using namespace std;

int main()
{
	//���ͣ�short    int    long    long long
	short num1 = 100;
	int num2 = 200;
	long num3 = 300;
	long long num4 = 400;
	cout << "ռ�õ��ڴ�ռ�:" << sizeof(short) << endl;
	cout << "ռ�õ��ڴ�ռ�:" << sizeof(num2) << endl;
	cout << "ռ�õ��ڴ�ռ�:" << sizeof(long) << endl;
	cout << "ռ�õ��ڴ�ռ�:" << sizeof(num4) << endl;

	system("pause");
	return 0;
}
*/





//////////////   10 ��������-ʵ�ͣ������ͣ�
/*
#include<iostream>
using namespace std;

int main()
{
	float f1 = 3.1415926f;   //Ĭ����������һ��С��������ʾ��λ��Ч����
	cout << "f1=" << f1 << endl;

	double d1 = 3.1415926;
	cout << "d1=" << d1 << endl;

	cout << "floatռ���ڴ�ռ�Ϊ" << sizeof(float) << endl;
	cout << "doubleռ���ڴ�ռ�Ϊ" << sizeof(double) << endl;

	//��ѧ������
	float f2 = 3e2f;   //3*10^2
	cout << "f2=" << f2 << endl;

	float f3 = 3e-2f;   //3*0.1^2
	cout << "f3=" << f3 << endl;

	system("pause");
	return 0;
}
*/




//////////////   11 ��������-�ַ���
/*
#include<iostream>
using namespace std;

int main()
{
	char ch = 'a';
	cout << ch << endl;
	cout << sizeof(ch) << endl;
	cout << (int)ch << endl;

	system("pause");
	return 0;
}
*/




//////////////   12 ��������-ת���ַ�
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "hello\nworld" << endl;
	cout << "\\" << endl;
	cout << "aaaa\they" << endl;  //ˮƽ�Ʊ��\t ���ҿ���������������
	cout << "aa\they" << endl;
	cout << "aaaaaa\they" << endl;

	system("pause");
	return 0;
}
*/





//////////////   13 ��������-�ַ�������
/*
#include<iostream>
#include<string>   //��string����ʱ Ҫ�������ͷ�ļ�
using namespace std;

int main()
{
	//1��C����ַ���
	char str1[] = "hello world";
	cout << str1 << endl;
	cout << str1[1] << endl;

	//2��C++����ַ���
	string str2 = "i am fine";
	cout << str2 << endl;
	cout << str2[2] << endl;

	system("pause");
	return 0;
}
*/





//////////////   14��������-��������
/*
#include<iostream>
using namespace std;

int main()
{
	bool flag1 = true;   //��������ֻҪ��0��������
	bool flag2 = false;

	cout << flag1 << endl;
	cout << flag2 << endl;
	cout << sizeof(flag1) << endl;

	system("pause");
	return 0;
}
*/





//////////////   15��������-���ݵ�����
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//��������
	int a = 0;
	cout << "���aһ��ֵ��" << endl;
	cin >> a;
	cout << "a��ֵΪ��" << a << endl;

	//����������
	float f = 3.14f;
	cout << "���fһ��ֵ��" << endl;
	cin >> f;
	cout << "f��ֵΪ��" << f << endl;

	//�ַ���
	char ch = ' ';
	cout << "���chһ��ֵ��" << endl;
	cin >> ch;
	cout << "ch��ֵΪ��" << ch << endl;

	//�ַ�����
	string str = " ";
	cout << "���strһ��ֵ��" << endl;
	cin >> str;
	cout << "str��ֵΪ��" << str << endl;

	//������
	bool flag = false;
	cout << "���flagһ��ֵ��" << endl;
	cin >> flag;
	cout << "flag��ֵΪ��" << flag << endl;

	system("pause");
	return EXIT_SUCCESS;
}
*/






//////////////   16�����-���������-�Ӽ��˳�����
/*
#include<iostream>
using namespace std;

int main()
{
	int a1 = 10;
	int b1 = 3;

	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;  //�������Ϊ����

	int a2 = 10;
	int b2 = 20;
	cout << a2 / b2 << endl;

	double d1 = 0.5;
	double d2 = 0.22;
	cout << d1 / d2 << endl;

	system("pause");
	return 0;
}
*/






//////////////   17�����-���������-ȡģ����
/*
#include<iostream>
using namespace std;

int main()
{
	int a1 = 10;
	int b1 = 3;
	cout << a1 % b1 << endl;
	cout << 10 % 20 << endl;
	cout << 40 % 20 << endl;
	//cout<<3.14%2.11<<endl;  С��������ȡģ����

	system("pause");
	return 0;
}
*/





//////////////   18�����-���������-�����ݼ�
/*
#include<iostream>
using namespace std;

int main()
{
	//ǰ�õ��� ���õ���
	int a = 1;
	int b = ++a;
	int c = 1;
	int d = c++;
	cout << "a=" << a << "\tb=" << b << endl;
	cout << "c=" << c << "\td=" << d << endl;

	//ǰ�õݼ� ���õݼ�
	int m = 1;
	int n = --m;
	int p = 1;
	int q = p--;
	cout << "m=" << m << "\tn=" << n << endl;
	cout << "p=" << p << "\tq=" << q << endl;

	//ǰ�õ����ͺ��õ���������
	//ǰ�õ��� ���ñ���+1 Ȼ����б��ʽ����
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2=" << a2 << endl;
	cout << "b2=" << b2 << endl;

	//���õ��� �Ƚ��б��ʽ���� ���ñ���+1
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;

	system("pause");
	return 0;
}
*/







//////////////   19�����-��ֵ�����
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 10, b = 10, c = 10, d = 10, e = 10;
	a += 10;
	b -= 2;
	c *= 3;
	d /= 5;
	e %= 3;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
	cout << "e=" << e << endl;

	system("pause");
	return 0;
}
*/





//////////////   20�����-�Ƚ������
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 10, b = 20;
	cout << (a == b) << endl;
	cout << (a != b) << endl;
	cout << (a > b) << endl;
	cout << (a < b) << endl;

	int c = 3, d = 3;
	cout << (c >= d) << endl;
	cout << (c <= d) << endl;

	system("pause");
	return 0;
}
*/





//////////////   21�����-�߼������-��
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	cout << !a << endl;
	cout << !!a << endl;

	system("pause");
	return 0;
}
*/






//////////////    22�����-�߼������-��
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 10;
	int c = 0;
	int d = 0;
	cout << (a && b) << endl;
	cout << (a && c) << endl;
	cout << (c && d) << endl;

	system("pause");
	return 0;
}
*/





//////////////   23�����-�߼������-��
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 10, b = 10, c = 0, d = 0;
	cout << (a || b) << endl;
	cout << (a || c) << endl;
	cout << (c || d) << endl;

	system("pause");
	return 0;
}
*/





//////////////   24�������̽ṹ-ѡ��ṹ-����if���
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "�������ķ�����" << endl;
	int a = 0;
	cin >> a;
	if (a > 500)
	{
		cout << "��������һ����ѧ" << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   25�������̽ṹ-ѡ��ṹ-����if���
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "�������ķ�����" << endl;
	int a = 0;
	cin >> a;
	if (a > 500)
	{
		cout << "��������һ����ѧ" << endl;
	}
	else
	{
		cout << "��δ����һ����ѧ" << endl;
	}

	system("pause");
	return 0;
}
*/




//////////////    26�������̽ṹ-ѡ��ṹ-������if���
/*
#include<iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "�������Ŀ��Է�����" << endl;
	cin >> score;
	if (score > 500)
	{
		cout << "��������һ����ѧ" << endl;
	}
	else if(score>400)
	{
		cout << "�������˶�����ѧ" << endl;
	}
	else if (score > 300)
	{
		cout << "��������������ѧ" << endl;
	}
	else
	{
		cout << "��δ���ϱ���ѧУ" << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   27�������̽ṹ-ѡ��ṹ-Ƕ��if���
/*
#include<iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "�������Ŀ��Է�����" << endl;
	cin >> score;
	if (score > 500)
	{
		cout << "��������һ����ѧ" << endl;
		if (score > 600)
		{
			cout << "���������廪��ѧ" << endl;
		}
		else if (score > 550)
		{
			cout << "�������˱�����ѧ" << endl;
		}
		else
		{
			cout << "���������й������ѧ" << endl;
		}
	}
	else if (score > 400)
	{
		cout << "�������˶�����ѧ" << endl;
	}
	else if (score > 300)
	{
		cout << "��������������ѧ" << endl;
	}
	else
	{
		cout << "��δ���ϱ���ѧУ" << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   28�������̽ṹ-ѡ��ṹ����-��ֻС�������
/*
#include<iostream>
using namespace std;

int main()
{
	int wa, wb, wc = 0;
	cout << "������С��A�����أ�" << endl;
	cin >> wa;
	cout << "������С��B�����أ�" << endl;
	cin >> wb;
	cout << "������С��C�����أ�" << endl;
	cin >> wc;

	if (wa > wb)
	{
		if (wa > wc)
		{
			cout << "С��A����" << endl;
		}
		else
		{
			cout << "С��C����" << endl;
		}
	}
	else
	{
		if (wb > wc)
		{
			cout << "С��B����" << endl;
		}
		else
		{
			cout << "С��C����" << endl;
		}
	}

	system("pause");
	return 0;
}
*/





//////////////   29�������̽ṹ-ѡ��ṹ����-��Ŀ�����
/*
#include<iostream>
using namespace std;

int main()
{
	//��a��b�Ƚϣ�������ֵ��ĸ�ֵ��c
	int a = 10, b = 20, c = 0;

	//a > b ? (c = a) : (c = b);
	c = (a > b ? a : b);
	cout << "c��ֵΪ��" << c << endl;

	//��C++����Ŀ��������ص��Ǳ��������Լ�����ֵ
	(a > b ? a : b) = 100;
	cout << "a��ֵΪ��" << a << endl;
	cout << "b��ֵΪ��" << b << endl;

	system("pause");
	return 0;
}
*/





//////////////   30�������̽ṹ-ѡ��ṹ-switch���
/*
#include<iostream>
using namespace std;

int main()
{
	//����Ӱ���
	cout << "������һ��������1~5����" << endl;
	int score = 0;
	cin >> score;

	switch (score)
	{
	case 5:
		cout << "�ܺ�" << endl;
		break;
	case 4:
		cout << "��" << endl;
		break;
	case 3:
		cout << "һ��" << endl;
		break;
	default:
		cout << "����" << endl;
		break;
	}

	system("pause");
	return 0;
}
*/





//////////////   31�������̽ṹ-ѭ���ṹ-while���
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cout << "���0~9��" << endl;
	while (a < 10)
	{
		cout << "a=" << a++ << endl;
	}
	cout << "���1~10��" << endl;
	while (b < 10)
	{
		cout << "b=" << ++b << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   32�������̽ṹ-ѭ���ṹ����-������
/*
#include<iostream>
//timeϵͳʱ��ͷ�ļ�
#include<ctime>
using namespace std;

int main()
{	//�����������ӣ����õ�ǰϵͳʱ���������������ֹÿ���������һ��
	srand((unsigned int)time(NULL));

	int target = 0, a = 0;
	target = rand() % 100 + 1;  //����1~100�������

	cout << "������һ��1~100�����ֽ��в²⣺" << endl;
	cin >> a;

	while (a != target)
	{
		if (a > target)
		{
			cout << "���µ��е����" << endl;
		}
		else
		{
			cout << "���µ��е�С��" << endl;
		}
		cout << "����������һ��1~100�����ֽ��в²⣺" << endl;
		cin >> a;
	}
	cout << "���¶��ˣ����־��ǣ�"<<a << endl;

	system("pause");
	return 0;
}
*/






//////////////   33�������̽ṹ-ѭ���ṹ-dowhile���
/*
#include<iostream>
using namespace std;

int main()
{
	int num1 = 0, num2 = 0;
	//����Ļ�����0~9
	do
	{
		cout << num1++ << endl;
	} while (num1 < 10);
	cout << "\n" << endl;
	//����Ļ�����1~10
	do
	{
		cout << ++num2 << endl;
	} while (num2 < 10);

	system("pause");
	return 0;
}
*/




//////////////   34�������̽ṹ-ѭ���ṹ����-ˮ�ɻ���
//ˮ�ɻ�����ָһ����λ��������ÿ��λ�ϵ����ֵ�3����֮�͵���������
//���磺1^3+5^3+3^3=153
//��do while������������λ���е�ˮ�ɻ���
/*
#include<iostream>
using namespace std;

int main()
{
	int num = 100;

	do
	{
		if (pow(num / 100, 3) + pow(num / 10 % 10, 3) + pow(num % 10, 3) == num)
		{
			cout << num << endl;
		}
		num++;

	} while (num < 1000);

	system("pause");
	return 0;
}
*/




//////////////   35�������̽ṹ-ѭ���ṹ-forѭ��
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 0;
	for (a = 0; a < 10; a++)
	{
		cout << a << endl;
	}

	system("pause");
	return 0;
}
*/



//////////////   36�������̽ṹ-ѭ���ṹ����-������
//��1��ʼ����100��������ָ�λ����7����ʮλ����7�����߸�����7�ı���
//���Ǵ�ӡ�����ӣ���������ֱ�Ӵ�ӡ���
/*
#include<iostream>
using namespace std;

int main()
{
	for (int num = 1; num <= 100; num++)
	{
		int a, b;
		a = num / 10;
		b = num % 10;
		if ((a == 7) || (b == 7) || (num % 7) == 0)
		{
			cout << "������" << endl;
		}
		else
		{
			cout << num << endl;
		}
	}

	system("pause");
	return 0;
}
*/




//////////////   37�������̽ṹ-Ƕ��ѭ��
/*
#include<iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   38�������̽ṹ-Ƕ��ѭ������-�˷��ھ���
//����Ƕ��ѭ����ʵ�ֳ˷��ھ���
/*
#include<iostream>
using namespace std;

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <=i ; j++)
		{
			cout << j << "*" << i << "=" << j * i <<"\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   39�������̽ṹ-��ת���-break���
/*
#include<iostream>
using namespace std;

int main()
{
	//breakʹ��ʱ��
	//1��������switch�����
	cout << "��ѡ����Ϸ�Ѷ�" << endl;
	cout << "1����ͨ" << endl;
	cout << "2���е�" << endl;
	cout << "3������" << endl;

	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "��ѡ������ͨ�Ѷ�" << endl;
		break;
	case 2:
		cout << "��ѡ�����е��Ѷ�" << endl;
		break;
	case 3:
		cout << "��ѡ���������Ѷ�" << endl;
		break;
	default:
		cout << "������1~3�Ѷȵȼ�" << endl;
		break;
	}

	//2��������ѭ�������

	//3��������ѭ��Ƕ�������

	system("pause");
	return 0;
}
*/




//////////////   40�������̽ṹ-��ת���-continue
/*
#include<iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;  //����ɸѡ������ִ�е��˾Ͳ�������ִ����䣬����ִ����һ��ѭ��
		}
		cout << i << endl;
	}

	system("pause");
	return 0;
}
*/




//////////////   41�������̽ṹ-��ת���-goto
//���Ƽ�ʹ��
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "11111" << endl;
	cout << "22222" << endl;
	goto FLAG;
	cout << "33333" << endl;
	cout << "44444" << endl;
	FLAG:
	cout << "55555" << endl;

	system("pause");
	return 0;
}
*/




//////////////   42����-һά���鶨�巽ʽ
/*
#include<iostream>
using namespace std;

int main()
{
	int arr1[4];
	int arr2[5] = { 1,2,3 };
	int arr3[] = { 3,7,9 };

	arr1[0] = 1;
	cout << arr1[0] << endl;
	cout << arr2[2] << endl;
	cout << arr3[1] << endl;

	for (int i = 0; i < sizeof(arr2)/sizeof(int) ; i++)
	{
		cout << arr2[i] << "  ";
	}cout << endl;

	system("pause");
	return 0;
}
*/




//////////////   43����-һά����-������
//һά����������;��
//1������ͳ�������������ڴ��еĳ���
//2�����Ի�ȡ�������ڴ��е��׵�ַ
/*
#include<iostream>
using namespace std;

int main()
{
	//1������ͳ�������������ڴ��еĳ���
	int arr1[5] = { 1,2,3,4,5 };
	cout << "��������ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr1) << endl;
	cout << "ÿ��Ԫ��ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr1[0]) << endl;
	cout << "������Ԫ�ظ���Ϊ��" << sizeof(arr1) / sizeof(arr1[0]) << endl;

	//2�����Ի�ȡ�������ڴ��е��׵�ַ
	cout << "�����׵�ַΪ��" << (int)arr1 << endl;
	cout << "�����е�һ��Ԫ�صĵ�ַΪ��" << (int)&arr1[0] << endl;
	cout << "�����еڶ���Ԫ�صĵ�ַΪ��" << (int)&arr1[1] << endl;

	system("pause");
	return 0;
}
*/





//////////////   44����-һά���鰸��-��ֻС�������
//��һ�������м�¼����ֻС������أ��磺int arr[5]={300,350,200,400,250};
//�ҳ�����ӡ���ص�С������
/*
#include<iostream>
using namespace std;

int main()
{
	int arr[5] = { 300,350,500,400,250 };
	int weight = arr[0];

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (weight < arr[i])
		{
			weight = arr[i];
		}
	}
	cout << "����С�������Ϊ��" << weight << endl;

	system("pause");
	return 0;
}
*/





//////////////   45����-һά���鰸��-Ԫ������
//������һ��5��Ԫ�ص����飬����Ԫ������
/*
#include<iostream>
using namespace std;

int main()
{
	int arr[] = { 1,6,5,9,3 };
	int index = sizeof(arr) / sizeof(arr[0]) - 1;
	for (int i = 0; i < (index+1)/2; i++)
	{
		int t;
		t = arr[i];
		arr[i] = arr[index - i];
		arr[index - i] = t;
	}
	for (int j = 0; j < index + 1; j++)
	{
		cout << arr[j] << " ";
	}cout << endl;

	system("pause");
	return 0;
}
*/




//////////////   46����-һά����-ð������
/*
#include<iostream>
using namespace std;

int main()
{
	int arr[] = { 4,2,8,0,5,7,1,3,12,9 };
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len-1 ; i++)
	{
		for (int j = 0; j < len - i-1 ; j++)
		{
			int t;
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}

	for (int i = 0; i < len ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//////////////   47����-��ά���鶨�巽ʽ
/*
#include<iostream>
using namespace std;

int main()
{
	//��ά���鶨�巽ʽ
	int arr1[2][3];
	int arr2[3][3] = { {1,1,1},{2,2,2},{3,3,3} };
	int arr3[3][2] = { 1,2,4 };
	int arr4[][3] = { {1,2,3},{3,2 } };  //����ʡ������ ������ʡ������

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr3[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr4[i][j]<<" ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
 */




 //////////////   48����-��ά����-������
 //�鿴��ά������ռ�ڴ�ռ�
 //��ȡ��ά�����׵�ַ
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int arr[2][3] = {
		 {1,2,3},
		 {4,5,6}
	 };
	 cout << "��ά������ռ�ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
	 cout << "��ά�����һ����ռ�ڴ�ռ�Ϊ��" << sizeof(arr[0]) << endl;
	 cout << "��ά�����һ��Ԫ����ռ�ڴ�ռ�Ϊ��" << sizeof(arr[0][0]) << endl;

	 cout << "��ά��������Ϊ��" << sizeof(arr) / sizeof(arr[0]) << endl;
	 cout << "��ά��������Ϊ��" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	 cout << "��ά������׵�ַΪ��" << (int)arr << endl;
	 cout << "��ά�����һ���׵�ַΪ��" << (int)arr[0] << endl;
	 cout << "��ά����ڶ����׵�ַΪ��" << (int)arr[1] << endl;
	 cout << "��ά����ڶ���Ԫ���׵�ַΪ��" << (int)&arr[0][1] << endl;


	 system("pause");
	 return 0;
 }
 */




 //////////////   49����-��ά���鰸��-���Գɼ�ͳ��
 //������ͬѧ����һ�ο����еĳɼ����±���ֱ��������ͬѧ���ܳɼ�
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 int main()
 {
	 int scores[3][3] =
	 {
		 {100,100,100},
		 {90,50,100},
		 {60,70,80}
	 };
	 string names[3] = { "����","����","����" };

	 for (int i = 0; i < 3; i++)
	 {
		 int sum = 0;
		 for (int j = 0; j < 3; j++)
		 {
			 sum += scores[i][j];
		 }
		 cout << names[i] << "���ܳɼ�Ϊ��" << sum << endl;
	 }

	 system("pause");
	 return 0;
 }
 */



 /////////////    50����-�����Ķ���
 /*
 #include<iostream>
 using namespace std;

 int add(int num1, int num2)
 {
	 int sum= num1 + num2;
	 return sum;
 }

 int main()
 {

	 system("pause");
	 return 0;
 }
 */




 /////////////   51����-�����ĵ���
 /*
 #include<iostream>
 using namespace std;

 int add(int num1, int num2)
 {
	 int sum = num1 + num2;
	 return sum;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;
	 int c = add(a, b);
	 cout << c << endl;

	 system("pause");
	 return 0;
 }
 */



 /////////////   52����-ֵ����
 /*
 #include<iostream>
 using namespace std;

 //�����������Ҫ����ֵ����������ʱ�������Ϳ�дvoid
 void swap(int num1, int num2)
 {
	 cout << "����ǰ��" << endl;
	 cout << "num1=" << num1 << "\t" << "num2=" << num2 << endl;

	 int temp;
	 temp = num1;
	 num1 = num2;
	 num2 = temp;

	 cout << "������" << endl;
	 cout << "num1=" << num1 << "\t" << "num2=" << num2 << endl;

 }

 int main()
 {
	 int a = 10, b = 20;

	 cout << "a=" << a << "\t" << "b=" << b << endl << endl;
	 swap(a, b);
	 //��������ֵ����ʱ���������βθı䲻��Ӱ��ʵ��
	 cout << endl << "a=" << a << "\t" << "b=" << b << endl;

	 system("pause");
	 return 0;
 }
 */




 /////////////    53����-��������ʽ
 /*
 #include<iostream>
 using namespace std;

 //1���޲��޷�
 void test01()
 {
	 cout << "this is test01." << endl;
 }

 //2���в��޷�
 void test02(int a)
 {
	 cout << "this is test02 a=" << a << endl;
 }

 //3���޲��з�
 int test03()
 {
	 cout << "this is test03" << endl;
	 return 300;
 }

 //4���в��з�
 int test04(int a)
 {
	 cout << "this is test04" << endl;
	 return 2 * a;
 }

 int main()
 {
	 test01();

	 test02(10);

	 int num3=test03();
	 cout << "num3=" << num3 << endl;

	 int num4 = test04(40);
	 cout << "num4=" << num4 << endl;

	 system("pause");
	 return 0;
 }
 */




 /////////////   54����-����������
 //���߱������������Ƽ���ε��ú�����������ʵ��������Ե������塣
 //�������������Զ�Σ����Ǻ����Ķ���ֻ����һ��
 /*
 #include<iostream>
 using namespace std;

 int max(int a, int b);  //�������������߱������˺������ڡ��������ܰѺ���д������������

 int main()
 {
	 int a = 10, b = 20;
	 cout << max(a, b) << endl;

	 system("pause");
	 return 0;
 }

 int max(int a, int b)
 {
	 return a > b ? a : b;
 }
 */


 /////////////   55����-�����ķ��ļ���д
 //�������ļ���дһ�����ĸ����裺
 //1��������׺��Ϊ.h��ͷ�ļ�
 //2��������׺��Ϊ.cpp��Դ�ļ�
 //3����ͷ�ļ���д����������
 //4����Դ�ļ���д�����Ķ���
 /*
 #include<iostream>
 #include "swap.h"
 using namespace std;

 int main()
 {
	 int num1 = 10, num2 = 20;
	 swap(num1, num2);

	 system("pause");
	 return 0;
 }
 */





 /////////////   56ָ��-ָ��Ķ����ʹ��
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int a = 10;

	 int* p;
	 p = &a;

	 cout << "a�ĵ�ַΪ��" << &a << endl;
	 cout << "ָ��pΪ��" << p << endl;

	 *p = 1000;
	 cout << "a=" << a << endl;
	 cout << "*p=" << *p << endl;

	 system("pause");
	 return 0;
 }
 */




 /////////////   57ָ��-ָ����ռ�ڴ�ռ�
 //��32λ����ϵͳ�£�ָ��ռ4���ֽڿռ��С��������������
 //��64λ��ָ��ռ8���ֽڿռ��С
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int a = 10;
	 int* p = &a;

	 cout << "sizeof (int *)=" << sizeof(int*) << endl;
	 cout << "sizeof (int *)=" << sizeof(float*) << endl;
	 cout << "sizeof (int *)=" << sizeof(double*) << endl;
	 cout << "sizeof (int *)=" << sizeof(char*) << endl;

	 system("pause");
	 return 0;
 }
 */





 /////////////    58ָ��-��ָ��
 //��ָ�룺ָ�����ָ���ڴ��б��Ϊ0�Ŀռ�
 //��;����ʼ��ָ�����
 //ע�⣺��ָ��ָ����ڴ��ǲ����Է��ʵ�
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 //��ָ�룺ָ�����ָ���ڴ��б��Ϊ0�Ŀռ�
	 int* p = NULL;

	 //��ָ��ָ����ڴ��ǲ����Է��ʵ�
	 //0~255֮����ڴ�����ϵͳռ�õģ��������û�����
	 //*p = 100;

	 system("pause");
	 return 0;
 }
 */





 /////////////   59ָ��-Ұָ��
 //ָ�����ָ��Ƿ����ڴ�ռ䣬�ڳ�����Ҫ����Ұָ��
 //��ָ���Ұָ�붼������������Ŀռ䣬��˲�Ҫ����
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 //ָ�����pָ���ڴ��ַ���Ϊ0x1100�Ŀռ�
	 //int* p = (int *)0x1100;
	 //����Ұָ�뱨��
	 //cout << *p << endl;

	 system("pause");
	 return 0;
 }
 */






 /////////////   60ָ��-const����ָ��
 //1��const����ָ�롪������ָ��
 //2��const���γ�������ָ�볣��
 //3��const������ָ�룬�����γ���
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 //1��const����ָ�롪������ָ��
	 //ָ��ָ���ֵ�����Ըģ�ָ���ָ����Ը�
	 int a = 10, b = 10;
	 const int* p = &a;
	 //*p = 20;   //����
	 p = &b;      //��ȷ


	 //2��const���γ�������ָ�볣��
	 //ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�
	 int* const p2 = &a;
	 //p2 = &b;   //����
	 *p2 = 20;     //��ȷ


	 //3��const������ָ�룬�����γ���
	 //ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵҲ�����Ը�
	 const int* const p3 = &a;
	 //*p3 = 20;    //����
	 //p3 = &b;    //����

	 system("pause");
	 return 0;
 }
 */





 /////////////   61ָ��-ָ�������
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };
	 cout << "��һ��Ԫ��Ϊ" << arr[0] << endl;

	 int* p = arr;
	 cout << "����ָ����ʵ�һ��Ԫ��" << *p << endl;

	 p++;   //ָ�����ƫ���ĸ��ֽ�
	 cout << "����ָ����ʵڶ���Ԫ��" << *p << endl;

	 for (int i = 0, *p = arr; i < 10; i++)
	 {
		 cout << "�����" << i + 1 << "��Ԫ��Ϊ��" << *(p++) << "  " << endl;
	 }

	 system("pause");
	 return 0;
 }
 */






 /////////////   62ָ��-ָ��ͺ���
 //����ָ�������������������޸�ʵ�ε�ֵ
 /*
 #include<iostream>
 using namespace std;

 //ֵ����
 void swap1(int x, int y)
 {
	 int temp = x;
	 x = y;
	 y = temp;

	 cout << "x=" << x << "  " << "y=" << y << endl;
 }

 //��ַ����
 void swap2(int* p1, int* p2)
 {
	 int temp = *p1;
	 *p1 = *p2;
	 *p2 = temp;

	 cout << "*p1=" << *p1 << "  " << "*p2=" << *p2 << endl;
 }

 int main()
 {
	 int a = 10, b = 20;
	 swap1(a, b);    //ֵ����
	 cout << "a=" << a << "  " << "b=" << b << endl;

	 cout << endl;
	 int c = 10, d = 20;
	 swap2(&c, &d);     //��ַ����
	 cout << "c=" << c << "  " << "d=" << d << endl;

	 system("pause");
	 return 0;
 }
 */






 /////////////   63ָ��-ָ���������ͺ�������
 //��װһ������������ð������ʵ�ֶ������������������
 /*
 #include<iostream>
 using namespace std;

 void bubbleSort(int* arr,int len)
 {
	 for (int i = 0; i < len-1; i++)
	 {
		 for (int j = 0; j < len-1-i; j++)
		 {
			 if (arr[j] > arr[j + 1])
			 {
				 int temp = arr[j];
				 arr[j] = arr[j + 1];
				 arr[j + 1] = temp;
			 }
		 }
	 }
 }

 int main()
 {
	 int arr[] = { 12,23,2,-7,33,0,-102,1,6 };
	 int len = sizeof(arr) / sizeof(arr[0]);

	 bubbleSort(arr, len);

	 for (int i = 0, *p = arr; i < len; i++)
	 {
		 cout << *(p++) << " ";
	 }cout << endl;

	 system("pause");
	 return 0;
 }
 */





 /////////////   64�ṹ��-�ṹ�嶨���ʹ��
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 //1������ѧ����������
 struct Student
 {
	 string name;
	 int age;
	 int score;
 }s3;

 //2��ͨ��ѧ�����ʹ���ѧ��

 int main()
 {
	 //2.1 struct Student s1
	 struct Student s1;   //�ṹ���������ʱ��struct�ؼ��ֿ���ʡ��
	 //��s1���Ը�ֵ��ͨ�� . ���ʽṹ���б���������
	 s1.name = "����";
	 s1.age = 18;
	 s1.score = 100;

	 cout << "������" << s1.name << "  ���䣺" << s1.age << "  ������" << s1.score << endl;

	//2.2 strcut Student s2={...}
	 struct Student s2 = { "����",20,80 };
	 cout << "������" << s2.name << "  ���䣺" << s2.age << "  ������" << s2.score << endl;

	//2.3 �ڶ���ṹ��ʱ˳�㴴���ṹ�����
	 s3.name = "����";
	 s3.age = 22;
	 s3.score = 75;
	 cout << "������" << s3.name << "  ���䣺" << s3.age << "  ������" << s3.score << endl;


	 system("pause");
	 return 0;
 }
 */





 /////////////   65�ṹ��-�ṹ������
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 struct Student
 {
	 string name;
	 int age;
	 int score;
 };

 int main()
 {
	 struct Student stuArray[8] =
	 {
		 {"����",18,100},
		 {"����",20,95},
		 {"����",25,90}
	 };

	 stuArray[1].name = "����";
	 stuArray[2].age = 30;

	 for (int i = 0; i < 3; i++)
	 {
		 cout << "������" << stuArray[i].name
			 << "  ���䣺" << stuArray[i].age
			 << "  ������" << stuArray[i].score
			 << endl;
	 }

	 system("pause");
	 return 0;
 }
 */





 /////////////   66�ṹ��-�ṹ��ָ��
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 struct Student
 {
	 string name;
	 int age;
	 int score;
 };

 int main()
 {
	 struct Student s = { "����",18,100 };

	 struct Student* p = &s;
	 cout << "������" << p->name
		 << "  ���䣺" << p->age
		 << "  ������" << p->score << endl;

	 system("pause");
	 return 0;
 }
 */





 /////////////   67�ṹ��-�ṹ��Ƕ�׽ṹ��
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 struct student
 {
	 string name;
	 int age;
	 int score;
 };

 struct teacher
 {
	 int id;
	 string name;
	 int age;
	 struct student stu;
 };

 int main()
 {
	 struct teacher t;
	 t.id = 12300;
	 t.name = "����";
	 t.age = 50;
	 t.stu.name = "С��";
	 t.stu.age = 20;
	 t.stu.score = 95;

	 cout << "��ʦ������" << t.name
		 << "  ��ʦ��ţ�" << t.id
		 << "  ��ʦ���䣺" << t.age << endl;
	 cout << "��ʦ������ѧ������:" << t.stu.name
		 << "  ѧ�����䣺" << t.stu.age
		 << "  ѧ��������" << t.stu.score << endl;

	 system("pause");
	 return 0;
 }
 */
 /////////////





 /////////   68�ṹ��-�ṹ������������
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 struct student
 {
	 string name;
	 int age;
	 int score;
 };

 //1��ֵ����
 void printStudent1(struct student s)
 {
	 s.score =100 ;
	 cout << "�Ӻ���1�У�������" << s.name << "  ���䣺" << s.age
		 << "  ������" << s.score << endl;
 }

 //2����ַ����
 void printStudent2(struct student* p)
 {
	 p->name = "����";
	 cout << "�Ӻ���2�У�������" << p->name << "  ���䣺" << p->age
		 << "  ������" << p->score << endl;
 }

 int main()
 {
	 struct student s;
	 s.name = "����";
	 s.age = 20;
	 s.score = 85;

	 printStudent1(s);
	 printStudent2(&s);

	 cout << "�������У�������" << s.name << "  ���䣺" << s.age
		 << "  ������" << s.score << endl;

	 system("pause");
	 return 0;
 }
 */





 /////////////   69�ṹ��-�ṹ����constʹ�ó���
 //��const��ֹ�����
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 struct student
 {
	 string name;
	 int age;
	 int score;
 };

 //�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������
 void printStudent(const struct student* s)
 {
	 //s->age=150;   //����const֮��һ�����޸ĵĲ����ͻᱨ�����Է�ֹ���������
	 cout << "������" << s->name << "  ���䣺" << s->age
		 << "  ������" << s->score << endl;
 }

 int main()
 {
	 struct student s = { "����",20,70 };

	 //ͨ��������ӡ�ṹ�������Ϣ
	 //printStudent(s);   //��ֵ������Ҫ���ṹ��ȫ������һ�ݣ�̫�˷���Դ

	 printStudent(&s);

	 system("pause");
	 return 0;
 }
 */





 /////////////    70�ṹ��-�ṹ�尸��1
 //ѧУ������������Ŀ��ÿ����ʦ����2��ѧ�����ܹ���3����ʦ����������
 //���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա
 //ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ������ѧ����ֵ
 //���մ�ӡ����ʦ���ݼ���ʦ������ѧ������
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 struct Student
 {
	 string name;
	 int score;
 };

 struct Teacher
 {
	 string name;
	 struct Student stu[5];
 };

 void write_information(struct Teacher t[])
 {
	 for (int i = 0; i < 3; i++)
	 {
		 string tname;
		 cout << endl << "�����ʦ" << i + 1 << "��������ֵ��";
		 cin >> tname;
		 t[i].name = tname;

		 for (int j = 0; j < 5; j++)
		 {
			 string sname;
			 int score;
			 cout  << "�����ʦ" << i + 1 << "�����ĵ�" << j + 1 << "��ѧ��������ֵ��";
			 cin >> sname;
			 t[i].stu[j].name = sname;

			 cout << "�����ʦ" << i + 1 << "�����ĵ�" << j + 1 << "��ѧ�����Է�����ֵ��";
			 cin >> score;
			 t[i].stu[j].score = score;
		 }
	 }
 }

 void print_information(struct Teacher t[])
 {
	 for (int i = 0; i < 3; i++)
	 {
		 cout << t[i].name << "��ʦ��";

		 for (int j = 0; j < 5; j++)
		 {
			 cout << t[i].stu[j].name << "-" << t[i].stu[j].score << "   ";
		 }
		 cout << endl;
	 }

 }

 int main()
 {
	 struct Teacher t[3];

	 write_information(t);
	 cout << endl;
	 print_information(t);

	 system("pause");
	 return 0;
 }
 */






 /////////////   71�ṹ��-�ṹ�尸��2
 //���һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա𡣴����ṹ�����飬�����д��5��Ӣ�ۡ�
 //ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 void bubbleSort(struct Hero heros[], int len);
 void printInfo(struct Hero heros[], int len);

 struct Hero
 {
	 string name;
	 int age;
	 string gender;
 };

 int main()
 {
	 struct Hero heros[5] =
	 {
		 {"����",23,"male"},
		 {"����",22,"male"},
		 {"�ŷ�",20,"male"},
		 {"����",21,"male"},
		 {"����",19,"female"}
	 };

	 int len = sizeof(heros) / sizeof(heros[0]);

	 cout << "����ǰ��" << endl;
	 printInfo(heros, len);
	 cout << endl << "�����" << endl;
	 bubbleSort(heros, len);

	 system("pause");
	 return 0;
 }

 void bubbleSort(struct Hero heros[], int len)
 {
	 for (int i = 0; i < len - 1; i++)
	 {
		 for (int j = 0; j < len - 1 - i; j++)
		 {
			 if (heros[j].age > heros[j + 1].age)
			 {
				 struct Hero temp = heros[j];
				 heros[j] = heros[j + 1];
				 heros[j + 1] = temp;
			 }
		 }
	 }

	 printInfo(heros, len);
 }

 void printInfo(struct Hero heros[], int len)
 {
	 for (int i = 0; i < len; i++)
	 {
		 cout << "������" << heros[i].name << "  "
			 << "���䣺" << heros[i].age << "  "
			 << "�Ա�" << heros[i].gender << endl;
	 }
 }
 */





 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */




 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */





 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */




 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */




 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */





 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */





 /////////////
 /*
 #include<iostream>
 using namespace std;

 int main()
 {


	 system("pause");
	 return 0;
 }
 */


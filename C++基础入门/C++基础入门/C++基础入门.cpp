//////////////  01 C++书写HelloWorld
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




/////////////////   02  注释
/*
#include<iostream>
using namespace std;

//有单行注释和多行注释

int main()
{
	//输出Hello World!
	cout << "Hello World!" << endl;
	system("pause");

	return 0;
}
*/



///////////////    03  变量
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




///////////   04 常量与变量的区别
/*
#include<iostream>
using namespace std;

//常量的定义方式
//1、#define 宏常量
//2、const修饰的变量

//1、#define 宏常量
#define Day 7
int main()
{
	cout << "一周共有" << Day << "天" << endl;

	//2、const修饰的变量
	const int month = 12;
	cout << "一年有" << month << "月" << endl;

	system("pause");
	return 0;
}
*/





////////////   05 关键字
/*
创建变量或常量时，不要用关键字做名称
*/





/////////////  06 标识符命名规则
/*
标识符不能是关键字
标识符只能由字母、数字、下划线组成
标识符第一个字符只能是字母或下划线
标识符区分大小写
*/





////////////////   07 数据类型-整型
/*
//数据类型的存在意义：给变量分配合适的内存空间
#include<iostream>
using namespace std;

int main()
{
	//整型
	//1、短整型
	short num1 = 10;
	//2、整型
	int num2 = 10;
	//3、长整型
	long num3 = 10;
	//4、长长整型
	long long num4 = 10;

	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;

	system("pause");
	return 0;
}
*/




///////////   09 数据类型-sizeof关键字
/*
//sizeof可以统计数据类型所占内存大小 size(数据类型/变量)

#include<iostream>
using namespace std;

int main()
{
	//整型：short    int    long    long long
	short num1 = 100;
	int num2 = 200;
	long num3 = 300;
	long long num4 = 400;
	cout << "占用的内存空间:" << sizeof(short) << endl;
	cout << "占用的内存空间:" << sizeof(num2) << endl;
	cout << "占用的内存空间:" << sizeof(long) << endl;
	cout << "占用的内存空间:" << sizeof(num4) << endl;

	system("pause");
	return 0;
}
*/





//////////////   10 数据类型-实型（浮点型）
/*
#include<iostream>
using namespace std;

int main()
{
	float f1 = 3.1415926f;   //默认情况下输出一个小数，会显示六位有效数字
	cout << "f1=" << f1 << endl;

	double d1 = 3.1415926;
	cout << "d1=" << d1 << endl;

	cout << "float占用内存空间为" << sizeof(float) << endl;
	cout << "double占用内存空间为" << sizeof(double) << endl;

	//科学计数法
	float f2 = 3e2f;   //3*10^2
	cout << "f2=" << f2 << endl;

	float f3 = 3e-2f;   //3*0.1^2
	cout << "f3=" << f3 << endl;

	system("pause");
	return 0;
}
*/




//////////////   11 数据类型-字符型
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




//////////////   12 数据类型-转义字符
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "hello\nworld" << endl;
	cout << "\\" << endl;
	cout << "aaaa\they" << endl;  //水平制表符\t 左右可以整齐地输出数据
	cout << "aa\they" << endl;
	cout << "aaaaaa\they" << endl;

	system("pause");
	return 0;
}
*/





//////////////   13 数据类型-字符串类型
/*
#include<iostream>
#include<string>   //用string声明时 要包含这个头文件
using namespace std;

int main()
{
	//1、C风格字符串
	char str1[] = "hello world";
	cout << str1 << endl;
	cout << str1[1] << endl;

	//2、C++风格字符串
	string str2 = "i am fine";
	cout << str2 << endl;
	cout << str2[2] << endl;

	system("pause");
	return 0;
}
*/





//////////////   14数据类型-布尔类型
/*
#include<iostream>
using namespace std;

int main()
{
	bool flag1 = true;   //布尔类型只要非0都代表真
	bool flag2 = false;

	cout << flag1 << endl;
	cout << flag2 << endl;
	cout << sizeof(flag1) << endl;

	system("pause");
	return 0;
}
*/





//////////////   15数据类型-数据的输入
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//整型输入
	int a = 0;
	cout << "请给a一个值：" << endl;
	cin >> a;
	cout << "a的值为：" << a << endl;

	//浮点型输入
	float f = 3.14f;
	cout << "请给f一个值：" << endl;
	cin >> f;
	cout << "f的值为：" << f << endl;

	//字符型
	char ch = ' ';
	cout << "请给ch一个值：" << endl;
	cin >> ch;
	cout << "ch的值为：" << ch << endl;

	//字符串型
	string str = " ";
	cout << "请给str一个值：" << endl;
	cin >> str;
	cout << "str的值为：" << str << endl;

	//布尔型
	bool flag = false;
	cout << "请给flag一个值：" << endl;
	cin >> flag;
	cout << "flag的值为：" << flag << endl;

	system("pause");
	return EXIT_SUCCESS;
}
*/






//////////////   16运算符-算术运算符-加减乘除运算
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
	cout << a1 / b1 << endl;  //整数相除为整数

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






//////////////   17运算符-算术运算符-取模运算
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
	//cout<<3.14%2.11<<endl;  小数不能做取模运算

	system("pause");
	return 0;
}
*/





//////////////   18运算符-算术运算符-递增递减
/*
#include<iostream>
using namespace std;

int main()
{
	//前置递增 后置递增
	int a = 1;
	int b = ++a;
	int c = 1;
	int d = c++;
	cout << "a=" << a << "\tb=" << b << endl;
	cout << "c=" << c << "\td=" << d << endl;

	//前置递减 后置递减
	int m = 1;
	int n = --m;
	int p = 1;
	int q = p--;
	cout << "m=" << m << "\tn=" << n << endl;
	cout << "p=" << p << "\tq=" << q << endl;

	//前置递增和后置递增的区别
	//前置递增 先让变量+1 然后进行表达式运算
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2=" << a2 << endl;
	cout << "b2=" << b2 << endl;

	//后置递增 先进行表达式运算 后让变量+1
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;

	system("pause");
	return 0;
}
*/







//////////////   19运算符-赋值运算符
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





//////////////   20运算符-比较运算符
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





//////////////   21运算符-逻辑运算符-非
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






//////////////    22运算符-逻辑运算符-与
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





//////////////   23运算符-逻辑运算符-或
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





//////////////   24程序流程结构-选择结构-单行if语句
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "输入您的分数：" << endl;
	int a = 0;
	cin >> a;
	if (a > 500)
	{
		cout << "您考上了一本大学" << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   25程序流程结构-选择结构-多行if语句
/*
#include<iostream>
using namespace std;

int main()
{
	cout << "输入您的分数：" << endl;
	int a = 0;
	cin >> a;
	if (a > 500)
	{
		cout << "您考上了一本大学" << endl;
	}
	else
	{
		cout << "您未考上一本大学" << endl;
	}

	system("pause");
	return 0;
}
*/




//////////////    26程序流程结构-选择结构-多条件if语句
/*
#include<iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "输入您的考试分数：" << endl;
	cin >> score;
	if (score > 500)
	{
		cout << "您考上了一本大学" << endl;
	}
	else if(score>400)
	{
		cout << "您考上了二本大学" << endl;
	}
	else if (score > 300)
	{
		cout << "您考上了三本大学" << endl;
	}
	else
	{
		cout << "您未考上本科学校" << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   27程序流程结构-选择结构-嵌套if语句
/*
#include<iostream>
using namespace std;

int main()
{
	int score = 0;
	cout << "输入您的考试分数：" << endl;
	cin >> score;
	if (score > 500)
	{
		cout << "您考上了一本大学" << endl;
		if (score > 600)
		{
			cout << "您考入了清华大学" << endl;
		}
		else if (score > 550)
		{
			cout << "您考入了北京大学" << endl;
		}
		else
		{
			cout << "您考入了中国人民大学" << endl;
		}
	}
	else if (score > 400)
	{
		cout << "您考上了二本大学" << endl;
	}
	else if (score > 300)
	{
		cout << "您考上了三本大学" << endl;
	}
	else
	{
		cout << "您未考上本科学校" << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   28程序流程结构-选择结构案例-三只小猪称体重
/*
#include<iostream>
using namespace std;

int main()
{
	int wa, wb, wc = 0;
	cout << "请输入小猪A的体重：" << endl;
	cin >> wa;
	cout << "请输入小猪B的体重：" << endl;
	cin >> wb;
	cout << "请输入小猪C的体重：" << endl;
	cin >> wc;

	if (wa > wb)
	{
		if (wa > wc)
		{
			cout << "小猪A最重" << endl;
		}
		else
		{
			cout << "小猪C最重" << endl;
		}
	}
	else
	{
		if (wb > wc)
		{
			cout << "小猪B最重" << endl;
		}
		else
		{
			cout << "小猪C最重" << endl;
		}
	}

	system("pause");
	return 0;
}
*/





//////////////   29程序流程结构-选择结构案例-三目运算符
/*
#include<iostream>
using namespace std;

int main()
{
	//将a与b比较，将变量值大的赋值给c
	int a = 10, b = 20, c = 0;

	//a > b ? (c = a) : (c = b);
	c = (a > b ? a : b);
	cout << "c的值为：" << c << endl;

	//在C++中三目运算符返回的是变量，可以继续赋值
	(a > b ? a : b) = 100;
	cout << "a的值为：" << a << endl;
	cout << "b的值为：" << b << endl;

	system("pause");
	return 0;
}
*/





//////////////   30程序流程结构-选择结构-switch语句
/*
#include<iostream>
using namespace std;

int main()
{
	//给电影打分
	cout << "请输入一个分数（1~5）：" << endl;
	int score = 0;
	cin >> score;

	switch (score)
	{
	case 5:
		cout << "很好" << endl;
		break;
	case 4:
		cout << "好" << endl;
		break;
	case 3:
		cout << "一般" << endl;
		break;
	default:
		cout << "不好" << endl;
		break;
	}

	system("pause");
	return 0;
}
*/





//////////////   31程序流程结构-循环结构-while语句
/*
#include<iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cout << "输出0~9：" << endl;
	while (a < 10)
	{
		cout << "a=" << a++ << endl;
	}
	cout << "输出1~10：" << endl;
	while (b < 10)
	{
		cout << "b=" << ++b << endl;
	}

	system("pause");
	return 0;
}
*/





//////////////   32程序流程结构-循环结构案例-猜数字
/*
#include<iostream>
//time系统时间头文件
#include<ctime>
using namespace std;

int main()
{	//添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));

	int target = 0, a = 0;
	target = rand() % 100 + 1;  //生成1~100的随机数

	cout << "请输入一个1~100的数字进行猜测：" << endl;
	cin >> a;

	while (a != target)
	{
		if (a > target)
		{
			cout << "您猜的有点大了" << endl;
		}
		else
		{
			cout << "您猜的有点小了" << endl;
		}
		cout << "请重新输入一个1~100的数字进行猜测：" << endl;
		cin >> a;
	}
	cout << "您猜对了！数字就是："<<a << endl;

	system("pause");
	return 0;
}
*/






//////////////   33程序流程结构-循环结构-dowhile语句
/*
#include<iostream>
using namespace std;

int main()
{
	int num1 = 0, num2 = 0;
	//在屏幕中输出0~9
	do
	{
		cout << num1++ << endl;
	} while (num1 < 10);
	cout << "\n" << endl;
	//在屏幕中输出1~10
	do
	{
		cout << ++num2 << endl;
	} while (num2 < 10);

	system("pause");
	return 0;
}
*/




//////////////   34程序流程结构-循环结构案例-水仙花数
//水仙花数是指一个三位数，它的每个位上的数字的3次幂之和等于它本身
//例如：1^3+5^3+3^3=153
//用do while语句求出所有三位数中的水仙花数
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




//////////////   35程序流程结构-循环结构-for循环
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



//////////////   36程序流程结构-循环结构案例-敲桌子
//从1开始数到100，如果数字各位含有7，或十位含有7，或者该数是7的倍数
//我们打印敲桌子，其余数字直接打印输出
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
			cout << "敲桌子" << endl;
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




//////////////   37程序流程结构-嵌套循环
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





//////////////   38程序流程结构-嵌套循环案例-乘法口诀表
//利用嵌套循环，实现乘法口诀表
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





//////////////   39程序流程结构-跳转语句-break语句
/*
#include<iostream>
using namespace std;

int main()
{
	//break使用时机
	//1、出现在switch语句中
	cout << "请选择游戏难度" << endl;
	cout << "1、普通" << endl;
	cout << "2、中等" << endl;
	cout << "3、困难" << endl;

	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "您选择了普通难度" << endl;
		break;
	case 2:
		cout << "您选择了中等难度" << endl;
		break;
	case 3:
		cout << "您选择了困难难度" << endl;
		break;
	default:
		cout << "请输入1~3难度等级" << endl;
		break;
	}

	//2、出现在循环语句中

	//3、出现在循环嵌套语句中

	system("pause");
	return 0;
}
*/




//////////////   40程序流程结构-跳转语句-continue
/*
#include<iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;  //可以筛选条件，执行到此就不再向下执行语句，而是执行下一次循环
		}
		cout << i << endl;
	}

	system("pause");
	return 0;
}
*/




//////////////   41程序流程结构-跳转语句-goto
//不推荐使用
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




//////////////   42数组-一维数组定义方式
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




//////////////   43数组-一维数组-数组名
//一维数组名的用途：
//1、可以统计整个数组在内存中的长度
//2、可以获取数组在内存中的首地址
/*
#include<iostream>
using namespace std;

int main()
{
	//1、可以统计整个数组在内存中的长度
	int arr1[5] = { 1,2,3,4,5 };
	cout << "整个数组占用的内存空间为：" << sizeof(arr1) << endl;
	cout << "每个元素占用的内存空间为：" << sizeof(arr1[0]) << endl;
	cout << "数组中元素个数为：" << sizeof(arr1) / sizeof(arr1[0]) << endl;

	//2、可以获取数组在内存中的首地址
	cout << "数组首地址为：" << (int)arr1 << endl;
	cout << "数组中第一个元素的地址为：" << (int)&arr1[0] << endl;
	cout << "数组中第二个元素的地址为：" << (int)&arr1[1] << endl;

	system("pause");
	return 0;
}
*/





//////////////   44数组-一维数组案例-五只小猪称体重
//在一个数组中记录了五只小猪的体重，如：int arr[5]={300,350,200,400,250};
//找出并打印最重的小猪体重
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
	cout << "最重小猪的体重为：" << weight << endl;

	system("pause");
	return 0;
}
*/





//////////////   45数组-一维数组案例-元素逆置
//请声明一个5个元素的数组，并将元素逆置
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




//////////////   46数组-一维数组-冒泡排序
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




//////////////   47数组-二维数组定义方式
/*
#include<iostream>
using namespace std;

int main()
{
	//二维数组定义方式
	int arr1[2][3];
	int arr2[3][3] = { {1,1,1},{2,2,2},{3,3,3} };
	int arr3[3][2] = { 1,2,4 };
	int arr4[][3] = { {1,2,3},{3,2 } };  //可以省略行数 但不能省略列数

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




 //////////////   48数组-二维数组-数组名
 //查看二维数组所占内存空间
 //获取二维数组首地址
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int arr[2][3] = {
		 {1,2,3},
		 {4,5,6}
	 };
	 cout << "二维数组所占内存空间为：" << sizeof(arr) << endl;
	 cout << "二维数组第一行所占内存空间为：" << sizeof(arr[0]) << endl;
	 cout << "二维数组第一个元素所占内存空间为：" << sizeof(arr[0][0]) << endl;

	 cout << "二维数组行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	 cout << "二维数组列数为：" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	 cout << "二维数组的首地址为：" << (int)arr << endl;
	 cout << "二维数组第一行首地址为：" << (int)arr[0] << endl;
	 cout << "二维数组第二行首地址为：" << (int)arr[1] << endl;
	 cout << "二维数组第二个元素首地址为：" << (int)&arr[0][1] << endl;


	 system("pause");
	 return 0;
 }
 */




 //////////////   49数组-二维数组案例-考试成绩统计
 //有三名同学，在一次考试中的成绩如下表，请分别输出三名同学的总成绩
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
	 string names[3] = { "张三","李四","王五" };

	 for (int i = 0; i < 3; i++)
	 {
		 int sum = 0;
		 for (int j = 0; j < 3; j++)
		 {
			 sum += scores[i][j];
		 }
		 cout << names[i] << "的总成绩为：" << sum << endl;
	 }

	 system("pause");
	 return 0;
 }
 */



 /////////////    50函数-函数的定义
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




 /////////////   51函数-函数的调用
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



 /////////////   52函数-值传递
 /*
 #include<iostream>
 using namespace std;

 //如果函数不需要返回值，声明函数时数据类型可写void
 void swap(int num1, int num2)
 {
	 cout << "交换前：" << endl;
	 cout << "num1=" << num1 << "\t" << "num2=" << num2 << endl;

	 int temp;
	 temp = num1;
	 num1 = num2;
	 num2 = temp;

	 cout << "交换后：" << endl;
	 cout << "num1=" << num1 << "\t" << "num2=" << num2 << endl;

 }

 int main()
 {
	 int a = 10, b = 20;

	 cout << "a=" << a << "\t" << "b=" << b << endl << endl;
	 swap(a, b);
	 //当我们做值传递时，函数的形参改变不会影响实参
	 cout << endl << "a=" << a << "\t" << "b=" << b << endl;

	 system("pause");
	 return 0;
 }
 */




 /////////////    53函数-常见的样式
 /*
 #include<iostream>
 using namespace std;

 //1、无参无返
 void test01()
 {
	 cout << "this is test01." << endl;
 }

 //2、有参无返
 void test02(int a)
 {
	 cout << "this is test02 a=" << a << endl;
 }

 //3、无参有返
 int test03()
 {
	 cout << "this is test03" << endl;
	 return 300;
 }

 //4、有参有返
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




 /////////////   54函数-函数的声明
 //告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
 //函数的声明可以多次，但是函数的定义只能有一次
 /*
 #include<iostream>
 using namespace std;

 int max(int a, int b);  //函数声明，告诉编译器此函数存在。这样就能把函数写在主函数后面

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


 /////////////   55函数-函数的分文件编写
 //函数分文件编写一般有四个步骤：
 //1、创建后缀名为.h的头文件
 //2、创建后缀名为.cpp的源文件
 //3、在头文件中写函数的声明
 //4、在源文件中写函数的定义
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





 /////////////   56指针-指针的定义和使用
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int a = 10;

	 int* p;
	 p = &a;

	 cout << "a的地址为：" << &a << endl;
	 cout << "指针p为：" << p << endl;

	 *p = 1000;
	 cout << "a=" << a << endl;
	 cout << "*p=" << *p << endl;

	 system("pause");
	 return 0;
 }
 */




 /////////////   57指针-指针所占内存空间
 //在32位操作系统下，指针占4个字节空间大小，无论数据类型
 //在64位下指针占8个字节空间大小
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





 /////////////    58指针-空指针
 //空指针：指针变量指向内存中编号为0的空间
 //用途：初始化指针变量
 //注意：空指针指向的内存是不可以访问的
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 //空指针：指针变量指向内存中编号为0的空间
	 int* p = NULL;

	 //空指针指向的内存是不可以访问的
	 //0~255之间的内存编号是系统占用的，不允许用户访问
	 //*p = 100;

	 system("pause");
	 return 0;
 }
 */





 /////////////   59指针-野指针
 //指针变量指向非法的内存空间，在程序中要避免野指针
 //空指针和野指针都不是我们申请的空间，因此不要访问
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 //指针变量p指向内存地址编号为0x1100的空间
	 //int* p = (int *)0x1100;
	 //访问野指针报错
	 //cout << *p << endl;

	 system("pause");
	 return 0;
 }
 */






 /////////////   60指针-const修饰指针
 //1、const修饰指针——常量指针
 //2、const修饰常量——指针常量
 //3、const既修饰指针，又修饰常量
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 //1、const修饰指针——常量指针
	 //指针指向的值不可以改，指针的指向可以改
	 int a = 10, b = 10;
	 const int* p = &a;
	 //*p = 20;   //错误
	 p = &b;      //正确


	 //2、const修饰常量——指针常量
	 //指针的指向不可以改，指针指向的值可以改
	 int* const p2 = &a;
	 //p2 = &b;   //错误
	 *p2 = 20;     //正确


	 //3、const既修饰指针，又修饰常量
	 //指针的指向不可以改，指针指向的值也不可以改
	 const int* const p3 = &a;
	 //*p3 = 20;    //错误
	 //p3 = &b;    //错误

	 system("pause");
	 return 0;
 }
 */





 /////////////   61指针-指针和数组
 /*
 #include<iostream>
 using namespace std;

 int main()
 {
	 int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };
	 cout << "第一个元素为" << arr[0] << endl;

	 int* p = arr;
	 cout << "利用指针访问第一个元素" << *p << endl;

	 p++;   //指针向后偏移四个字节
	 cout << "利用指针访问第二个元素" << *p << endl;

	 for (int i = 0, *p = arr; i < 10; i++)
	 {
		 cout << "数组第" << i + 1 << "个元素为：" << *(p++) << "  " << endl;
	 }

	 system("pause");
	 return 0;
 }
 */






 /////////////   62指针-指针和函数
 //利用指针作函数参数，可以修改实参的值
 /*
 #include<iostream>
 using namespace std;

 //值传递
 void swap1(int x, int y)
 {
	 int temp = x;
	 x = y;
	 y = temp;

	 cout << "x=" << x << "  " << "y=" << y << endl;
 }

 //地址传递
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
	 swap1(a, b);    //值传递
	 cout << "a=" << a << "  " << "b=" << b << endl;

	 cout << endl;
	 int c = 10, d = 20;
	 swap2(&c, &d);     //地址传递
	 cout << "c=" << c << "  " << "d=" << d << endl;

	 system("pause");
	 return 0;
 }
 */






 /////////////   63指针-指针配合数组和函数案例
 //封装一个函数，利用冒泡排序，实现对整型数组的升序排序
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





 /////////////   64结构体-结构体定义和使用
 /*
 #include<iostream>
 #include<string>
 using namespace std;

 //1、创建学生数据类型
 struct Student
 {
	 string name;
	 int age;
	 int score;
 }s3;

 //2、通过学生类型创建学生

 int main()
 {
	 //2.1 struct Student s1
	 struct Student s1;   //结构体变量创建时，struct关键字可以省略
	 //给s1属性赋值，通过 . 访问结构体中变量的属性
	 s1.name = "张三";
	 s1.age = 18;
	 s1.score = 100;

	 cout << "姓名：" << s1.name << "  年龄：" << s1.age << "  分数：" << s1.score << endl;

	//2.2 strcut Student s2={...}
	 struct Student s2 = { "李四",20,80 };
	 cout << "姓名：" << s2.name << "  年龄：" << s2.age << "  分数：" << s2.score << endl;

	//2.3 在定义结构体时顺便创建结构体变量
	 s3.name = "王五";
	 s3.age = 22;
	 s3.score = 75;
	 cout << "姓名：" << s3.name << "  年龄：" << s3.age << "  分数：" << s3.score << endl;


	 system("pause");
	 return 0;
 }
 */





 /////////////   65结构体-结构体数组
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
		 {"张三",18,100},
		 {"李四",20,95},
		 {"王五",25,90}
	 };

	 stuArray[1].name = "赵六";
	 stuArray[2].age = 30;

	 for (int i = 0; i < 3; i++)
	 {
		 cout << "姓名：" << stuArray[i].name
			 << "  年龄：" << stuArray[i].age
			 << "  分数：" << stuArray[i].score
			 << endl;
	 }

	 system("pause");
	 return 0;
 }
 */





 /////////////   66结构体-结构体指针
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
	 struct Student s = { "张三",18,100 };

	 struct Student* p = &s;
	 cout << "姓名：" << p->name
		 << "  年龄：" << p->age
		 << "  分数：" << p->score << endl;

	 system("pause");
	 return 0;
 }
 */





 /////////////   67结构体-结构体嵌套结构体
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
	 t.name = "老王";
	 t.age = 50;
	 t.stu.name = "小张";
	 t.stu.age = 20;
	 t.stu.score = 95;

	 cout << "老师姓名：" << t.name
		 << "  老师编号：" << t.id
		 << "  老师年龄：" << t.age << endl;
	 cout << "老师辅导的学生姓名:" << t.stu.name
		 << "  学生年龄：" << t.stu.age
		 << "  学生分数：" << t.stu.score << endl;

	 system("pause");
	 return 0;
 }
 */
 /////////////





 /////////   68结构体-结构体做函数参数
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

 //1、值传递
 void printStudent1(struct student s)
 {
	 s.score =100 ;
	 cout << "子函数1中，姓名：" << s.name << "  年龄：" << s.age
		 << "  分数：" << s.score << endl;
 }

 //2、地址传递
 void printStudent2(struct student* p)
 {
	 p->name = "王五";
	 cout << "子函数2中，姓名：" << p->name << "  年龄：" << p->age
		 << "  分数：" << p->score << endl;
 }

 int main()
 {
	 struct student s;
	 s.name = "张三";
	 s.age = 20;
	 s.score = 85;

	 printStudent1(s);
	 printStudent2(&s);

	 cout << "主函数中，姓名：" << s.name << "  年龄：" << s.age
		 << "  分数：" << s.score << endl;

	 system("pause");
	 return 0;
 }
 */





 /////////////   69结构体-结构体中const使用场景
 //用const防止误操作
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

 //将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来
 void printStudent(const struct student* s)
 {
	 //s->age=150;   //加入const之后，一旦有修改的操作就会报错，可以防止我们误操作
	 cout << "姓名：" << s->name << "  年龄：" << s->age
		 << "  分数：" << s->score << endl;
 }

 int main()
 {
	 struct student s = { "张三",20,70 };

	 //通过函数打印结构体变量信息
	 //printStudent(s);   //用值传递需要将结构体全部复制一份，太浪费资源

	 printStudent(&s);

	 system("pause");
	 return 0;
 }
 */





 /////////////    70结构体-结构体案例1
 //学校正在做毕设项目，每名老师带领2个学生，总共有3名老师。需求如下
 //设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
 //学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带学生赋值
 //最终打印出老师数据及老师所带的学生数据
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
		 cout << endl << "请给老师" << i + 1 << "的姓名赋值：";
		 cin >> tname;
		 t[i].name = tname;

		 for (int j = 0; j < 5; j++)
		 {
			 string sname;
			 int score;
			 cout  << "请给老师" << i + 1 << "所带的第" << j + 1 << "个学生姓名赋值：";
			 cin >> sname;
			 t[i].stu[j].name = sname;

			 cout << "请给老师" << i + 1 << "所带的第" << j + 1 << "个学生考试分数赋值：";
			 cin >> score;
			 t[i].stu[j].score = score;
		 }
	 }
 }

 void print_information(struct Teacher t[])
 {
	 for (int i = 0; i < 3; i++)
	 {
		 cout << t[i].name << "老师：";

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






 /////////////   71结构体-结构体案例2
 //设计一个英雄的结构体，包括成员姓名、年龄、性别。创建结构体数组，数组中存放5名英雄。
 //通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
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
		 {"刘备",23,"male"},
		 {"关羽",22,"male"},
		 {"张飞",20,"male"},
		 {"赵云",21,"male"},
		 {"貂蝉",19,"female"}
	 };

	 int len = sizeof(heros) / sizeof(heros[0]);

	 cout << "排序前：" << endl;
	 printInfo(heros, len);
	 cout << endl << "排序后：" << endl;
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
		 cout << "姓名：" << heros[i].name << "  "
			 << "年龄：" << heros[i].age << "  "
			 << "性别：" << heros[i].gender << endl;
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


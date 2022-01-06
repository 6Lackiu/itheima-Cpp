#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->init_Speech();

	//创建12名选手
	this->create_Speaker();

	//加载往届记录
	this->loadRecord();
}

//展示菜单
void SpeechManager::show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "**********     欢迎参加演讲比赛     ***********" << endl;
	cout << "**********     1、开始演讲比赛     ************" << endl;
	cout << "**********     2、查看往届记录     ************" << endl;
	cout << "**********     3、清空比赛记录     ************" << endl;
	cout << "**********     0、退出比赛程序     ************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

//退出系统
void SpeechManager::exit_System()
{
	cout << endl << "欢迎下次使用！" << endl << endl;
	system("pause");
	exit(0);
}

//初始化容器和属性
void SpeechManager::init_Speech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_record.clear();

	//比赛轮数初始化为1
	this->m_index = 1;
}

//创建选手
void SpeechManager::create_Speaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		//12名选手编号
		this->v1.push_back(i + 10001);

		//选手编号以及对应的选手信息 存放到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));	
	}
}

//开始比赛  -  比赛流程控制
void SpeechManager::start_Speech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();

	//第二轮比赛
	this->m_index++;
	//1、抽签
	this->speechDraw();	
	//2、比赛
	this->speechContest();	
	//3、显示最终结果
	this->showScore();	
	//4、保存分数
	this->saveRecord();

	//重置比赛，获取记录
		//初始化容器和属性
	this->init_Speech();

	//创建12名选手
	this->create_Speaker();

	//加载往届记录
	this->loadRecord();

	cout << "本届比赛结束！" << endl;
	system("pause");
	system("cls");
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_index << ">>轮比赛选手正在抽签" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "抽签顺序如下：" << endl;

	if (this->m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it!=v1.end(); it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
	}
	else if (this->m_index == 2)
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it!=v2.end(); it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
	}
	cout << "-------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void SpeechManager::speechContest()
{
	cout << "-----------     第" << this->m_index << "轮比赛正式开始     ----------" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>> groupScore;		//key是得分，value是具体选手编号，greater从大到小排列
	
	int num = 0;		//记录人员个数，6人一组

	vector<int> v_Src;		//比赛选手容器
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;		//先随机出600~1000的整数，再除以10得到60~100的小数
			//cout << score << ' ';		//取消注释可看到每个选手得分
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());		//降序排序
		d.pop_back();		//去除最低分
		d.pop_front();		//去除最高分

		double sum = accumulate(d.begin(), d.end(), 0.0f);			//总分
		double avg = sum / (double)d.size();			//平均分

		//打印平均分
		//cout << "编号：" << *it << "   姓名：" << this->m_Speaker[*it].m_name << "   或取平均分：" << avg << endl;

		//将平均分放入到map容器中
		//用map的key值找到对应选手，找到人之后再将这一轮分数存入m_score中
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//将打分数据放入临时小组容器中
		groupScore.insert(make_pair(avg, *it));		//key是得分，value是具体选手编号
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次如下" << endl;
			for (multimap<double, int, greater<double>>::iterator it2 = groupScore.begin(); it2 != groupScore.end(); it2++)
			{
				cout << "编号：" << it2->second << "   姓名：" << this->m_Speaker[it2->second].m_name
					<< "   成绩：" << this->m_Speaker[it2->second].m_score[this->m_index - 1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it2 = groupScore.begin(); it2 != groupScore.end() && count < 3; it2++, count++)
			{
				if (this->m_index == 1)		//如果现在是第一轮，取走前三名放入第二轮
				{
					v2.push_back((*it2).second);
				}
				else if (this->m_index == 2)			//如果现在是第二轮，取走前三名得到最终排名
				{
					vVictory.push_back((*it2).second);
				}
			}
			cout << endl;
			groupScore.clear();		//小组容器清空
		}
	}
	cout << "-----------     第" << this->m_index << "轮比赛结束！     ----------" << endl;
	cout << endl;
	system("pause");
}

//显示比赛结果
void SpeechManager::showScore()
{
	cout << "-----------     第" << this->m_index << "轮晋级选手信息如下     ----------" << endl;
	vector<int> v;

	if (this->m_index == 1)
	{
		v = v2;
	}
	else if (this->m_index == 2)
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << "   姓名：" << this->m_Speaker[*it].m_name 
			<< "   得分：" << this->m_Speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//保存记录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);		//以追加方式写文件

	//将每个选手数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		//	.csv文件以逗号分割数据！
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	ofs.close();		//关闭文件
	cout << "记录已经保存！" << endl;

	this->FileIsEmpty = false;		//已经有记录，文件不为空
}

//读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);		//读文件

	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件被清空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且不为空
	this->FileIsEmpty = false;

	ifs.putback(ch);		//将上面读取的单个字符 再放回来

	string data;
	int index = 0;			//第几届比赛

	while (ifs>>data)
	{
		vector<string> v;			//存放6个string字符串

		//10002, 86.675, 10009, 81.3, 10007, 78.55,
		int pos = -1;			//查到逗号位置的变量，初识为没有查到
		int start = 0;			//起始寻找位置为0

		while (true)
		{
			pos = data.find(",", start);		//从start开始找逗号
			if (pos == -1)
			{
				//没有找到
				break;
			}

			//找到了，进行分割   参数1 起始位置    参数2 截取长度
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

//显示往届得分
void SpeechManager::showRecord()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届" << endl
				<< "冠军编号：" << this->m_record[i][0] << "  得分：" << this->m_record[i][1] << "   "
				<< "   亚军编号：" << this->m_record[i][2] << "  得分：" << this->m_record[i][3] << "   "
				<< "   季军编号：" << this->m_record[i][4] << "  得分：" << this->m_record[i][5] << endl << endl;
		}
	}

	system("pause");
	system("cls");
}

//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果文件存在则删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化容器和属性
		this->init_Speech();

		//创建12名选手
		this->create_Speaker();

		//加载往届记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");

}

//析构函数
SpeechManager::~SpeechManager()
{

}
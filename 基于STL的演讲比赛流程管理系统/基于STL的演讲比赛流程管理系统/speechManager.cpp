#include "speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������������
	this->init_Speech();

	//����12��ѡ��
	this->create_Speaker();

	//���������¼
	this->loadRecord();
}

//չʾ�˵�
void SpeechManager::show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "**********     ��ӭ�μ��ݽ�����     ***********" << endl;
	cout << "**********     1����ʼ�ݽ�����     ************" << endl;
	cout << "**********     2���鿴�����¼     ************" << endl;
	cout << "**********     3����ձ�����¼     ************" << endl;
	cout << "**********     0���˳���������     ************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void SpeechManager::exit_System()
{
	cout << endl << "��ӭ�´�ʹ�ã�" << endl << endl;
	system("pause");
	exit(0);
}

//��ʼ������������
void SpeechManager::init_Speech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_record.clear();

	//����������ʼ��Ϊ1
	this->m_index = 1;
}

//����ѡ��
void SpeechManager::create_Speaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧ��ѡ����Ϣ ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));	
	}
}

//��ʼ����  -  �������̿���
void SpeechManager::start_Speech()
{
	//��һ�ֱ���
	//1����ǩ
	this->speechDraw();
	//2������
	this->speechContest();
	//3����ʾ�������
	this->showScore();

	//�ڶ��ֱ���
	this->m_index++;
	//1����ǩ
	this->speechDraw();	
	//2������
	this->speechContest();	
	//3����ʾ���ս��
	this->showScore();	
	//4���������
	this->saveRecord();

	//���ñ�������ȡ��¼
		//��ʼ������������
	this->init_Speech();

	//����12��ѡ��
	this->create_Speaker();

	//���������¼
	this->loadRecord();

	cout << "�������������" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "��ǩ˳�����£�" << endl;

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

//����
void SpeechManager::speechContest()
{
	cout << "-----------     ��" << this->m_index << "�ֱ�����ʽ��ʼ     ----------" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>> groupScore;		//key�ǵ÷֣�value�Ǿ���ѡ�ֱ�ţ�greater�Ӵ�С����
	
	int num = 0;		//��¼��Ա������6��һ��

	vector<int> v_Src;		//����ѡ������
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;		//�������600~1000���������ٳ���10�õ�60~100��С��
			//cout << score << ' ';		//ȡ��ע�Ϳɿ���ÿ��ѡ�ֵ÷�
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());		//��������
		d.pop_back();		//ȥ����ͷ�
		d.pop_front();		//ȥ����߷�

		double sum = accumulate(d.begin(), d.end(), 0.0f);			//�ܷ�
		double avg = sum / (double)d.size();			//ƽ����

		//��ӡƽ����
		//cout << "��ţ�" << *it << "   ������" << this->m_Speaker[*it].m_name << "   ��ȡƽ���֣�" << avg << endl;

		//��ƽ���ַ��뵽map������
		//��map��keyֵ�ҵ���Ӧѡ�֣��ҵ���֮���ٽ���һ�ַ�������m_score��
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//��������ݷ�����ʱС��������
		groupScore.insert(make_pair(avg, *it));		//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С�������������" << endl;
			for (multimap<double, int, greater<double>>::iterator it2 = groupScore.begin(); it2 != groupScore.end(); it2++)
			{
				cout << "��ţ�" << it2->second << "   ������" << this->m_Speaker[it2->second].m_name
					<< "   �ɼ���" << this->m_Speaker[it2->second].m_score[this->m_index - 1] << endl;
			}

			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it2 = groupScore.begin(); it2 != groupScore.end() && count < 3; it2++, count++)
			{
				if (this->m_index == 1)		//��������ǵ�һ�֣�ȡ��ǰ��������ڶ���
				{
					v2.push_back((*it2).second);
				}
				else if (this->m_index == 2)			//��������ǵڶ��֣�ȡ��ǰ�����õ���������
				{
					vVictory.push_back((*it2).second);
				}
			}
			cout << endl;
			groupScore.clear();		//С���������
		}
	}
	cout << "-----------     ��" << this->m_index << "�ֱ���������     ----------" << endl;
	cout << endl;
	system("pause");
}

//��ʾ�������
void SpeechManager::showScore()
{
	cout << "-----------     ��" << this->m_index << "�ֽ���ѡ����Ϣ����     ----------" << endl;
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
		cout << "��ţ�" << *it << "   ������" << this->m_Speaker[*it].m_name 
			<< "   �÷֣�" << this->m_Speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//�����¼
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);		//��׷�ӷ�ʽд�ļ�

	//��ÿ��ѡ������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		//	.csv�ļ��Զ��ŷָ����ݣ�
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	ofs.close();		//�ر��ļ�
	cout << "��¼�Ѿ����棡" << endl;

	this->FileIsEmpty = false;		//�Ѿ��м�¼���ļ���Ϊ��
}

//��ȡ��¼
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);		//���ļ�

	//�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�����յ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ��
	this->FileIsEmpty = false;

	ifs.putback(ch);		//�������ȡ�ĵ����ַ� �ٷŻ���

	string data;
	int index = 0;			//�ڼ������

	while (ifs>>data)
	{
		vector<string> v;			//���6��string�ַ���

		//10002, 86.675, 10009, 81.3, 10007, 78.55,
		int pos = -1;			//�鵽����λ�õı�������ʶΪû�в鵽
		int start = 0;			//��ʼѰ��λ��Ϊ0

		while (true)
		{
			pos = data.find(",", start);		//��start��ʼ�Ҷ���
			if (pos == -1)
			{
				//û���ҵ�
				break;
			}

			//�ҵ��ˣ����зָ�   ����1 ��ʼλ��    ����2 ��ȡ����
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

//��ʾ����÷�
void SpeechManager::showRecord()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "��" << i + 1 << "��" << endl
				<< "�ھ���ţ�" << this->m_record[i][0] << "  �÷֣�" << this->m_record[i][1] << "   "
				<< "   �Ǿ���ţ�" << this->m_record[i][2] << "  �÷֣�" << this->m_record[i][3] << "   "
				<< "   ������ţ�" << this->m_record[i][4] << "  �÷֣�" << this->m_record[i][5] << endl << endl;
		}
	}

	system("pause");
	system("cls");
}

//��ռ�¼
void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc ����ļ�������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������������
		this->init_Speech();

		//����12��ѡ��
		this->create_Speaker();

		//���������¼
		this->loadRecord();

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");

}

//��������
SpeechManager::~SpeechManager()
{

}
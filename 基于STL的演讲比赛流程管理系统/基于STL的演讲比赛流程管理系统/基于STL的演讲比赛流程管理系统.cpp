//��������
//ѧУ����һ���ݽ���������12���˲μӡ����������֣���һ��Ϊ��̭�������ڶ���Ϊ������
//ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ���10001~10012
//������ʽ�����������ÿ��6���ˣ�
//��һ�ַ�Ϊ����С�飬���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
//ʮ����ί�ֱ��ÿ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣����ƽ����Ϊ����ѡ�ֵĳɼ�
//��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
//�ڶ���Ϊ�Q����ǰ����ʤ��
//ÿ�ֱȹ�����Ҫ��ʾ����ѡ�ֵ���Ϣ

//������
//��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ���׶�
//�鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
//��ձ�����¼�����ļ����������
//�˳��������򣺿����˳���ǰ����

#include<iostream>
#include<string>
#include<ctime>
#include "speechManager.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	//�������������
	SpeechManager sm;


	////����
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "��ţ�" << it->first
	//		<< "   ������" << it->second.m_name
	//		<< "   ������" << it->second.m_score[0] << endl;
	//}

	int choice = 0;

	while (1)
	{
		sm.show_Menu();			//չʾ�˵�

		cout << "����������ѡ��";
		cin >> choice;

		switch (choice)
		{
		case 1:			//��ʼ����
			sm.start_Speech();
			break;
		case 2:			//�鿴��¼
			sm.showRecord();
			break;
		case 3:			//��ռ�¼
			sm.clearRecord();
			break;
		case 0:			//�˳�ϵͳ
			sm.exit_System();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
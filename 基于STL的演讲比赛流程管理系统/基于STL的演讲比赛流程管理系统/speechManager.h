#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include "speaker.h"

using namespace std;

//����ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();		//ֻ������

	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exit_System();

	//��ʼ������������
	void init_Speech();

	//����ѡ��
	void create_Speaker();

	//��ʼ����  -  �������̿���
	void start_Speech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//��������
	~SpeechManager();


	//��Ա����
	vector<int> v1;		//��һ�ֱ���ѡ�ֱ��  12��
	vector<int> v2;		//�ڶ��ֱ���ѡ�ֱ��  6��
	vector<int> vVictory;			//����ǰ����ѡ�ֱ��
	map<int, Speaker> m_Speaker;		//��ű�ż���Ӧѡ��
	int m_index;			//��¼��������

	//�ж��ļ��Ƿ�Ϊ��
	bool FileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_record;		//keyΪĳһ�죬valueΪ��ȡ�ı�����Ϣ������ֵ��ɵ�string��
};
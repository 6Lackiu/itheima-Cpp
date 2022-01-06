#include "workerManager.h"

WorkerManager::WorkerManager()		//���캯��
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);		//���ļ�
	this->m_FileIsEmpty = false;

	//1���ļ������ڣ��ļ�δ������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;		//���Դ���
		//��ʼ������
		this->m_EmpNum = 0;		//��ʼ������
		this->m_FileIsEmpty = true;		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_EmpArray = NULL;		//��ʼ������ָ��
		ifs.close();
		return;
	}

	//2���ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())		//Ϊ������ļ�Ϊ��
	{
		//cout << "�ļ�Ϊ�գ�" << endl;		//���Դ���
		//��ʼ������
		this->m_EmpNum = 0;		//��ʼ������
		this->m_FileIsEmpty = true;		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_EmpArray = NULL;		//��ʼ������ָ��
		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼������
	int number = this->get_EmpNum();
	this->m_FileIsEmpty = false;		//��ʼ���ļ��Ƿ�Ϊ��
	//cout << "ְ������Ϊ��" << number << endl;		//���Դ���
	this->m_EmpNum = number;

	//����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];		//���ٿռ�
	this->init_Emp();		//���ļ������ݴ���������
}

//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "***************************************************" << endl;
	cout << "********      ��ӭʹ��ְ������ϵͳ��    ***********" << endl;
	cout << "**************    0.�˳��������     **************" << endl;
	cout << "**************    1.����ְ����Ϣ     **************" << endl;
	cout << "**************    2.��ʾְ����Ϣ     **************" << endl;
	cout << "**************    3.ɾ����ְְ��     **************" << endl;
	cout << "**************    4.�޸�ְ����Ϣ     **************" << endl;
	cout << "**************    5.����ְ����Ϣ     **************" << endl;
	cout << "**************    6.�����������     **************" << endl;
	cout << "**************    7.��������ĵ�     **************" << endl;
	cout << "***************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);		//�������ĵ���exit(0)�����򶼻��˳�
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;		//�����û�������ְ������
	cin >> addNum;

	if (addNum > 0)		//���ְ��
	{
		//������ӵ��¿ռ��С
		int newSize = this->m_EmpNum + addNum;		//�¿ռ�����=ԭ����¼������+��������
		
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i=0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;		//ְ�����
			string name = " ";		//ְ������
			int dSelect = 0;		//����ѡ��

			cout << "�������"<<i+1<<"����ְ����ţ�";

			while (1)
			{
				cin >> id;
				int result = IsExist(id);
				if (result != -1)
				{
					cout << "��ְ������Ѵ��ڣ�����������ְ����ţ�";
				}
				else
				{
					break;
				}
			}

			cout << "�������" << i + 1 << "����ְ��������";
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			
			Worker* worker = NULL;
				cin >> dSelect;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
				}
		
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;                                       

		//�ļ�Ϊ�ձ�־��Ϊ��
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		//�ɹ���Ӻ󣬱������ݵ��ļ��� 
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);		//�������ʽ���ļ���д�ļ���

	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_deptname << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);		//����ʽ���ļ�

	int ID;
	string name;
	int dID;

	int num = 0;		//ͳ������
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		num++;
	}
	ifs.close();		//�ر��ļ�

	return num;
}

//��ʼ��ְ��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;

	int index = 0;
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;

		if (dID == 1)		//��ְͨ��
		{
			worker = new Employee(ID, name, dID);
		}
		else if (dID == 2)		//����
		{
			worker = new Manager(ID, name, dID);
		}
		else		//�ϰ�
		{
			worker = new Boss(ID, name, dID);
		}

		//���ļ������ݴ����������
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();		//���ö�̬���ó���ӿ�
		}
	}

	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)		//�ҵ���ְ��
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ��ְ��
		cout << "��������Ҫɾ����ְ����ţ�";
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)			//˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];			//����ǰ��
			}
			this->m_EmpNum--;		//���������м�¼��ְ������
			if (m_EmpNum == 0)
			{
				m_FileIsEmpty = true;
			}

			this->save();			//����ͬ�����µ��ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ����ɾ��ʧ�ܣ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�ְ���ı��" << endl;
		int id;
		cin >> id;

		int result = this->IsExist(id);
		if (result != -1)
		{
			delete this->m_EmpArray[result];

			int newID = 0;
			string newName = " ";
			int dselect = 1;

			cout << "�鵽" << id << "��ְ�����������޸ĺ��ְ���ţ�";
			cin >> newID;
			cout << "�������޸ĺ��������";
			cin >> newName;
			cout << "�������޸ĺ�ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(newID, newName, 1);
				break;
			case 2:
				worker = new Manager(newID, newName, 2);
				break;
			case 3:
				worker = new Boss(newID, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[result] = worker;			//�������ݵ�������
			cout << "�޸ĳɹ���" << endl;
			this->save();			//���浽�ļ���
		}
		else
		{
			cout << "�޸�ʧ�ܣ�ְ�������ڣ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "��������ҵ�ְ����ţ�";
			int id;
			cin >> id;

			int result = IsExist(id);
			if (result != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[result]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "��������ҵ�ְ��������";
			string name;
			cin >> name;
			bool flag = false;			//�ж��Ƿ���ҵ��ı�־��Ĭ��Ϊδ�ҵ�

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ�����ְ�����Ϊ��"<<
						this->m_EmpArray[i]->m_id<<"�ţ�ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout<< "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������ְ�������������" << endl;
		cout << "2������ְ����Ž�������" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;		//������Сֵ�����ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)			//����
				{
					if (this->m_EmpArray[MinOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						MinOrMax = j;
					}
				}
				else			//����
				{
					if (this->m_EmpArray[MinOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						MinOrMax = j;
					}
				}
			}

			//�ж��ʼ�϶�����Сֵ�����ֵ�ǲ�����ʵ����Сֵ�����ֵ��������ǣ���������
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();		//�Ѱ�����������
	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ������ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);		//ɾ���ļ������´������൱�����
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;

			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()		//��������
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
}
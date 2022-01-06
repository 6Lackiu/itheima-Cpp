#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	this->m_FileIsEmpty = false;

	//1���ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		this->m_Empnum = 0;
		ifs.close();
		return;
	}

	//2���ļ����ڵ���¼Ϊ��
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		//cout << "�ļ���¼Ϊ�գ�" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		this->m_Empnum = 0;
		ifs.close();
		return;
	}

	//3���ļ����ڲ���������
	int num = this->get_num();
	this->m_Empnum = num;
	this->m_FileIsEmpty = false;

	//����ְ������������
	this->m_EmpArray = new Worker * [this->m_Empnum];
	//��ʼ��ְ��
	init_emp();
}

//��ʾ�˵�
void WorkerManager::ShowMenu()
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
void WorkerManager::Exit_System()
{
	cout << "ϵͳ�˳�����ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//���ӳ�Ա
void WorkerManager::Add_Emp()
{
	int addnum;
	cout << "��������Ҫ���ӵ�ְ��������";
	cin >> addnum;

	if (addnum > 0)
	{
		int NewSize = this->m_Empnum + addnum;
		Worker** NewSpace = new Worker * [NewSize];

		//��ԭ���ݿ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				NewSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//���������
		for (int i = 0; i < addnum; i++)
		{
			int id=0;
			string name=" ";
			int dselect=0;

			cout << "�������"<<i+1<<"��ְ����ţ�";
			while (1)
			{
				cin >> id;
				int ret = IsExist(id);
				if (ret != -1)
				{
					cout << "��ְ������Ѵ��ڣ����������룺";
				}
				else
				{
					break;
				}
			}
			
			cout << "������ְ��������";
			cin >> name;
			cout << "������ְ����λ��" << endl;
			cout << "1��ְ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dselect;

			Worker* worker = NULL;

			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, dselect);
				break;
			case 2:
				worker = new Manager(id, name, dselect);
				break;
			case 3:
				worker = new Boss(id, name, dselect);
				break;
			default:
				break;
			}
			NewSpace[this->m_Empnum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NewSpace;
		this->m_Empnum = NewSize;

		this->m_FileIsEmpty = false;		//�ļ���Ϊ��

		cout << "�ɹ����" << addnum << "��ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "���������������" << endl;
	}

	system("pause");
	system("cls");
}

//д�ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_deptname << endl;
	}

	ofs.close();
}

//��ȡ�ļ��е�����
int WorkerManager::get_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int num = 0;
	int id;
	string name;
	int dID;

	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		num++;
	}
	ifs.close();
	return num;
}

//��ʼ��Ա��
void WorkerManager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1)
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manager(id, name, dID);
		}
		else
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;		//���ļ��е����ݷŵ�������
		index++;
	}
	ifs.close();
}

//��ʾԱ��
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (id == this->m_EmpArray[i]->m_id)
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
		cout << "��������Ҫɾ����ְ����ţ�";
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_Empnum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			if (this->m_Empnum == 0)
			{
				this->m_FileIsEmpty = true;
			}

			this->save();
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
		cout << "��������Ҫ�޸�ְ���ı�ţ�";
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			int new_id=0;
			string new_name=" ";
			int new_dselect=1;

			delete this->m_EmpArray[ret];
			cout << "���ҵ�" << id << "��ְ�����������µ�ְ����ţ�";
			while (1)
			{
				cin >> new_id;
				int ret2 = this->IsExist(new_id);
				if (ret2 != -1)
				{
					cout << "��ְ���Ѵ��ڣ�����������ְ����ţ�";
				}
				else
				{
					break;
				}
			}
			cout << "�������µ�ְ��������";
			cin >> new_name;

			cout << "�������µ�ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> new_dselect;
			Worker* worker = NULL;
			switch(new_dselect)
			{
			case 1:
				worker = new Employee(new_id, new_name, 1);
				break;
			case 2:
				worker = new Manager(new_id, new_name, 1);
				break;
			case 3:
				worker = new Boss(new_id, new_name, 1);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ���Ա�����޸�ʧ�ܣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����Ա��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�����������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int select;
		cin >> select;

		if (select == 1)
		{
			cout << "��������Ҫ���ҵ�ְ����ţ�";
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if(select==2)
		{
			bool flag = false;		//�Ƿ��ҵ���־
			string name;
			cout << "��������Ҫ���ҵ�ְ��������";
			cin >> name;

			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "���ҳɹ�����ְ�����Ϊ��" << this->m_EmpArray[i]->m_id << "�ţ�ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
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
		cout << "����������ʽ��" << endl;
		cout << "1��ְ�������������" << endl;
		cout << "2��ְ����Ž�������" << endl;
		int select;
		cin >> select;

		for (int i = 0; i < this->m_Empnum; i++)
		{
			for (int j = i + 1; j < this->m_Empnum; j++)
			{
				if (select == 1)		//����
				{
					if (this->m_EmpArray[i]->m_id > this->m_EmpArray[j]->m_id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
				else if (select == 2)		//����
				{
					if (this->m_EmpArray[i]->m_id < this->m_EmpArray[j]->m_id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
			}
		
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->show_Emp();		//�Ѱ�����������		
	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}

		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		cout << "�ļ���ճɹ���" << endl;
	}
	else
	{
		cout << "ȡ������ļ���" << endl;
	}
	system("pause");
	system("cls");
}

//����
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
}
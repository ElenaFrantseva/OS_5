#include "Header.h"

void vvod_psjn(int* n, Schedule* pro)
{
	int i, choise;
	cout << "1. ������ ���������� � ��������� ��������������\n";
	cout << "2. ������������� ����������\n";
	do {
		cout << "1 ��� 2: "; cin >> choise;
	} while (choise != 1 && choise != 2);

	if (choise == 1)
	{
		do {
			cout << "������� ���������� ��������� (1-10): "; cin >> *n;
		} while (*n < 1 || *n > 10);

		cout << "������� ����� �������� � ����� ����������\n";

		for (i = 0; i < *n; i++)
		{
			do {
				cout << "������� � " << i + 1 << " ";
				cin >> pro[i].at;
				cin >> pro[i].bt;
				pro[i].btt = pro[i].bt;
			} while (pro[i].at < 0 || pro[i].bt < 0);
			if (pro[i].at == 0) pro[i].status = "ready";
			else pro[i].status = "not_l";

			pro[i].num = i + 1;
		}
	}
	else
	{
		srand(time(NULL));
		*n = rand() % (10 - 1) + 2;
		pro[0].at = 0; pro[0].status = "ready"; pro[0].bt = rand() % (10) + 1; pro[0].num = 1;
		pro[0].btt = pro[0].bt;
		for (i = 1; i < *n; i++)
		{
			pro[i].at = rand() % (10) + 1;
			pro[i].bt = rand() % (10) + 1;
			pro[i].btt = pro[i].bt;
			pro[i].status = "not_l";
			pro[i].num = i + 1;
		}


	}
}

void print_psjn(int n, Schedule* pro)
{
	cout << endl;
	cout << "�����\tT ��������\tT ����������\tT ����������\tT ����������\tT ��������\t������\n";

	for (int i = 0; i < n; i++)
	{
		pro[i].ta = pro[i].ct - pro[i].at;
		pro[i].wt = pro[i].ta - pro[i].btt;
		pro[i].M = pro[i].ta - pro[i].btt;
		pro[i].R = pro[i].btt / double(pro[i].ta);
		pro[i].P = pro[i].ta / double(pro[i].btt);

		/*����� ������ ��������, ������� ��������, ������� ����������, �������
		����������, ������� ����������, ������� ��������, ������*/

		cout << pro[i].num << "\t\t" << pro[i].at << "\t\t" << pro[i].btt << "\t\t" << pro[i].ct << "\t\t" << pro[i].ta << "\t\t" << pro[i].wt << "\t" << pro[i].status;
		cout << endl;
	}
}

void vvod_prr(int* n, vector <Schedule>& pro)
{
	int i, choise;
	cout << "1. ������ ���������� � ��������� ��������������\n";
	cout << "2. ������������� ����������\n";
	do {
		cout << "1 ��� 2: "; cin >> choise;
	} while (choise != 1 && choise != 2);


	if (choise == 1)
	{
		Schedule temp;
		do {
			cout << "������� ���������� ��������� (1-10): "; cin >> *n;
		} while (*n < 1 || *n > 10);

		cout << "������� ����� ��������, ����� ���������� � ���������\n";

		for (i = 0; i < *n; i++)
		{

			do {
				cout << "������� � " << i + 1 << " ";

				cin >> temp.at;
				cin >> temp.bt;
				cin >> temp.prior;
				temp.btt = temp.bt;
			} while (temp.at < 0 || temp.bt < 0 || temp.prior < 0);
			if (temp.at == 0) temp.status = "ready";
			else temp.status = "not_l";

			temp.num = i + 1;
			pro.push_back(temp);
		}

	}
	else
	{
		Schedule temp;
		srand(time(NULL));
		*n = rand() % (7 - 3) + 2;
		for (i = 0; i < *n; i++)
		{
			temp.at = rand() % (5);
			temp.bt = rand() % (5) + 1;
			temp.btt = temp.bt;
			temp.prior = rand() % (5) + 1;
			if (temp.at == 0)temp.status = "ready";
			else temp.status = "not_l";
			temp.num = i + 1;

			pro.push_back(temp);
		}
	}
	sort(pro.begin(), pro.end(), compare3);
}

void print_prr(int n, vector <Schedule>& pro)
{
	cout << endl;
	cout << "�����\tT ��������\tT ����������\tT ����������\tT ����������\tT ��������\t���������\t������\n";
	//cout << "�����\tT ��������\tT ����������\t���������\t������\n";
	for (int i = 0; i < n; i++)
	{
		pro[i].ta = abs(pro[i].ct - pro[i].at);
		pro[i].wt = abs(pro[i].ta - pro[i].btt);
		pro[i].M = abs(pro[i].ta - pro[i].btt);
		pro[i].R = pro[i].btt / double(pro[i].ta);
		pro[i].P = pro[i].ta / double(pro[i].btt);

		/*����� ������ ��������, ������� ��������, ������� ����������, �������
		����������, ������� ����������, ������� ��������, ������*/

		cout << pro[i].num << "\t\t" << pro[i].at << "\t\t" << pro[i].btt << "\t\t" << pro[i].ct << "\t\t" << pro[i].ta << "\t\t" << pro[i].wt << "\t" << pro[i].prior << "\t\t" << pro[i].status;
		cout << endl;
	}
}

void task_psjn(int n, Schedule* pro)
{
	//�������( ���������� �����, ��������� ������������, �������� ���������)
	double M = 0, R = 0, P = 0;
	for (int i = 0; i < n; i++)
	{
		M += pro[i].M; P += pro[i].P; R += pro[i].R;
	}
	cout << endl;
	cout << "�����\t���������� T\t� ������������\t\t�������� �\n";
	for (int i = 0; i < n; i++)
		cout << pro[i].num << "\t\t" << pro[i].M << "\t\t" << fixed << setprecision(4) << pro[i].R << "\t\t" << pro[i].P << endl;

	cout << endl;
	cout << "\t������� ���������\n";
	cout << "���������� �����: " << M / double(n) << endl;
	cout << "��������� ������������: " << R / double(n) << endl;
	cout << "�������� ���������: " << P / double(n) << endl;
}

void task_prr(int n, vector <Schedule>& pro)
{
	//�������( ���������� �����, ��������� ������������, �������� ���������)
	double M = 0, R = 0, P = 0;
	for (int i = 0; i < n; i++)
	{
		M += pro[i].M; P += pro[i].P; R += pro[i].R;
	}
	cout << endl;
	cout << "�����\t���������� T\t� ������������\t\t�������� �\n";
	for (int i = 0; i < n; i++)
		cout << pro[i].num << "\t\t" << pro[i].M << "\t\t" << fixed << setprecision(4) << pro[i].R << "\t\t" << pro[i].P << endl;

	cout << endl;
	cout << "\t������� ���������\n";
	cout << "���������� �����: " << M / double(n) << endl;
	cout << "��������� ������������: " << R / double(n) << endl;
	cout << "�������� ���������: " << P / double(n) << endl;
}

bool compare1(Schedule a, Schedule b)
{
	return a.at < b.at;
	/* ���������� TRUE, ���� �����*/
}
bool compare2(Schedule a, Schedule b)
{
	return a.bt < b.bt;
	/* ���������� TRUE, ���� �����*/
}
bool compare3(Schedule& a, Schedule& b)
{
	return a.prior < b.prior;
	/* ���������� TRUE, ���� �����*/
}
bool check(vector <Schedule>& p)
{
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i].status != "done") return false;
	}
	return true;
}

void PrintLogs(vector <Schedule>& p)
{
	auto it = p.begin();

	for (int k = 0; k < p.size(); k++)
	{
		cout << "\t" << it->status << "\t";
		it++;

	}cout << endl;

}
#include "Header.h"


void PRR()
{
	vector <Schedule> pro;
	//Массив процессов

	int n = 0, i, j, pcom;
	//n = номер процесса
	int q = 3, tmp, k = 0, quant = 0;


	vvod_prr(&n, pro);
	for (int k = 0; k < pro.size(); k++)
		cout << "\t" << pro[k].num << "\t";
	cout << endl;

	auto itTask = pro.begin();

	PrintLogs(pro); quant++;
	while (!check(pro))
	{
		if (itTask->status != "done")
		{
			for (int i = 0; i < pro.size(); i++)
			{
				if (pro[i].status == "not_l" && q <= pro[i].at)
					pro[i].status = "ready";
			}


			itTask->status = "run";
			for (int i = 0; i < q; i++)
			{
				if (itTask->bt <= 0)
				{
					itTask->status = "done";
					itTask->ct = quant - 1;
				}

				itTask->bt--;

				PrintLogs(pro); quant++;
				if (itTask->bt <= 0)
				{
					itTask->status = "done";
					itTask->ct = quant - 1;
				}
			};
			itTask->status = "ready";
			if (itTask->bt <= 0)
			{
				itTask->status = "done";
				itTask->ct = quant - 1;
			}


		}
		++itTask;
		if (itTask == pro.end()) { itTask = pro.begin(); }

	};

	PrintLogs(pro); quant++;



	print_prr(n, pro);
	task_prr(n, pro);
}

void PSJN()
{
	Schedule pro[10];
	//Массив процессов
	int n = 0, i, j, pcom;
	//n = номер процесса

	vvod_psjn(&n, pro);


	sort(pro, pro + n, compare1);

	cout << "Квант\t";
	for (int k = 1; k <= n; k++) cout << "\t" << k; cout << endl;

	int quant = 1;
	i = 0;
	pcom = 0;
	while (pcom < n)
	{
		for (j = 0; j < n; j++)
		{
			if (pro[j].at > i)
				break;
		}

		sort(pro, pro + j, compare2);
		//сортировать процессы в соответствии с их временем прибытия

		if (j > 0)
		{
			for (j = 0; j < n; j++)
			{
				if (pro[j].bt != 0)
					break;
			}
			if (pro[j].at > i)
			{
				i = pro[j].at;

			}
			pro[j].ct = i + 1;
			pro[j].bt--;
			pro[j].status = "run";
		}

		cout << quant << " квант: ";
		for (int k = 0; k < n; k++)
		{
			if (pro[pro[k].num - 1].at < quant && pro[pro[k].num - 1].status != "run" && pro[pro[k].num - 1].status != "done")
				pro[pro[k].num - 1].status = "ready";
			cout << "\t" << pro[pro[k].num - 1].status;
		}cout << endl;
		quant++;

		i++;

		pcom = 0;
		for (j = 0; j < n; j++)//проверка, что все процессы выполнились
		{
			if (pro[j].bt == 0)
			{
				pro[j].status = "done";
				pcom++;
			}
		}
	}
	cout << quant << " квант: ";
	for (int k = 0; k < n; k++)
	{
		if (pro[pro[k].num - 1].at < quant && pro[pro[k].num - 1].status != "run" && pro[pro[k].num - 1].status != "done")
			pro[pro[k].num - 1].status = "ready";
		cout << "\t" << pro[pro[k].num - 1].status;
	}cout << endl;
	print_psjn(n, pro);
	task_psjn(n, pro);
}
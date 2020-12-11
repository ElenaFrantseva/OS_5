#pragma once
#pragma once
#include <iostream>
#include <string> 
#include <fstream> 
#include <conio.h> 
#include <algorithm>
#include <locale.h> 
#include <time.h> 
#include <vector> 

#include <iomanip>
#include <queue> 

using namespace std;


void PSJN();
void PRR();

typedef struct proccess
{
	int at, bt, ct, ta, wt, btt, num, prior;
	string status;
	int M; double R, P;

	/*
at = Время прибытия
bt, btt = Время выполнения (bt уменьшается)
ct = Время завершения
ta = Измененние времени
wt = Время ожидания
*/

}Schedule;

bool compare1(Schedule a, Schedule b);
bool compare2(Schedule a, Schedule b);
bool compare3(Schedule& a, Schedule& b);
bool check(vector <Schedule>& p);

void task_psjn(int n, Schedule* pro);
void task_prr(int n, vector <Schedule>& pro);


void print_psjn(int n, Schedule* pro);
void print_prr(int n, vector <Schedule>& pro);

void vvod_prr(int* n, vector <Schedule>& pro);
void vvod_psjn(int* n, Schedule* pro);


void PrintLogs(vector <Schedule>& p);
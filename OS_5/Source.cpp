#include "Header.h"


int main()
{
	setlocale(LC_ALL, "ru");

	while (true) {
		cout << "\n\n1. PSJN\n2. RR с приоритетом\n";
		int ch; do { cout << "1/2: "; cin >> ch; } while (ch != 1 && ch != 2);


		if (ch == 1) PSJN();
		if (ch == 2) PRR();
	}

	cout << endl << endl << endl;
	system("pause");
	return 1;
}


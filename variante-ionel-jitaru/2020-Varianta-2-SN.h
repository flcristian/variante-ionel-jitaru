#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	for (int a = n; a >= 1; a--) {
		if (n % a == 0 && a > n / a) {
			cout << "(" << a << " " << n / a << ") ";
		}
	}
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti numarul elementelor : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void removePos(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void rezolvareSub3Problema2() {
	int x[100], n;
	citirePb2(x, n);

	for (int i = 0; i < n; i++) {
		if (x[i] < 0) {
			removePos(x, n, i);
			i--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
}

// Problema 3

void citireLast(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void bubbleSort(int x[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

void rezolvareSub3Problema3() {
	int x[10000], n;
	citireLast(x, n);
	int y[10000], m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 100 == 20) {
			y[m] = x[i];
			m++;
		}
	}
	bubbleSort(y, m);
	cout << y[m - 2] << " " << y[m - 1];
}
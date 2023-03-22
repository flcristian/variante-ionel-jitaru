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
	
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			int k = i, j = n / i;
			if (k < j && (k % 2 != j % 2)) {
				cout << "[" << k << ", " << j << "]" << endl;
				c++;
			}
		}
	}
	if (c == 0) {
		cout << "nu exista";
	}
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti numarul de elemente : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[100], n;
	citirePb2(x, n);
	for (int i = 0; i < n; i++) {
		if (x[i] < 0) {
			x[i] *= -1;
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

void only20Last(int x[], int n, int y[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 100 == 20) {
			y[m] = x[i];
			m++;
		}
	}
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
	int x[1000], n, y[1000], m;
	citireLast(x, n);
	only20Last(x, n, y, m);
	bubbleSort(y, m);
	cout << y[0] << " " << y[1] << endl;
}
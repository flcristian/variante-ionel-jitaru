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

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i % 2 == 0 && (i * j + (i / j) == n)) {
				cout << i << "-" << j << " ";
			}
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

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);

	int c = 0;
	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		if (x[i] != x[j]) {
			c++;
		}
	}
	cout << c;
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

void removePos(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void rezolvareSub3Problema3() {
	int x[10000], n;
	citireLast(x, n);

	int r = 0, c = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] == x[r]) {
			removePos(x, n, i);
			i--, c++;
		}
		else {
			if (c > 0) {
				removePos(x, n, r);
				i--, c = 0;
			}
			r = i;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

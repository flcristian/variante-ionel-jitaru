#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

int countDiv(int n) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			c++;
		}
	}
	return c;
}

bool estePrim(int n) {
	if (countDiv(n) == 2) {
		return 1;
	}
	return 0;
}

void rezolvareSub3Problema1() {
	int n, p;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti p : ";
	cin >> p;

	if (estePrim(p)) {
		int f[100]{};
		int i = 2;
		while (n > 1) {
			if (n % i == 0 && estePrim(i)) {
				f[i]++;
				n /= i;
			}
			else {
				i++;
			}
		}
		cout << f[p];
	}
	else {
		cout << -1;
	}
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti numarul elementelor : ";
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[40], n;
	citirePb2(x, n);

	int f1[20]{}, f2[20]{};
	for (int i = 0; i < n; i++) {
		f1[x[i]]++;
	}
	for (int i = n; i < 2 * n; i++) {
		f2[x[i]]++;
	}

	int c = 0;
	for (int i = 0; i < 20; i++) {
		if (f1[i] >= 1 && f2[i] >= 1) {
			cout << i << " ";
			c++;
		}
	}
	if (c == 0) {
		cout << "nu exista";
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

void rezolvareSub3Problema3() {
	int x[10000], n;
	citireLast(x, n);

	int max = 0, s = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] < 0) {
			s += x[i];
			if (max > s) {
				max = s;
			}
		}
		else {
			s = 0;
		}
	}
	cout << max;
}
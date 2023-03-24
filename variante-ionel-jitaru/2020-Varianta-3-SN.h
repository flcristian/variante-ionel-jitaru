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

void descompunere(int f[], int n) {
	int i = 2;
	while (n > 1) {
		if (estePrim(i) && n % i == 0) {
			f[i]++;
			n /= i;
		}
		else {
			i++;
		}
	}
}

void rezolvareSub3Problema1() {
	int n, m;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;

	int f1[100]{}, f2[100]{};
	descompunere(f1, n);
	descompunere(f2, m);
	
	int c = 0;
	for (int i = 0; i < 100; i++) {
		if (f1[i] > 0 && f2[i] > 0) {
			c++;
		}
	}
	cout << c;
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;

	int x[100];
	for (int i = 0, j = k - 1; i < n; i++, j--) {
		x[i] = abs(j);
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

void rezolvareSub3Problema3() {
	int x[10000], n;
	citireLast(x, n);

	int p = -1, r = -1;

	for (int i = 0; i < n; i++) {
		if (x[i] < 0) {
			if (p == -1) {
				p = i;
			}
			r = i;
		}
	}

	cout << r - p + 1 << " ";
}

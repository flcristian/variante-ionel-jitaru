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

	int suma = 0, f[10]{};
	while (n > 0) {
		f[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 1 && f[i] > 0) {
			suma += i;
		}
	}
	cout << suma;
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

	int y[20], m = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] > x[i - 1]) {
			y[m] = x[i];
			m++;
		}
	}

	for (int i = 0; i < m; i++) {
		cout << y[i] << " ";
	}
}

// Problema 3

void citireLast(int x[], int& n, int& k) {
	ifstream f("bac.txt");
	f >> k;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void rezolvareSub3Problema3() {
	int x[10000], n, k;
	citireLast(x, n, k);
	
	int max = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 5 == 0) {
			c++;
			if (c > max) {
				max = c;
			}
		}
		else {
			c = 0;
		}
	}
	cout << max;
}
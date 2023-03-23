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
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	int f[100]{}, i = 2;
	while (n > 1) {
		if (n % i == 0 && estePrim(i)) {
			f[i]++;
			n /= i;
		}
		else {
			i++;
		}
	}
	int produs = 1;
	for (int i = 0; i < 100; i++) {
		if (f[i] > 0) {
			produs *= i;
		}
	}
	cout << produs;
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti numarul elementelor : ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[21], n;
	citirePb2(x, n);

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] < i) {
			cout << x[i] << " ";
			c++;
		}
	}
	if (c == 0) {
		cout << "nu exista";
	}
}

// Problema 3

void nr(int x[], int& n, int p) {
	for (int i = 11; i <= 99; i++) {
		if ((i % 10) * (i / 10) == p) {
			x[n] = i;
			n++;
		}
	}
}

void rezolvareSub3Problema3() {
	int p1, p2;
	cout << "Introduceti p1 : ";
	cin >> p1;
	cout << "Introduceti p2 : ";
	cin >> p2;

	int x[1000], y[1000], n = 0, m = 0;
	nr(x, n, p1);
	nr(y, m, p2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c = x[i] * 100000 + y[j];
			cout << c << endl;
		}
	}
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 2

// Problema 2

struct flori {
	int cod;
	int nrVarietati;
	int nrExemplare[10];
};

void rezolvareSub2Problema2() {
	flori f[20];
}

// Subiectul 3

// Problema 1

void formareX(int n, int x[], int& m) {
	x[0] = 2;
	m = 1;
	while (x[m - 1] * 2 <= n && x[m - 1] <= n) {
		x[m] = x[m - 1] * 2;
		m++;
	}
}

int pDoi(int n) {
	int x[100], m;
	formareX(n, x, m);
	if (x[m - 1] > n) {
		return -1;
	}
	else {
		return x[m - 1];
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	
	cout << pDoi(n);
}

// Problema 3

int next(int x, int n) {
	if (n > 10) {
		if (x % 2 == 1) {
			return x * 2;
		}
		else {
			return x + 1;
		}
	}
	else {
		return n + 1;
	}
}

void rezolvare(int y[100], int& n, int x) {
	y[0] = 1;
	n = 1;
	while (y[n - 1] <= x && next(y[n - 1], n) <= x) {
		y[n] = next(y[n - 1], n);
		n++;
	}
}

void rezolvareSub3Problema3() {
	int x;
	cout << "Introduceti x : ";
	cin >> x;

	int y[100], n;
	rezolvare(y, n, x);
	for (int i = n - 1; i > -1; i--) {
		cout << y[i] << " ";
	}
}

// ? ? ? ?
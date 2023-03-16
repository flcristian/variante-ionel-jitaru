#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(int k, int s[]) {
	for (int i = 0; i < k + 1; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool solutie(int s[], int k) {
	cout << k << endl;
	if (k < 3 && s[k] % 2 == 1) {
		return 1;
	}
	return 0;
}

void back(int x[], int s[], int k, int n) {
	for (int i = 0; i < n; i++) {
		cout << n << endl;
		s[k] = x[i];
		if (solutie(s, k)) {
			tipar(k, s);
		}
		else {
			back(x, s, k + 1, n);
		}
	}
}

void rezolvareSub1Problema3() {
	int x[4] = { 5,6,7,8 };
	int s[10];
	int n = 4;

	back(x, s, 0, n);
}

// Subiectul 3

// Problema 1

int countDiv(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool estePrim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void putere(int n, int& d, int& p) {
	int i = 2, c = 0, min = 99999, minD;
	while (i <= n) {
		if (n % i == 0 && estePrim(i)) {
			c++;
			cout << i << endl;
			n /= i;
		}
		else {
			if (c != 0 && c < min) {
				min = c, minD = i;
			}
			c = 0;
			i++;
		}
	}
	if (c != 0 && c < min) {
		min = c, minD = i;
	}
	d = minD;
	p = min;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	int d, p;
	putere(n, d, p);
	cout << d << " " << p;
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;

	int x[100][100];
	for (int i = 0; i < n * k; i++) {
		for (int j = 0; j < n; j++) {
			cout << i / k + j + 1 << " ";
			x[i][j] = i / k + j + 1;
		}
		cout << endl;
	}
}

// Problema 3

void rezolvare(int y[], int& n, int x) {
	y[0] = x;
	n = 1;
	while (y[n - 1] > 1) {
		y[n] = y[n - 1] / 2;
		n++;
	}
}

void rezolvareSub3Problema3() {
	int x;
	cout << "Introduceti x : ";
	cin >> x;

	int y[100], n;
	rezolvare(y, n, x);
	for (int i = 0; i < n; i++) {
		cout << y[i] << " ";
	}
}
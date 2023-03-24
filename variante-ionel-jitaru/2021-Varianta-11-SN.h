#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

void cifreImpare(int x, int a[], int& n) {
	while (x > 0) {
		int c = x % 10;
		if (c % 2 == 1) {
			a[n] = c;
			n++;
		}
		x /= 10;
	}
}

int oglindite(int a[], int b[], int n, int m) {
	if (n == m) {
		for (int i = 0, j = n - 1; i < n; i++, j--) {
			if (a[i] != b[j]) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

void rezolvareSub3Problema1() {
	int x, y;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;

	int a[100], b[100], n = 0, m = 0;
	cifreImpare(x, a, n);
	cifreImpare(y, b, m);

	cout << oglindite(a, b, n, m);
}

// Problema 2

void rezolvareSub3Problema2() {
	int x[40], n, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;
	n *= 2;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}

	for (int i = 0, j = n - k; i < k; i++, j++) {
		int r = x[i];
		x[i] = x[j];
		x[j] = r;
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
}

// Problema 3

void sir(int f[], int& n, int x) {
	f[0] = 1;
	n = 1;
	while (f[n - 1] < x) {
		f[n] = f[n - 1] + 2;
		n++;
	}
}

void rezolvareSub3Problema3() {
	int x;
	cout << "Introduceti x : ";
	cin >> x;
	int f[1000], n;
	sir(f, n, x);
	if (f[n - 1] > x) {
		n--;
	}
	for (int i = n - 1; i > -1; i--) {
		cout << f[i] << " ";
	}
}
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

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

void divizoriPrimi(int x, int f[]) {
	int i = 1;
	while (x > 1) {
		if (estePrim(i) && x % i == 0) {
			f[i]++;
			x /= i;
		}
		else {
			i++;
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	int f[1000]{};
	divizoriPrimi(n, f);
	int min = n, r = n;
	for (int i = 0; i < 1000; i++) {
		if (f[i] > 0 && f[i] < min) {
			min = f[i];
			r = i;
		}
	}
	cout << r << " " << min << endl;
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;

	int x[10000];
	for (int i = 0; i < n * k; i++) {
		x[i] = n + (i / k);
	}

	for (int i = 0; i < n * k; i++) {
		cout << x[i] << " ";
	}
}

// Problema 3

void formareSir(int x[], int& d, int n) {
	d = 1;
	x[0] = 1;
	while (x[d - 1] < n) {
		x[d] = x[d - 1] * 2;
		d++;
	}
}

void rezolvareSub3Problema3() {
	int n, x[1000], d;
	cout << "Introduceti n : ";
	cin >> n;
	formareSir(x, d, n);
	if (x[d - 1] > n) {
		d--;
	}
	for (int i = d - 1; i > -1; i--) {
		cout << x[i] << " ";
	}
}
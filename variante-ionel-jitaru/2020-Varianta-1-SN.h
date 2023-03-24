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

	int f[100]{};
	int i = 0;
	while (n > 1) {
		if (estePrim(i) && n % i == 0) {
			f[i]++;
			n /= i;
		}
		else {
			i++;
		}
	}

	int max = 0, x[100], m = 0;
	for (int i = 0; i < 100; i++) {
		if (f[i] == max) {
			x[m] = i;
			m++;
		}
		if (f[i] > max) {
			max = f[i];
			x[0] = i;
			m = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << x[i] << " ";
	}
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;

	int x[100];
	for (int i = 0; i < n * k; i++) {
		x[i] = k + (i / k);
		cout << x[i] << " ";
	}
}

// Problema 3

void sir(int f[], int& n, int x) {
	f[0] = 1;
	f[1] = 1;
	n = 2;
	while (f[n - 1] < x) {
		f[n] = 3 * f[n - 1] - 1;
		n++;
	}
}

void rezolvareSub3Problema3() {
	int x, f[100], n = 0;
	cout << "Introduceti x : ";
	cin >> x;
	sir(f, n, x);
	if (f[n - 1] > x) {
		n--;
	}
	ofstream fisier("bac.txt");
	for (int i = n - 1; i > -1; i--) {
		fisier << f[i] << " ";
		cout << f[i] << " ";
	}
	fisier.close();
}

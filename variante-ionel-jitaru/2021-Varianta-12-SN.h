#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

int frate(int x) {
	int y = 0, m = 0;
	while (x > 0) {
		if (x % 10 == 9) {
			return -1;
		}
		y = y + (x % 10 + 1) * pow(10, m);
		m++;
		x /= 10;
	}
	return y;
}

void rezolvareSub3Problema1() {
	int x;
	cout << "Introduceti x : ";
	cin >> x;

	int y = frate(x);
	cout << y;
}

// Problema 2

void rezolvareSub3Problema2() {
	int x[20], n, k;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
	
	int r = x[k - 1];
	for (int i = k - 1; i > 0; i--) {
		x[i] = x[i - 1];
	}
	x[0] = r;

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

	int r = x[0], c = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] > r) {
			c++;
		}
	}
	cout << c + 1;
}
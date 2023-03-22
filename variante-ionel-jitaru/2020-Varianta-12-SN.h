#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

bool estePutere2(int n) {
	for (int i = 0; pow(2, i) <= n; i++) {
		if (pow(2, i) == n) {
			return 1;
		}
	}
	return 0;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	
	int i = n, c = -1;
	while (c == -1) {
		if (estePutere2(i)) {
			c = i;
		}
		i--;
	}
	cout << c << endl;
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti numarul de elemente : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}


void rezolvareSub3Problema2() {
	int x[100], n;
	citirePb2(x, n);

	int k = 1;
	for (int i = n - 1, j = 0; i > -1 && j < n - 1; i -= k, j += (1 - k)) {
		if (k == 1) {
			if (x[i] % 2 == 0) {
				j = i;
				k--;
				x[j] = x[j + 1];
			}
		}
		else {
			x[j] = x[j + 1];
		}
	}
	n--;

	if (k == 1) {
		cout << "nu exista" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << x[i] << " ";
		}
	}
}

// Problema 3

void formareSir(int y[], int& d, int x) {
	d = 1;
	y[0] = 1;
	while (y[d - 1] < x) {
		if (d < 10) {
			y[d] = y[d - 1] + 1;
		}
		else {
			y[d] = y[d - 1] * 2;
		}
		d++;
	}
}

void rezolvareSub3Problema3() {
	int x, y[1000], d;
	cout << "Introduceti n : ";
	cin >> x;
	formareSir(y, d, x);
	if (y[d - 1] > x) {
		d--;
	}
	for (int i = d - 1; i > -1; i--) {
		cout << y[i] << " ";
	}
}
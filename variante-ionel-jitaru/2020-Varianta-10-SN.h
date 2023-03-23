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

	int produs = 1, f[10]{};
	while (n > 0) {
		f[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0 && f[i] > 0) {
			produs *= i;
		}
	}
	produs *= pow(-1, produs % 2);
	cout << produs;
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

void adaugarePozitie(int x[], int& n, int k, int nr) {
	for (int i = n; i > k; i--) {
		x[i] = x[i - 1];
	}
	x[k] = nr;
	n++;
}

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);
	bool exista = false;
	for (int i = 0; i < n - 1; i++) {
		if (x[i] % 2 == x[i + 1] % 2) {
			adaugarePozitie(x, n, i + 1, 2020);
			exista = true;
			i++;
		}
	}
	if (exista) {
		for (int i = 0; i < n; i++) {
			cout << x[i] << " ";
		}
	}
	else {
		cout << "nu exista";
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

	int max = 0, c = 1;
	for (int i = 0; i < n; i++) {
		if (x[i] == x[i - 1] + 1) {
			c++;
			if (c > max) {
				max = c;
			}
		}
		else {
			c = 1;
		}
	}
	cout << max;
}
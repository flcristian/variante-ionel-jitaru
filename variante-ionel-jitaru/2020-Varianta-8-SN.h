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

	int suma = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0 && estePrim(i)) {
			suma += i;
		}
	}
	
	cout << suma;
}

// Problema 2

void citirePb2(int x[], int& n, int& k) {
	cout << "Introduceti numarul elementelor : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[20], n, k;
	citirePb2(x, n, k);

	int r = x[0];
	for (int i = 0; i < k - 1; i++) {
		x[i] = x[i + 1];
	}
	x[k - 1] = r;
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

	int max = 0, f[10]{};
	for (int i = 0; i < n; i++) {
		int k = x[i] % 10;
		f[k]++;
		if (f[k] > max) {
			max = f[k];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (f[i] == max) {
			cout << i << " ";
		}
	}
}
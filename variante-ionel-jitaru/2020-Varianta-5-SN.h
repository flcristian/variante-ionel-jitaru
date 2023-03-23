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

	int max = 0;
	while (n > 0) {
		int c = n % 10;
		if (c > max) {
			max = c;
		}
		n /= 10;
	}
	cout << max + 1;
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

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);

	int c = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 20 == 0) {
			c++;
		}
	}
	cout << c;
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

	int max = 0, s = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > 0) {
			s += x[i];
			if (s > max) {
				max = s;
			}
		}
		else {
			s = 0;
		}
	}
	cout << max;
}
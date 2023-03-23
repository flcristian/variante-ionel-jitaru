#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int x, y;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;

	int z[10000], n = 0;
	for (int i = x; i <= y; i++) {
		if (sqrt(i) == (int)sqrt(i)) {
			z[n] = i;
			n++;
		}
	}

	if (n == 0) {
		cout << "nu exista";
	}
	else {
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += z[i];
			cout << z[i];
			if (i != n - 1) {
				cout << "+";
			}
		}
		cout << "=" << s << endl;
	}
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

	for (int i = 0; i < n; i++) {
		int j = x[i] / 100;
		j++;
		x[i] = j * 100 + (x[i] % 100);
	}

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
	int y[10000], m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] != x[i - 1]) {
			y[m] = x[i];
			m++;
		}
	}

	for (int i = 0; i < m; i++) {
		cout << y[i] << " ";
	}
}
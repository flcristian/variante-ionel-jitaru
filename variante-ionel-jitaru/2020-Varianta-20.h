#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	char a[7][7];

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (j > i && j < 7 - i - 1) {
				cout << "a ";
				a[i][j] = 'a';
			}
			else if (j > 7 - i - 1 && j < i) {
				cout << "a ";
				a[i][j] = 'a';
			}
			else {
				cout << "b ";
				a[i][j] = 'b';
			}
		}
		cout << endl;
	}
}

// Subiectul 3

void citireLast(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

bool estePar(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
}

int sumaMax(int x[], int n) {
	int max = 0, s = 0;
	for (int i = 0; i < n - 1; i++) {
		s += x[i];
		if (estePar(x[i]) != estePar(x[i + 1])) {
			if (s > max) {
				max = s;
			}
			s = 0;
		}
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	cout << sumaMax(x, n);
}
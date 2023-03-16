#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(char s[]) {
	for (int i = 0; i < 4; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k, char s[]) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == 3) {
		return 1;
	}
	return 0;
}

void back(int k, char s[], char x[]) {
	for (int i = 0; i < 4; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(k + 1, s, x);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	char x[4] = { 'b','e','i','n' };
	char s[100];

	back(0, s, x);
}

// Subiectul 2

struct Data {
	int zi;
	int luna;
	int an;
};

struct Elev {
	char nume[30];
	Data dataNasterii;

	bool ulterior(Data e) {
		int difZi = e.zi - dataNasterii.zi;
		int difLuna = e.luna - dataNasterii.luna;
		int difAn = e.an - dataNasterii.an;

		if (difAn > 0) {
			return 0;
		}
		else if (difAn < 0) {
			return 1;
		}
		else {
			if (difLuna > 0) {
				return 0;
			}
			else if (difLuna < 0) {
				return 1;
			}
			else {
				if (difZi < 0) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
};

// Subiectul 3

// Problema 1

void afisare(int x, int y, int k) {
	if (x > y) {
		int r = x;
		y = x;
		x = r;
	}

	for (int i = x, j = 1; i <= y; i++, j++) {
		cout << i << " ";
		if (j % k == 0) {
			cout << "* ";
		}
	}
}

void rezolvareSub3Problema1() {
	int x, y, k;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;
	cout << "Introduceti k : ";
	cin >> k;
	afisare(x, y, k);
}

// Problema 2

int countCifreRecursiv(int x, int c) {
	if (x != 0) {
		return countCifreRecursiv(x / 10, c + 1);
	}
	return c;
}

int countCifre(int x) {
	int c = 0;
	while (x != 0) {
		c++;
		x /= 10;
	}
	return c;
}

void atribuire(int cifre[], int c, int x) {
	for (int i = c - 1; i > -1; i--) {
		cifre[i] = x % 10;
		x /= 10;
	}
}

void rezolvareSub3Problema2() {
	int x, c;
	cout << "Introduceti x : ";
	cin >> x;
	c = countCifreRecursiv(x, 0);
	int cifre[100];
	atribuire(cifre, c, x);
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			cout << cifre[j] << " ";
		}
		cout << endl;
	}
}

// Problema 3

void citire(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void frecventa(int x[], int n, int f[]) {
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0) {
			f[x[i] / 2]++;
		}
	}
}

void afisareCifreIndice(int i, int f[]) {
	while (f[i] > 0) {
		cout << i * 2 << " ";
		f[i]--;
	}
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citire(x, n);
	int f[5]{};
	frecventa(x, n, f);
	for (int i = 0; i < 5; i++) {
		afisareCifreIndice(i, f);
	}
}
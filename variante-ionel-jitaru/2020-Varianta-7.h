#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 4; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
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

void back(string x[], string s[], int k) {
	for (int i = 0; i < 6; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[6] = { "albizia", "jacaranda", "laburnum", "magnolie", "mimoza", "sakura" };
	string s[10];

	back(x, s, 0);
}

// Subiectul 2

// Problema 2

struct carte {
	char titlu[20];
	char autor[20];
};

struct biblio {
	int numar;
	carte carte[100];
};

void rezolvareSub2Problema2() {
	biblio c;
}

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

int putere(int n, int p) {
	if (estePrim(p)) {
		int putere = 0;
		int i = 2;
		while (n > 1) {
			if (n % i == 0 && estePrim(i)) {
				if (i == p) {
					putere++;
				}
				n /= i;
			}
			else {
				i++;
			}
		}
		return putere;
	}
	else {
		return -1;
	}
}

void rezolvareSub3Problema1() {
	int n, p;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti p : ";
	cin >> p;

	cout << putere(n, p);
}

// Problema 2

void polarizate(int x[100][100], int m, int n) {
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (x[i][0] == x[j][n - 1]) {
				cout << x[i][0] << " ";
				c++;
			}
		}
	}
	if (c == 0) {
		cout << "nepolarizate";
	}
}

void citire(int x[100][100], int& m, int& n) {
	cout << "Introduceti m : ";
	cin >> m;
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Introduceti x[" << i << "][" << j << "] : ";
			cin >> x[i][j];
		}
	}
}

void rezolvareSub3Problema2() {
	int x[100][100], m, n;
	citire(x, m, n);
	polarizate(x, m, n);
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

int minSuma(int x[], int n) {
	int min = x[0];
	for (int i = 0; i < n; i++) {
		int suma = 0;
		for (int j = i; j < n; j++) {
			suma += x[j];
			if (suma < min) {
				min = suma;
			}
		}
	}
	return min;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	cout << minSuma(x, n);
}
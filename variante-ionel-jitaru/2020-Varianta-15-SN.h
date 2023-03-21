#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 2

void rezolvareSub2Problema2() {
	double Ax, Ay, Bx, By;
	Ax = 2.1, Ay = 3, Bx = -2.5, By = 3.3;
	if ((Ax == 0 && Ay == 0) || (Bx == 0 && By == 0)) {
		cout << "origine";
	}
	else {
		cout << "altceva";
	}
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

int divPrimMax(int x) {
	for (int i = x; i > 1; i--) {
		if (estePrim(i) && x % i == 0) {
			return i;
		}
	}
	return -1;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << divPrimMax(n);
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

int countCifre(int x) {
	int c = 0;
	while (x > 0) {
		c++;
		x /= 10;
	}
	return c;
}

int countCifrePare(int x) {
	int c = 0;
	while (x > 0) {
		int cifra = x % 10;
		if (cifra % 2 == 0) {
			c++;
		}
		x /= 10;
	}
	return c;
}

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);

	int c = 0;
	for (int i = 0; i < n; i++) {
		int cc = countCifre(x[i]);
		int cp = countCifrePare(x[i]);
		int ci = cc - cp;
		if (cp == ci) {
			c++;
		}
	}
	cout << c;
}

// Problema 3

void adaugare(int s[], int nr[], int& d) {
	int x = s[0] * 10 + s[1];
	cout << x << endl;
	nr[d] = x;
	d++;
}

bool valid(int s[], int p) {
	if (s[0] == 0) {
		return 0;
	}
	if (s[0] * s[1] == p) {
		return 1;
	}
	return 0;
}

bool solutie(int s[], int p, int k) {
	if (s[0] == 0) {
		return 0;
	}
	if (s[0] * s[1] == p && k == 1) {
		return 1;
	}
	return 0;
}

void back(int s[], int p, int nr[], int& d, int k) {
	for (int i = 0; i < 10; i++) {
		s[k] = i;
		if (solutie(s, p, k)) {
			adaugare(s, nr, d);
		}
		else {
			if (k == 0) {
				back(s, p, nr, d, k + 1);
			}
		}
	}
}

void rezolvareSub3Problema3() {
	int p1, p2;
	cout << "Introduceti p1 : ";
	cin >> p1;
	cout << "Introduceti p2 : ";
	cin >> p2;
	int nr1[1000], nr2[1000];
	int d1 = 0, d2 = 0;
	int s[100];
	back(s, p1, nr1, d1, 0);
	back(s, p2, nr2, d2, 0);
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cout << nr1[i] << "000" << nr2[j] << endl;
		}
	}
}
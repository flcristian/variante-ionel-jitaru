#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

void tipar(string s[]) {
	for (int i = 0; i < 5; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
	return 1;
}

bool solutie1(int k) {
	if (k == 4) {
		return 1;
	}
	return 0;
}

void back(string x[], string s[], int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie1(k)) {
				tipar(s);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema2() {
	string x[5] = { "caprifoi", "iasomie", "liliac", "tamarix", "scumpie" };
	string s[10];

	back(x, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	int a[4][5];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			cout << (4 - i - 1) * 5 + j + 1 << " ";
			a[i][j] = (4 - i - 1) * 5 + j + 1;
		}
		cout << endl;
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

void prodprim(int n, int& p) {
	p = 1;
	bool flag = false;
	int i = 2;
	while (n > 1) {
		if (n % i == 0 && estePrim(i)) {
			if (flag == false) {
				flag = true;
				p *= i;
			}
			n /= i;
		}
		else {
			i++;
			flag = false;
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	int p;
	prodprim(n, p);
	cout << p;
}

// Problema 3

void factori(int x[], int& n, int p) {
	n = 0;
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			if (a * b == p) {
				x[n] = a * 10 + b;
				n++;
			}
		}
	}
}

void output(int s[]) {
	for (int i = 0; i < 10; i++) {
		cout << s[0] << i << i << i << s[1] << " ";
	}
}

bool solutie(int k) {
	if (k == 1) {
		return 1;
	}
	return 0;
}

void back(int x[], int y[], int n, int m, int k, int s[]) {
	int n_m;
	(k == 0 ? n_m = n : n_m = m);

	for (int i = 0; i < n_m; i++) {
		(k == 0 ? s[k] = x[i] : s[k] = y[i]);
		if (solutie(k)) {
			output(s);
		}
		else {
			back(x, y, n, m, k + 1, s);
		}
	}
}

void rezolvareSub3Problema3() {
	int p1, p2;
	cout << "Introduceti p1 : ";
	cin >> p1;
	cout << "Introduceti p2 : ";
	cin >> p2;

	int x[100], y[100], n, m;
	factori(x, n, p1);
	factori(y, m, p2);
	int s[100];
	back(x, y, n, m, 0, s);
}
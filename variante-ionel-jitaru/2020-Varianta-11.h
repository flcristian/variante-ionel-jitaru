#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 2

void tipar(string s[]) {
	for (int i = 0; i < 3; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool solutie(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

bool apare(string y[], string x) {
	for (int i = 0; i < 3; i++) {
		if (y[i] == x) {
			return 1;
		}
	}
	return 0;
}

bool valid(int k, string s[], string y[]) {
	for (int i = 0; i < k; i++) {
		if (apare(y, s[i]) == apare(y, s[i + 1])) {
			return 0;
		}
	}
	return 1;
}

void back(string x[], string y[], string s[], int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k, s, y)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, y, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema2() {
	string x[5] = { "azalea", "begonia", "vriesea", "busuioc", "feriga" };
	string y[3] = { "azalea", "begonia", "vriesea" };
	string s[10];

	back(x, y, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, p;
	int a[7][7];

	p = 1;
	for (i = 0; i < 7; i++) {
		p *= a[i][i];
	}

	cout << p;
}

// Subiectul 3

bool estePatrat(int x) {
	double r = sqrt(x);
	if (r == (int)sqrt(x)) {
		return 1;
	}
	return 0;
}

int suma(int x, int y) {
	int s = 0;
	for (int i = x; i <= y; i++) {
		if (estePatrat(i)) {
			s += i;
		}
	}
	return s;
}

void rezolvareSub3Problema1() {
	int x, y;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;
	int s = suma(x, y);
	if (s == 0) {
		cout << "nu exista";
	}
	else {
		cout << s;
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

void rezolvare(int x[], int n) {
	int c = 1;
	for (int i = 1; i < n; i++) {
		if (x[i] != x[i - 1]) {
			cout << x[i - 1] << " " << c << " ";
			c = 0;
		}
		c++;
		if (i == n - 1) {
			cout << x[i - 1] << " " << c << " ";
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	rezolvare(x, n);
}
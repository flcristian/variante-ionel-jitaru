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
		if (s[i] == s[k]) {
			return 0;
		}
		if (apare(y, s[i]) && apare(y, s[i + 1])) {
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

void rezolvareSub1Problema3() {
	string x[5] = { "Hanging", "Meteora", "Sumela", "Taktsang", "Taung Kalat" };
	string y[3] = { "Hanging", "Sumela", "Taung Kalat" };
	string s[10];

	back(x, y, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j, a[4][5];
	for (int i = 3; i > -1; i--) {
		for (int j = 4; j > -1; j--) {
			if (j == 4) {
				a[i][j] = 4 - i;
			}
			else {
				a[i][j] = a[i][j + 1] + 4;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

// Subiectul 3

// Problema 1

int maxim(int n) {
	int max = 0;
	while (n > 0) {
		int c = n % 10;
		if (c > max && c % 2 == 1) {
			max = c;
		}
		n /= 10;
	}
	return max;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << maxim(n);
}

// Problema 3

void citire(int x[], int& n, int p[100][100], int& m) {
	ifstream f("bac.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> x[i];
	}
	m = 0;
	while (!f.eof()) {
		f >> p[m][0] >> p[m][1];
		m++;
	}
	f.close();
}

bool contine(int x[], int n, int s, int d) {
	for (int i = 0; i < n; i++) {
		if (x[i] >= s && x[i] <= d) {
			return 1;
		}
	}
	return 0;
}

void afisare(int x[], int n, int p[100][100], int m) {
	for (int i = 0; i < m; i++) {
		int s = p[i][0], d = p[i][1];
		if (!contine(x, n, s, d)) {
			cout << s << " " << d << endl;
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n, p[100][100], m;
	citire(x, n, p, m);
	afisare(x, n, p, m);
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 5; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	bool apareFrisca = 0, apareUrda = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
		if (s[i] == "frisca") {
			apareFrisca = 1;
		}
		if (s[i] == "urda") {
			apareUrda = 1;
		}
	}
	if (apareFrisca == 1 && apareUrda == 1) {
		return 0;
	}
	return 1;
}

bool solutie(int k) {
	if (k == 4) {
		return 1;
	}
	return 0;
}

void back(string x[], string y[], string z[], string s[], int k) {
	for (int i = 0; i < 3 && k < 3; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, y, z, s, k + 1);
			}
		}
	}
	if (k > 2) {
		for (int i = 0; i < 3; i++) {
			(k == 3 ? s[k] = y[i] : s[k] = z[i]);

			if (valid(k, s)) {
				if (solutie(k)) {
					tipar(s);
				}
				else {
					back(x, y, z, s, k + 1);
				}
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[3] = { "faina","lapte","oua" };
	string y[3] = { "ciocolata","dulceata","urda" };
	string z[3] = { "cascaval","marar","frisca" };
	string s[10];

	back(x, y, z, s, 0);
}

// Subiectul 2

// Problema 2

struct Unghi {
	int FataMuchie;
	int FataFata;
};

struct poliedru {
	int NrVarfuri;
	int Muchie;
	Unghi Unghi;
};

void rezolvareSub2Problema2() {
	poliedru p;
}

// Subiectul 3

// Problema 1

void generatoare(int n) {
	for (int a = 1; a <= n/2; a++) {
		for (int b = 1; b <= n/2; b++) {
			if (a * b + (a / b) == n) {
				cout << a << "-" << b << " ";
			}
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	generatoare(n);
}

// Problema 2

bool complementare(int f1[], int f2[], int m) {
	for (int i = 0; i < m; i++) {
		if (!(f1[i]) + f2[i] == 1) {
			return 0;
		}
	}
	return 1;
}

int colComplementare(int x[100][100], int m, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int f1[100];
		for (int j = 0; j < m; j++) {
			f1[j] = x[j][i];
		}
		for (int k = 0; k < n; k++) {
			if (k != i) {
				int f2[100];
				for (int j = 0; j < m; j++) {
					f2[j] = x[j][k];
				}
				if (complementare(f1, f2, m)) {
					count++;
				}
			}
		}
	}
	return count/2;
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
	cout << colComplementare(x, m, n);
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

bool apare(int y[], int m, int x) {
	for (int i = 0; i < m; i++) {
		if (y[i] == x) {
			return 1;
		}
	}
	return 0;
}

void numereFrecventa2(int x[], int n) {
	int y[100], m = 0;
	for (int i = 0; i < n; i++) {
		if (!apare(y, m, x[i])) {
			int c = 0;
			for (int j = 0; j < n; j++) {
				if (x[i] == x[j]) {
					c++;
				}
			}
			if (c == 2) {
				cout << x[i] << " ";
				y[m] = x[i];
				m++;
			}
		}	
	}
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	numereFrecventa2(x, n);
}
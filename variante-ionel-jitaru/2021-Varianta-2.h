#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

struct Band {
	int indice = -1;
	string nume = "";

	Band() {
	}

	Band(int indice, string nume) {
		this->indice = indice;
		this->nume = nume;
	}
};

void tipar(Band s[]) {
	for (int i = 0; i < 4; i++) {
		cout << s[i].nume;
		if (i != 3) {
			cout << " | ";
		}
	}
	cout << endl;
}

bool apartineVectorului(int y[], int m, int indice) {
	for (int i = 0; i < m; i++) {
		if (y[i] == indice) {
			return 1;
		}
	}
	return 0;
}

bool valid(int k, Band s[], int y[], int m) {
	for (int i = 0; i < k; i++) {
		if (apartineVectorului(y, m, s[i].indice) == 1 && apartineVectorului(y, m, s[i + 1].indice) == 1) {
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

void back(int n, int m, Band s[], Band x[], int y[], int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(k, s, y, m)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(n, m, s, x, y, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int n = 5, m = 3;
	Band A(1, "Bono");
	Band B(2, "Bruce Springsteen");
	Band C(3, "Bon Jovi");
	Band D(4, "Leonard Cohen");
	Band E(5, "Portugal.The Man");

	Band x[5] = { A,B,C,D,E };
	int y[3] = { 1,3,5 };
	Band s[100];

	back(n, m, s, x, y, 0);
}

// Subiectul 3

// Problema 1

int countDivizori(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool estePrim(int x) {
	if (countDivizori(x) == 2) {
		return 1;
	}
	return 0;
}

int celMaiMicFactorPrim(int x) {
	for (int i = 2; i < x; i++) {
		if (estePrim(i) && x % i == 0) {
			return i;
		}
	}
	return x;
}

void descompunereFactori(int x[], int n) {
	while (n != 1) {
		int factor = celMaiMicFactorPrim(n);
		x[factor]++;
		n /= factor;
	}
}

int factori(int n, int m) {
	int fn[100]{};
	int fm[100]{};

	descompunereFactori(fn, n);
	descompunereFactori(fm, m);
	
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (fn[i] == fm[i] && fn[i] != 0) {
			count++;
		}
	}
	return count;
}

void rezolvareSub3Problema1() {
	cout << factori(16500, 10780);
}

// Problema 2

void rezolvareSub3Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	int x[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < n - i) {
				cout << i + j + 1 << " ";
				x[i][j] = i + j + 1;
			}
			else {
				cout << 2 * n - (j + i + 1) << " ";
				x[i][j] = 2 * n - (j + i + 1);
			}
		}
		cout << endl;
	}
}

// Problema 3

int maxSecventa(int x[], int n) {
	int lastPos = 0, lastPosInvers = n - 1;
	for (int i = 0; i < n; i++) {
		if (x[i] > 0) {
			lastPos = i;
		}
		if (x[n - i - 1] > 0) {
			lastPosInvers = n - i - 1;
		}
	}
	int max = n - lastPosInvers; // Incepe cu numar pozitiv.
	int seTermina = lastPos + 1;
	if (seTermina > max) {
		max = seTermina;
	}
	return max;
}

void citire(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void rezolvareSub3Problema3() {
	int n, x[100];
	citire(x, n);
	cout << maxSecventa(x, n);
}
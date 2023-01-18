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

bool valid(string s[], int k) {
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

void back(int n, string x[], string s[], int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(s, k)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(n, x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int n = 6;
	string x[6] = { "MAVA","MCA","MCFR","MNHCV","MNLR","MNT" };
	string s[4];

	back(n, x, s, 0);
}

// Subiectul 2

// Problema 2

struct exponat {
	char nume[20] = {};
	char colectie[20] = {};
};

struct m {
	int numar = -1;
	exponat exponat[100] = {};
};

void rezolvareSub2Problema2() {
	m muzeu;
	muzeu.numar = 1;
	muzeu.exponat[0].nume[0] = 'a';
	muzeu.exponat[0].nume[1] = 'b';
	muzeu.exponat[0].nume[2] = 'c';
	muzeu.exponat[0].colectie[0] = 'a';
	muzeu.exponat[0].colectie[1] = 'b';
	muzeu.exponat[0].colectie[2] = 'c';

	for (int i = 0; i < 20; i++) {
		cout << muzeu.exponat[0].nume[i];
	}
	for (int i = 0; i < 20; i++) {
		cout << muzeu.exponat[0].colectie[i];
	}
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

int sumaDivizoriNuPrimi(int x) {
	int s = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0 && !estePrim(i)) {
			s += i;
		}
	}
	return s;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << "Suma este : " << sumaDivizoriNuPrimi(n) << endl;
}

// Problema 2

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

void rezervatii(int x[100][100], int m, int n) {
	int fprimul[401]{};
	int fultimul[401]{};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0 && x[i][j] > 0) {
				fprimul[x[i][j]]++;
			}
			if (j == n - 1 && x[i][j] > 0) {
				fultimul[x[i][j]]++;
			}
		}
	}
	for (int i = 0; i < 401; i++) {
		if (fprimul[i] > 0 && fultimul[i] > 0) {
			cout << i << " ";
		}
	}
}

void rezolvareSub3Problema2() {
	int m, n;
	int x[100][100];
	citire(x, m, n);
	rezervatii(x, m, n);
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

void cifreZPrietene(int x[], int n, int f[]) {
	for (int i = 0; i < n; i++) {
		f[(x[i] / 10) % 10]++;
	}
}

void maxZPrietene(int f[], int y[], int& m) {
	m = 0;
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (f[i] == max) {
			y[m] = i;
			m++;
		}
		if (f[i] > max) {
			max = f[i];
			y[0] = i;
			m = 1;
		}
	}
}

int apareCifra(int y[], int m, int c) {
	for (int i = 0; i < m; i++) {
		if (y[i] == c) {
			return i;
		}
	}
	return -1;
}

void outputNumereCuMaxZPrieten(int x[], int n, int y[], int m) {
	for (int i = n - 1; i > -1; i--) {
		int cifra = apareCifra(y, m, (x[i] / 10) % 10);
		if (cifra != -1) {
			cout << i + 1 << " ";
			y[cifra] = -1;
		}
	}
}

void rezolvareSub3Problema3() {
	int n, m;
	int f[10]{};
	int x[100], y[100];
	citireLast(x, n);
	cifreZPrietene(x, n, f);
	maxZPrietene(f, y, m);
	outputNumereCuMaxZPrieten(x, n, y, m);
}


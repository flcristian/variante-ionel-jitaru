#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3 - MI

void tipar(int m, string s[]) {
	for (int i = 0; i < m; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	bool aparJeleuri = 0, aparPraline = 0;
	for (int i = 0; i <= k; i++) {
		if (i != k && s[i] == s[k]) {
			return 0;
		}
		if (s[i] == "jeleuri") {
			aparJeleuri = 1;
		}
		if (s[i] == "praline") {
			aparPraline = 1;
		}
	}
	if (aparJeleuri == 1 && aparPraline == 1) {
		return 0;
	}
	return 1;
}

bool solutie(int m, int k) {
	if (k == m - 1) {
		return 1;
	}
	return 0;
}

void back(int n, int m, string x[], string s[], int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(m, k)) {
				tipar(m, s);
			}
			else {
				back(n, m, x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int n = 4;
	string x[4] = { "bomboane","drajeuri","jeleuri","praline" };
	string s[100];
	for (int m = 2; m < 4; m++) {
		back(n, m, x, s, 0);
	}
}

// Subiectul 2

// Problema 3 - SN

void avion() {
	struct Avion {
		int ora_aterizare;
		int minut_aterizare;
		int durata;
		
		int x() {
			return (ora_aterizare * 60 + minut_aterizare) - durata;
		}

		int ora_decolare() {
			return x() / 60;
		}

		int minut_decolare() {
			return x() % 60;
		}
	};

	Avion X;
	X.ora_aterizare = 21;
	X.minut_aterizare = 47;
	X.durata = 73;

	cout << X.ora_decolare() << endl;
	cout << X.minut_decolare();
}

// Subiectul 3

// Problema 1 - MI = SN

int max(int x, int y, int z) {
	int nr[3] = { x,y,z };
	int max = nr[0];
	for (int i = 1; i < 3; i++) {
		if (nr[i] > max) {
			max = nr[i];
		}
	}
	return max;
}

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {

			a = a - b;
		}
		if (a < b) {

			b = b - a;
		}
	}
	return a;
}

int cmmmc(int a, int b) {
	return a * b / cmmdc(a, b);
}

int mozaic(int a, int b, int c) {
	int m = cmmmc(a, b);
	m = cmmmc(m, c);
	return m;
}

void rezolvareSub3Problema1() {
	int x, y, z;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;
	cout << "Introduceti z : ";
	cin >> z;
	cout << mozaic(x, y, z);
}

// Problema 2 SN

void citireSub3Pb2(int x[], int& n) {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
}

int countCifre(int x) {
	int c = 0;
	while (x != 0) {
		c++;
		x /= 10;
	}
	return c;
}

int auToateNrKCifre(int x[], int n) {
	int y[100];
	for (int i = 0; i < n; i++) {
		y[i] = countCifre(x[i]);
	}
	int nr = y[0];
	for (int i = 1; i < n; i++) {
		if (y[i] != nr) {
			return -1;
		}
	}
	return nr;
}

void rezolvareSub3Problema2SN() {
	int n, x[100];
	citireSub3Pb2(x, n);
	int nr = auToateNrKCifre(x, n);
	if (nr == -1) {
		cout << "NU" << endl;
	}
	else {
		cout << nr << endl;
	}
}

// Problema 3 - MI = SN

void citireSub3Pb3(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int secventaParaMax(int x[], int y[], int n, int& d) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int iCurent, jCurent;
		if (x[i] % 2 == 0) {
			iCurent = i;
			for (int j = n - 1; j > i - 1; j--) {
				if (x[j] == x[iCurent]) {
					int l = j - iCurent;
					if (l == max) {
						y[d] = x[iCurent];
						d++;
					}
					if (l > max) {
						max = l;
						y[0] = x[iCurent];
						d = 1;
					}
				}
			}
		}
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], y[100];
	int n, d;
	citireSub3Pb3(x, n);
	int max = secventaParaMax(x, y, n, d);
	cout << max + 1 << endl;
	for (int i = 0; i < d; i++) {
		cout << y[i] << " ";
	}
	cout << endl;
}
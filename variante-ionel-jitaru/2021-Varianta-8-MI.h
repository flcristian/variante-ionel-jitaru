#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 6; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	bool apareCamasa = 0, apareCravata = 0;
	bool aparePantaloni = 0, apareSosete = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
		if (s[i] == "camasa") {
			apareCamasa = 1;
		}
		if (s[i] == "cravata") {
			if (!apareCamasa) {
				return 0;
			}
			apareCravata = 1;
		}
		if (s[i] == "sacou" && !apareCravata) {
			return 0;
		}
		if (s[i] == "pantaloni") {
			aparePantaloni = 1;
		}
		if (s[i] == "sosete") {
			apareSosete = 1;
		}
		if (s[i] == "pantofi" && (!apareSosete || !aparePantaloni)) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == 5) {
		return 1;
	}
	return 0;
}

void back(int k, string x[], string s[]) {
	for (int i = 0; i < 6; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(k + 1, x, s);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[6] = { "camasa", "cravata", "pantaloni", "pantofi", "sacou", "sosete" };
	string s[100];
	back(0, x, s);
}

// Subiectul 2

// Problema 2

struct elev {
	int sem1;
	int sem2;
};

struct p {
	int numar;
	elev elev[40];
};

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

int countFactoriPrimi(int x) {
	int c = 0;
	for (int i = 2; i <= x; i++) {
		if (x % i == 0 && estePrim(i)) {
			c++;
		}
	}
	return c;
}

void nrfp(int n, int& m) {
	int max = 0, maxNumar;
	for (int i = n; i > 2; i--) {
		int count = countFactoriPrimi(i);
		if (count > max) {
			max = count;
			maxNumar = i;
		}
	}
	m = maxNumar;
}

void rezolvareSub3Problema1() {
	int n, m;
	cout << "Introduceti n : ";
	cin >> n;
	nrfp(n, m);
	cout << m << endl;
}

// Problema 2

void citire(int x[100][100], int& n) {
	ifstream f("bac.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> x[i][j];
		}
	}
	f.close();
}

void rezolvareSub3Problema2() {
	int x[100][100], n;
	citire(x, n);
	int suma = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i && j > n - i - 1 && j != n - 1) {
				suma += x[i][j];
			}
		}
	}
	cout << suma << endl;
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

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	int unu = -1, doi = -1;
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 1) {
			if (unu == -1) {
				unu = x[i];
			}
			else if (doi == -1) {
				doi = x[i];
			}
			else {
				unu = doi;
				doi = x[i];
			}
		}
	}
	if (unu != -1 && doi != -1) {
		cout << unu << " " << doi;
	}
	else {
		cout << "nu exista";
	}
}
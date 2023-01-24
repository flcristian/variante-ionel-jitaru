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

bool apare(string y[], int m, string piatra) {
	for (int i = 0; i < m; i++) {
		if (y[i] == piatra) {
			return 1;
		}
	}
	return 0;
}

bool valid(int k, string s[], string y[], int m) {
	for (int i = 0; i < k; i++) {
		if (apare(y, m, s[i]) == 1 && apare(y, m, s[i + 1]) == 1) {
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

void back(int k, string x[], string y[], int n, int m, string s[]) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(k, s, y, m)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(k + 1, x, y, n, m, s);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[5] = { "rubin","opal","safir","smarald","topaz" };
	string y[3] = { "rubin","safir","topaz" };
	int n = 5, m = 3;

	string s[100];

	back(0, x, y, n, m, s);
}

// Subiectul 2

// Problema 2

struct centru {
	int x;
	int y;
};

struct cerc {
	centru centru;
	int raza;
};

void rezolvareSub2Problema2() {
	cerc fig;
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

int factori(int n, int m) {
	int c = 0;
	int flag = 0;
	int i = 2;
	while (i <= n && i <= m) {
		if (estePrim(i)) {
			if (n % i == 0 && m % i == 0) {
				c += (flag + 1) % 2;
				flag = 1;
				n /= i, m /= i;
			}
			else {
				flag = 0;
				i++;
			}
		}
		else {
			flag = 0;
			i++;
		}
	}
	return c;
}

void rezolvareSub3Problema1() {
	int n, m;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;

	cout << factori(n, m);
}

// Problema 2

void rezolvareSub3Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	int x[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c = 1;
			if ((i + j + 1) / n > 0) {
				c *= -1;
			}
			cout << (n - (i + j + 1))*c << " ";
		}
		cout << endl;
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

int secventa(int x[], int n) {
	int i = 0, j = n - 1;
	int fi = -1, fj = -1;
	while (fi == -1 || fj == -1) {
		if (x[i] < 0 && fi == -1) {
			fi = i;
		}
		if (x[j] < 0 && fj == -1) {
			fj = j;
		}
		i++, j--;
	}
	int ni = n - fi;
	int nj = fj + 1;
	int max = ni;
	if (nj > max) {
		max = nj;
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	cout << secventa(x, n);
}
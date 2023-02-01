#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 2

void tipar(int s[]) {
	for (int i = 0; i < 3; i++) {
		cout << s[i];
	} 
	cout << endl;
}

bool estePar(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
}

bool valid(int k, int s[]) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[k]) {
			return 0;
		}
		if (estePar(s[i]) == estePar(s[i + 1])) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

void back(int s[], int k) {
	for (int i = 1; i < 10; i++) {
		s[k] = i;
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema2() {
	int s[100];

	back(s, 0);
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

int nrDivPrimi(int n) {
	int c = 0;
	int i = 2;
	int count = 0;
	while (i <= n) {
		if (n % i == 0 && estePrim(i)) {
			cout << i << endl;
			count++;
			n /= i;
		}
		else {
			if (count % 2 == 1) {
				c++;
			}
			count = 0;
			i++;
		}
	}
	if (count % 2 == 1) {
		c++;
	}
	return c;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << nrDivPrimi(n);
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, m;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	int x[100][100];
	for (int i = n - 1, k = 1; i > -1; i--) {
		for (int j = m - 1; j > -1; j--, k += 2) {
			x[i][j] = pow(k, 2);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

// Problema 3

void citire(int x[], int y[], int& m, int& n) {
	ifstream f("bac.txt");
	f >> m >> n;
	for (int i = 0; i < m; i++) {
		f >> x[i];
	}
	for (int i = 0; i < n; i++) {
		f >> y[i];
	}
	f.close();
}

void interclasare(int x[], int y[], int z[], int m, int n, int& p) {
	int i = 0, j = 0, k = 0;
	while (i < m && j < n) {
		if (x[i] == y[j]) {
			z[k] = x[i];
			i++;
			j++;
			k++;
		}
		else if (x[i] < y[j]) {
			z[k] = x[i];
			i++;
			k++;
		}
		else {
			z[k] = y[j];
			j++;
			k++;
		}
	}
	while (i < m) {
		z[k] = x[i];
		i++;
		k++;
	}
	while (j < n) {
		z[k] = y[j];
		j++;
		k++;
	}
	p = k;
}

void afisare(int z[], int p) {
	for (int i = 0; i < p; i++) {
		if (i == 0) {
			cout << z[i] << " ";
		}
		if (estePar(z[i - 1]) != estePar(z[i])) {
			cout << z[i] << " ";
		}
	}
}

void rezolvareSub3Problema3() {
	int m, n, p;
	int x[100], y[100], z[100];
	citire(x, y, m, n);
	interclasare(x, y, z, m, n, p);
	afisare(z, p);
}


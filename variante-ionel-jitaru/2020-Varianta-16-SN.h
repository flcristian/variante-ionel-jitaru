#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 2

// Problema 2

void rezolvareSub2Problema2() {
	int Ax, Ay, Bx, By;
	Ax = 0, Ay = 3, Bx = 3, By = 5;

	string a = "intersecteaza axa";
	if (!((Ax <= 0 && Bx >= 0) || (Ay <= 0 && By >= 0) || (Ax >= 0 && Bx <= 0) || (Ay >= 0 && By <= 0))) {
		a = "nu " + a;
	}

	cout << a;
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

void factoriPrimi(int x, int f[]) {
	int i = 2;
	while (x > 1) {
		if (estePrim(i) && (x % i == 0)) {
			f[i]++;
			x /= i;
		}
		else {
			i++;
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	int f[100]{};
	factoriPrimi(n, f);
	for (int i = 0; i <= 100; i++) {
		if (f[i] % 2 == 1) {
			cout << i << " ";
		}
	}
}

// Problema 2

void citirePb2(int& n) {
	cout << "Introduceti n : ";
	cin >> n;
}

void rezolvareSub3Problema2() {
	int x[100], n;
	citirePb2(n);
	for (int i = n - 1, j = 1; i > -1; i--, j += 2) {
		x[i] = pow(j, 2);
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
}

// Problema 3

void citireLast(int x[], int y[], int& m, int& n) {
	ifstream f("bac.txt");
	f >> m;
	f >> n;
	for (int i = 0; i < m; i++) {
		f >> x[i];
	}
	for (int i = 0; i < n; i++) {
		f >> y[i];
	}
}

void interclasare(int x[], int y[], int z[], int m, int n, int& o) {
	int i = 0, j = 0, k = 1;
	if (x[i] > y[j]) {
		z[0] = y[j];
		j++;
	}
	else {
		z[0] = x[i];
		i++;
	}
	while (i < m || j < n) {
		int l = z[k - 1] % 2;
		if (l == 0) {
			if (y[j] > z[k - 1]) {
				z[k] = y[j];
				k++;
			}
			j++;
		}
		else {
			if (x[i] > z[k - 1]) {
				z[k] = x[i];
				k++;
			}
			i++;
		}
	}
	o = k;
}

void rezolvareSub3Problema3() {
	int x[10000], y[10000], m, n;
	citireLast(x, y, m, n);
	int z[10000], o;
	interclasare(x, y, z, m, n, o);
	cout << o << endl;
	for (int i = 0; i < o; i++) {
		cout << z[i] << " ";
	}
}


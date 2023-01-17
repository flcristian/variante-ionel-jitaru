#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

int countDivizori(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

int estePrim(int x) {
	if (countDivizori(x) == 2) {
		return 1;
	}
	return 0;
}

void atribuire(int x[], int& n, int numar) {
	n = 0;
	for (int i = 2; i <= numar; i++) {
		if (estePrim(i)) {
			x[n] = i;
			n++;
		}
	}
}

void tipar(int s[], int k, int numar) {
	for (int i = 0; i < k; i++) {
		cout << s[i];
		if (i != k - 1) {
			cout << "+";
		}
		else {
			cout << "=" << numar;
		}
	}
	cout << endl;
}

void back(int x[], int suma, int n, int numar, int s[], int k) {
	if (suma == numar) {
		tipar(s, k, numar);
	}
	else {
		int i = 0;
		s[k] = 0;
		while (suma + s[k] < numar && k < n + 1 && i < n) {
			s[k] = x[i];
			suma = suma + s[k];
			back(x, suma, n, numar, s, k + 1);
			suma = suma - s[k];
			i++;
		}
	}
}

void rezolvareSub1Problema3() {
	int numar;
	cout << "Introduceti numarul : ";
	cin >> numar;
	int n;
	int x[100], s[100];
	int suma = 0;
	atribuire(x, n, numar);
	back(x, suma, n, numar, s, 0);
}

// Subiectul 2

// Problema 2

struct c {
	char titlu[50];
	char autor[100];
	int nrExemplare;
};

// Subiectul 3

// Problema 1

bool identice(int n) {
	if (n / 10 != 0) {
		if (n % 10 == n / 10 % 10) {
			return identice(n/10);
		}
		return 0;
	}
	return 1;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	cout << identice(n);
}

// Problema 2

void citire(int& m, int& n) {
	cout << "Introduceti m : ";
	cin >> m;
	cout << "Introduceti n : ";
	cin >> n;
}

void rezolvareSub3Problema2() {
	int m, n;
	int x[100][100];
	citire(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = ((i + 1) * (j + 1)) % 10;
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

// Problema 3

void citireLast(int x[], int& n) {
	ifstream f("bac.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> x[i];
	}
	f.close();
}

void rezolvareSub3Problema3() {
	int n, x[100];
	citireLast(x, n);
	int max = x[0];
	for (int i = 0; i < n; i++) {
		if (x[i] > max) {
			max = x[i];
		}
		cout << max << " ";
	}
}
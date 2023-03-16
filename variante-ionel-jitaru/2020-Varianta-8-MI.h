	#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 2

int inversN(int n) {
	int i = 0;
	while (n != 0) {
		i = i * 10 + n % 10;
		n /= 10;
	}
	return i;
}

bool apare(int x[], int c, int y) {
	for (int i = 0; i < c; i++) {
		if (x[i] == y) {
			return 1;
		}
	}
	return 0;
}

void cifreN(int x[], int& c, int n) {
	c = 0;
	int i = inversN(n);
	while (i != 0) {
		if (!apare(x, c, i % 10)) {
			x[c] = i % 10;
			c++;
		}
		i /= 10;
	}
}

void tipar(int k, int s[]) {
	for (int i = 0; i < k + 1; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k, int s[], int n) {
	int i = 0;
	for (int j = 0; j < k + 1; j++) {
		i = i * 10 + s[j];
	}
	if (i < n) {
		return 1;
	}
	return 0;
}

void back(int n, int x[], int c, int s[], int k) {
	for (int i = 0; i < c; i++) {
		s[k] = x[i];
		if (valid(k, s, n)) {
			tipar(k,s);
			back(n, x, c, s, k + 1);
		}
	}
}

void rezolvareSub1Problema2() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	int x[100], c;
	cifreN(x, c, n);
	int s[100];
	back(n, x, c, s, 0);
}

// Subiectul 3

// Problema 2

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

int suma(int n) {
	int i = 2, s = 0;
	bool apare = false;
	while (n > 1) {
		if (n % i == 0 && estePrim(i)) {
			if (!apare) {
				apare = 1;
				s += i;
			}
			n /= i;
		}
		else {
			i++;
			apare = 0;
		}
	}
	return s;
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	cout << suma(n);
}

// Problema 2

void citire(int x[100][100], int& n, int& k) {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Introduceti x[" << i << "][" << j << "] : ";
			cin >> x[i][j];
		}
	}
}

void modificare(int x[100][100], int k) {
	int r = x[k - 1][0];
	for (int j = 0; j < k - 2; j++) {
		x[k - 1][j] = x[k - 1][j + 1];
	}
	x[k - 1][k - 2] = r;
}

void rezolvareSub3Problema2() {
	int x[100][100], n, k;
	citire(x, n, k);
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	modificare(x, k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

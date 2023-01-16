#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(int s[]) {
	for (int i = 0; i < 5; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int s[], int k) {
	int c = 0;
	for (int i = 0; i <= k; i++) {
		if (s[i] == 1) {
			c++;
		}
		else {
			c = 0;
		}

		if (c == 3) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == 4) {
		return 1;
	}
	return 0;
}

void back(int s[], int k) {
	for (int i = 0; i < 2; i++) {
		s[k] = i + 1;
		if (valid(s, k)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int s[100];
	back(s, 0);
}

// Subiectul 2

// Problema 2

struct Data {
	int zi;
	int luna;
	int an;
};

struct c {
	int gramaj;
	Data data;
};

void rezolvareSub2Problema2() {
	c ciocolata;
	ciocolata.gramaj = 15;
	ciocolata.data.zi = 4;
	ciocolata.data.luna = 11;
	ciocolata.data.an = 2029;

	cout << "Gramaj: " << ciocolata.gramaj << "g" << endl;
	cout << "(" << ciocolata.data.zi << "." << ciocolata.data.luna << "." << ciocolata.data.an << ")" << endl;
}

// Subiectul 3

// Problema 1

int n(int x) {
	int count = 0;
	for (int i = 2; i <= x; i++) {
		if (x % i == 0) {
			count++;
		}
	}
	return count;
}

void rezolvareSub3Problema1() {
	int x;
	cout << "Introduceti x : ";
	cin >> x;
	cout << n(x) << endl;
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

void rezolvareSub3Problema2() {
	int m, n;
	int x[100][100];
	citire(x, m, n);

	for (int i = 0; i < m; i++) {
		int max = -1;
		for (int j = 0; j < n; j++) {
			if (x[i][j] > max && x[i][j] < 21) {
				max = x[i][j];
			}
		}
		if (max != -1) {
			cout << max << endl;
		}
		else {
			cout << "nu exista" << endl;
		}
	}
}

// Problema 3

void citireLast(int& n1, int& n2, int x[], int y[]) {
	ifstream f("bac1.txt");
	ifstream g("bac2.txt");
	f >> n1;
	g >> n2;
	for (int i = 0; i < n1; i++) {
		f >> x[i];
	}
	for (int i = 0; i < n2; i++) {
		g >> y[i];
	}
	f.close();
	g.close();
}

void divizibile5(int x[], int n, int y[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 5 == 0) {
			y[m] = x[i];
			m++;
		}
	}
}

void interclasare(int x[], int y[], int z[], int n1, int n2, int& n3) {
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) {
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
	while (i < n1) {
		z[k] = x[i];
		i++;
		k++;
	}
	while (j < n2) {
		z[k] = y[j];
		j++;
		k++;
	}
	n3 = k;
}

bool apare(int x[], int n, int c) {
	for (int i = 0; i < n; i++) {
		if (x[i] == c) {
			return 1;
		}
	}
	return 0;
}

void rezolvareSub3Problema3() {
	int n1, n2, n3;
	int x[100], y[100], z[100];
	citireLast(n1, n2, x, y);
	interclasare(x, y, z, n1, n2, n3);
	int nr[100], d;
	divizibile5(z, n3, nr, d);
	for (int i = 0; i < d; i++) {
		if (apare(x, n1, nr[i]) == !apare(y, n2, nr[i])) {
			cout << nr[i] << " ";
		}
	}
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[], int& count) {
	for (int i = 0; i < 3; i++) {
		cout << s[i] << " ";
		if (s[i] == "Daria") {
			count++;
		}
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	for (int i = 1; i < k; i++) {
		if (s[i] == s[k]) {
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

void back(int k, string x[], string s[], int& count) {
	for (int i = 1; i < 6; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s, count);
			}
			else {
				back(k + 1, x, s, count);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	int count = 0;
	string x[6] = { "Alex","Cezar","Tudor","Daria","Ela","Maria" };
	string s[100];
	s[0] = x[0];
	back(1, x, s, count);
	cout << endl << count;
}

// Subiectul 2

// Problema 2

struct centru {
	int x;
	int y;
};

struct figura {
	centru centru;
	int diametru;
};

// Subiectul 3

// Problema 1

int invers(int x) {
	int i = 0;
	while (x != 0) {
		i = i * 10 + x % 10;
		x /= 10;
	}
	return i;
}

void numar(int n, int c, int& m) {
	m = 0;
	bool diferit = false;
	while (n != 0) {
		if (n % 10 != c) {
			m = m * 10 + n % 10;
			diferit = true;
		}
		n /= 10;
	}
	if (!diferit) {
		m = -1;
	}
	else {
		m = invers(m);
	}
}

void rezolvareSub3Problema1() {
	int n, c, m;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti c : ";
	cin >> c;
	numar(n, c, m);

	cout << m;
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, x[100][100];
	cout << "Introduceti n : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = (n - (j + i + 1)) % n;
			if (k < 0) {
				k *= -1;
			}
			cout << k << " ";
			x[i][j] = k;
		}
		cout << endl;
	}
}

// Problema 3

void citire(int x[], int& n) {
	ifstream f("bac.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int maxSecventa(int x[], int n) {
	int y = 0, z = -1;
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] < 0) {
			if (z == -1) {
				z = i;
			}
			else {
				y = z + 1;
				z = i;
			}
		}
		int curent = i - y + 1;
		if (curent > max) {
			max = curent;
		}
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citire(x, n);

	cout << maxSecventa(x, n);
}
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


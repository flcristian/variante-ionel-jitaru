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

bool solutie(int k) {
	if (k == 3) {
		return 1;
	}
	return 0;
}

bool apare(string y[], string x) {
	for (int i = 0; i < 3; i++) {
		if (y[i] == x) {
			return 1;
		}
	}
	return 0;
}

bool valid(int k, string s[], string y[]) {
	for (int i = 0; i < k; i++) {
		if (apare(y, s[i]) == 1 && apare(y, s[i + 1])) {
			return 0;
		}
	}
	return 1;
}

void back(string x[], string y[], string s[], int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k, s, y)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, y, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[5] = { "cal","caine","papagal","porumbel","ponei" };
	string y[3] = { "cal","papagal","ponei" };
	string s[10];

	back(x, y, s, 0);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	int a[4][5];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			cout << (i + 1) * 5 - j << " ";
			a[i][j] = (i + 1) * 5 - j;
		}
		cout << endl;
	}
}

// Subiectul 3

// Problema 1

void produs(int n, int& p) {
	int f[10]{};
	while (n != 0) {
		if (n % 10 % 2 == 0) {
			f[n % 10]++;
		}
		n /= 10;
	}
	p = 1;
	for (int i = 0; i < 10; i++) {
		if (f[i] > 0) {
			p *= i;
		}
	}
}

void rezolvareSub3Problema1() {
	int n, p;
	cout << "Introduceti n : ";
	cin >> n;

	produs(n, p);
	cout << p;
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


int maxRatie(int x[], int n) {
	int max = 0, maxR;
	for (int i = 1; i < n; i++) {
		int r = x[i] - x[i - 1];
		int c = 0;
		for (int j = i; j < n; j++) {
			if (x[j] - x[j - 1] != r) {
				j = n;
				if (c > max) {f
					max = c;
					maxR = r;
				}
			}
			if (j == n - 1) {
				if (c > max) {
					max = c;
					maxR = r;
				}
			}
			c++;
		}
	}
	return maxR;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	cout << maxRatie(x, n);
}
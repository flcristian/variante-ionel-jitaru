#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 3; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
	return 1;
}

bool solutie1(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

void back(string x[], string s[], int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie1(k)) {
				tipar(s);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[5] = { "rosu","galben","verde","albastru","violet" };
	string s[10];

	back(x, s, 0);
}

// Subiectul 3

// Problema 1

void suma(int n, int& s) {
	s = 0;
	while (n != 0) {
		if ((n % 10) % 2 == 1) {
			s += n % 10;
		}
		n /= 10;
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	int s;
	suma(n, s);
	cout << s;
}

// Problema 3

void citireLast(int x[], int& n, int& k) {
	ifstream f("bac.txt");
	f >> k;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void kSecvente(int x[], int n, int k) {
	int max = 0;
	int count = 0; 
	for (int i = 0; i < n; i++) {
		if (x[i] % k == 0) {
			int c = 0;
			for (int j = i; j < n; j++) {
				if (x[j] % k != 0) {
					j = n;
					if (c == max) {
						count++;
					}
					if (c > max) {
						count = 1;
						max = c;
					}
				}
				if (j == n) {
					if (c == max) {
						count++;
					}
					if (c > max) {
						count = 1;
						max = c;
					}
				}
				c++;
			}
		}
	}
	cout << max << " " << count << endl;
}

void rezolvareSub3Problema3() {
	int x[100], n, k;
	citireLast(x, n, k);
	kSecvente(x, n, k);
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string x[], int s[], int k) {
	for (int i = 0; i < k + 1; i++) {
		cout << x[s[i]] << " ";
	}
	cout << endl;
}

bool valid(int s[], int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k, int p[], int s[]) {
	int suma = 0;
	for (int i = 0; i < k + 1; i++) {
		suma += p[s[i]];
	}
	if (suma == 500) {
		return 1;
	}
	return 0;
}

void back(string x[], int s[], int p[], int k) {
	for (int i = 0; i < 8; i++) {
		s[k] = i;
		if (valid(s, k)) {
			if (solutie(k, p, s)) {
				tipar(x, s, k);
			}
			else {
				back(x, s, p, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[8] = { "casca", "costum de inot", "cleme", "dopuri de urechi", "pluta", "masca de snorkeling", "ochelari", "snorkel" }; 
	int p[8] = { 40,400,30,30,10,400,70,60 };
	int s[100];

	back(x, s, p, 0);
}\

// Subiectul 3

// Problema 1

bool estePar(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
}

void perechi(int n) {
	for (int i = 1; i <= n / 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * j == n && estePar(i) != estePar(j) && j > i) {
				cout << "[" << i << " " << j << "] ";
			}
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	perechi(n);
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

void bubbleSort(int x[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

void afisare(int x[], int n) {
	for (int i = 0, c = 0; i < n && c < 3; i++) {
		if (x[i] % 100 == 20) {
			cout << x[i] << " ";
			c++;
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	bubbleSort(x, n);
	afisare(x, n);
}
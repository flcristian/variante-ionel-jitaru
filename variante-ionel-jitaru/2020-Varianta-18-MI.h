#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

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

bool solutie(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

void back(string x[], string s[], int k) {
	for (int i = 0; i < 5; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, s, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[5] = { "Oedip", "Poema romana", "Rapsodia romana nr. 1", "Rapsodia romana nr. 2", "Simfonia nr. 1" };
	string s[100];

	back(x, s, 0);
}

// Subiectul 3

// Problema 1

void suma(int n, int& s) {
	int f[10]{};
	while (n > 0) {
		f[n % 10]++;
		n /= 10;
	}
	s = 0;
	for (int i = 2; i < 10; i++) {
		if (i % 2 == 0 && f[i] > 0) {
			s += i;
		}
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

// Problema 2

void citirePb2(char cuvinte[200][200], int& n, int& k) {
	char text[10000] = "", nr[10] = "", kr[10] = "";
	cout << "Introduceti numarul de cuvinte : ";
	cin.getline(nr, 100);
	n = atoi(nr);
	cout << "Introduceti pozitia cuvantului dorit : ";
	cin.getline(kr, 100);
	k = atoi(kr);
	for (int i = 0; i < n; i++) {
		cout << "Introduceti cuvantul " << i << " : ";
		cin.getline(cuvinte[i], 200);
	}
}

bool esteSufix(char* cuvant, char* sufix) {
	int i = 0;
	int j = 0;

	for (i = strlen(cuvant) - 1, j = strlen(sufix) - 1; cuvant[i] == sufix[j]; i--, j--);

	if (j == -1) {
		return 1;
	}
	return 0;
}

void rezolvareSub3Problema2() {
	char cuvinte[200][200];
	int n, k;
	citirePb2(cuvinte, n, k);
	k--;

	char sufix[200] = "";
	strcpy(sufix, cuvinte[k]);
	for (int i = 0; i < n; i++) {
		if (i != k) {
			if (esteSufix(cuvinte[i], sufix)) {
				cout << cuvinte[i] << " ";
			}
		}
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

void afisare(int x[], int n) {
	int max = 0, count = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 10 == 0) {
			c++;
		}
		else {
			if (c == max) {
				count++;
			}
			if (c > max) {
				max = c;
				count = 1;
			}
			c = 0;
		}
	}
	if (c == max) {
		count++;
	}
	if (c > max) {
		max = c;
		count = 1;
	}
	cout << max << " " << count << endl;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citire(x, n);
	afisare(x, n);
}
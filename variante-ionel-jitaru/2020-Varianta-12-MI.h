#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 2

// Problema 2

struct flori {
	int cod;
	int nrVarietati;
	int nrExemplare[10];
};

void rezolvareSub2Problema2() {
	flori f[20];
}

// Subiectul 3

// Problema 1

void formareX(int n, int x[], int& m) {
	x[0] = 2;
	m = 1;
	while (x[m - 1] * 2 <= n && x[m - 1] <= n) {
		x[m] = x[m - 1] * 2;
		m++;
	}
}

int pDoi(int n) {
	int x[100], m;
	formareX(n, x, m);
	if (x[m - 1] > n) {
		return -1;
	}
	else {
		return x[m - 1];
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;
	
	cout << pDoi(n);
}

// Problema 2

void spargere(char text[], char cuvinte[100][100], int& d) {
	d = 0;
	char* a;
	a = strtok(text, " ");
	while (a != NULL) {
		strcpy(cuvinte[d], a);
		d++;
		a = strtok(NULL, " ");
	}
}

bool esteVocala(char litera) {
	char vocale[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < 5; i++) {
		if (litera == vocale[i]) {
			return 1;
		}
	}
	return 0;
}

void cautareSiEliminareVocala(char cuvant[100], bool& found) {
	for (int i = strlen(cuvant) - 1; i > 0 && !found; i--) {
		if (esteVocala(cuvant[i])) {
			char seg1[100] = "";
			char seg2[100] = "";
			strncpy(seg1, cuvant, i);
			strcpy(seg2, cuvant + i + 1);
			strcpy(cuvant, seg1);
			strcat(cuvant, seg2);
			found = true;
		}
	}
}

void rezolvareSub3Problema2() {
	char text[100] = "";
	char cuvinte[100][100];
	int d;
	cout << "Introduceti textul : ";
	cin.getline(text, 100);
	spargere(text, cuvinte, d);

	bool found = false;
	if (!found) {
		for (int i = d - 1; i > 0; i--) {
			cautareSiEliminareVocala(cuvinte[i], found);
		}
	}
	
	if (found) {
		for (int i = 0; i < d; i++) {
			cout << cuvinte[i] << " ";
		}
	}
	else {
		cout << "nu exista";
	}
	cout << endl;
}

// Problema 3

void rezolvare(int y[100], int& n, int x) {
	n = 0;
	while (y[n - 1] < x) {
		if (n < 10) {
			y[n] = n + 1;
		}
		else {
			if (n % 2 == 0) {
				y[n] = y[n - 1] * 2;
			}
			else {
				y[n] = y[n - 1] + 1;
			}
		}
		n++;
	}
}

void rezolvareSub3Problema3() {
	int x;
	cout << "Introduceti x : ";
	cin >> x;

	int y[100], n;
	rezolvare(y, n, x);
	for (int i = n - 1; i > -1; i--) {
		cout << y[i] << " ";
	}
}
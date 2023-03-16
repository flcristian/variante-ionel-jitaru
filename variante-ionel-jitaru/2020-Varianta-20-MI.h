#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 1

// Problema 3

bool comparator(char x[6][200], int k, char cuvant1[200], char cuvant2[200]) {
	bool apare = 0;
	for (int i = 0; i < k; i++) {
		if (strcmp(x[i], cuvant1) == 0) {
			apare = 1;
		}
		if ((strcmp(x[i], cuvant2) == 0) && !apare) {
			return 0;
		}
	}
	return 1;
}

void tipar(char s[10][200]) {
	for (int i = 0; i < 6; i++) {
		cout << s[i];
		if (i < 5) {
			cout << " - ";
		}
	}
	cout << "\n\n";
}

bool valid(char s[10][200], int k) {
	bool apareCiuperci = false, apareSalata = false, aparePanna = false;
	for (int i = 0; i < k; i++) {
		if (strcmp(s[i], s[k]) == 0) {
			return 0;
		}
	}
	char ciuperci[] = "ciuperci cu spanac";
	char legume[] = "legume la cuptor";
	char pere[] = "pere umplute cu nuca";
	char panna[] = "panna cotta de cocos cu vanilie";
	char salata[] = "salata cu smochine";
	char tort[] = "tort de lamaie";
	if (comparator(s, k, legume, ciuperci) && k == 5) {
		return 0;
	}
	if (comparator(s, k, salata, legume) && k == 5) {
		return 0;
	}
	if ((comparator(s, k, panna, tort) || comparator(s, k, panna, pere)) && k == 5) {
		return 0;
	}
	return 1;
}

bool solutie(int k) {
	if (k == 5) {
		return 1;
	}
	return 0;
}

void back(char s[10][200], char x[6][200], int k) {
	for (int i = 0; i < 6; i++) {
		strcpy(s[k], x[i]);
		if (valid(s, k)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(s, x, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	char x[6][200] = { "ciuperci cu spanac", "legume la cuptor", "pere umplute cu nuca", "panna cotta de cocos cu vanilie", "salata cu smochine", "tort de lamaie" };
	char s[10][200];
	back(s, x, 0);
}



// Subiectul 2

// Problema 3

void rezolvareSub2Problema3() {
	int i, j;
	char a[7][7];

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (j > i && j < 7 - i - 1) {
				cout << "a ";
				a[i][j] = 'a';
			}
			else if (j > 7 - i - 1 && j < i) {
				cout << "a ";
				a[i][j] = 'a';
			}
			else {
				cout << "b ";
				a[i][j] = 'b';
			}
		}
		cout << endl;
	}
}

// Subiectul 3

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

void rezolvareSub3Problema2() {
	char text[100] = "";
	char cuvinte[100][100];
	int d;
	cout << "Introduceti textul : ";
	cin.getline(text, 100);
	spargere(text, cuvinte, d);

	for (int i = 0; i < d; i++) {
		int k = atoi(cuvinte[i]);
		if (k == 0 && cuvinte[i][0] != '0') {
			cout << cuvinte[i];
		}
		else {
			cout << k;
		}
		cout << " ";
	}
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

bool estePar(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
}

int sumaMax(int x[], int n) {
	int max = 0, s = 0;
	for (int i = 0; i < n - 1; i++) {
		s += x[i];
		if (estePar(x[i]) != estePar(x[i + 1])) {
			if (s > max) {
				max = s;
			}
			s = 0;
		}
	}
	return max;
}

void rezolvareSub3Problema3() {
	int x[100], n;
	citireLast(x, n);
	cout << sumaMax(x, n);
}
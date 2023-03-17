#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 2

// Problema 2

struct Proiect {
	int cod;
	int nrProiecte;
};

void rezolvareSub2Problema2() {
	Proiect proiect1, proiect2;
	proiect1.cod = 0, proiect1.nrProiecte = 12;
	proiect2.cod = 1, proiect2.nrProiecte = 5;

	if (proiect1.nrProiecte > proiect2.nrProiecte) {
		cout << proiect1.cod << " ";
	}
	else {
		cout << proiect2.cod << " ";
	}
	cout << (int)((proiect1.nrProiecte + proiect2.nrProiecte) / 2);
}

// Problema 3

void rezolvareSub2Problema3() {
	char a;
	int i, k;
	char vocale[5] = { 'a','e','i','o','u' };
	k = 0;
	for (i = 1; i <= 10; i++) {
		cin >> a;
		for (int j = 0; j < 5; j++) {
			if (a == vocale[j]) {
				k++;
			}
		}
	}
	cout << k;
}

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int n, c = 0;
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if ((n % 2 == i % 2) && (n % i == 0)) {
			c++;
		}
	}
	cout << c;
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);

	bool exista = false;
	for (int i = 0, j = n - 1; i < n / 2; i++) {
		if (x[i] != x[j - i]) {
			exista = true;
		}
	}

	if (exista) {
		cout << "DA";
	}
	else {
		cout << "NU";
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

void removePos(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void rezolvareSub3Problema3() {
	int x[100000], n;
	citireLast(x, n);

	for (int i = 0; i < n - 1; i++) {
		if (x[i] == x[i + 1]) {
			removePos(x, n, i);
			i--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
}
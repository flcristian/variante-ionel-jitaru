#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 1

// Problema 3

void rezolvareSub1Problema3() {
	int i, j;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if ((j > i && j < 7 - i - 1)||(j > 7 - i - 1 && j < i)) {
				cout << "a ";
			}
			else {
				cout << "b ";
			}
		}
		cout << endl;
	}
}

// Subiectul 2

// Problema 2

struct Ingredient {
	char cod;
	double cantitate;
};

void rezolvare(Ingredient i1, Ingredient i2) {
	Ingredient max;
	if (i1.cantitate > i2.cantitate) {
		max = i1;

	}
	else if (i2.cantitate > i1.cantitate) {
		max = i2;
	}

	switch (max.cod)
	{
	case 'C':
		cout << "C" << endl;
		cout << "cacao";
		break;
	case 'M':
		cout << "M" << endl;
		cout << "miere";
		break;
	default:
		cout << "altceva";
		break;
	}
}

void rezolvareSub2Problema2() {
	Ingredient cacao, miere;
	cacao.cod = 'C', cacao.cantitate = 150;
	miere.cod = 'M', miere.cantitate = 80;
	rezolvare(cacao, miere);
}

// Subiectul 3

// Problema 1

int cbk(int b, int n) {
	int r = n;
	int countCifre = 0;
	while (r > 0) {
		r /= 10;
		countCifre++;
	}
	
	int s = 0, i = countCifre;
	while (n > 0) {
		int c = n % 10;
		s += c * pow(b, i);
		i--;
		n /= 10;
	}
	return s;
}
	
void rezolvareSub3Problema1() {
	int b, n;
	cout << "Introduceti b : ";
	cin >> b;
	cout << "Introduceti n : ";
	cin >> n;

	cout << cbk(b, n);
}

// Problema 2

void citireS3P2(double x[], int& n) {
	cout << "Introduceti numarul de elemente : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	double x[20];
	int n;
	citireS3P2(x, n);
	
	for (int i = 0; i < n; i++) {
		x[i] = (int)(x[i]);
		cout << x[i] << " ";
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

void rezolvareSub3Problema3() {
	int x[100000], n;
	citireLast(x, n);

	int max = 0, suma = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0) {
			suma += x[i];
			if (suma > max) {
				max = suma;
			}
		}
		else {
			suma = 0;
		}
	}

	cout << max << endl;
}
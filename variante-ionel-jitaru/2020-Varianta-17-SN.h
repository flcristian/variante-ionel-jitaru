#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 2

// Problema 2

void rezolvareSub2Problema2() {
	int zi1, luna1, zi2, luna2;
	zi1 = 5, luna1 = 4;
	zi2 = 8, luna2 = 3;

	if (luna1 < luna2 && zi1 < luna1) {
		cout << zi1 << "." << luna1 << endl;
		cout << zi2 << "." << luna2 << endl;
	}
	else {
		cout << zi2 << "." << luna2 << endl;
		cout << zi1 << "." << luna1 << endl;
	}
}

// Problema 3

void rezolvareSub2Problema3() {
	char a;
	int i, ok;

	ok = 1;
	char vocale[5] = { 'a','e','i','o','u' };
	for (i = 1; i <= 11; i++) {
		cin >> a;

		bool esteVocala = false;
		for (int j = 0; j < 5; j++) {
			if (a == vocale[j]) {
				esteVocala = true;
			}
		}

		if (!esteVocala) {
			ok = 0;
		}
	}

	cout << ok;
}

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	int max = -1;
	while (n != 0) {
		int c = n % 10;
		if (c % 2 == 1 && c > max) {
			max = c;
		}
		n /= 10;
	}
	cout << max;
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

int contineDoarImpare(int x) {
	while (x != 0) {
		if()
	}
}

//todo
void adaugarePozitie() {

}

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);


}

// Problema 3
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i % 2 == 0 && (i * j + (i / j) == n)) {
				cout << i << "-" << j << " ";
			}
		}
	}
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti numarul elementelor : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elementul " << i << " : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[20], n;
	citirePb2(x, n);

	// NU E GATA!
	// NU E GATA!
	// NU E GATA!
	// NU E GATA!
	// NU E GATA!
}

// Problema 3

void rezolvareSub3Problema3() {

}
// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!
// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!
// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!// NU E GATA!
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 3

// Problema 1

int sumaDiv(int x) {
	int s = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			s += i;
		}
	}
	return s;
}

void rezolvareSub3Problema1() {
	int x, y;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;

	int s1 = sumaDiv(x), s2 = sumaDiv(y);
	if (s1 > s2) {
		int r = s1;
		s1 = s2;
		s2 = r;
	}
	int suma = x + y;

	if (suma > s1 && suma < s2) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

// Problema 2

void citirePb2(int x[], int& n) {
	cout << "Introduceti n : ";
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
}

void rezolvareSub3Problema2() {
	int x[40], n;
	citirePb2(x, n);


}

// Problema 3

void rezolvareSub3Problema3() {

}
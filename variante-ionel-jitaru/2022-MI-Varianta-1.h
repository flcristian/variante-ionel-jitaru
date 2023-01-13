#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 3

// Problema 1

int max(int x, int y, int z) {
	int nr[3] = { x,y,z };
	int max = nr[0];
	for (int i = 1; i < 3; i++) {
		if (nr[i] > max) {
			max = nr[i];
		}
	}
	return max;
}

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {

			a = a - b;
		}
		if (a < b) {

			b = b - a;
		}
	}
	return a;
}

int cmmmc(int a, int b) {
	return a * b / cmmdc(a, b);
}

int mozaic(int a, int b, int c) {
	int m = cmmmc(a, b);
	m = cmmmc(m, c);
	return m;
}

void rezolvareSub3Problema1() {
	int x, y, z;
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti y : ";
	cin >> y;
	cout << "Introduceti z : ";
	cin >> z;
	cout << mozaic(x, y, z);
}

// Problema 2


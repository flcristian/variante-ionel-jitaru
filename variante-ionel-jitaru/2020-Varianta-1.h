#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

int formareNumar(int s[], int k) {
	int i = 0;
	for (int j = 0; j < k + 1; j++) {
		i = i * 10 + s[j];
	}
	return i;
}

void back(int k, int s[]) {
	for (int i = 0; i < 4 && k < 3; i++) {
		if (i == 0 && k == 0) {
			i++;
		}
		s[k] = i;
		int numar = formareNumar(s, k);
		if (numar % 2 == 1) {
			cout << numar << endl;
		}
		back(k + 1, s);
	}
}

void rezolvareSub1Problema3() {
	int s[100];

	back(0, s);
}

// Subiectul 2

// Problema 2

struct Punct {
	double x;
	double y;
};

struct triunghi {
	Punct A;
	Punct B;
	Punct C;
};

void rezolvareSub2Problema2() {
	triunghi t;
	t.A.x = 2;
	t.B.y = -1.2;
	t.C.y = 12;

	cout << t.A.x << " " << t.B.y << " " << t.C.y << endl;
}

// Subiectul 3

// Problema 1

int countDiv(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool estePrim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void descompunereFactoriPrimi(int x, int f[]) {
	for (int i = 2; i <= x; i++) {
		if (x % i == 0 && estePrim(i)) {
			f[i]++;
			x /= i;
			i--;
		}
	}
}

void putere(int n, int& d, int& p) {
	int f[100]{};
	descompunereFactoriPrimi(n, f);
	d = 0, p = 0;
	for (int i = 0; i < 100; i++) {
		if (f[i] > p) {
			p = f[i];
			d = i;
		}
		else if (p == f[i] && i > d) {
			d = i;
		}
	}
}

void rezolvareSub3Problema1() {
	int n, d, p;
	cout << "Introduceti n : ";
	cin >> n;
	putere(n, d, p);
	cout << d << " " << p << endl;
}

// Problema 2

void rezolvareSub3Problema2() {
	int n, k;
	int x[100][100];
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < (n+1)*k; j++) {
			cout << (i + 1) + j / k << " ";
			x[i][j] = (i + 1) + j / k;
		}
		cout << endl;
	}
}

// Problema 3

int afisare(int y, int v[], int& n) {
	
}

void rezolvareSub3Problema3() {

}



























#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Subiectul 2

// Problema 2

struct Lucrare {
	char tip;
	int catalog;

	void afisare() {
		switch (tip)
		{
		case 'O':
			cout << "Oedip" << endl << catalog << endl;
			break;
		case 'P':
			cout << "Poema Romana" << endl << catalog << endl;
			break;
		case 'R':
			cout << "Rapsodia Romana" << endl << catalog << endl;
			break;
		default:
			break;
		}
	}
};

void rezolvareSub2Problema2() {
	Lucrare Oedip, Poema, Rapsodia;
	Oedip.tip = 'O', Poema.tip = 'P', Rapsodia.tip = 'R';
	Oedip.catalog = 0, Poema.catalog = 3, Rapsodia.catalog = 5;

	Oedip.afisare();
	Poema.afisare();
	Rapsodia.afisare();
}

// Subiectul 3

// Problema 1

void rezolvareSub3Problema1() {
	int n, suma = 0;
	cout << "Introduceti n : ";
	cin >> n;

	int frecventa[10]{};
	while (n != 0) {
		frecventa[n % 10]++;
		n /= 10;
	}

	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0 && frecventa[i] > 0) {
			suma += i;
		}
	}
	cout << suma;
}

// Problema 2

void citirePb2(int x[], int& n, int& k) {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
}

int cifraZecilor(int x) {
	int c = x % 100;
	c /= 10;
	return c;
}

void rezolvareSub3Problema2() {
	int x[20], n, k;
	citirePb2(x, n, k);
	k--;
	
	int c = cifraZecilor(x[k]);
	for (int i = 0; i < n; i++) {
		if (i != k && cifraZecilor(x[i]) == c){
			cout << x[i] << " ";
		}
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
	int x[10000], n;
	citireLast(x, n);

	int max = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 10 == 0) {
			c++;
			if (c > max) {
				max = c;
			}
		}
		else {
			c = 0;
		}
	}
	cout << max;
}
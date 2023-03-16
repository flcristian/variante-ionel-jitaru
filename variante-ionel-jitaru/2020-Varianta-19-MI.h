#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 5; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	bool apareWeb = 0, apareInterviuri = 0, apareImagine = 0, apareSunet = 0, apareText = 0, apareVideo = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
		if (s[i] == "web") {
			apareWeb = 1;
		} 
		if (s[i] == "interviuri") {
			apareInterviuri = 1;
		}
		if (s[i] == "imagine") {
			apareImagine = 1;
		}
		if (s[i] == "sunet") {
			apareSunet = 1;
		}
		if (s[i] == "text") {
			apareText = 1;
		}
		if (s[i] == "video") {
			apareVideo = 1;
		}
	}

	if (apareWeb && (apareSunet || apareVideo)) {
		return 0;
	}
	if (apareInterviuri && (apareImagine || apareText)) {
		return 0;
	}

	return 1;
}

bool solutie(int k) {
	if (k == 4) {
		return 1;
	}
	return 0;
}

void back(string x[], string y[], string z[], string s[], int k) {
	for (int i = 0; i < 3 && k < 3; i++) {
		s[k] = x[i];
		if (valid(k, s)) {
			if (solutie(k)) {
				tipar(s);
			}
			else {
				back(x, y, z, s, k + 1);
			}
		}
	}
	if (k > 2) {
		int d;
		k == 3 ? d = 2 : d = 4;
		for (int i = 0; i < d; i++) {
			(k == 3 ? s[k] = y[i] : s[k] = z[i]);

			if (valid(k, s)) {
				if (solutie(k)) {
					tipar(s);
				}
				else {
					back(x, y, z, s, k + 1);
				}
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[3] = { "culegeri", "manuale", "notite" };
	string y[2] = { "web", "interviuri" };
	string z[4] = { "imagine", "sunet", "text", "video" };
	string s[10];

	back(x, y, z, s, 0);
}

// Subiectul 3

// Problema 1

void paritate(int n, int& nr) {
	nr = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			if (n % 2 == i % 2) {
				nr++;
			}
		}
	}
}

void rezolvareSub3Problema1() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	int nr;
	paritate(n, nr);
	cout << nr;
}

// Problema 2

void citire(int x[100][100], int& m, int& n, int& k) {
	cout << "Introduceti m : ";
	cin >> m;
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti k : ";
	cin >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Introduceti x[" << i << "][" << j << "] : ";
			cin >> x[i][j];
		}
	}
}

bool conditie(int x[100][100], int m, int n, int k) {
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < n && i != k - 1; j++) {
			if (x[k - 1][j] == x[i][j]) {
				flag = false;
			}
		}
		if (flag) {
			return 1;
		}
	}
	return 0;
}

void rezolvareSub3Problema2() {
	int m, n, k, x[100][100];
	citire(x, m, n, k);
	if (conditie(x,m,n,k)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}
}

// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 

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

bool apare(int y[100], int m, int x) {
	for (int i = 0; i < m; i++) {
		if (y[i] == x) {
			return 1;
		}
	}
	return 0;
}

void vector(int x[100], int y[100], int n, int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0 && !apare(y,m,x[i])) {
			y[m] = x[i];
			m++;
		}
	}
}

void rezolvareSub3Problema3() {
	int x[100], y[100], n, m;
	citireLast(x, n);
	vector(x, y, n, m);
	for (int i = 0; i < m; i++) {
		cout << y[i] << " ";
	}
}
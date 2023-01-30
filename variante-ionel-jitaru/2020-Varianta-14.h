#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string x[], int s[], int k) {
	for (int i = 0; i < k + 1; i++) {
		cout << x[s[i]] << " ";
	}
	cout << endl;
}

bool valid(int s[], int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k, int p[], int s[]) {
	int suma = 0;
	for (int i = 0; i < k + 1; i++) {
		suma += p[s[i]];
	}
	if (suma == 500) {
		return 1;
	}
	return 0;
}

void back(string x[], int s[], int p[], int k) {
	for (int i = 0; i < 8; i++) {
		s[k] = i;
		if (valid(s, k)) {
			if (solutie(k, p, s)) {
				tipar(x, s, k);
			}
			else {
				back(x, s, p, k + 1);
			}
		}
	}
}

void rezolvareSub1Problema3() {
	string x[8] = { "casca", "costum de inot", "cleme", "dopuri de urechi", "pluta", "masca de snorkeling", "ochelari", "snorkel" }; 
	int p[8] = { 40,400,30,30,10,400,70,60 };
	int s[100];

	back(x, s, p, 0);
}
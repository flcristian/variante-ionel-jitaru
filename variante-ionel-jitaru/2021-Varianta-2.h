#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]) {
	for (int i = 0; i < 4; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k, string s[]) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
}

void rezolvareSub1Problema3() {
	int n = 5, m = 3;
	string x[5] = { "Bono" , "Bruce Springsteen", "Bon Jovi", "Leonard Cohen", "Portugal.The Man" };
	string s[4];

	back(n, m, s, x, 0);
}
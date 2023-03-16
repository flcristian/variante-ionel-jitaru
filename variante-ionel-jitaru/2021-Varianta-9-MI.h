#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 2

void tipar(string s[]){
    for(int i = 0;i<5;i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

bool valid(int k, string s[]){
    for(int i = 0;i<k;i++){
        if(s[i]==s[k]){
            return 0;
        }
    }
    return 1;
}

bool solutie(int k){
    if(k == 4){
        return 1;
    }
    return 0;
}

void back(int k, string x[], string s[]){
    for(int i = 0;i<5;i++){
        s[k]=x[i];
        if(valid(k, s)){
            if(solutie(k)){
                tipar(s);
            } else{
                back(k+1,x,s);
            }
        }
    }
}

void rezolvareSub1Problema2(){
    string x[5]={"salcie","carpen","larice","fag","ulm"};
    string s[5];
    
    back(0,x,s);
}

// Subiectul 2

// Problema 3

void rezolvareSub2Problema3(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<5;j++){
            cout << (i+j)%3 << " ";
        }
        cout << endl;
    }
}

// Subiectul 3

// Problema 1

void citire1(int& a, int& b, int& k){
    cout << "Introduceti a : ";
    cin >> a;
    cout << "Introduceti b : ";
    cin >> b;
    cout << "Introduceti k : ";
    cin >> k;
}

void divizor(int a, int b, int k, int& nr){
    nr = 0;
    for(int i=a;i<=b;i++){
        if(i%10==k && i%k==0){
            nr++;
            cout << i << " ";
        }
    }
}

void rezolvareSub3Problema1(){
    int a,b,k;
    int nr;
    citire1(a,b,k);
    divizor(a,b,k,nr);
    cout<<nr<<endl;
}

// Problema 2

void spargere(char text[], char cuvinte[100][100], int& d) {
    d = 0;
    char* a;
    a = strtok(text, " ");
    while (a != NULL) {
        strcpy(cuvinte[d], a);
        d++;
        a = strtok(NULL, " ");
    }
}

bool esteVocala(char litera) {
    char vocale[5] = { 'a','e','i','o','u' };
    for (int i = 0; i < 5; i++) {
        if (litera == vocale[i]) {
            return 1;
        }
    }
    return 0;
}

void frecventaVocale(char cuvant[100], int frecventa[5]) {
    char vocale[5] = { 'a','e','i','o','u' };
    for (int i = 0; i < strlen(cuvant); i++) {
        for (int j = 0; j < 5; j++) {
            if (cuvant[i] == vocale[j]) {
                frecventa[j]++;
            }
        }
    }
}

bool doarOVocala(int frecventa[5]) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (frecventa[i] > 0) {
            count++;
        }
    }
    if (count == 1) {
        return 1;
    }
    return 0;
}

void rezolvareSub3Problema2() {
    char text[100] = "";
    char cuvinte[100][100];
    int d;
    cout << "Introduceti textul : ";
    cin.getline(text, 100);
    spargere(text, cuvinte, d);

    for (int i = 0; i < d; i++) {
        int frecventa[5]{};
        frecventaVocale(cuvinte[i], frecventa);
        if (doarOVocala(frecventa)) {
            cout << cuvinte[i] << " ";
        }
    }
}

// Problema 3

void citireLast(int x[], int& n){
    ifstream f("bac.txt");
    n = 0;
    while(!f.eof()){
        f>>x[n];
        n++;
    }
    f.close();
}

void adaugareFrecventaCifre(int x, int f[]){
    while(x!=0){
        f[x%10]++;
        x/=10;
    }
}

void adaugareFrecventaNumere(int x[], int n, int f[]){
    for(int i = 0;i<n;i++){
        adaugareFrecventaCifre(x[i],f);
    }
}

void afisareFrecventaIndice(int i, int f[]){
    while(f[i]>0){
        cout << i;
        f[i]--;
    }
}

void afisareLast(int f[]){
    for(int i = 9;i>-1;i--){
        afisareFrecventaIndice(i,f);
    }
}

void rezolvareSub3Problema3(){
    int x[100], n;
    int f[10]{};
    citireLast(x,n);
    adaugareFrecventaNumere(x,n,f);
    afisareLast(f);
}




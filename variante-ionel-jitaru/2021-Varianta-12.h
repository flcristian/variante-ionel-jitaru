#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]){
    for(int i = 0;i<3;i++){
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
    if(k==2){
        return 1;
    }
    return 0;
}

void back(int k, string x[], string s[]){
    for(int i =0;i<5;i++){
        s[k]=x[i];
        if(valid(k,s)){
            if(solutie(k)){
                tipar(s);
            }else{
                back(k+1,x,s);
            }
        }
    }
}

void rezolvareSub1Problema3(){
    string x[5]={"rosu","galben","verde","albastru","violet"};
    string s[100];
    back(0,x,s);
}

// Subiectul 3

// Problema 1

int countCifre(int x){
    int c = 0;
    while(x!=0){
        c++;
        x/=10;
    }
    return c;
}

int formareNumar(int z[], int n){
    int i = 0;
    for(int j = 0;j<n;j++){
        i=i*10+z[j];
    }
    return i;
}

void frate(int x, int& y){
    int z[100], n = countCifre(x);
    for (int i = n-1; i >-1; i--) {
        z[i] = x % 10 + 1;
        z[i] = z[i] % 10;
        x /= 10;
    }
    if (z[0] == 0) {
        y = -1;
    }
    else {
        y = formareNumar(z, n);
    }
}

void rezolvareSub3Problema1(){
    int x,y;
    cout << "Introduceti x : ";
    cin >> x;

    frate(x,y);
    cout << y;
}

// Problema 2

void citireFisier(int x[100][100], int& n, int& k) {
    ifstream f("bac.txt");
    f>>n>>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            f >> x[i][j];
        }
    }
    f.close();
}

void citireTastatura(int x[100][100], int& n, int& k){
    cout << "Introduceti n : ";
    cin >> n;
    cout << "Introduceti k : ";
    cin >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << "Introduceti x[" << i << "][" << j << "] : ";
            cin >> x[i][j];
        }
    }
}

void rezolvareSub3Problema2(){
    int x[100][100], n, k;
    citireFisier(x,n,k);

    int r = x[k-1][n-k-1];
    for(int i = n-k - 1;i>0;i--){
        x[k-1][i] = x[k-1][i-1];
    }
    x[k-1][0]=r;

    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
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

void bubbleSortDescrescator(int x[], int n){
    bool flag = true;
    do{
        flag = true;
        for(int i = 0;i<n-1;i++){
            if(x[i]<x[i+1]){
                int r = x[i];
                x[i]=x[i+1];
                x[i+1]=r;
                flag=false;
            }
        }
    }while(flag==false);
}

void rezolvareSub3Problema3(){
    int x[100], n;
    citireLast(x,n);
    int r = x[0];
    bubbleSortDescrescator(x,n);
    int i = n - 1;
    while(x[i]!=r){
        i--;
    }
    cout << i + 1;
}











































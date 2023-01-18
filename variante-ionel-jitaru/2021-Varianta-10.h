#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 3

void tipar(string s[]){
    for(int i = 0;i<4;i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

bool valid(int k, string s[]){
    for(int i = 0;i<k;i++){
        if(s[i]>=s[i+1]){
            return 0;
        }
    }
    return 1;
}

bool solutie(int k){
    if(k == 3){
        return 1;
    }
    return 0;
}

void back(int k, string x[], string s[]){
    for(int i = 0;i<6;i++){
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
    string x[6]={"Ana", "Ioana", "Lia", "Maria", "Miruna", "Simona"};
    string s[100];
    back(0,x,s);
}

// Subiectul 2

struct Elev{
    int cod;
    double nota1;
    double nota2;
};

void rezolvareSub2Problema2(){
    Elev y[30];
}

// Subiectul 3

// Problema 1

int sumaDivizori(int x){
    int suma = 0;
    for(int i = 1;i<=x;i++){
        if(x%i==0){
            suma+=i;
        }
    }
    return suma;
}

int armonie(int x, int y){
    int sumaX = sumaDivizori(x);
    int sumaY = sumaDivizori(y);
    int suma = x + y;

    if(sumaX>sumaY){
        int r = sumaX;
        sumaX = sumaY;
        sumaY = r;
    }
    
    if((!(suma>sumaX)) || (!(suma<sumaY))){
        return 0;
    }
    return 1;
}

void rezolvareSub3Problema1(){
    int x,y;
    cout << "Introduceti x : ";
    cin >> x;
    cout << "Introduceti y : ";
    cin >> y;

    cout << armonie(x,y);
}

// Problema 2

void citireFisier(int x[100][100], int& m, int& n){
    ifstream f("bac.txt");
    f>>m>>n;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            f>>x[i][j];
        }
    }
    f.close();
}

void citire(int x[100][100], int& m, int& n){
    cout << "Introduceti m : ";
    cin >> m;
    cout << "Introduceti n : ";
    cin >> n;

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout << "Introduceti x[" << i << "][" << j << "] : ";
            cin >> x[i][j];
        }
    }
}

void atribuireVectori(int x[100][100], int m, int n, int v1[], int v2[], int& d1, int& d2){
    d1 = n - 1;
    d2 = m - 1;

    for(int i = 0;i<d1;i++){
        v1[i]=x[0][i];
    }
    for(int i = 1;i<m;i++){
        v2[i-1]=x[i][d1];
    }
}

bool apare(int x[], int n, int nr){
    for(int i = 0;i<n;i++){
        if(x[i]==nr){
            return 1;
        }
    }
    return 0;
}

void filtreaza(int v1[], int v2[], int d1, int d2, int y[], int& k){
    k = 0;
    for(int i = 0;i<d1;i++){
        if(apare(v2,d2,v1[i])){
            y[k]=v1[i];
            k++;
        }
    }
}

void afisare(int x[], int n){
    for(int i = 0;i<n;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void rezolvareSub3Problema2(){
    int x[100][100], m, n;
    citireFisier(x,m,n);
    int v1[100],v2[100],d1,d2;
    atribuireVectori(x,m,n,v1,v2,d1,d2);
    int y[100], k;
    filtreaza(v1,v2,d1,d2,y,k);
    if(k != 0){
        afisare(y,k);
    } else{
        cout << "nu exista";
    }
    
}

// Problema 3

void citireLast(int x[], int& n){
    ifstream f("bac.txt");
    n = 0;
    while(!f.eof()){
        f >> x[n];
        n++;
    }
    f.close();
}

void bubbleSort(int x[], int n){
    bool flag = true;
    do{
        flag = true;
        for(int i = 0;i<n-1;i++){
            if(x[i]>x[i+1]){
                int r = x[i];
                x[i]=x[i+1];
                x[i+1]=r;
                flag = false;
            }
        }
    } while(flag==false);
}

void rezolvareSub3Problema3(){
    int x[100], n;
    citireLast(x,n);
    int retinut = x[0];
    bubbleSort(x,n);

    int i = 0;
    while(x[i]!=retinut){
        i++;
    }
    cout << i + 1;
}


















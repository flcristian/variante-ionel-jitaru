#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Subiectul 1

// Problema 2

// ? ? ? ? ? ? ? ? ? 
// ? ? ? ? ? ? ? ? ? 
// ? ? ? ? ? ? ? ? ? 

void tipar(int s[]){
    bool apareNenul = false;
    for(int i = 0;i<4;i++){
        if(s[i]!=0){
            apareNenul=true;
            cout << s[i];
        } else{
            if(apareNenul){
                cout << s[i];
            }
        }
    }
    if(!apareNenul){
        cout << 0;
    }
    cout << endl;
}

bool solutie(int k){
    if(k == 3){
        return 1;
    }
    return 0;
}

void back(int k, int x[], int s[]){
    for(int i = 0;i<3;i++){
        s[k]=x[i];
        if(solutie(k)){
            tipar(s);
        }else{
            back(k+1,x,s);
        }
    }
}

void rezolvareSub1Problema2(){
    int x[3] = {0,1,2};
    int s[100];
    back(0,x,s);
}

// ? ? ? ? ? ? ? ? ? 
// ? ? ? ? ? ? ? ? ? 
// ? ? ? ? ? ? ? ? ? 

// Subiectul 3

// Problema 1

int inversFaraPare(int x){
    int i = 0;
    while(x!=0){
        if((x%10)%2==1){
            i = i * 10 + x%10;
        } 
        x/=10;
    }
    return i;
}

void imog(int x, int y, int& rez){
    x = inversFaraPare(x);
    y = inversFaraPare(y);
    if(x==inversFaraPare(y)){
        rez = 1;
    } else{
        rez = 0;
    }
}

void rezolvareSub3Problema1(){
    int x, y;
    cout << "Introduceti x : ";
    cin >> x;
    cout << "Introduceti y : ";
    cin >> y;
    int rez;
    imog(x,y,rez);
    cout << rez;
}

// Problema 2

void citireFisier(int x[100][100], int& n, int& k) {
    // Trebuie din tastatura, dar dureaza prea mult 
    // introducerea manuala. (La bac din tastatura)
    ifstream f("bac.txt");
    f>>n>>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            f >> x[i][j];
        }
    }
    f.close();
}

// | | |               | | |
// V V V Din tastatura V V V

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
    int nr = k - 1;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;

    for(int i = 0;i<nr;i++){
        int r = x[i][nr];
        x[i][nr] = x[nr][i];
        x[nr][i]=r;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

// Problema 3

void atribuire(int v[], int& n, int y){
    v[0] = 1;
    n = 1;
    while(v[n-1]<y && v[n-1]+2*n<=y){
        v[n]=v[n-1]+2*n;
        n++;
    }
}

void rezolvareSub3Problema3(){
    int x,y;
    cout << "Introduceti x : ";
    cin >> x;  
    cout << "Introduceti y : ";
    cin >> y;

    // Nu inteleg la ce trebuie x in problema asta.

    int v[100], n;
    atribuire(v,n,y);

    for(int i = n - 1;i>-1;i--){
        cout << v[i] << " ";
    }
}





















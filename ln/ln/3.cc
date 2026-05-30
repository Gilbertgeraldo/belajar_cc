#include<bits/stdc++.h>
#define Nmaks 10
using namespace std;
typedef int matrik[Nmaks][Nmaks];

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main(void) {
    int n,i,j;
    matrik A,B,C;
    cout << "\nProgram penjumlahan Matriks A 2x2 dan B 2x2\n" << endl;
    cout << endl;
    n =2;
    cout << "\nMasukan Nilai-Nilai matriks A :\n" << endl;
    for (int i = 0;i <= n; i++) {
        for (int j =1; j <= n;j++) {
            cout << "A[" << i << " , " <<  j << "] = ",cin >> A[i][j];
        }
    }
    system("clear");
    cout << "\nMasukan nilai-nilai untuk matrik B :" << endl;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            cout << "B[" << i << " , " <<  j << "] = ",cin >> B[i][j];
        }
    }
    system("Clear");
    //Penjumlahan matriks A dan B -> C = A + B
    for (int i = 1; i <= n;i++) {
        for (int j =1; j <= n;j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    //isi matriks A
    gotoxy(1,5);
    cout << "A = ";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            gotoxy(2+4*j,2+2*i);
            cout << A[i][j];
        }
    }

    //isi matriks B
    gotoxy(1,10);
    cout << "B = ";
    for (int i = 0; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            gotoxy(2+4*j,7+2*i);
            cout << B[i][j];
        }
    }

    //menampilkan matriks C
    gotoxy(1,15);
    cout << "C = ";
    for (int i = 1; i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            gotoxy(2+4*j,12+2*i);
            cout << A[i][j];
        }
    }

    gotoxy(12,15);
    cout << " + ";
    for (int i = 1;i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            gotoxy(13+4*j,12+2*i);
            cout<<B[i][j];
        }
    }

    gotoxy(23,15);
    cout << " + ";
    for (int i = 1;i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            gotoxy(24+4*j,12+2*i);
            cout<<C[i][j];
        }
    }
    cout << endl;
}
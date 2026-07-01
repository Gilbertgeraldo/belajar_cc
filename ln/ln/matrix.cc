#include<bits/stdc++.h>
using namespace std;

void main () {
    int mat[3][3],i,j,sum = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            cout << "\nEnter a number : ";
            cin >> mat[3][3];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0;j < 3;j++) {
            sum += mat[i][j];
        }
    }
    cout << "\nThe entered Matrix is\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << mat[i][j];
        }
        cout << "\n";
    }
    cout << "\nSum of the lower triangular matrix is" << sum;
}
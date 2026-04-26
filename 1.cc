#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[10][10],i,j ,row,col,count = 0,k = 0,sp[15][3],tran[10][3];
    cout << "\nENTER HOW MANY ROWS AND COLOUMNS";
    cin >> row>>col;
    for (i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cout << endl << "Enter a number";
            cin >> arr[i][j];
        }

        cout << "\nENTER THE ARRAY ELEMENTS ARE\n";
        for (i = 0;i < col; i++) {
            cout << setw(4) << arr[i][j];
            cout << endl;
        }

        for (i = 0;i < row;i++)
            for (j = 0; j < col;j++)
                if (arr[i][j] != 0)
                    count++;

        sp[0][0] = row;
        sp[0][1] = col;
        sp[0][2] = col;

        k = 1;

        for (i = 0;i < row;i++)
            for (j = 0;k < col;j++) {
                if(arr[i][j] != 0) {
                    sp[k][0] = i;
                    sp[k][1] = j;
                    sp[k][2] = arr[i][j];
                    k++;
                }
            }
        cout << "\nTHE SPRASE MATRIX IS\n";
        for (i = 0;i <= count;i++) {
            for (j = 0;j < 3;j++)
                cout << " " << sp[i][j];
                cout << endl;
        }

        tran[0][0] = col;
        tran[0][1] = col;
        tran[0][2] = count;
        k = 1;
        for (i = 0; i < col;i++)
            for (j = 1;j <= col;j++) {
                if (sp[i][j] == 1) {
                    {
                        tran[k][0]=sp[j][1];
                        tran[k][1]=sp[j][0];
                        tran[k][2]=sp[j][2];
                         k++;
                }
            }

    cout << "\nTRANSPOSE OF THE SPRASE MATRIX : ";
    for (i = 0; i <= count;i++) {
        for (j = 0; j < 3;j++)
        cout << setw(5) << tran[i][j];
        cout << endl;
    }
}
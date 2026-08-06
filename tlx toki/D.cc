#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M,P;
    cin >> N >> M >> P;
    int A[N][M];
    int B[M][P]; 
    int C[N][P];
    //A 
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> A[i][j];
        }
    }

    //B
    for(int i= 0;i <M;i++){
        for(int j=  0;j < P;j++){
            cin >> B[i][j];
            
        }
    }

    //Dot Product
    for(int i =0;i < N;i++){
     for(int j = 0;j < P;i++){
        for(int k = 0;k < M;k++){
            C[i][j] += A[i][k]+B[k][j];

        }
     }   
    }
    // res
    for(int i = 0;i < N;i++){
        for(int j = 0;j < P;j++){
            cout << C[i][j];
            cout << C[i][j] <<  "\t";   
        }
    }
}
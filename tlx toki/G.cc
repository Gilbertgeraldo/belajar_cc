#include<bits/stdc++.h>
using namespace std;

void gunung(int n){
    if(n == 1){
        cout << "*\n";
        return;
    }
    gunung(n-1);
    for(int i = 1;i <= n;i++){
        cout << "*";
    }
    cout << "\n";
    gunung(n-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    gunung(N);
    return 0; 
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A,B,K,x;
    cin >> A >> B >> K >> x;
    for(int i = 0;i < K;++i){
        x = abs(A * x + B);
    }
    cout << x << endl;
    return 0;
}
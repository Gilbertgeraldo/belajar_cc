#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;

        long long fA,fB,val;

        cin >> fA;
        for(int i = 1;i < n;++i){
            cin >> val;
        }

        cin >> fB;
        for(int i = 1;i < m;++i){
            cin >> val;
        }

        long long bea = fA + n - 1;
        long long ver  = fB + m - 1;

        cout << (ver <= bea ? 1 : 2) << '\n';
    }   
    return 0;
}
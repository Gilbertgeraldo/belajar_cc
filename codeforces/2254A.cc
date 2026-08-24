#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int steps = 0;
    while(true){
        sort(a.begin(),a.end());
        if(a[0] == a[1] || a[1] == a[2]){
            break;
        }
        steps++;
        a.back()++;
        a[0]++;
    }
    cout << steps << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
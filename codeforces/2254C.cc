#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string a,b; cin >> a >> b;
    int Aven = 0, Aodd = 0;
    int Bven = 0,Bodd = 0;
    for(int i = 1;i < n;i++){
        if(a[i] == '1'){
            if(i % 2 == 0){
                Aven++;
            }else{
                Aodd++;
            }
        }
        if(b[i] == '1'){
            if(i % 2 == 0){
                Bven++;
            }else{
                Bodd++;
            }
        }
    }
    if(Aven == Aodd && Bven == Bodd){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0; 
}
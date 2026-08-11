#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int block = 1;
    for(int i = 1;i < n;i++){
        if(s[i] != s[i-1]){
            block++;
        }
    }
    int save = 0;
    for(int i = 1;i < n-1;i++){
        if(s[i] != s[i-1] && s[i] != s[i+1]){
            if(s[i-1] == s[i+1]){
                save = 2;
            }else{
                save = max(save,1);
            }
        }
    }
    cout << block - save << "\n";
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
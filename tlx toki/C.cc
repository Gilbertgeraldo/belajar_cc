#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0;i <= N;++i){
        for(int j = i+1;j <= i;++j){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
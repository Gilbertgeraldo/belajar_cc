#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N) || N <= 0) return 0;
    vector<int> a(N);
    for(int i = 0;i < N;++i){
        cin >> a[i];
    }
    cout << *max_element(a.begin(),a.end()) << "\n";
    cout << *min_element(a.begin(),a.end()) << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,D;
    cin >> N >> D;

    int X[1005];
    int Y[1005];

    for(int i = 0;i < N;i++){
        cin >> X[i] >> Y[i];
    }
    int mn = INT_MAX;
    int mx = INT_MIN;

    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
            
            int dx = abs(X[j] - X[i]);
            int dy = abs(Y[j] - Y[i]);

            int t;
            if(D == 1){
                t = dx + dy;
            }else if(D == 2){
                t = dx * dx + dy * dy;
            }else{
                t = dx*dx*dx + dy*dy*dy;

            }
            mn = min(mn,t);
            mx = max(mx,t);
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}
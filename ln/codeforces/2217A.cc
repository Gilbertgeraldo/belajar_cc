#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
    int n,k;cin >> n >> k;
    ll sum = 0,multi = n*k;
    for(int i = 0;i < n;++i) {
        int x;cin >> x;
        sum+=x;
    }
    if(sum%2!=0 || sum == 1 || multi%2==0) {
        cout << "YES" << endl;
        return;
    }
    cout << "no" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int t = 1;
   cin >> t;
   while(t--) solve();
    return 0;
}
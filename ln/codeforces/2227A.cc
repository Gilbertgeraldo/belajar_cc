#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve() {
    int x,y;
    cin >> x >> y;

    if (x % 2 != 0 && y % 2 != 0) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
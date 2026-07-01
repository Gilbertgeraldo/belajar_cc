#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m,d;
        cin >> n >> m >> d;

        int mx = d / m + 1;
        int ans = (n + mx - 1) / mx;

        cout << ans << "\n";
    }
    return 0;
}
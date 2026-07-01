#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll hitung_opsi(ll start, ll target) {
    ll ops = 0;
    while (start != target) {
        if (start < target) {
            ops += (target - start);
            break;
        }
        if (start % 2 == 0) {
            start /= 2;
        } else {
            start += 1;
        }
        ops++;
    }
    return ops;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 1e18;
    for (ll target = 1; target <= 50; target++) {
        ll total_ops_sekarang = 0;
        
        for (int i = 0; i < n; i++) {
            total_ops_sekarang += hitung_opsi(a[i], target);
        }

        ans = min(ans, total_ops_sekarang);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
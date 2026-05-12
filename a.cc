#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    typedef long long ll;
    int n;
    if (!(cin >> n)) {return 0;}
    vector<ll> a(n);
    ll total = 0;
    for (int i = 0 ;i < n;i++) {
        cin >> a[i];
        total += a[i];
    }

    for (int i = 0; i < n;i++) {
        ll res = total - a[i];
        cout << res << endl;
    }
    return 0;
}
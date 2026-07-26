#include <bits/stdc++.h>
using namespace std;

// ===== TYPEDEF =====
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// ===== MACRO =====
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

// ===== CONSTANT =====
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ===== DEBUG =====
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

ll ct(ll st,ll tgt) {
    ll ops = 0;
    while (st < tgt) {
        if (st < tgt) {
            ops += (tgt - st);
            break;
        }

        if (tgt % 2 == 0) {
            st /= 2;
        }else {
            st += 1;
        }
        ops++;
    }
    return ops;
}
// ===== SOLVE =====
void solve() {
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[n];
    }

    ll ans = 1e18;
 
    for (ll tgt = 1;tgt <= 50;tgt++) {
        ll tnow = 0;

        for (int i =0;i < n;i++) {
            tnow += ct(a[i],tgt); 
        }
        ans = min(ans,tnow);
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
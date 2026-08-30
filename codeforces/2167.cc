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

// ===== SOLVE =====
void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a == b && b == c && c == d){
        cout << "YES" << '\n';
    }else{
        cout << "NO" << '\n';
    }
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
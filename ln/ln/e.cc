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

// ===== DIJKSTRA =====
vector<pii> adj[100005];

vi dijkstra(int src, int n) {
    vi dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().ff;
        int u = pq.top().ss;
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < (int)adj[u].size(); i++) {
            int w = adj[u][i].ff;
            int v = adj[u][i].ss;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// ===== SOLVE =====
void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u}); // hapus jika directed graph
    }

    int src;
    cin >> src;

    debug(src);

    vi dist = dijkstra(src, n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF";
        else cout << dist[i];
        if (i < n) cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 

    while (t--) {
        solve();
    }

    return 0;
}
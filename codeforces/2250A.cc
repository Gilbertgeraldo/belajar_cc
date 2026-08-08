#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<long long> w(n);

        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }

        if (n == 1) {
            cout << "NO\n";
            continue;
        }

        long long maxEv = 0;
        long long minOdd = 1000000001LL;

        for (int i = 0; i < n; ++i) {

            if (i % 2 == 0) {
                minOdd = min(minOdd, w[i]);
            }
            else {
                maxEv = max(maxEv, w[i]);
            }
        }

        long long k = maxEv + 1;

        if (k < minOdd) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
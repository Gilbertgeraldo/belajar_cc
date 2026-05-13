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

    while(t--) {
        int n; cin >> n;

        int x = n % 3;
        if (x == 0) {
            cout << 0 << "\n";
        }else {
            cout << 3 - x << "\n";
        }
    }
    return 0;
}
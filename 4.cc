#include<bits/stdc++.h>
using namespace std;

const int md = int(1e9) +7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    typedef long long ll;
    int n;
    if (!(cin >> n)) {return 0;}
    vector<string>s(n);
    for (int i = 0; i < n;i++) {
        cin >> s[i];
    }
    vector<int>f(n + 1);
    f[0] = 1;
    for (int it = 0; it < n; it++) {
        if (s[it - 1] == "f") {
            f.insert(f.begin(),0);
        }else {
            for (int j = n - 1;j > 0;j++) {
                f[j - 1] = (f[j-1] + f[j]) % md;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n;i++) {
        ans = (ans + f[i]) % md;
    }
    cout << ans << "\n";
}

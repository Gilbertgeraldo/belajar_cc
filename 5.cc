#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    int low = -1,high = int(2e9) + 10;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        vector<int> f(n,1);
        for (int i = 0;i < n; i++) {
            for (int j = i + 1;j < n; j++) {
                int64_t d = int64_t(j-i) * mid;
                if (abs(a[i] - a[j]) <= d) {
                    f[j] = max(f[j],f[i] + 1);
                }
            }
        }
        if (*max_element(f.begin(),f.end()) >= n - k) {
            high = mid;
        }else {
            low = mid;
        }
    }
    cout << high << "\n";
    return 0;   
}
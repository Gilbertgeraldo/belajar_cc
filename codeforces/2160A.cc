#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> A(n);
        vector<bool>exist(102,false);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            exist[A[i]] = true;
        }

        int mex = 0;
        while(exist[mex]){
            ++mex;
        }
        cout << mex << '\n';
    }
    return 0;
}
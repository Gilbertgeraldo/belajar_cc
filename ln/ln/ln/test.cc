#include<bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    if (n <= 1) {return false;}

    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) {return false;}
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    if (cin >> a >> b) {
        int start = min(a,b);
        int end = max(a,b);

        vector<int>pr;
        for (int i = start;i <= end;i++) {
            if (isprime(i)) {
                pr.push_back(i);
            }
        }

        for (size_t i = 0;i < pr.size();i++) {
            cout << pr[i];
            if (i < pr.size() - 1) {cout << ", ";}
        }
        cout << "\n";
    }
    return 0;
}
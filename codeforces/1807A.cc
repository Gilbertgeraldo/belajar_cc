#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while(t--) {
        int a,b,c; cin >> a >> b >> c;
        if (a + b == c) {cout << "+";}
        else {cout << "-";}
        cout << "\n";
    }
    return 0;
}
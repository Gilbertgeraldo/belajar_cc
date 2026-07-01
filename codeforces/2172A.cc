#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int>s(3);
    cin >> s[0] >> s[1] >> s[2];
    
    sort(s.begin(),s.end());
    if (s[2] - s[0] >= 10) {
        cout << "check again" << "\n";
    }else {
        cout << "final " << s[1] << "\n";
    }
    return 0;
}
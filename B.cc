#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) {return 0;}

    long lom  b_r = 1,b_c = N;
    for (long long r = 1; r * r <= N;r++) {
        if (N % r == 0) {
            long long c = N / r;
            if (c - r < b_c - b_r) {
                b_r = r;
                b_c = c;
            }
        }
    }
    cout << b_r << " " << b_c << endl;
    return 0;
}
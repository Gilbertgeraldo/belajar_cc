#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

//Euler's formula
// Syarat : E <= 3*V - 6 (V >=3)
bool IsPlanar(int V,int E) {
    if (V < 3) return true;
    return E <= 3*V - 6;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << IsPlanar(5,10) << endl;
    cout << IsPlanar(4,6);

    return 0;
}
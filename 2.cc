#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    vector<int> e(n);
    for (int i = 0;i < n;i++) {
        cin >> e[i];
        e.push_back(e[i]);
    }

    for (auto x : e) {
        cout << x << endl;
    }
    cout << endl;

    e.pop_back();
    cout << "Data dalam vector setelah di pop_back : " << endl;
    for (auto x : e) {
        cout << x << endl;
    }

    e.resize(5);
    cout << "Angka setelah di resize : " << endl;
    for (auto x : e) {
        cout << x << endl;
    }
    cout << endl;

    e.assign(3,100);
    cout << "Isi vector setelah di assign : " << endl;
    for (auto x : e) {
        cout << x << endl;
    }
    cout << endl;
    return 0;
}
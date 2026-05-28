#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;
    for (int i = 1;i < 10; i++) {
        v.push_back(i);
    }

    cout << "Using begin & end" << endl;
    for (auto i = v.begin();i != v.end();++i) {
        cout << *i << "\t";
    }

    cout << "Using Cbegin & Cend" << endl;
    for (auto i = v.cbegin();i != v.cend();++i) {
        cout << *i << "\t";
    }

    cout << "Using Crbegin & Crend" << endl;
    for (auto i = v.crbegin();i != v.crend();++i) {
        cout << *i << "\t";
    }
    return 0;
}
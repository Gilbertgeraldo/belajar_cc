#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct Data {
    int x;string y;double z;
    Data(int x,string y,double z) : x(x),y(y),z(z) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Data> v;
    v.emplace_back(10, "Halo", 3.14); // emplace_back lebih efisien untuk struct
    v.emplace_back(20, "Dunia", 5.75);

    for (auto &d : v) {
        cout << d.x << d.y << d.z << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll N;
    cin >> N;

    ll s = round(sqrt(N));

    if (s * s != N) {
        cout <<"Lampu mati" << endl;
    }else {
        cout << "Lampu nyala : " << endl;
    }
}
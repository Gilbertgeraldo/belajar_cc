#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

int hitung_vokal(string s) {
    if (s.empty()) {return 0;}

    char c = tolower(s[0]);
    bool isVokal = (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');

    if (isVokal) {
        return 1 + hitung_vokal(s.substr(1));
    }else {
        return 0 + hitung_vokal(s.substr(1));
    }
}

int main() {
    cout << hitung_vokal("lorem ipsum dolor sit amet fermentum egestas luctus praesent torquent justo.") << endl;
    return 0;
}